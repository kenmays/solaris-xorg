###############################################################################
#
# libXaw - Athena Widgets toolkit, based on libXt intrinsics
#
# Copyright (c) 2007, 2016, Oracle and/or its affiliates. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next
# paragraph) shall be included in all copies or substantial portions of the
# Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
#

# Package name used in tarballs
MODULE_NAME=libXaw

# Version number (used in path names)
MODULE_VERSION=1.0.13

# Checksums for upstream tarball
TARBALL_MD5   = e5e06eb14a608b58746bdd1c0bd7b8e3
TARBALL_SHA1  = 15f891fb88aae966b3064dcc1510790a0ebc75a0
TARBALL_SHA256= 8ef8067312571292ccc2bbe94c41109dcf022ea5a4ec71656a83d8cce9edb0cd

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES=

# Library name
LIBNAME=Xaw

# pkg(5) name we deliver the files in (override default)
MODULE_PKGNAME=x11/library/toolkit/libxaw7
MODULE_PKGNAME_SET=yes

# ARC cases that covered this module
# LSARC/2008/609 libXaw.so.7
MODULE_ARC_CASES = LSARC/2008/609

# Library man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES=man/*.man
MODULE_STABILITY=Uncommitted
MODULE_MTLEVEL=See XtToolkitThreadInitialize(3XT)
MODULE_MTLEVEL_SET=yes
LIB_MAN_SUFFIX=3xaw

# Link with version mapfile
# MODULE_LD_OPTIONS = -M $(PWD)/mapfile-vers

# pkg-config files that need to have -R added
FIX_PC_FILES=xaw7.pc.in

# Additional arguments to pass to configure
# We only ship libXaw.so.7, since we don't need to maintain binary
# compatibility with the libXaw.so.6 version we never shipped, and never
# started shipping the now-dropped-by-X.Org libXaw.so.8 (Xaw + Xprint)
MODULE_CONFIG_OPTS= --disable-xaw6

# Compatibility links from /usr/X11/lib to /usr/lib
MODULE_X11_LIBCOMPAT_LINKS = libXaw.so libXaw.so.7 libXaw7.so libXaw7.so.7

include ../Makefile.inc

# Additional man page to install
MAN3LIB_DIR = $(PROTODIR)$(MODULE_MAN_DIR)/man3lib
install: $(MAN3LIB_DIR)/libXaw.3lib

$(MAN3LIB_DIR)/libXaw.3lib: libXaw.3lib
	mkdir -p $(MAN3LIB_DIR)
	sed -e 's%__distroname__%$(DISTRO_NAME)%g' libXaw.3lib > $@
