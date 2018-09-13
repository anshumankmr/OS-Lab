determinant=`expr $2 \* $2 - 4 \* $1 \* $3`
#echo $determinant
twoa=`expr $1 \* 2`
case $determinant in 
    "0")
        echo "Roots are real and equal"
        calc=$(echo "sqrt ( $determinant )" | bc -l)
        #echo $calc
        calc=`expr 0 - $2 + $calc`
        #echo $calc
        root=$( expr "$calc" / "$twoa" )
        echo Root is $root
        ;;
    *)
      if [ $determinant -lt 0 ]
      then
          echo "No Real Roots Exist"
      else
      	echo "Roots are real and unequal"
      	calc=$(echo "sqrt ( $determinant )" | bc -l)
      	#echo $calc
      	calc1=` expr 0 - $2 + $calc `
      	calc2=` expr 0 - $2 - $calc `
      	root1=$(expr "$calc1" / "$twoa")
      	root2=$(expr "$calc2" / "$twoa")
      	echo Roots are $root1 and $root2
      fi
    ;;
esac