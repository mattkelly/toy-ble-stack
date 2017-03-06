/**
 * @TODO header
 * @TODO make a generic connection database
 * @TODO linked list perhaps
 */
#pragma once

#include <stdbool.h>

#include "hci_defs.h"
#include "l2cap.h"

typedef uint16_t L2capLinkHandle;

// @TODO should probably be user-configurable
#define L2CAP_MAX_NUM_LINKS 2

typedef struct {
    bool is_init;

    L2capLinkHandle handle;

    L2capAclReceiveStateMachine acl_recv_fsm;
} L2capLink;

/**
 * @TODO
 */
L2capLink *L2capLinkForHandle(L2capLinkHandle handle);

/**
 * @TODO
 */
L2capLink *L2capLinkInitNew(L2capLinkHandle handle);
