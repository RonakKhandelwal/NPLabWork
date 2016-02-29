       #include <stdio.h>
       #include <stdlib.h>
       #include <sys/time.h>
       #include <sys/types.h>
       #include <unistd.h>
       #include <fcntl.h>

       int main(void)
       {
           fd_set rfds;
           struct timeval tv;
           int retval;
           int fd1;
           
          
           

           
           FD_ZERO(&rfds);
           FD_SET(0, &rfds);
          // FD_SET(fd1,&rfds);

           
           tv.tv_sec = 5;
           tv.tv_usec = 0;

           retval = select(1, &rfds, NULL, NULL, &tv);
           

           if (retval == -1)
               perror("select()");
           else if (retval)
               printf("Data is available now.\n");
               /* FD_ISSET(0, &rfds) will be true. */
           else
               printf("No data within five seconds.\n");

           exit(EXIT_SUCCESS);
       }

