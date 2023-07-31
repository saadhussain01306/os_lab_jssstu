#!/bin/bash

echo "Enter a number:"
read num

length=${#num};

for((i=length-1; i>=0; i--))
do
    reverse=$reverse${num:i:1}
done

if [ $reverse == $num ]  #or [[ "$reverse" == "$num" ]] 
then 
    echo "The number $num is a palindrome"
else 
    echo "The number $num is not a palindrome"
fi
