#include "hci.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "hci_defs.h"
#include "hci_transport.h"
#include "l2cap.h"
#include "toy_ble.h"

// @TODO real logging
#include <stdio.h>
#include <inttypes.h>

/**
 * The buffer to be used for all outgoing
 * HCI commands.
 */
static uint8_t _hci_cmd_buf[HCI_MAX_CMD_LEN];

/**
 * @brief Initialize a new HCI Command.
 *
 * @param[in] ogf The OGF of the command
 * @param[in] ocf The OCF of the command
 *
 * @return Pointer to command that caller should fill
 */
static inline void *_InitHciCmd(uint16_t ogf, uint16_t ocf)
{
    _hci_cmd_buf[0] = kHciPacketTypeCommand;
    *((uint16_t*)&_hci_cmd_buf[1]) = HCI_OPCODE(ogf, ocf);
    return &_hci_cmd_buf[1];
}

/**
 * @brief Send an HCI Command.
 *
 * @param[in] len Length of the command, excluding packet type byte
 */
static inline int _SendHciCmd(size_t len)
{
    return TBLE_Dep_HciTransportSendPacket(_hci_cmd_buf, len + 1);
}

int HciSendReset(void)
{
    HciCmdReset *const pkt =
        _InitHciCmd(kHciGroupControllerBaseband, kHciCmdControllerReset);
    pkt->hdr.param_len = sizeof(*pkt) - sizeof(pkt->hdr);

    return _SendHciCmd(sizeof(*pkt));
}

// @TODO enums etc.
int HciSendSetAdvertisingParams(uint16_t adv_interval_min,
        uint16_t adv_interval_max,
        uint8_t adv_type,
        uint8_t own_addr_type,
        uint8_t peer_addr_type,
        BdAddr peer_addr,
        uint8_t adv_chan_map,
        uint8_t adv_filter_policy)
{
    HciCmdSetAdvertisingParams *const pkt =
        _InitHciCmd(kHciGroupLeController, kHciCmdLeSetAdvertisingParams);
    pkt->hdr.param_len = sizeof(*pkt) - sizeof(pkt->hdr);

    pkt->adv_interval_min = adv_interval_min;
    pkt->adv_interval_max = adv_interval_max;
    pkt->adv_type = adv_type;
    pkt->own_addr_type = own_addr_type;
    pkt->peer_addr_type = peer_addr_type;
    pkt->adv_chan_map = adv_chan_map;
    pkt->adv_filter_policy = adv_filter_policy;

    if (peer_addr != NULL) {
        // @TODO probably needs byte reversing
        memcpy(pkt->peer_addr, peer_addr, BD_ADDR_LEN);
    }

    return _SendHciCmd(sizeof(*pkt));
}

int HciSendAdvertiseEnable(bool enable)
{
    HciCmdSetAdvertiseEnable *const pkt =
        _InitHciCmd(kHciGroupLeController, kHciCmdLeSetAdvertiseEnable);
    pkt->hdr.param_len = sizeof(*pkt) - sizeof(pkt->hdr);

    pkt->enable = enable;

    return _SendHciCmd(sizeof(*pkt));
}

static int _HandleAclDataReceived(const void *data, size_t len)
{
    printf("HCI ACL In: [ ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", ((uint8_t*)data)[i]);
    }
    printf("] (%" PRIu16 " bytes)\n", len);

    const HciAclDataPkt *const pkt = data;

    printf(" --> Conn handle: %u\n", pkt->hdr.conn_handle);
    printf(" --> PB Flag: %u\n", pkt->hdr.pkt_boundary_flag);
    printf(" --> BC Flag: %u\n", pkt->hdr.broadcast_flag);
    printf(" --> Data Len: %" PRIu16 "\n", pkt->hdr.data_len);

    // @TODO dependency function for upper layer, etc.
    return L2capHandleAclDataReceived(pkt->data, pkt->hdr.data_len, pkt->hdr.pkt_boundary_flag);
}

static int _HandleEventReceived(const void *data, size_t len)
{
    printf("HCI Event In: [ ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", ((uint8_t*)data)[i]);
    }
    printf("] (%" PRIu16 " bytes)\n", len);

    return 0;
}

int HciHandleDataReceived(void *data, size_t len)
{
    int status = 0;

    const HciPkt *const pkt = data;

    switch (pkt->type) {
        case kHciPacketTypeAclData:
            status = _HandleAclDataReceived(pkt->data, len - sizeof(pkt->type));
            break;

        case kHciPacketTypeEventData:
            status = _HandleEventReceived(pkt->data, len - sizeof(pkt->type));
            break;

        default:
            printf("ERROR: Unknown packet type received: type = %" PRIx8 "\n", pkt->type);
            status = -1;
            break;
    }

    return status;
}
