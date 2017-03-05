/**
 * This file defines a generic HCI transport interface.
 *
 * Users must provide implementations for the functions defined in this file.
 */
#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Initialize this HCI transport.
 *
 * @TODO define error codes
 * @return 0 for success, else error code
 */
int TBLE_Dep_HciTransportInit(void);

/**
 * Send a packet over the HCI transport.
 *
 * @param[in] packet The packet data to send
 * @param[in] len    The length of packet
 *
 * @TODO define error codes
 * @return 0 for success, else error code
 */
int TBLE_Dep_HciTransportSendPacket(const void *packet, size_t len);

/**
 * Check if the transport is able to send a packet now.
 *
 * @return true if transport can send a packet, send false
 */
bool TBLE_Dep_HciTransportCanSendPacketNow(void);

/**
 * Callback to be called when a new incoming packet is received over the transport
 *
 * @param[in] pkt The received packet
 * @param[in] len The length of the received packet
 */
typedef int(*TBLE_PacketReceivedCallback)(void *pkt, size_t len);

/**
 * Register the packet received callback.
 */
void TBLE_Dep_HciTransportRegisterPacketReceivedCallback(TBLE_PacketReceivedCallback cb);
