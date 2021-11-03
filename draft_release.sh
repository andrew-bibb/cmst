#! /bin/bash
#
#
readonly name="cmst"

if [[ -z ${1} ]]; then
echo "Must supply a release name (ex: 2020.03.07) -- exiting"
exit 1
fi


tag=$name-${1}

git archive -v -9 --worktree-attributes --format=tar.xz --prefix=${tag}/ master  --output=..//${tag}.tar.xz
