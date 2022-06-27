#!/bin/sh
cat /etc/passwd | grep -v \# | sed 's/:.*//g' | sed -n 'n;p' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | sed "s/$/, /g" | tr -d "\n" | sed "s/,[[:space:]]$/./" | tr -d "\n"
