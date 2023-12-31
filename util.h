/* util.h
 * Copyright (c) 2012 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Logging and other utility functions.
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>
#include <syslog.h>

#define die(_msg, ...) do { \
	syslog(LOG_ERR, "libminijail: " _msg, ## __VA_ARGS__); \
	abort(); \
} while (0)

#define pdie(_msg, ...) \
	die(_msg ": %s", ## __VA_ARGS__, strerror(errno))

#define warn(_msg, ...) \
	syslog(LOG_WARNING, "libminijail: " _msg, ## __VA_ARGS__)

#define info(_msg, ...) \
	syslog(LOG_INFO, "libminijail: " _msg, ## __VA_ARGS__)

extern const char *log_syscalls[];
extern const size_t log_syscalls_len;

int lookup_syscall(const char *name);
const char *lookup_syscall_name(int nr);
char *strip(char *s);
char *tokenize(char **stringp, const char *delim);

#endif /* _UTIL_H_ */
