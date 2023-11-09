#include "hsh.h" 
  
 /** 
  * read_line - read a line from the stream 
  * 
  * Return: pointer that points the the read line 
  */ 

char *read_line(void) 
 { 
         int j, c, buffer; 
         char *line; 
  
         buffer = 1024, j = 0; 
         line = malloc(sizeof(char) * buffer); 
  
         if (line == NULL) 
         { 
                 _puts("allocation error in read_stream\n"); 
                 exit(EXIT_FAILURE); 
         } 
         while (1) 
         { 
                 c = getchar(); /* read first char from stream */ 
                 if (c == EOF) 
                 { 
                         free(line); 
                         exit(EXIT_SUCCESS); 
                 } 
                 else if (c == '\n') 
                 { 
                         line[j] = '\0'; 
                         return (line); 
                 } 
                 else 
                 { 
                         line[j] = c; 
                 } 
                 j++; 
                 } 
         } 
