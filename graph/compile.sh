#! /bin/bash

file_name=$1

echo "file_name: ${file_name}"
g++ -std=c++11  ${file_name}.cpp -o ./build/${file_name}
echo "compile done"

./build/${file_name}

exit 0
