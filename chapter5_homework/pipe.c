/**
 * @file closeout.c
 * @author wuyifff (1327490841@qq.com)
 * @brief ostep chapter5 qestion8
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

pid_t pid1,pid2;
void
sigchild(){
    printf("\nparent get sigint\n");
    kill(pid1, SIGINT);
    kill(pid2, SIGINT);
}

int main()
{
    int fd[2];
    char buf;
    if( (pipe(fd) < 0))
        fprintf(stderr, "pipe err");
    if( (pid1 = fork()) < 0){
        fprintf(stderr, "fork err");
    }
    else if(pid1 == 0){
        close(fd[1]);
        while (read(fd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);
        exit(0);
    }
    if( (pid2 = fork()) < 0){
        fprintf(stderr, "fork err");
    }
    else if(pid2 == 0){
        close(fd[0]);
        char c;
        while(read(STDIN_FILENO, &c, 1))
            write(fd[1], &c, 1);
        close(fd[1]);
        wait(NULL);
        exit(0);
    }
    signal(SIGINT, sigchild);
    pause();
    return 0;
}