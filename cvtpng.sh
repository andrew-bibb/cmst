#! /bin/bash

# argument 1 directory to process (required)
if [[ -z ${1} ]]; then
	echo "Must supply a directory to operate on -- exiting"
	exit 1
fi

# process each file
for file in $(ls ${1}/*.png); do
	echo "converting " "${file}"
	filename="${file##*/}"
  filenameNoExt="${filename%.*}"
  path="${file%${filename}}"
	convert -background black -alpha background "${file}" "${path}${filenameNoExt}.png"	
done


exit 0	
