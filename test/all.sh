#!/bin/bash

FILES=maps/*
for f in $FILES
do
    echo "Processing $f..."
    ./fdf $f
done
