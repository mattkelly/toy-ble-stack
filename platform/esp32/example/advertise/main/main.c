#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "hci.h"
#include "toy_ble.h"

void app_main(void)
{
    if (TBLE_Init() != 0) {
        printf("ERROR: TBLE_Init failed\n");
        return;
    }

    printf("HciSendReset\n");
    HciSendReset();

    printf("HciSendSetAdvertisingParams\n");
    HciSendSetAdvertisingParams(256,  // 160ms
                                256,  // 160ms
                                0,    // Connectable undirected (ADV_IND)
                                0,    // Public BD_ADDR
                                0,    // Public BD_ADDR
                                NULL,
                                0x07, // 37, 38, 39
                                0);   // Process All Conn and Scan

    printf("HciSendAdvertiseEnable\n");
    HciSendAdvertiseEnable(true);

    while (1) {
    }
}
