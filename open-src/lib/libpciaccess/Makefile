###############################################################################
#
# libpciaccess - generic PCI access software library & scanpci utility
#
# Copyright (c) 2008, 2016, Oracle and/or its affiliates. All rights reserved.
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

# Package name used in tarballs
MODULE_NAME=libpciaccess

# Version number (used in path names)
MODULE_VERSION=0.13.4

# Checksums for upstream tarball
TARBALL_MD5   = ace78aec799b1cf6dfaea55d3879ed9f
TARBALL_SHA1  = 99e791fe20924b9da29bf7c7ed9438739c4f2930
TARBALL_SHA256= 07f864654561e4ac8629a0ef9c8f07fbc1f8592d1b6c418431593e9ba2cf2fcf

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES = scanpci.man.patch,-p1 \
		21510615.patch \
		21850880.patch \
		21509973.patch

# Library name
LIBNAME=libpciaccess

# Package metadata
MODULE_DESC = the libpciaccess library and scanpci utility
# pkg(5) name we deliver the files in (override default)
MODULE_PKGNAME=diagnostic/scanpci
MODULE_PKGNAME_SET=yes
# Package classification (override default)
MODULE_PKGCLASS=System/Hardware
MODULE_PKGCLASS_SET=yes

# ARC cases that covered this module
# PSARC/2008/638  libpciaccess & scanpci 
MODULE_ARC_CASES = PSARC/2008/638

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES=man/scanpci.man
MODULE_STABILITY=Volatile
LIB_MAN_SUFFIX=3pciaccess

# Update scanpci.man with program man page flags instead of library ones
SUNTOUCH_MAN_FLAGS  = $(COMMON_SUNTOUCH_MAN_FLAGS)
SUNTOUCH_MAN_FLAGS +=-p $(MODULE_BIN_DIR)/
SUNTOUCH_MAN_FLAGS_SET=yes

# pkg-config files that need to have -R added
FIX_PC_FILES=pciaccess.pc.in

# Activate additional debugging code in debug builds
MODULE_DEBUG_FLAGS=-DDEBUG

# Override linker flags for scanpci program
PCIACCESS_PROG_LDFLAGS = $(MAPFILES_FOR_PROGS) ../src/libpciaccess.so.0
PROGRAM_VARS = scanpci
PROGRAM_MAKEFLAGS = $(PROGRAM_VARS:%=%_LDADD="$(PCIACCESS_PROG_LDFLAGS)")
MODULE_BUILD_MAKEFLAGS = AM_MAKEFLAGS='$(PROGRAM_MAKEFLAGS)'

# Additional targets for scanpci
MODULE_ADD_INSTALL_TARGETS_64 = install_scanpci
MODULE_ADD_INSTALL_TARGETS = $(MODULE_ADD_INSTALL_TARGETS_$(BUILD_TYPE))

# Compatibility links from /usr/X11/bin to /usr/bin
MODULE_X11_BINCOMPAT_LINKS = scanpci

include ../Makefile.inc

# We want to install scanpci, even though the upstream Makefile doesn't
install_scanpci: default_install
	mkdir -p $(PROTODIR)$(MODULE_BIN_DIR) \
		 $(PROTODIR)/etc/security/exec_attr.d/ \
		 $(PROTODIR)$(MODULE_MAN_DIR)/man1
	$(INSTALL_SCRIPT) -m 755 $(BUILD_DIR)/scanpci/scanpci \
		$(PROTODIR)$(MODULE_BIN_DIR)/scanpci
	$(INSTALL_SCRIPT) -m 444 $(BUILD_DIR)/man/scanpci.1 \
		$(PROTODIR)$(MODULE_MAN_DIR)/man1/scanpci.1
	$(INSTALL_SCRIPT) -m 444 exec_attr \
		$(PROTODIR)/etc/security/exec_attr.d/scanpci
