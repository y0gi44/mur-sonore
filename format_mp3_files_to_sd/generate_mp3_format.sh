#!/bin/bash

i=1

for fic in $(ls *.mp3)
do 
    cp "$fic" $(printf "%03d" $i)".mp3"
    echo $(printf "%03d" $i)" --> $fic" >> correspondances.txt
    i=$(( $i + 1 ))
    
done
