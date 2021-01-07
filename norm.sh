#!/bin/sh

norminette *.c *.h > norm.txt; grep -i -B 1 'Error' norm.txt > vimalove
vim  $(cat vimalove | sed -n -e 's/^.*Norme: //p' |tr '\n' ' ')
rm -f vimalove
