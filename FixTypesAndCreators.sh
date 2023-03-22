#!/bin/sh

#bash --version
#GNU bash, version 2.05b.0(1)-release (powerpc-apple-darwin8.0)
#Copyright (C) 2002 Free Software Foundation, Inc.

# compatible with bash 2.05b.0(1) which is used by Mac OS X 10.4.11
# also compatible with posix sh which dosn't support <<<
if ! echo ":$PATH:" | grep -Eq '.*:/Developer/Tools:.*'; then
	PATH="$PATH:/Developer/Tools"
fi

find XPostFacto \(  -name '*.cpp' -or -name '*.c' -or -name '*.h' -or -name '*.r' -or -name '*.xml' \) \
	-exec SetFile -t TEXT -c CWIE {} \;

find XPostFacto -name '*.mcp' \
	-exec SetFile -t MMPr -c CWIE {} \;

find XPostFacto -name '*.Lib' \
	-exec SetFile -t MPLF -c CWIE {} \;
