#!/bin/sh
export LD_LIBRARY_PATH=/tmp
export LD_PRELOAD=/tmp/getuid.so
$@
