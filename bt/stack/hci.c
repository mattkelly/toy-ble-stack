#include "hci.h"

#include <stdint.h>
#include <string.h>

#include "hci_defs.h"
#include "hci_transport.h"
#include "toy_ble.h"

/**
 * The buffer to be used for all outgoing
 * HCI commands.
 */
static uint8_t _hci_cmd_buf[HCI_MAX_CMD_LEN];

static void *_InitHciCmd(uint16_t ogf, uint16_t ocf)
{
    _hci_cmd_buf[0] = kHciPacketTypeCommand;
    *((uint16_t*)&_hci_cmd_buf[1]) = HCI_OPCODE(ogf, ocf);
    return &_hci_cmd_buf[1];
}

int HciSendReset(void)
{
    HciCmdReset *const pkt =
        _InitHciCmd(kHciGroupControllerBaseband, kHciCmdControllerReset);
    pkt->hdr.param_len = sizeof(*pkt) - sizeof(pkt->hdr);

    return TBLE_Dep_HciTransportSendPacket(_hci_cmd_buf, sizeof(*pkt) + 1);
}

// @TODO enums etc.
int HciSendSetAdvertisingParams(uint16_t adv_interval_min,
        uint16_t adv_interval_max,
        uint8_t adv_type,
        uint8_t own_addr_type,
        uint8_t peer_addr_type,
        uint8_t peer_addr[6],
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

    return TBLE_Dep_HciTransportSendPacket(_hci_cmd_buf, sizeof(*pkt) + 1);
}

int HciSendAdvertiseEnable(bool enable)
{
    HciCmdSetAdvertiseEnable *const pkt =
        _InitHciCmd(kHciGroupLeController, kHciCmdLeSetAdvertiseEnable);
    pkt->hdr.param_len = sizeof(*pkt) - sizeof(pkt->hdr);

    pkt->enable = enable;

    return TBLE_Dep_HciTransportSendPacket(_hci_cmd_buf, sizeof(*pkt) + 1);
}
