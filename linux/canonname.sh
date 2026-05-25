#!/bin/sh
find . \( -name "*.cp" -o -name "*.c++" -o -name "*.cc" -o -name "*.cxx" \) -exec sh -c 'mv "$0" "${0%.*}.cpp"' {} \;