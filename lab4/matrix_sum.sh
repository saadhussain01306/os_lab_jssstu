#!/bin/bash
#program to read and sum the two matrices
declare -A a
declare -A b
declare -A s
echo "Enter the row and columns of the first matrix:"
read r1 c1
echo "enter the elements one by one"
for ((i=0;i<$r1;i++))
do
for ((j=0;j<$c1;j++))
do
read a[$i,$j]
done
done

echo "Enter the row and columns of the second matrix:"
read r2 c2
echo "enter the elements one by one"
for ((i=0;i<$r2;i++))
do
for ((j=0;j<$c2;j++))
do
read b[$i,$j]
done
done

echo "The first matrix is:"
for  ((i=0;i<$r1;i++))
do
for ((j=0;j<$c1;j++))
do
echo -ne "${a[$i,$j]}" "\t"
done
echo -e "\n"
done

echo "The second matrix is:"
for  ((i=0;i<$r1;i++))
do
for ((j=0;j<$c1;j++))
do
echo -ne "${b[$i,$j]}" "\t"
done
echo -e "\n"
done


if [[ $r1 -ne $r2 ]] || [[ $c1 -ne $c2 ]]
then
echo "The matrix cannot be added because the row/column number is not same"
exit  1
fi

echo "The sum of the two given matrix is:"
for ((i=0;i<$r1;i++))
do
for ((j=0;j<$c1;j++))
do
s[$i,$j]=$((${a[$i,$j]}+${b[$i,$j]}))
echo -ne "${s[$i,$j]}" "\t"
done
echo -e "\n"
done



#bash matrix_sum.sh
Enter the row and columns of the first matrix:
2 2
enter the elements one by one
1 
2
3 
4
Enter the row and columns of the second matrix:
2 2
enter the elements one by one
1
2
3
4
The first matrix is:
1 	2 	

3 	4 	

The second matrix is:
1 	2 	

3 	4 	

The sum of the two given matrix is:
2 	4 	

6 	8 	
#
