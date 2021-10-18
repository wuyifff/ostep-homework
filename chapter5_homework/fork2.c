/**
 * @file fork2.c
 * @author wuyifff (1327490841@qq.com)
 * @brief ostep chapter 5 question 2
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    pid_t pid;
    char f[] = "father\n";
    char c[] = "child\n";
    fd = open("test", O_CREAT | O_WRONLY  , S_IRWXU);
    if( (pid = fork()) < 0)
    {
        fprintf(stderr, "fork error!");
    }
    else if( pid == 0)
    {
        int i = 0;
        while( i++ < 10000)
            write(fd,c,6);
    }
    else
    {
        int i = 0;
        while( i++ < 10000)
            write(fd,f,7);
    }
    return 0;

}