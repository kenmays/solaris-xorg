###############################################################################
#
# Xfont Makefile
#
# Copyright (c) 2006, 2017, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=libXfont

# Version number (used in path names)
MODULE_VERSION=1.5.4

# Checksums for upstream tarball
TARBALL_MD5   = 16eaf156edd79b68038b6a7c44aa9e9b
TARBALL_SHA1  = 9db050f63b9c4cb19e0dbb40575558ccb95719ca
TARBALL_SHA256= 1a7f7490774c87f2052d146d1e0e64518d32e6848184a18654e8d0bb57883242

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES  = ps-fonts.patch,-p1

# Library name
LIBNAME=Xfont

# Man pages to apply Sun footer to & attributes to list
#SUNTOUCHED_MANPAGES=man/*.man
MODULE_STABILITY=Project Private
LIB_MAN_SUFFIX=3xfont

# ARC cases that covered this module
# PSARC 2003/094 Bitmap Font File Compression Formats
MODULE_ARC_CASES = PSARC/2003/094

# Additional configure script options to select the modules we use
MODULE_CONFIG_OPTS= --enable-freetype --disable-type1 --disable-cid \
	--disable-speedo --enable-fontcache --enable-fc --enable-builtins \
	--with-bzip2

# pkg-config files that need to have -R added
FIX_PC_FILES=xfont.pc.in

# Install in private subdir
MODULE_ADD_LIB_SUBDIR=$(X11_SERVERLIBS_SUBDIR)

# Need to link with libfontenc in server private directory
MODULE_LDFLAGS= -L$(PROTODIR)$(X11_SERVERLIBS_DIR)$(ARCHLIBSUBDIR)

# Link with version mapfile
MODULE_LD_OPTIONS = -M $(PWD)/mapfile-vers

include ../Makefile.inc

