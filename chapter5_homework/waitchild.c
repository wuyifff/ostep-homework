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

int main()
{
    pid_t pid;
    int status;
    if((pid = fork()) < 0){
        fprintf(stderr, "fork error");
    }
    else if( pid == 0)
    {
        sleep(1);
        printf("child exit\n");
        return 0;
    }
    printf("parent is waiting for child\n");
    //wait for SIGCHILD
    wait(&status);
    printf("parent get the message\nparent exit\n");
    return 0;
}