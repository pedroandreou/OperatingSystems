#!/bin/bash
echo "Would you please tell me your name and age? :)"
read string
IFS=' ' read -r -a array <<< "$string"
i=-1
	for element in "${array[@]}"
	do
		((i++))
	done

	
if  [[ "${array[i]}" < 20 ]] && [[ $(("${array[i]}")) == "${array[i]}" ]];  then

		echo "you are still young! Enjoy life!"
	fi
exit 0
