TARGET = Game_guess_the_number
CC = gcc

PREF_OBJ = ./obj/
PREF_SRC = ./src/


SRC = ${wildcard ${PREF_SRC}*.c}
OBJ = ${patsubst ${PREF_SRC}%.c, ${PREF_OBJ}%.o, ${SRC}}




${TARGET} : ${OBJ}
	${CC} ${OBJ} -o ${TARGET}

${PREF_OBJ}%.o : ${PREF_SRC}%.c
	${CC} -c $< -o $@

clean: 
	rm ${TARGET} ${PREF_OBJ}*.o