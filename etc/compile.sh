#! /bin/bash

file_name=$1

echo "file_name: ${file_name}"
g++ ${file_name}.cpp -o ./build/${file_name} -std=c++11
echo "compile done"

./build/${file_name}

exit 0
