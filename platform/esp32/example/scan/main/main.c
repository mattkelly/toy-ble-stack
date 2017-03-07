/**
 * @TODO header
 * @TODO use GAP rather than direct HCI
 */
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

    HciSendReset();

    // Note that we set the scan interval equal to the scan window,
    // so scanning should run continuously.
    HciSendSetScanParams(0x01, // Active scanning
            0x0004,            // Min scan interval
            0x0004,            // Min scan window
            0x0,               // Public address type
            0x0);              // Accept everything except directed adv not addressed to us

    HciSendSetScanEnable(true,   // Enable scan
                         false); // Don't filter duplicates

    while (1) {
    }
}
