###############################################################################
#
# xlsclients - utility to list clients connected to a given X server
#
# Copyright (c) 2008, 2013, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=xlsclients

# pkg(5) name we deliver the files in (override default)
MODULE_PKGNAME=x11/diagnostic/x11-info-clients
MODULE_PKGNAME_SET=yes


# Package metadata
MODULE_DESC = the xlsclients utility to list clients connected to a given X server

# Version number (used in path names)
MODULE_VERSION=1.1.3

# Checksums for upstream tarball
TARBALL_MD5   = 9fbf6b174a5138a61738a42e707ad8f5
TARBALL_SHA1  = a980aa006c0ca180e4c79be2bd6514205dd218a3
TARBALL_SHA256= 5d9666fcc6c3de210fc70d5a841a404955af709a616fde530fe4e8f7723e3d3d

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES = 

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES = man/xlsclients.man
MODULE_STABILITY=Committed

# Compatibility links from /usr/X11/bin to /usr/bin
MODULE_X11_BINCOMPAT_LINKS = xlsclients

include ../Makefile.inc
