NAME = map_test

srcPATH = ../TemplateAnalizer


SRCS =	main.cpp \
		StringAndDictParser.cpp \
		$(srcPATH)/Analizer.cpp

SANITIZE = -fsanitize=address
COMPILE = g++ -Wall -Werror -Wextra
CLEAR_LINE = \033[2K\c

all: dict message
	$(COMPILE) $(SRCS) -o $(NAME) $(SANITIZE)
	./map_test 0

dict:
	bash mapScript.sh

message:
	@echo "\033[37;1;45mкомпиляция\033[0m"

fclean: clean
	rm -f $(NAME)

.silent: message
