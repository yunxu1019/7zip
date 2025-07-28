/* LzmaLib.h -- LZMA library interface
2023-04-02 : Igor Pavlov : Public domain */

#ifndef ZIP7_INC_LZMA_LIB_H
#define ZIP7_INC_LZMA_LIB_H

#include "7zTypes.h"

EXTERN_C_BEGIN

#define Z7_STDAPI int Z7_STDCALL

#define LZMA_PROPS_SIZE 5
Z7_STDAPI LzmaUncompress(unsigned char *dest, size_t *destLen, const unsigned char *src, SizeT *srcLen);

EXTERN_C_END

#endif
