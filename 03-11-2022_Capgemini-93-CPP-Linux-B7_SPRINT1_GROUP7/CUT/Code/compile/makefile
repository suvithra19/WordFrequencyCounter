SRCDIR = src
INCLUDEDIR = include
OBJDIR = obj
BINDIR = bin
VALGRIND = tools/valgrind
FILE = "/home/cg93-user34/frequencyCounter/data/student.txt" "/home/cg93-user34/frequencyCounter/data/fruit.txt" 

INCLUDEFLAGS = -I${INCLUDEDIR}
CPPFLAGS = -ansi -c -g -std=c++11 -Wall -DDEBUG ${INCLUDEFLAGS}

main : InputFile.o common.o main.o
	g++ -o ${BINDIR}/main ${OBJDIR}/InputFile.o ${OBJDIR}/common.o ${OBJDIR}/main.o -lpthread

main.o : ${SRCDIR}/main.cpp
	g++ -o ${OBJDIR}/main.o ${CPPFLAGS} ${SRCDIR}/main.cpp

InputFile.o : ${SRCDIR}/InputFile.cpp
	g++ -o ${OBJDIR}/InputFile.o ${CPPFLAGS} ${SRCDIR}/InputFile.cpp

common.o : ${SRCDIR}/common.cpp
	g++ -o ${OBJDIR}/common.o ${CPPFLAGS} ${SRCDIR}/common.cpp

valgrind : main
	valgrind --leak-check=full --show-reachable=yes ${BINDIR}/main ${FILE}  2> ${VALGRIND}/valgrind.txt

clean :
	echo "cleaning up .o and exes"
	rm ${BINDIR}/main ${OBJDIR}/InputFile.o ${OBJDIR}/FrequencyCounter.o ${OBJDIR}/common.o
