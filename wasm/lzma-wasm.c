#include "../C/LzmaLib.h"
#include <emscripten.h>
unsigned char props[LZMA_PROPS_SIZE] = {  93,   0,   0,   1,   0 };
size_t propsSize = LZMA_PROPS_SIZE;

EMSCRIPTEN_KEEPALIVE
int compress(unsigned char *dest, size_t destLen, unsigned char *src, size_t srcLen) {
    unsigned long outLen = destLen;
    int res = LzmaCompress(dest, &outLen, src, srcLen, 
        props, &propsSize,
        5/*level*/, 1<<16/*dictSize*/,
        3/*lc*/, 0/*lp*/, 2/*pb*/,
        32/*fb*/, 1/*numThreads*/);
    if (res != SZ_OK) {
        return res<=0?res:-res;
    }
    return (int)outLen;
}

EMSCRIPTEN_KEEPALIVE
int decompress(unsigned char *dest, size_t destLen, unsigned char *src, size_t srcLen) {
    unsigned long outLen = destLen;
    int res = LzmaUncompress(dest, &outLen, src, &srcLen, props, LZMA_PROPS_SIZE);
    if (res != SZ_OK) {
        return res<=0?res:-res;
    }
    return (int)outLen;
}