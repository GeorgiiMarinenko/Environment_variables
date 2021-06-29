NAME = map_test

srcPATH = ../TemplateAnalizer


SRCS =	main.cpp \
		StringAndDictParser.cpp \
		$(srcPATH)/Analizer.cpp

CFLAGS = -static

COMPILE = g++
CLEAR_LINE = \033[2K\c

all: dict message
	$(COMPILE) $(SRCS) -o $(NAME)
	@bash info.sh

dict:
	bash mapScript.sh

message:
	echo "\033[37;1;45mкомпиляция\033[0m"

fclean: clean
	rm -f $(NAME)

.silent: message
