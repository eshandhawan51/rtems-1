/*
 *  mkfifo() - POSIX 1003.1b 5.4.1 - Make a FIFO Special File
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

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int mkfifo(
  const  char *path,
  mode_t       mode
)
{
  return mknod( path, mode | S_IFIFO, 0LL );
}
