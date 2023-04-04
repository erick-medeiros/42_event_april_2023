#!/bin/bash

echo -n > result.txt
file="input.txt"
while read -r line; do
echo -e "$line" | perl palindrome.pl | grep "The" >> result.txt
done <$file

echo diff:
diff expected.txt result.txt