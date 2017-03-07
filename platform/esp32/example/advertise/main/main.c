/**
 * @TODO header
 * @TODO use GAP rather than direct HCI
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "hci.h"
#include "toy_ble.h"

const uint8_t adv_data[] = {
    0x02, 0x01, 0x06, // General Discoverable, BR/EDR unsupported
    0x0b, 0x09, 'T', 'o', 'y', ' ', 'B', 'L', 'E' // Complete Local Name
};
const uint8_t adv_data_len = sizeof(adv_data);

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

    printf("HciSendSetAdvertisingData\n");
    HciSendSetAdvertisingData(adv_data_len, adv_data);

    printf("HciSendAdvertiseEnable\n");
    HciSendSetAdvertiseEnable(true);

    while (1) {
    }
}
