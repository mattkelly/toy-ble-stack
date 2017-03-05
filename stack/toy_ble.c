#include "toy_ble.h"

#include "hci_transport.h"

// @TODO real logging
#include <stdio.h>
#include <inttypes.h>

// @TODO
static int PacketReceivedCb(void *data, size_t len)
{
    printf("TBLE PacketReceivedCb: [ ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", ((uint8_t*)data)[i]);
    }
    printf("] (%" PRIu16 " bytes)\n", len);

    return 0;
}

int TBLE_Init(void)
{
    int ret = 0;

    ret = TBLE_Dep_HciTransportInit();
    if (ret != 0) {
        printf("ERROR: TBLE_Dep_HciTransportInit failed\n");
        return ret;
    }

    printf("Transport init success\n");

    TBLE_Dep_HciTransportRegisterPacketReceivedCallback(PacketReceivedCb);

    return 0;
}
