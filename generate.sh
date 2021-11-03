#!/bin/bash
#
#	Script to enerate differnet size icons.
#	dmenu
#
#
for i in 16 20 22 24 32 36 40 48 64 72 96 128 192 256 384 512; do 
		mkdir -p "./${i}x${i}"
		convert ./cmst-icon.svg -transparent white -filter box -resize ${i}x${i} -unsharp 0x6+0.5+0 -background "rgba(0,0,0,0)"  -flatten "./${i}x${i}/cmst.png" 		
		 		
done
  
