/**
 * @file fork3.c
 * @author wuyifff (1327490841@qq.com)
 * @brief ostep chapter5 qestion4
 * @version 0.1
 * @date 2021-10-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{

    pid_t pid;
    char *agv[] = {"ls","/home",NULL};
    if( (pid =fork()) < 0){
        fprintf( stderr, "fork1 error!");
    }
    else if( pid == 0 ){
        fprintf(stdout,"child1 execl:\n");
        fflush(stdout);
        if((execl( "/bin/ls", "ls", "/home", NULL)) < 0)
            fprintf(stderr, "execl error\n");
        exit(0);
    }
    if( (pid =fork()) < 0){
        fprintf( stderr, "fork2 error!");
    }
    else if( pid == 0 ){
        sleep(1);
        fprintf(stdout,"child2 execle:\n");
        fflush(stdout);
        if((execle( "/bin/ls", "ls", "/home", NULL)) < 0)
            fprintf(stderr, "execle error\n");
        exit(0);
    }
    if( (pid =fork()) < 0){
        fprintf( stderr, "fork3 error!");
    }
    else if( pid == 0 ){
        sleep(2);
        fprintf(stdout,"child3 execlp:\n");
        fflush(stdout);
        if((execlp( "/bin/ls", "ls", "/home", NULL)) < 0)
            fprintf(stderr, "execlp error\n");
        exit(0);
    }
    if( (pid =fork()) < 0){
        fprintf( stderr, "fork4 error!");
    }
    else if( pid == 0 ){
        sleep(3);
        fprintf(stdout,"child4 execv:\n");
        fflush(stdout);
        if((execv( "/bin/ls", agv)) < 0)
            fprintf(stderr, "execv error\n");
        exit(0);
    }
    if( (pid =fork()) < 0){
        fprintf( stderr, "fork5 error!");
    }
    else if( pid == 0 ){
        sleep(4);
        fprintf(stdout,"child5 execvp:\n");
        fflush(stdout);
        if((execvp( "/bin/ls", agv)) < 0)
            fprintf(stderr, "execvp error\n");
        exit(0);
    }
    if( (pid =fork()) < 0){
        fprintf( stderr, "fork4 error!");
    }
    else if( pid == 0 ){
        sleep(5);
        fprintf(stdout,"child6 execvpe:\n");
        fflush(stdout);
        if((execvpe( "/bin/ls", agv, NULL)) < 0)
            fprintf(stderr, "execvpe error\n");
        exit(0);
    }
    sleep(6);
    fprintf(stdout,"\nfather quit\n");
    fflush(stdout);
    return 0;
}