#!/bin/bash
### This script is to dump dataset1 (artROOT) files with the absolute path into a txt file.
### Meanwhile, dump dataset2 (celltree) file which has one-to-one correspondance 
### with dataset1 file into another txt file.
### To make WCP executables work easily, the total number of events for celltree 
### file is recommended to output as well.

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

