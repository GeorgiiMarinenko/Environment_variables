NAME = map_test

srcPATH = ../TemplateAnalizer


SRCS =	main.cpp \
		StringAndDictParser.cpp \
		$(srcPATH)/Analizer.cpp

CFLAGS = -static

COMPILE = g++

all: dict message
	$(COMPILE) $(SRCS) -o $(NAME)

dict:
	bash mapScript.sh

message:
	echo "\033[37;1;45mкомпиляция\033[0m"

fclean: clean
	rm -f $(NAME)

.silent: message
