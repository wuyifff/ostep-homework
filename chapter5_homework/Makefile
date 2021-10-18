
all: fork1.exe fork2.exe fork4.exe wait.exe waitpid.exe
%.exe:%.c
	gcc $< -o $*.exe -Wall

clean:
	rm -f *.exe
