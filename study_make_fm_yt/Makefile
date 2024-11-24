# # include what you use 


# # - Циклические зависимости между хедерами страшее чем между модулями
# #   поэтому минимизируйте включение в хедер

# # - В данном случае можно детектировать лишние хедера везде по проекту.

# # $ iwyu ./sourse/hash.c -I ./include

# # source/hash.c should add these lines:
# # #include <stdlib.h> //for calloc, free

# # source/hash.c should remove these lines:
# # - #include <malloc.h> // lines 13-13
# # - #include <math.h>   // lines 14-14







# # Декларативная модель

# # - Вы описываете зависимости, а не процесс.

# # FLAGS ?= -02

# # LCmain.o: LCmain.c
# #	 gcc ${FLAGS} -c LCmain.c -o LCmain.one

# # - Стрелочной "->" я обозначаю символ табуляции (обязательный).

# # - Переменная FLAGS может быть установлена извне или изнутри.

# # make FLAGS="-g -o0"

# # - Операция ?= означает "установить если не определена по правилам shell".

# # make FLAGS=







# # Общее правило

# # - Любое правило (рецепт) в make записывается единообразно.

# # <таргет>: [<реквизиты>]
# # ->  [команды shell]

# # - Таргет обычно означает файл и make следит за датой обновления файла.

# # - Рецепт пересобирается только если изменился хотя бы один реквизит либо
# # если реквизита вообще нет.

# # clean:
# # -> rm -rf *.x *.o *.log



# # Простейший makefile :


# FLAGS ?= -02
# TESTS = ./TESTS

# all: LCmain.o cache.o hash.o list.o0
# 	gcc ${FLAGS} -I ./include LCmain.o cache.o hash.o list.o -o LC.x

# LCmain.o: LCmain.c
# 	gcc ${FLAGS} -I ./include -c LCmain.c

# cache.o: ./source/cache.c
# 	gcc ${FLAGS} -I ./include -c ./source/cache.c -o cache.o

# clean:
# 	rm -rf *.x *.o *.log




# # @ - Заглушает вывод 

# # $$ - Экранирование $ - потому что один $ обозначает разименывание переменной







# # Заглушить вывод строчки 

# # - По умолчанию make показывает все строчки исполнения.

# # - Если нам надо заглушить вывод, мы указываем @ впереди.


# testrun: LC.x
# 	@for i in ${TESTS}/*.dat; do \
# 		echo "$$(basename $${i})"; \
# 		./LC.x < $${i}; \
# 		echo ""; \
# 	done > all.log
# 	@if diff -w all.log ${TESTS}/corr.log; then \
# 		echo "Tests pass"; else echo "Tests failed"; \
# 	fi 






# # Проблема простого примера 


# # - Компилятор прибит гвоздями

# LCmain.o: LCmain.c
# 	gcc ${FLAGS} -I ./include -c LCmain.c -o LCmain.o

# # Для компиляторов, линкеров и т.д. в make есть стандартные переменные.

# LCmain.o: LCmain.c
# 	${CC} ${CFLAGS} -c LCmain.c -o LCmain.o

# # Но прежде чем продолжать, давайте разберемся с переменными.


# # Стандартная переменная окружения CC - C Compiler


# # Для компиляции кода на C: CC, CFLAGS


# # Для компиляции кода на C ++: CXX, CPPFLAGS


# # Для этапа связывания: LDFLAGS

# # После компиляции кода: LD_LIBRARY_PATH







# # Ленивые переменные 


# $ cat lazyassgn.mak

# baz = Nobody
# bar = Hello ${baz}
# baz = World

# .PHONY: all
# all:
# 	@echo "bar = ${bar}"
	
# $ make -f lazyassgn.mak

# bar = Hello World


# # .PHONY таргеты это специальные таргеты, которые не соответствуют 
# # никаким результирующим файлам.


# # Таргеты вида all, install, clean, info, distclean, check рекомендуется 
# # всегда такими делать, чтобы случайный файл с таким именем в папке не помешал
# # сборке






# # Не надо бороться с ленивостью


# # - Пример плохого кода который заходит в большое количество подпапок.

# SUBDIRS = foo bar baz

# .PHONY: subdirs
# subdirs:
# 	for dir in ${SUBDIRS}; do \
# 		${MAKE} -C $$dir; \
# 	done

# # - Вы потеряли параллельность .

# # - Ошибки в рекурсивной сборке будут проигнорированы.
# # Можно вставить логику их обнаружения, но тогда она будет работать
# # при вызове make -k, когда мы как рах хотим проигнорировать ошибки. 


# # -С большое обозначает смени путь на ту папку которая аргумент а дальше вызови там make 






# # Ленивые списки


# # - Исправим ситуацию 

# SUBDIRS = sub1 sub2 sub3

# .PHONY: subdirs
# subdirs: ${SUBDIRS}

# .PHONY: ${SUBDIRS}
# ${SUBDIRS}: 
# 	@${MAKE} -C $@

# # - Обратите внимание на автоматическую переменную $@.



# # Список в make задается перечнем с использованием пробелов.
# # Список с одной стороны является как и все просто строчкой


# # Но список может быть раскрыт слева в рецепте, он становится несколькими
# # таргетами с тем же рецептом.



 





# #  Автоматические переменные 

# LCmain.o: LCmain.c 
# 	${CC} ${CFLAGS} -c LCmain.c - o LCmain.o

# LCmain.o: LCmain.c
# 	${CC} ${CFLAGS} -c $^ -o $@


# # $@ - имя таргета.
# # $^ - имена всех реквизитов.
# # $< - имя первого реквизита


# # Также возможно отдельно оперировать с частями имен относящимся к 
# # папкам и файлам : $(@D), $(@F) и т.д.




# # Ленивая бесконечность 


# bar = Hello ${baz}
# baz = World

# .PHONY: all
# all:
# 	@echo "bar = ${bar}"


# # - Неинициализированная ленивая переменная откладывается в разрешении.

# # - Но как вы думаете, а что если ошибочно написать: 

# bar = Hello ${bar}

# # - Получим ли мы бесконечный вывод ?









# # Энергичные присвоения 


# # - Можно зафорсить вычисления.

# bar := Hello ${baz}
# baz := World

# .PHONY: all
# all:
# 	@echo "bar := ${bar}"


# # - На экране просто Hello 

# # - Неинициализированная энергичная переменная это пустая строка.

# # - Но ни ленивые ни энергичные присваивания не сработают на внешнюю переменную.








# Override


# - Чтобы записать, дописать или переписать переменную, заданную снаружи,
# надо указать override

CFLAGS ?= -02

COMMONINC = -I./include 

override CFLAGS += ${COMMONINC}

# Теперь будет работать

# make CFLAGS="-g -00"	










# Промежуточные итоги

# - Используйте стандартные переменные для компиляторов, линкеров и т.д.

# - Используйте также стандартные переменные для флагов.

# - Помечайте PHONY те таргеты, которые не соответствуют файлам.

# - Старайтесь не бороться с ленивостью, а использовать ее.

# - Используйте override если вы предполагаете что переменная задается извне.

# - Не пишите сложные shell-скрипты внутри makefiles.

# - Используйте автоматические переменные.



# Новый подход, новые проблемы

CC ?= gcc
CFLAGS ?= -02
COMMONINC = -I./include 

override CFLAGS += ${COMMONINC}

LCmain.o: LCmain.c
	${CC} ${CFLAGS} -c $^ -o $@

cache.o : cache.c 
	${CC} {CFLAGS} -c $^ -o $@

list.o : list.c
	${CC} {CFLAGS} -c $^ -o $@  


# Много абсолютно однотипных строчек.

# CC в действительности не редефайнит умолчание .

# $ make -f makefile.v1.mak

# cc -02 -I./include
#	-c LCmain.c -o LCmain.o


# Тогда как вроде бы мы выставили явно gcc







# Проверка на default


# - Есть переменные (ARFLAGS, ASFLAGS, CFLAGS, ...) у которых default undefined/

# - Есть переменные (AR, AS, CC, ...) у которых есть default values.


ifeq (${origin CC}, default)
	CC = gcc
endif


# - Функция origin интересна тем что рассказывает откуда пришла переменная.
# Ее возможные значения : undefined, default, environment, file и прочие.


# - К слову мы еще не говорили о функциях.c











# Функции в make

# - Функция вызывается как ${function [<argument>]}.

cfiles = main1.c foo.c main2.c bar.c

mains = main1.c main2.c 
filtered = ${filter-out ${mains}, ${cfiles}}

# - Изо всех функции главной для нас является patsubst.
# Как аргументы она берет pattern , replacement, text

objs = ${patsubst %.c, %.o, ${cfiles}}

# - У нее есть второй вариант ${var:pattern=replacement}.

ofilt = ${filtered:%.c=%.o}













# Pattern rules

# Чтобы разобраться с однотипными рецептами, можно написать общий.

CSRC = LCmain.c source/cache.c source/hash.c source/list.c
COBJ = ${CSRC:%.c=%.o}


%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

LC.x : ${COBJ}
	${CC} $^ -o $@ ${LDFLAGS}


# - На самом деле такой рецепт не надо даже писать т.к. он уже есть.


# - Но в данном случае будет пробем: объектные файлы начнут возникать внутри папок







# Пишем свой pattern rules 


CSRC = LCmain.c source/cache.c source/hash.c source/list.c
COBJ = LCmain.o cache.o hash.o list.o

%.o : source/%.c
	${CC} ${CFLAGS} -c $^ -o $@


LC.x : ${COBJ}
	${CC} $^ -o $@ ${LDFLAGS}


# - Правило для LCmain взято как implicit

# Тут я хотел бы остановиться на одном неприятном моменте.









# Wildcards

# - Многие любят делать вот так.

CSRC = LCmain.c ${wildcards source/*.c}


# - Сами по себе wildcards ничем не плохи, но тут у меня есть концептуальное 
# возражение 


# - Мне не очень нравится система сборки, которая считает своими таргетами 
# весь мусор который она найдет в папке source.


# - Опыт показывает, что списки файлов лучше прибивать намертво простым
# перечислением.