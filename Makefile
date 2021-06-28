NAME = map

srcPATH = ./src/
includePATH = ./include/

SRCS =	$(srcPATH)main.cpp \
		$(srcPATH)dictParser.cpp \
		$(srcPATH)mapObj.cpp \
		$(srcPATH)keyDetector.cpp \
		$(srcPATH)Analizer.cpp

INCLUDES =	$(srcPATH)mapObj.h \
			$(srcPATH)dictParser.h \
			$(srcPATH)keyDetector.h \
			$(srcPATH)Analizer.h \

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

