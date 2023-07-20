for file in $(find . -type f -name "*.c")
do
        Name=$(echo "$file" | cut -d'/' -f2 | cut -d'.' -f1)
	if [ ! -f "./$Name" ]
	then 
		score="5"
	else
		output=$(./$Name)
        	if [ "$output" = "20" ]
        	then
                	score="10"
        	else
                	score="7"
		fi
        fi
        echo $(echo "$file" | cut -d'/' -f2)      $score
done
