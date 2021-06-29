#!bin/bash
echo "Do you want to display reference string and function result?"
echo "yes/no: "
read answer
if [[ "$answer" = "yes" ]]
then
./map_test 1
fi
if [[ "$answer" = "no" ]]
then
./map_test 0
fi
