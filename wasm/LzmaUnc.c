/* LzmaLib.c -- LZMA library wrapper
2023-04-02 : Igor Pavlov : Public domain */

#include "Precomp.h"
#include "Alloc.h"
#include "LzmaDec.h"
#include "LzmaLib.h"
unsigned char props[LZMA_PROPS_SIZE] = {  93,   0,   0,   1,   0 };
size_t propsSize = LZMA_PROPS_SIZE;

Z7_STDAPI LzmaUncompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t *srcLen
)
{
  ELzmaStatus status;
  return LzmaDecode(dest, destLen, src, srcLen, props, (unsigned)propsSize, LZMA_FINISH_ANY, &status, &g_Alloc);
}
