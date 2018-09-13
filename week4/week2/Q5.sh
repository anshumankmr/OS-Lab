cat $1>>$2
sort -g -u $2
sort -g -u $2>>sorted_life.txt
