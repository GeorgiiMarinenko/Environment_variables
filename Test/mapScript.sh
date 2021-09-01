#!bin/bash

echo -en "\033[37;1;42mсоздание файла с переменными окружения\033[0m\n"
env > dict1.txt
echo key=5 >> dict1.txt
