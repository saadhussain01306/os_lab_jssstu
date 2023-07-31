#SHELL SCRPIT FOR GREATEST OF THREE NUMBERS

#!/bin/bash

echo "Enter the three numbers"
echo "enter the 1st number"
read n1
echo "enter the 2nd number"
read n2
echo "enter the 3rd number"
read n3

if [[ n1 -gt n2 ]] && [[ n1 -gt n3 ]]
 then
    echo "The greatest of the three numbers is $n1"
fi

if [[ n2 -gt n1 ]] && [[ n2 -gt n3 ]]
 then
    echo "The greatest of the three numbers is $n2"
fi

if [[ n3 -gt n1 ]] && [[ n3 -gt n2 ]]
 then
    echo "The greatest of the three numbers is $n3"
fi

if [[ n1 -eq n2 ]] && [[ n2 -eq n3 ]]
 then
    echo "All three numbers are same"
fi

#output
# gedit great_three.sh
# bash great_three.sh
# Enter the three numbers
# enter the 1st number
#34
#enter the 2nd number
#21
#enter the 3rd number
#67
#The greatest of the three numbers is 67
