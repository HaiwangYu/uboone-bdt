#!/bin/bash

if [ x$1 == x -o x$2 == x -o x$3 == x ]; then
echo "Usage: script arg1[begin index of files] arg2[end index of files] arg3[artROOT defname]"
exit 0
fi

source /cvmfs/uboone.opensciencegrid.org/products/setup_uboone.sh
setup sam_web_client

if [ -f $3_$1_$2.txt ]; then
echo "$3_$1_$2.txt existed!"
exit 0
fi

echo "read in"
i=1
for file in `samweb list-files "defname:$3"`
do
    if [ $i -ge $1 -a $i -le $2 ]; then
    echo "File $i"

    ### artROOT file dump (not output yet)
    echo -e "$file"    
    #samweb locate-file $file #print out file path

    filepath=`samweb locate-file $file`
    filepath0=${filepath#*:}
    tag=${filepath%%:*}
    filepath1=${filepath0%(*)}
    inputfile=$filepath1/$file

    ### artROOT output to txt file
    echo $inputfile >> $3_$1_$2.txt
    if [ "$tag" != "enstore" ]; then
        echo "Not on disk? $tag" >> $3_$1_$2.txt
    fi

    fi
    i=`expr $i + 1`

    if [ $i -gt $2 ]; then
    echo "Finished"
    exit 1
    fi
done

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
