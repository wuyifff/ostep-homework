/**
 * @file fork3.c
 * @author wuyifff (1327490841@qq.com)
 * @brief ostep chapter5 qestion5
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
void handler()
{
    sleep(1);
    printf("get the message\n");
}

int main()
{
    pid_t pid;
    if((pid = fork()) < 0){
        fprintf(stderr, "fork error");
    }
    else if( pid == 0)
    {
        signal(SIGUSR1, handler);
        printf("child is waiting for parent\n");
        fflush(stdout);
        pause();
        printf("child exit\n");
        fflush(stdout);
        return 0;
    }
    sleep(1);
    kill(pid,SIGUSR1);
    printf("parent exit\n");
    return 0;
}