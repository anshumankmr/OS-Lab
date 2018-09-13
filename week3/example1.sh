echo "menu test"
stop=0
while [ $stop -eq 0 ]
do
echo"1: print the date 2,3: print the cwd 4: exit"
echo
echo "Your Choice?"
read reply
echo 
case $reply in 
 "1")
     date
     ;;
 "2"|"3")
         pwd
         ;;
 "4")
     stop=1
     ;;
 *)echo "illegal"
   ;;
esac
stop=1
done
