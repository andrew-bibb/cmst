#! /bin/bash
#
#
readonly name="cmst"


git remote rm origin
git remote add origin "https://github.com/andrew-bibb/${name}.git"
git fetch
git rebase origin/master

