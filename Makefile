NAME = map

srcPATH = ./src/
includePATH = ./include/

SRCS =	$(srcPATH)main.cpp \
		$(srcPATH)dictParser.cpp \
		$(srcPATH)mapObj.cpp \
		$(srcPATH)keyDetector.cpp \
		$(srcPATH)Analizer.cpp

INCLUDES =	$(includePATH)mapObj.h \
			$(includePATH)dictParser.h \
			$(includePATH)keyDetector.h \
			$(includePATH)Analizer.h \

CFLAGS = -static

COMPILE = g++

all:
	bash mapScript.sh
	$(COMPILE) $(SRCS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

