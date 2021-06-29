NAME = map

srcPATH = ./src/
includePATH = ./include/

SRCS =	main.cpp \
		Analizer.cpp

INCLUDES =	mapObj.h \
			Analizer.h \

CFLAGS = -static

COMPILE = g++

all: message
	$(COMPILE) $(SRCS) -o $(NAME)

dict:
	bash mapScript.sh

message:
	echo "\033[37;1;45mкомпиляция\033[0m"

fclean: clean
	rm -f $(NAME)

.phony: message
