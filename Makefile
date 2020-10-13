# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = RogueLike.o XMLHanlder.o
CC = g++ -std=c++11 
INCLUDE = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/include/
LIBS = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/lib/ 
CFLAGS = -Wall -g
EXECUTABLE = RogueLike
COMMANDLINE = ../xmlfiles/badScroll.xml
OUT=RogueLike

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) $(COMMANDLINE)

cleanmake : clean $(EXECUTABLE)

.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) -I $(INCLUDE) -L $(LIBS) -lxerces-c

%.o : %.c 
	$(CC) $(CFLAGS) -I $(INCLUDE) -L $(LIBS) -c $@  -lxerces-c

clean :
	rm $(EXECUTABLE) ${OBJS} 
