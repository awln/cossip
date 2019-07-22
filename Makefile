CC=g++ -g3 -Wall

# List of source files for your thread library
COSSIP_SOURCES= cp_server.cpp

# Generate the names of the thread library's object files
COSSIP_OBJS=${COSSIP_SOURCES:.cpp=.o}

TEST_SOURCES= $(wildcard test/test*.cpp)
TEST_EXECS= $(basename $(TEST_SOURCES))

# Collect test filename
TEST_SOURCES= test/test*.cpp

# Generate 
all: libcossip.o 
# all: app

# Compile the thread library and tag this compilation
libcossip.o: ${COSSIP_OBJS}
	ld -r -o $@ ${COSSIP_OBJS}

# Compile an application program
app: app.cpp libthread.o
	${CC} -o $@ $^ -ldl -pthread

test%: $@ libcossip.o
	${CC} -o $(basename $@) $@ $^ -ldl

# Generic rules for compiling a source file to an object file
%.o: %.cpp
	${CC} -c $<
%.o: %.cc
	${CC} -c $<

clean:
	rm -f ${THREAD_OBJS} libcossip.o app
temp:
	@echo ${TEST_SOURCES}
	@echo ${basename ${TEST_SOURCES}} 
