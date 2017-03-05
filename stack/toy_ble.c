#include "toy_ble.h"

#include "hci.h"
#include "hci_transport.h"

// @TODO real logging
#include <stdio.h>
#include <inttypes.h>


int TBLE_Init(void)
{
    int ret = 0;

    ret = TBLE_Dep_HciTransportInit();
    if (ret != 0) {
        printf("ERROR: TBLE_Dep_HciTransportInit failed\n");
        return ret;
    }

    printf("Transport init success\n");

    TBLE_Dep_HciTransportRegisterPacketReceivedCallback(HciHandleDataReceived);

    return 0;
}
