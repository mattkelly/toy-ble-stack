#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "bt.h" // esp-idf VHCI definitions

const uint8_t HCI_RESET_PKT[] = {0x01, 0x03, 0x0C, 0x00};

static void HostSendPacketAvailableCb(void)
{
    printf("HostSendPacketAvailableCb\n");
}

static int HostReceivedPacketCb(uint8_t *data, uint16_t len)
{
    printf("HostReceivedPacketCb: [ ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", data[i]);
    }
    printf("] (%" PRIu16 " bytes)\n", len);

    return 0;
}

static const esp_vhci_host_callback_t _vhci_host_cb = {
    .notify_host_send_available = HostSendPacketAvailableCb,
    .notify_host_recv = HostReceivedPacketCb,
};

void app_main(void)
{
    esp_bt_controller_init();
    esp_vhci_host_register_callback(&_vhci_host_cb);

    esp_vhci_host_send_packet((uint8_t*)HCI_RESET_PKT, sizeof(HCI_RESET_PKT));

    while (1) {
    }
}
