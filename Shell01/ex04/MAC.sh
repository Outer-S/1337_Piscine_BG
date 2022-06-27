#!/bin/sh
ifconfig | grep -w ether  | sed "s/ether//g;s/[[:space:]]//g"
