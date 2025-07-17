#!/usr/bin/env bash
if [ -L $0 ]
then
__dirname=`dirname $(readlink $0)`
else
__dirname=`dirname $0`
fi
c=$__dirname/../C

emcc -o ./lzma.js \
    -s WASM=1 \
    -s INITIAL_MEMORY=16MB \
    -s MAXIMUM_MEMORY=1GB \
    -s STACK_SIZE=12MB \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s "EXPORTED_RUNTIME_METHODS=['ccall']" \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s ENVIRONMENT=node \
    -O3 \
    $c/LzmaLib.c lzma-wasm.c \
    $c/LzmaEnc.c $c/LzmaDec.c $c/Alloc.c $c/LzFind.c $c/LzFindMt.c $c/LzFindOpt.c $c/Threads.c