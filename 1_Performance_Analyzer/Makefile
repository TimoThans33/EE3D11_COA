CC=g++
OBJS = main.cpp computer.cpp program.cpp

.PHONY: clean default
default:
	echo "Usage to compile performance analyzer : make app"

app: ${OBJ}
	${CC} ${OBJS} -o $@

clean:
	-rm app
	