#!bin/sh
echo "Enter the number of rows"
read n

odd=9
even=0

for (( i = 0; i < $n; i++ ))
do
    for (( j = 0; j <= $i; j++))
    do  
        echo -n " "
    done
    k=$(((2\*(n - i)) - 1))
    for (( j = 0; j < $k; j++))
    do
        if [ `expr $i % 2` -eq 0 ]
        then
            echo -n even
        else
            echo -n odd
        fi
    done
    if [ `expr $i % 2` -eq 0 ]
    then
        even=`expr $even - 1`
    else
        odd=`expr $odd - 1`
    fi
done