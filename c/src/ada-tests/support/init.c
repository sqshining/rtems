/* 
 *  COPYRIGHT (c) 1989, 1990, 1991, 1992, 1993, 1994.
 *  On-Line Applications Research Corporation (OAR).
 *  All rights assigned to U.S. Government, 1994.
 *
 *  This material may be reproduced by or for the U.S. Government pursuant
 *  to the copyright license under the clause at DFARS 252.227-7013.  This
 *  notice must appear in all copies of this file and its derivatives.
 *
 *  $Id$
 */

#define __RTEMS_VIOLATE_KERNEL_VISIBILITY__
#include <bsp.h>
#include <stdlib.h>

void *POSIX_Init(
  void *argument
)
{
  extern int gnat_main ( int argc, char **argv, char **envp );

  (void) gnat_main ( 0, 0, 0 );

  exit( 0 );
}

/*
 *  Only for sp04
 */

rtems_id tcb_to_id(
  Thread_Control *tcb
)
{
  return tcb->Object.id;
}

/*
 *  By putting this in brackets rather than quotes, we get the search
 *  path and can get this file from ".." in the mptests.
 */

#define CONFIGURE_INIT
#define CONFIGURE_GNAT_RTEMS
#define CONFIGURE_MEMORY_OVERHEAD        (256)

#include <config.h>
