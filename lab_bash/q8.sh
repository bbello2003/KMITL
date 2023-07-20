prog_name=$(echo $1 | cut -d'.' -f1) 
#printf "%s\n" $prog_name
gcc -o $prog_name $1 
if [ -f $prog_name ] 
then 
 ans=$(./$prog_name) 
else 
 ans=5
fi
printf "%s %s\n" $1 $ans
