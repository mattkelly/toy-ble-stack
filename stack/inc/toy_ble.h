/**
 * This file defines the main public interface to the Toy BLE Stack.
 */
#pragma once

#include <stdint.h>

#define BD_ADDR_LEN 6

typedef uint8_t BdAddr[BD_ADDR_LEN];

/**
 * Initialize the stack. Must be called before any other TBLE_* functions are called.
 *
 * @TODO define error codes
 * @return 0 for success, else error code
 */
int TBLE_Init(void);
