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

    while (1) {
    }
}
