#!/bin/sh
find "$1" -name "*.cpp" -exec zip -j archive.zip {} \+