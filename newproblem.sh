#!/bin/bash

DIR=$1
SUF=$2
mkdir $DIR
echo "### 00" >> $DIR/inputs.txt
echo "### 00" >> $DIR/outputs.txt
touch $DIR/program.$SUF
