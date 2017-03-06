/**
 * @TODO header
 */
#include "l2cap.h"

#include <stddef.h>
#include <stdint.h>

#include "hci_defs.h"
#include "l2cap_link.h"


int L2capHandleAclDataReceived(const void *data, size_t len, HciAclPacketBoundaryFlag pb_flag)
{
    /*
    L2capLink *const link = L2capLinkForHandle(pkt->hdr.conn_handle);

    // LE links are created automatically, so just create one
    // if it doesn't exist
    if (link == NULL) {
        link = L2capLinkInitNew(handle);

        if (link == NULL) {
            // @TODO what to do here?
            printf("ERROR: out of L2CAP links\n");
            return -1;
        }
    }

    HciAclReceiveStateMachine *const fsm = link->acl_recv_fsm;
    switch (pb_flag)
    {
        case kL2capAclPbFlagFirstFlushable:
            // @TODO
            break;

        case kL2capAclPbFlagFirstNonFlushable:
        case kL2capAclPbFlagContinuingFragment:
        case kL2capAclPbFlagCompleteL2capPdu:
        default:
            // @TODO some of these
            printf("ERROR: ACL PB flag %u not yet supported\n", pb_flag);
            status = -1;
            break;
    }
    */

    return 0;
}
