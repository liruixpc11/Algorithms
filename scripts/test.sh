#!/usr/bin/env bash

if [ -z "$1" ]; then
    echo "usage: $0 COMPONENT_NAME"
    exit 1
fi

cd `dirname "${BASH_SOURCE[0]}"`
cd ..

DATA_FILE=data/$1.txt
if [ -f ${DATA_FILE} ]; then
    bin/$1 <data/$1.txt
else
    bin/$1
fi