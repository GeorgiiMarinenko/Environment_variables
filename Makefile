NAME = map

srcPATH = ./src/
includePATH = ./include/

SRCS =	$(srcPATH)main.cpp \
		$(srcPATH)dictParser.cpp \
		$(srcPATH)mapObj.cpp \
		$(srcPATH)keyDetector.cpp \

INCLUDES =	$(includePATH)mapObj.h \
			$(includePATH)dictParser.h \
			$(includePATH)keyDetector.h \

CFLAGS = -static

COMPILE = g++

all:
	$(COMPILE) $(SRCS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

