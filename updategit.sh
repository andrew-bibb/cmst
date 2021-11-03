#! /bin/bash
#
#
readonly name="cmst"

if [[ -z ${1} ]]; then
echo "Must supply a decription of the update with the command -- exiting"
exit 1
fi


# extract the manpage from the gzip file if it does not exist
if [[ ! -e ./misc/manpage/cmst.1 ]];  then
	gzip -d ./misc/manpage/cmst.1.gz
fi
if [[ -e ./misc/manpage/cmst.1.gz ]];  then
	rm ./misc/manpage/cmst.1.gz
fi

#
git add ./"${name}".pro
git add ./"${name}".pri
git add ./"${name}".qrc
git add ./'building_and_installing.txt'
git add ./README.md
git add ./apps/resource.h
git add --all ./apps/cmstapp/code
git add ./apps/cmstapp/cmstapp.pro
git add --all ./apps/rootapp/code
git add --all ./apps/rootapp/system
git add ./apps/rootapp/rootapp.pro
git add --all ./images
git add --all ./text
git add --all ./misc/desktop
git add --all ./misc/appdata
git add ./misc/manpage/cmst.1
git add --all ./translations
git add --all ./stylesheets
git add ./.gitattributes
#
git commit -m "${1}"

git remote rm origin
git remote add origin "https://github.com/andrew-bibb/${name}.git"

git push origin master 
#git push origin issue159
