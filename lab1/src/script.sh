#!/bin/bash
echo $(pwd)
dv=$(date '+%d/%m/%Y %H:%M:%S')
dt=$(date -d +10minutes +%Y%m%d%H%M.%S)
echo "$dv"
echo "$dt" 
printenv PATH