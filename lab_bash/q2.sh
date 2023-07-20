myvar ="Hi there"
#myx = "error because of spacebar"
echo $myvar
echo 1 "$myvar"
echo 2 '$myvar' #strong quote e.g. echo 'myvar contains "$myvar"'
echo 3 'myvar contains "'"$myvar"'"'
echo 4 \$myvar 
echo 5 "myvar contains \"$myvar\""
echo Enter some text
read myvar
echo '$myvar' value is $myvar
exit 0
