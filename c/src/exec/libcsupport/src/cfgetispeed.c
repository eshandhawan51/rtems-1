/*
 *  cfgetispeed() - POSIX 1003.1b 7.1.3 - Baud Rate Functions
 *
 *  COPYRIGHT (c) 1989-1998.
 *  On-Line Applications Research Corporation (OAR).
 *  Copyright assigned to U.S. Government, 1994.
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id$
 */

#include <rtems.h>
#if defined(RTEMS_NEWLIB)

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <termios.h>

speed_t cfgetispeed(
  const struct termios *tp
)
{
  return (tp->c_cflag / (CIBAUD / CBAUD)) &  CBAUD;
}
#endif
