/**
 * @file closeout.c
 * @author wuyifff (1327490841@qq.com)
 * @brief ostep chapter5 qestion7
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    if( (pid = fork()) < 0){
        fprintf(stderr, "fork err");
    }
    else if(pid == 0)
    {
        close(STDOUT_FILENO);
        printf("i am child\n");
        exit(0);
    }
    sleep(1);
    return 0;
}