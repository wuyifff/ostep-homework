/**
 * @file fork1.c
 * @author wuyifff (1327490841@qq.com)
 * @brief ostep chapter5 qestion1
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    pid_t ch;
    if( (ch = fork()) < 0 )
    {
        fprintf(stderr, "fork failed\n");
    }
    else if( ch == 0)
    {
        x = 200;
        printf("child is = %d\n",x);
    }
    else
    {
        printf("father is x = %d\n",x);
        sleep(1);
        printf("father is x = %d\n",x);
    }
    return 0;
}