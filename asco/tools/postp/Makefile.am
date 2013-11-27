## Process this file with automake to produce Makefile.in
# 
# tools/postp/Makefile.am
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

bin_PROGRAMS = postp

INCLUDES = -I$(srcdir)/../auxfunc

noinst_HEADERS = auxfunc_measurefromlis.h auxfunc_updatelis.h

postp_SOURCES = auxfunc_measurefromlis.c auxfunc_updatelis.c postp.c \
	../auxfunc/auxfunc.c

CLEANFILES = *~ *.orig *.rej
MAINTAINERCLEANFILES = Makefile.in
