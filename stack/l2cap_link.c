/**
 * @TODO header
 */
#include "l2cap_link.h"

#include <stdbool.h>
#include <stddef.h>

/**
 * L2CAP Link database.
 */
static L2capLink _link_db[L2CAP_MAX_NUM_LINKS];

static inline void _ResetLink(L2capLink *link)
{
    link->is_init = false;

    // Reset ACL Receive State Machine
    link->acl_recv_fsm.state = kL2capAclReceiveStateIdle;
    link->acl_recv_fsm.num_bytes_expected = 0;
    link->acl_recv_fsm.buffer_pos = 0;
}

/**
 * @TODO
 */
static L2capLink *_GetFreeLink(void)
{
    for (size_t i = 0; i < L2CAP_MAX_NUM_LINKS; i++) {
        if (_link_db[i].is_init == false) {
            return &_link_db[i];
        }
    }

    return NULL;
}

/**
 * @TODO
 */
L2capLink *L2capLinkForHandle(L2capLinkHandle handle)
{
    for (size_t i = 0; i < L2CAP_MAX_NUM_LINKS; i++) {
        if ((_link_db[i].is_init == false)
                && (_link_db[i].handle == handle)) {
            return &_link_db[i];
        }
    }

    return NULL;
}

L2capLink *L2capLinkInitNew(L2capLinkHandle handle)
{
    L2capLink *const link = _GetFreeLink();

    if (link != NULL) {
        _ResetLink(link);
        link->is_init = true;
        link->handle = handle;
    }

    return link;
}
