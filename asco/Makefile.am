## Process this file with automake to produce Makefile.in
# 
# Makefile.am
#
# Automake input file.
#
# Copyright (C) 2006 Stefan Jahn <stefan@lkcc.org>
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this package; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
# Boston, MA 02110-1301, USA.  
#

EXTRA_DIST = hooke.diff hooke.sh autogen.sh

SUBDIRS = tools doc examples

if DEBUG
ASCO_TEST = asco-test
else
ASCO_TEST =
endif

if MPI
ASCO_MPI = asco-mpi
else
ASCO_MPI =
endif

noinst_PROGRAMS = $(ASCO_TEST)

bin_PROGRAMS = asco asco-test $(ASCO_MPI)

asco_test_SOURCES = auxfunc.c auxfunc_alter.c auxfunc_monte.c \
	auxfunc_measurefromlis.c rfmodule.c initialize.c errfunc.c evaluate.c \
	asco-test.c

asco_SOURCES = auxfunc.c auxfunc_alter.c auxfunc_monte.c \
	auxfunc_measurefromlis.c rfmodule.c initialize.c errfunc.c evaluate.c \
	de36.c hooke.c nmlatest.c asco.c

asco_mpi_SOURCES = auxfunc.c auxfunc_alter.c auxfunc_monte.c \
	auxfunc_measurefromlis.c rfmodule.c initialize.c errfunc.c evaluate.c \
	de36.c hooke.c nmlatest.c asco.c

noinst_HEADERS = auxfunc_alter.h auxfunc_measurefromlis.h de.h initialize.h \
	version.h auxfunc.h auxfunc_monte.h errfunc.h rfmodule.h

asco_mpi_LINK = $(CC_MPI) $(DEFS) $(CFLAGS) $(INCLUDES) -DMPI $(LIBS) $(LDFLAGS) -o $@

CLEANFILES = *~ *.orig *.rej
MAINTAINERCLEANFILES = Makefile.in

AM_CFLAGS  = -DASCO
