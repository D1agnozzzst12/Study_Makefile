
# MyProject : main.o my_lib.o
# 	gcc main.o my_lib.o -o MyProject

# main.o : main.c
# 	gcc -c main.c -o main.o

# my_lib.o : my_lib.c
# 	gcc -c my_lib.c -o my_lib.o

# clean:
# 	rm MyProject *.o



# Улучшение 1
# TARGET = MyProject
# CC = gcc
# ${TARGET}: main.o my_lib.o
# 	${CC} main.o my_lib.o -o ${TARGET}

# main.o : main.c
# 	${CC} -c main.c -o main.o

# my_lib.o : my_lib.c
# 	${CC} -c my_lib.c -o my_lib.o

# clean:
# 	${TARGET} *.o



# Улучшение 2
# TARGET = MyProject
# CC = gcc

# SRC = ${wildcard *.c}
# OBJ = ${patsubst %.c, %.o, ${SRC}}

# ${TARGET} : ${OBJ}
# 	${CC} ${OBJ} -o ${TARGET}

# %.o : %.c 
# 	${CC} -c $< -o $@
# clean:
# 	rm ${TARGET} *.o


# Улучшение 3


TARGET = MyProject
CC = gcc

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC = ${wildcard ${PREF_SRC}*.c}
OBJ = ${patsubst ${PREF_SRC}%.c, ${PREF_OBJ}%.o, ${SRC}}

${TARGET} : ${OBJ}
	${CC} ${OBJ} -o ${TARGET}

${PREF_OBJ}%.o : ${PREF_SRC}%.c 
	${CC} -c $< -o $@
clean:
	rm ${TARGET} ${PREF_OBJ}*.o
