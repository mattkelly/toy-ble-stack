/**
 * Implements hci_transport.h for the esp32.
 */
#include "hci_transport.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "bt.h" // esp-idf VHCI definitions

// @TODO currently always true
static bool _can_send_packet = true;

TBLE_PacketReceivedCallback packet_received_cb = NULL;

static void _HostSendPacketAvailableCb(void)
{
    printf("HostSendPacketAvailableCb\n");
    _can_send_packet = true;
}

static int _HostReceivedPacketCb(uint8_t *data, uint16_t len)
{
    if (packet_received_cb != NULL) {
        packet_received_cb(data, len);
    }

    return 0;
}

static const esp_vhci_host_callback_t _vhci_host_cb = {
    .notify_host_send_available = _HostSendPacketAvailableCb,
    .notify_host_recv = _HostReceivedPacketCb,
};

int TBLE_Dep_HciTransportInit(void)
{
    printf("TBLE_Dep_HciTransportInit\n");
    esp_bt_controller_init();
    esp_vhci_host_register_callback(&_vhci_host_cb);

    return 0;
}


int TBLE_Dep_HciTransportSendPacket(const void *packet, size_t len)
{
    printf("TBLE_Dep_HciTransportSendPacket: [ ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", ((uint8_t*)packet)[i]);
    }
    printf("] (%zu bytes)\n", len);

    esp_vhci_host_send_packet((uint8_t*)packet, len);

    return 0;
}

/**
 * Check if the transport is able to send a packet now.
 *
 * @return true if transport can send a packet, send false
 */
bool TBLE_Dep_HciTransportCanSendPacketNow(void)
{
    return _can_send_packet;
}

/**
 * Register the packet received callback.
 */
void TBLE_Dep_HciTransportRegisterPacketReceivedCallback(TBLE_PacketReceivedCallback cb)
{
    packet_received_cb = cb;
}
