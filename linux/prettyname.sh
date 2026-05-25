#!/bin/sh
grep "PRETTY_NAME=" /etc/os-release 2>/dev/null | cut -d '=' -f2 | tr -d '"'