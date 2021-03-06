/*
 * QEMU Guest Agent core declarations
 *
 * Copyright IBM Corp. 2011
 *
 * Authors:
 *  Adam Litke        <aglitke@linux.vnet.ibm.com>
 *  Michael Roth      <mdroth@linux.vnet.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */
#include "qapi/qmp/dispatch.h"
#include "qemu-common.h"

#define QGA_READ_COUNT_DEFAULT 4096

typedef struct GAState GAState;
typedef struct GACommandState GACommandState;
extern GAState *ga_state;

void ga_command_state_init(GAState *s, GACommandState *cs);
void ga_command_state_add(GACommandState *cs,
                          void (*init)(void),
                          void (*cleanup)(void));
void ga_command_state_init_all(GACommandState *cs);
void ga_command_state_cleanup_all(GACommandState *cs);
GACommandState *ga_command_state_new(void);
bool ga_logging_enabled(GAState *s);
void ga_disable_logging(GAState *s);
void ga_enable_logging(GAState *s);
void slog(const gchar *fmt, ...);
void ga_set_response_delimited(GAState *s);
bool ga_is_frozen(GAState *s);
void ga_set_frozen(GAState *s);
void ga_unset_frozen(GAState *s);

#ifndef _WIN32
void reopen_fd_to_null(int fd);
#endif
