#!/bin/sh
find . -name "*.sh" -type f | sed "s/^.*[//]//;s/\.sh$//"
