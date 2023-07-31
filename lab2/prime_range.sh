echo "enter the lower limit of the range of the numbers to be printed"
read n1
echo "enter the upper limit of the range of the numbers to be printed"
read n2
echo "The prime number is the given range of $n1 - $n2 is:"
for ((i=n1; i<=n2; i++))
do
flag=1
for ((j=2; j<=$i/2; j++))
do
  if [[ $((i%j)) == 0 ]]
  then
    flag=0
    break
  fi  
done

if [[ $flag == 1 ]]
then
  echo "$i"
fi
done
/*
bash prime_range.sh
enter the lower limit of the range of the numbers to be printed
10
enter the upper limit of the range of the numbers to be printed
20
The prime number is the given range of 10 - 20 is:
11
13
17
19
*/
