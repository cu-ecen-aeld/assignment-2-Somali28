#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <syslog.h>
#include <syslog.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char* argv[])
{
    if ( argc < 3)
    {
        syslog(LOG_USER,"Less arguments provided\n The order of the arguments should be:  1')' Full path to a file (including filename) on the filesystem. 2')' Text string which will be written within this file. \n");
        exit(1);
    }
    else if ( argc > 3 )
    {
        syslog(LOG_USER, "Excess argumnents provided\n The order of the arguments should be: 1')' Full path to a file (including filename) on the filesystem. 2')' Text string which will be written within this file. \n");
        exit(1);
    }
    char file_path[500];
    int last_input = 49;
    int fd ; // File descriptopr
    ssize_t wr;
    strncpy(file_path, argv[1], strlen(argv[1]));
    for (int i = 0 ; i < (int)strlen(argv[1]); i++)
    {
        if (file_path[i] == '/')
            last_input = i;
    }
    if ( last_input == 499 )
    {
        syslog(LOG_ERR,"File path corrupted/incorrect\n");
        exit(0);
    }
    file_path[strlen(argv[1])] = '\0';
    syslog(LOG_DEBUG,"Input file:%s, Input string:%s\n",argv[1],argv[2]);
    fd = open(&file_path[0], O_CREAT | O_RDWR, 777);
    if ( fd == -1 )
    {
        syslog(LOG_ERR,"File cannot be created or opened\n");
        exit(0);
    }
    wr = write(fd, argv[2], strlen(argv[2]));
    if ( wr == -1 )
    {
        syslog(LOG_ERR,"Write operation unsuccesful\n");
        exit(0);
    }
    syslog(LOG_DEBUG,"Write Successful - Input file:%s, Input string:%s\n",argv[1],argv[2]);
    
} 
