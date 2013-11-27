#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT(ASCO,0.4.8,asco-bugs@lists.sourceforge.net)
AC_CONFIG_SRCDIR([de36.c])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([no-define])
AM_MAINTAINER_MODE
AC_PREFIX_DEFAULT([/usr/local])
test "x$prefix" = xNONE && prefix="/usr/local"

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

dnl Check for debugging.
AC_ARG_ENABLE([debug],
  AC_HELP_STRING([--enable-debug],
                 [include debug output @<:@default=no@:>@]),
  [case "$enableval" in
   yes) enable_debug="yes" ;;
   no)  enable_debug="no"  ;;
   *)   enable_debug="no"  ;;
   esac],
  [enable_debug="no"])
if test $USE_MAINTAINER_MODE = yes; then
  enable_debug="yes"
fi
if test "$enable_debug" = yes; then
  AC_DEFINE(DEBUG, 1, [Define if debug output should be supported.])
else
  AC_DEFINE(NDEBUG, 1, [Define if debug code should be suppressed.])
  if test "x$GCC" = xyes; then
    CFLAGS="`echo $CFLAGS | sed -e 's/\-g //g'`"
    CXXFLAGS="`echo $CXXFLAGS | sed -e 's/\-g //g'`"
    LDFLAGS="$LDFLAGS -s"
  fi
fi
AM_CONDITIONAL(DEBUG, test x$enable_debug = xyes)
unset enable_debug

dnl Yet another compiler check.
if test "x$GCC" = xyes; then
  CXXFLAGS="$CXXFLAGS -fno-exceptions -fno-rtti -fno-check-new"
  if test $USE_MAINTAINER_MODE = yes; then
    CFLAGS="$CFLAGS -W -Wall -Wmissing-prototypes"
    CXXFLAGS="$CXXFLAGS -W -Wall"
  fi
fi

dnl Check for MP-ICC.
AC_PATH_PROG(CC_MPI, mpicc, :)
AM_CONDITIONAL(MPI, test "$CC_MPI" != ":")

dnl Checks for libraries.
AC_CHECK_LIB(m, sin)
AC_CHECK_LIB(wsock32, main)

dnl Add here all your Makefiles. These are created by configure.
AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 tools/Makefile
                 tools/postp/Makefile
                 tools/log/Makefile
                 tools/auxfunc/Makefile
                 tools/monte/Makefile
                 tools/alter/Makefile
                 examples/Makefile
                 examples/Eldo/Makefile
                 examples/Eldo/amp3/Makefile
                 examples/Eldo/amp3/extract/Makefile
                 examples/Eldo/bandpass/Makefile
                 examples/Eldo/bandpass/extract/Makefile
                 examples/Eldo/classE/Makefile
                 examples/Eldo/classE/extract/Makefile
                 examples/Eldo/inv/Makefile
                 examples/Eldo/inv/extract/Makefile
                 examples/HSPICE/Makefile
                 examples/HSPICE/amp3/Makefile
                 examples/HSPICE/amp3/extract/Makefile
                 examples/HSPICE/bandpass/Makefile
                 examples/HSPICE/bandpass/extract/Makefile
                 examples/HSPICE/classE/Makefile
                 examples/HSPICE/classE/extract/Makefile
                 examples/HSPICE/inv/Makefile
                 examples/HSPICE/inv/extract/Makefile
                 examples/LTspice/Makefile
                 examples/LTspice/amp3/Makefile
                 examples/LTspice/amp3/extract/Makefile
                 examples/LTspice/bandpass/Makefile
                 examples/LTspice/bandpass/extract/Makefile
                 examples/LTspice/classE/Makefile
                 examples/LTspice/classE/extract/Makefile
                 examples/LTspice/inv/Makefile
                 examples/LTspice/inv/extract/Makefile
                 examples/Qucs/Makefile
                 examples/Qucs/amplifier/Makefile
                 examples/Qucs/amplifier/extract/Makefile
                 examples/Qucs/bandpass/Makefile
                 examples/Qucs/bandpass/extract/Makefile
                 examples/Qucs/stability/Makefile
                 examples/Qucs/stability/extract/Makefile
                 examples/Spectre/Makefile
                 examples/Spectre/amp3/Makefile
                 examples/Spectre/amp3/extract/Makefile
                 examples/Spectre/bandpass/Makefile
                 examples/Spectre/bandpass/extract/Makefile
                 examples/Spectre/classE/Makefile
                 examples/Spectre/classE/extract/Makefile
                 examples/Spectre/inv/Makefile
                 examples/Spectre/inv/extract/Makefile
                 examples/rosen/Makefile
                 examples/rosen/bin/Makefile
                 examples/rosen/extract/Makefile])

AC_OUTPUT

dnl Print results.
AC_MSG_RESULT([])
AC_MSG_RESULT([ $PACKAGE version $VERSION configured successfully.])
AC_MSG_RESULT([])
