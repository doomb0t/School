/*
 * =====================================================================================
 *
 *       Filename:  a03.c
 *
 *    Description:  reads argv[1] chars one at a time from child to parent
 *                  outputs how many char's  the proc counts through pipe
 *
 *        Version:  1.0
 *        Created:  05/29/2015 01:42:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *         Source:  starter code by Michael Trigiboff PhD.
 *   Organization:  PCC CS201 Computer Systems
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*ERROR HANDLING*/
#define READ_ERR        -2
#define WRITE_ERR       -3
#define PROTOCOL_ERR    -1

/*PROTOCOL CMD DEF*/
#define OPEN_CMD        -12
#define ACK_CMD         -10
#define CLOSE_CMD       -13
#define EOA_CMD         -14 //end of args flag

static int fd_in, fd_out;

char read_pipe ()
{
    char c;

    if(read(fd_in, &c, 1) == 1) {
        return c;
        }
    else {
        printf("read_pipe: read err\n");
        exit(WRITE_ERR);
        }
}

void write_pipe (char c)
{
    if(write(fd_out, &c, 1) != 1) {
        printf("write_pipe: err\n");
        exit(WRITE_ERR);
        }   
}

void get_cmd (char cmd)
{
    char c = read_pipe();

    if(c == cmd)
        write_pipe(ACK_CMD);
    else {
        printf("get_cmd: protocol err\n");
        exit(PROTOCOL_ERR);
        }
}

void send_cmd (char cmd)
{
    char c;

    write_pipe(cmd);
    if ((c =  read_pipe()) != ACK_CMD) {
        printf("send_cmd: protocol err, read '%d' 0x%X\n", c, c & 0xFF);
        exit(PROTOCOL_ERR);
        }
}

char get_data ()
{
    char c = read_pipe();
    write_pipe(ACK_CMD);
    return c;
}

void send_data (char ch)
{
    char c;

    write_pipe(ch);
    if((c = read_pipe()) != ACK_CMD) {
        printf("send_cmd: protocol  err\n");
        exit(PROTOCOL_ERR);
        }
//    printf("parent: '%c' acknowledged\n", ch);
}

int main(int argc, char **argv)
{
    pid_t pid;
    int to_child[2];
    int from_child[2];
    int i,j;
        
    // set up pipe to child
    if(pipe(to_child)) {
        printf("pipe: to child: err\n");
        return -1;
        }  

    //pipe from child
    if(pipe(from_child)) {
        printf("pipe from child err\n");
        return -1;
        }
    
    // create parent and child 
    pid = fork();
        
    //error handling
    if(pid < 0) {
        printf("fork err%d\n", pid);
        }
    // -- running in child process --
    else if (pid == 0) {
	int     nChars = 0;
        char    c;
       
        printf("CS201 - Assignment 3 - Jonathon Sonesen\n");
        
        //pipes for child
        fd_in = to_child[0];
        close(from_child[0]);
        fd_out = from_child[1];
        close(to_child[1]);
        
        get_cmd(OPEN_CMD);

        // Receive characters from parent process via pipe
	// one at a time, and count them.
        c = get_data();
        while(c != EOA_CMD) {
            nChars++;
            c = get_data();
            }
        get_cmd(CLOSE_CMD);
        close(fd_in);
        close(fd_out);
 
	// Return number of characters counted to parent process.
	return nChars;
	}

    else {	
        // -- running in parent process --
	int     nChars = 0;
        
        //parent pipes
        close(to_child[0]);
        fd_out = to_child[1];
        fd_in = from_child[0];
        close(from_child[1]); 
        send_cmd(OPEN_CMD);
        
        //cycle through args and char stating at argv[1]
        for(i = 1; i < argc; i++)
            for (j = 0; j < strlen(argv[i]); j++)
                send_data (argv[i][j]);
        send_cmd(EOA_CMD);      //signal end of agruments
        send_cmd(CLOSE_CMD);
        waitpid(pid, &nChars, 0); //da reaping  
        printf("child counted %d characters\n", nChars/256);
	close(fd_in);
        close(fd_out);
        return 0;
	} 
}
