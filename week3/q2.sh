x=0
y=$(expr $1 \* 2 )
while [ $x -le $y ]
do  
	if [ `expr $x % 2` -eq 1 ]
	then 
		echo $x 
	fi
	x=$(expr "$x" + "1")
done 
