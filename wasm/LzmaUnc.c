/* LzmaLib.c -- LZMA library wrapper
2023-04-02 : Igor Pavlov : Public domain */

#include "..\C\Precomp.h"
#include "..\C\Alloc.h"
#include "..\C\LzmaDec.h"
#include "LzmaUnc.h"
#include <windows.h>
#include <stdio.h>
void * walloc(ISzAllocPtr p, size_t size){
    UNUSED_VAR(p)
    return GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, size);
}
void wfree(ISzAllocPtr p, void *ptr){
    UNUSED_VAR(p)
    GlobalFree(ptr);
}
const ISzAlloc w_Alloc = { walloc, wfree };
unsigned char props[LZMA_PROPS_SIZE] = {  93,   0,   0,   1,   0 };
size_t propsSize = LZMA_PROPS_SIZE;

Z7_STDAPI LzmaUncompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t *srcLen)
{
    ELzmaStatus status;
    return LzmaDecode(dest, destLen, src, srcLen, props, (unsigned)propsSize, LZMA_FINISH_ANY, &status, &w_Alloc);
}
void noop(ISzAlloc *p){
}
int __cdecl main() {
    noop(&g_Alloc);
    return 0;
}