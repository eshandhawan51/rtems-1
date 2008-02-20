@c
@c  COPYRIGHT (c) 1988-2008.
@c  On-Line Applications Research Corporation (OAR).
@c  All rights reserved.
@c
@c  $
@c

@chapter Network Commands

@section Introduction

The RTEMS shell has the following network commands:

@itemize @bullet


@item @code{netstats} - obtain network statistics

@item @code{ifconfig} - configure a network interface

@item @code{route} - show or manipulate the IP routing table

@end itemize

@section Commands

@c
@c
@c
@page
@subsection netstats - obtain network statistics

@pgindex netstats

@subheading SYNOPSYS:

netstats [-Aimfpcutv]

@subheading DESCRIPTION:

This command XXX

@subheading NOTES:

NONE

@subheading EXAMPLES:

The following is an example of how to use netstats:

@example
EXAMPLE_TBD
@end example

@subheading CONFIGURATION:

@findex CONFIGURE_SHELL_NO_COMMAND_NETSTATS
@findex CONFIGURE_SHELL_COMMAND_NETSTATS

In order to disable this command out if you are configuring all commands,
define @code{CONFIGURE_SHELL_NO_COMMAND_NETSTATS}.

In order to enable this command if you are building a custom command set
define @code{CONFIGURE_SHELL_COMMAND_NETSTATS}.


@subheading PROGRAMMING INFORMATION:

@findex rtems_shell_rtems_main_netstats

The @code{COMMAND} is implemented by a C language function
which has the following prototype:

@example
int rtems_shell_rtems_main_netstats(
  int    argc,
  char **argv
);
@end example

The configuration structure for the @code{COMMAND} has the
following prototype:

@example
extern rtems_shell_cmd_t rtems_shell_NETSTATS_Command;
@end example

@c
@c
@c
@page
@subsection ifconfig - configure a network interface

@pgindex ifconfig

@subheading SYNOPSYS:

ifconfig

@subheading DESCRIPTION:

This command XXX

@subheading NOTES:

NONE

@subheading EXAMPLES:

The following is an example of how to use ifconfig:

@example
EXAMPLE_TBD
@end example

@subheading CONFIGURATION:

@findex CONFIGURE_SHELL_NO_COMMAND_IFCONFIG
@findex CONFIGURE_SHELL_COMMAND_IFCONFIG

In order to disable this command out if you are configuring all commands,
define @code{CONFIGURE_SHELL_NO_COMMAND_IFCONFIG}.

In order to enable this command if you are building a custom command set
define @code{CONFIGURE_SHELL_COMMAND_IFCONFIG}.


@subheading PROGRAMMING INFORMATION:

@findex rtems_shell_rtems_main_ifconfig

The @code{COMMAND} is implemented by a C language function
which has the following prototype:

@example
int rtems_shell_rtems_main_ifconfig(
  int    argc,
  char **argv
);
@end example

The configuration structure for the @code{COMMAND} has the
following prototype:

@example
extern rtems_shell_cmd_t rtems_shell_IFCONFIG_Command;
@end example

@c
@c
@c
@page
@subsection route - show or manipulate the ip routing table

@pgindex route

@subheading SYNOPSYS:

route [subcommand]

@subheading DESCRIPTION:

This command XXX

@subheading NOTES:

NONE

@subheading EXAMPLES:

The following is an example of how to use route:

@example
EXAMPLE_TBD
@end example

@subheading CONFIGURATION:

@findex CONFIGURE_SHELL_NO_COMMAND_ROUTE
@findex CONFIGURE_SHELL_COMMAND_ROUTE

In order to disable this command out if you are configuring all commands,
define @code{CONFIGURE_SHELL_NO_COMMAND_ROUTE}.

In order to enable this command if you are building a custom command set
define @code{CONFIGURE_SHELL_COMMAND_ROUTE}.


@subheading PROGRAMMING INFORMATION:

@findex rtems_shell_rtems_main_route

The @code{COMMAND} is implemented by a C language function
which has the following prototype:

@example
int rtems_shell_rtems_main_route(
  int    argc,
  char **argv
);
@end example

The configuration structure for the @code{COMMAND} has the
following prototype:

@example
extern rtems_shell_cmd_t rtems_shell_ROUTE_Command;
@end example

