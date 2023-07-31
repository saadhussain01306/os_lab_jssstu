echo "enter the number of elements in the array"
read n
echo "enter the elements one by one"
for (( i=0;i<n;i++))
do
  read a[$i]
done

largest=${a[0]}
for (( i=1;i<n;i++))
do
   if [[ ${a[i]} -gt $largest ]]
   then
     largest=${a[i]}
   fi  
done

echo "the largest number in the array is $largest"


#bash great_array.sh
