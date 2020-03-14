#!/bin/bash

DIR=$1
PROGRAM='program.py'
INPUTS='inputs.txt'
OUTPUTS='outputs.txt'

mkdir $DIR/input
mkdir $DIR/output

awk 'BEGIN{c=0}NR!=1{if($1 ~ /^#+/){c++}else{file="'$DIR'/input/"c".txt"; print $0 > file}}' $DIR/$INPUTS
awk 'BEGIN{c=0}NR!=1{if($1 ~ /^#+/){c++}else{file="'$DIR'/output/"c".txt"; print $0 > file}}' $DIR/$OUTPUTS

input_files=( $(ls $DIR/input/) )
output_files=( $(ls $DIR/output/) )

num=$((${#input_files[@]}-1))

if [ -f $DIR/tmp.txt ]; then
  rm $DIR/tmp.txt
fi

for i in $(seq 0 $num);
do
    echo "--- test case $i ---"
    case $2 in
    "py")
        cat $DIR/input/${input_files[i]} | python -m memory_profiler $DIR/$PROGRAM > $DIR/tmp.txt
        ;;
    "cpp")
        PROGRAM='program.cpp'
        clang++ -std=c++11 $DIR/$PROGRAM -o $DIR/out
        cat $DIR/input/${input_files[i]} | $DIR/out > $DIR/tmp.txt 2>&1
        ;;
    *)
        cat $DIR/input/${input_files[i]} | python -m memory_profiler $DIR/$PROGRAM >> $DIR/tmp.txt
        ;;
    esac
    output="$DIR/output/${output_files[i]}"
    line_num=`awk 'END{print NR}' $output`
    line_num=$(($line_num + 1))
    head -n $line_num $DIR/tmp.txt | diff $output -
done

# rm $DIR/tmp.txt
rm -R $DIR/input/
rm -R $DIR/output/

