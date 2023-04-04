#!/bin/bash

# "2147483648"

for i in {-10..50}; do
    output1=$(./sastantua $i)
    output2=$(./sastantua_linux $i)

    if [ "$output1" == "$output2" ]; then
        echo -n -e "\r OK! $i "
    else
    {
		echo -e "\r KO! $i "
		break
	}
    fi
done