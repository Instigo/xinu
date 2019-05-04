#!/bin/sh

# Purpose: To remove the carriage return from the line as 
# *NIX uses only LF

#find . -type f | xargs -Ix sed -i.bak -r 's/\r//g' x

find . -type f -name '*.bak' | xargs -Ix rm x
