#!/bin/sh
id -G -n $FT_USER | sed 's/[[:space:]]/,/g' | tr -d '\n'
