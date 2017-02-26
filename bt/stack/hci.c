#include "hci.h"

#include <stdint.h>

#include "hci_defs.h"
#include "hci_transport.h"

// @TODO real logging
#include <stdio.h>

/**
 * The buffer to be used for all outgoing
 * HCI commands.
 */
static uint8_t _hci_cmd_buf[HCI_MAX_CMD_LEN];

int HciSendReset(void)
{
    printf("HciSendReset\n");

    _hci_cmd_buf[0] = kHciPacketTypeCommand;

    HciCmdReset *const pkt = (HciCmdReset*)&_hci_cmd_buf[1];
    pkt->hdr.opcode = HCI_OPCODE(kHciGroupControllerBaseband, kHciCmdControllerReset);

    return TBLE_Dep_HciTransportSendPacket(_hci_cmd_buf, sizeof(*pkt) + 1);
}
