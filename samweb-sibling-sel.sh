#!/bin/bash

filename=$1
WCP_celltree_dataset=$2
n=1
while read line; do
    input_artROOT=`basename $line`
    WCP_parent_file=`samweb get-metadata $input_artROOT | grep 'Parents:' | awk '{print $2}'`
    input_celltree=`samweb list-files "defname:$WCP_celltree_dataset and ischildof:(file_name $WCP_parent_file)" | xargs | awk '{print $NF}'`
    #echo "$n : $input_artROOT $WCP_parent_file $input_celltree"
    if [[ $input_celltree == "nusel"* ]]; then
        echo $line
    fi
    n=$((n+1))
done < $filename
