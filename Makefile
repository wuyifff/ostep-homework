all: fork1.o
%.o:%.c
	gcc $< -o $*.exe -Wall

clean:
	rm -f *.exe
