#!/bin/sh
if [ "$1" = "build" ]; then
    mkdir -p Build && g++ "$2" -o Build/main
fi

if [ "$1" = "run" ]; then
    mkdir -p Build && g++ "$2" -o Build/main && ./Build/main
fi

if [ "$1" = "clean" ]; then
    rm -rf Build
fi