#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int my_strlen(char *src);
char*my_strcpy(char *dest,char *src);
int my_strcmp(char *s1,char *s2);
void File_error(FILE *fp);
int My_read_line(char *ptr,size_t size,size_t memb,FILE*fp);
int My_write_line(char *ptr,FILE*fp);
int my_atoi(char *s);
char * my_iota(int i);