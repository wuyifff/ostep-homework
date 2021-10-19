
src = $(wildcard *.c)

obj=$(patsubst %.c, %, $(src))

all : $(obj)
%:%.c
	gcc $< -o $@ -Wall

.PHONY:clean
clean:
	-rm  -f $(obj)

