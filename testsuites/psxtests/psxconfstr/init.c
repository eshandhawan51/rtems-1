/*
 *  @file
 *  @brief Test suite for confstr method
 */

/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2020 Eshan Dhawan, Sebastian Huber
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <rtems.h>
#include <rtems/test.h>
#include <unistd.h>
#include <rtems/bspIo.h>

#include "tmacros.h"
#include "test_support.h"

const char rtems_test_name[] = "PSXCONFSTR";

/* Forward declaration to avoid warnings */
rtems_task Init( rtems_task_argument ignored );

static char buffer[512];

static const T_action actions[] = {
  T_report_hash_sha256,
  T_check_task_context,
  T_check_file_descriptors,
  T_check_rtems_barriers,
  T_check_rtems_extensions,
  T_check_rtems_message_queues,
  T_check_rtems_partitions,
  T_check_rtems_periods,
  T_check_rtems_regions,
  T_check_rtems_semaphores,
  T_check_rtems_tasks,
  T_check_rtems_timers,
  T_check_posix_keys
};

static const T_config config = {
  .name = "psxconfstr",
  .buf = buffer,
  .putchar = rtems_put_char,
  .buf_size = sizeof(buffer),
  .verbosity = T_VERBOSE,
  .now = T_now_clock,
  .action_count = T_ARRAY_SIZE(actions),
  .actions = actions
};

/* init test function begins */ 
T_TEST_CASE(confstr)
{
  
int r;
  char * buf ;
  const char UPE[] = "unsupported programming environment";
  size_t len1;
  len1 = strlen(UPE) + 1; 
  r = confstr(_CS_PATH, buf, sizeof(buf));
  T_quiet_psx_success(r);

  r = confstr(_CS_POSIX_V6_ILP32_OFFBIG_CFLAGS, buf, sizeof(buf));
  T_quiet_eq_int(r, len1);

  r = confstr(_CS_POSIX_V6_LP64_OFF64_LDFLAGS, buf, sizeof(buf));
  T_quiet_eq_int(r, len1);

  r = confstr(_CS_POSIX_V7_ILP32_OFF32_CFLAGS, buf, sizeof(buf));
  T_quiet_eq_int(r, len1);

  r = confstr(_CS_POSIX_V7_ILP32_OFFBIG_CFLAGS, buf, sizeof(buf));
  T_quiet_eq_int(r, len1);

  r = confstr(_CS_POSIX_V7_LP64_OFF64_LIBS, buf, sizeof(buf));
  T_quiet_eq_int(r, len1);

  r = confstr(_CS_POSIX_V6_LP64_OFF64_CFLAGS, buf, sizeof(buf));
  T_quiet_eq_int(r, len1);

  r = confstr(_CS_PATH, buf, sizeof(buf));
  T_quiet_psx_success(r);

}

rtems_task Init(rtems_task_argument ignored)
{
  int exit_code;

  TEST_BEGIN();

  T_register();
  exit_code = T_main(&config);
  if (exit_code == 0) {
    TEST_END();
  }

 rtems_test_exit(exit_code);

}
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS 1

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_INIT

#include <rtems/confdefs.h>
/* end of file */
