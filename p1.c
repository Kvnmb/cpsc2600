 #include <sys/types.h> 
      #include <stdio.h> 
      #include <unistd.h>
 
      int main() { 
           pid_t  a, b; 
           a = fork(); 
           b = fork(); 
           if (a != 0) 
                 b = fork(); 
           if (b == 0) 
                 a = fork(); 
           printf("hello\n"); 
           return 0; 
      }     