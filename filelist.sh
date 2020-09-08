#!/bin/bash

if [ x$1 == x ]; then
	echo "Usage: script arg1[output directory containing each individual job output dir]"
	exit 0
fi

if [ -f filelist.txt ]; then
        rm filelist.txt
fi

for dir in `ls $1`
do
	#if [[ $dir =~ $type ]]; then
	#	continue
	#fi 
	echo $dir
	#find $1/$dir -name "WCP_selection.root" | xargs | awk '{print $NF}' | tee -a filelist.txt	
	find $1/$dir -name "*_ext_*.root" | xargs | awk '{print $NF}' | tee -a filelist.txt
	#find $1/$dir -name "*_gen_*.root" | xargs | awk '{print $NF}' | tee -a filelist.txt
	#find $1/$dir -name "*_ext_bnb_*.root" | xargs | awk '{print $NF}' | tee -a filelist.txt
	#find $1/$dir -name "*_bnb_*.root" | xargs | awk '{print $NF}' | tee -a filelist.txt
	#find $1/$dir -name "*_simmxd_*.root" | xargs | awk '{print $NF}' | tee -a filelist.txt
done
