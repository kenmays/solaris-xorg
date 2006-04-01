/*
 * Copyright (c) 2005 ASPEED Technology Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of the authors not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  The authors makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * THE AUTHORS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
 
#include "xf86.h"
#include "xf86_ansic.h"
#include "xf86_OSproc.h"
#include "xf86Resources.h"
#include "xf86RAC.h"
#include "xf86cmap.h"
#include "compiler.h"
#include "mibstore.h"
#include "vgaHW.h"
#include "mipointer.h"
#include "micmap.h"

#include "fb.h"
#include "regionstr.h"
#include "xf86xv.h"
#include "Xv.h"
#include "vbe.h"

#include "xf86PciInfo.h"
#include "xf86Pci.h"

/* framebuffer offscreen manager */
#include "xf86fbman.h"

/* include xaa includes */
#include "xaa.h"
#include "xaarop.h"

/* H/W cursor support */
#include "xf86Cursor.h"

/* Driver specific headers */
#include "ast.h"

/* Prototype type declaration*/
Bool ASTMapMem(ScrnInfoPtr pScrn);
Bool ASTUnmapMem(ScrnInfoPtr pScrn);
Bool ASTMapMMIO(ScrnInfoPtr pScrn);
void ASTUnmapMMIO(ScrnInfoPtr pScrn);

Bool
ASTMapMem(ScrnInfoPtr pScrn)
{
   ASTRecPtr pAST = ASTPTR(pScrn);


   pAST->FBVirtualAddr = xf86MapPciMem(pScrn->scrnIndex, VIDMEM_FRAMEBUFFER,
				 pAST->PciTag,
				 pAST->FBPhysAddr, pAST->FbMapSize);
				 
   if (!pAST->FBVirtualAddr)
      return FALSE;

   return TRUE;
}

Bool
ASTUnmapMem(ScrnInfoPtr pScrn)
{
   ASTRecPtr pAST = ASTPTR(pScrn);
 
   xf86UnMapVidMem(pScrn->scrnIndex, (pointer) pAST->FBVirtualAddr,
		   pAST->FbMapSize);
		   
   pAST->FBVirtualAddr = 0;
   
   return TRUE;
}

Bool
ASTMapMMIO(ScrnInfoPtr pScrn)
{
   int mmioFlags;
   ASTRecPtr pAST = ASTPTR(pScrn);

#if !defined(__alpha__)
   mmioFlags = VIDMEM_MMIO | VIDMEM_READSIDEEFFECT;
#else
   mmioFlags = VIDMEM_MMIO | VIDMEM_READSIDEEFFECT | VIDMEM_SPARSE;
#endif

   pAST->MMIOVirtualAddr = xf86MapPciMem(pScrn->scrnIndex, mmioFlags,
				         pAST->PciTag,
				         pAST->MMIOPhysAddr, pAST->MMIOMapSize);
   if (!pAST->MMIOVirtualAddr)
      return FALSE;

   return TRUE;
}

void
ASTUnmapMMIO(ScrnInfoPtr pScrn)
{
   ASTRecPtr pAST = ASTPTR(pScrn);

   xf86UnMapVidMem(pScrn->scrnIndex, (pointer) pAST->MMIOVirtualAddr,
		   pAST->MMIOMapSize);
   pAST->MMIOVirtualAddr = 0;
   
}
 

