#include "extra.h"

int my_strlen(char *src)
{
    int num=0;
    while(*src!='\0')
    {
        src++;
        num++;

    }
    return num;
}

char*my_strcpy(char *dest,char *src)
{
    while(*src!='\0')
    {
        *dest=*src;
        src++;
        dest++;

    }
    *dest='\0';


    return dest;
}

int my_strcmp(char *s1,char *s2)
{
    int step=0;
    int flag=0;
    char *temp=s1;
    while (*temp!='\0')
    {
        temp++;
        step++;
    }
    
    while(*s1!='\0')
    {
        if(*s1==*s2)
        {
            s1++;
            s2++;
            flag++;
        }
        else
        {
            break;
        }
    }
    if(flag==step)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}


void File_error(FILE *fp)
{
      if(fp==NULL)
    {
        printf("txl.txt error\n");
    }
    exit(1);
}

int My_read_line(char *ptr,size_t size,size_t memb,FILE*fp)
{
    int i=0;
    char temp;

    while(fread(&temp,1,1,fp)!=0)
    {
        if(temp=='\n')
        {
            break;
        }
        ptr[i]=temp;
        i++;

        if(feof(fp)!=0)
        {
            break;
        }
    }
    ptr[i]='\0';
}

int my_atoi(char *s)
{
    int flag=1;
    int result=0;
    if(*s=='-')
    {
        flag=-1;
        s++;
    }
    while(*s)
    {
        if(*s>='0'&&*s<='9')
        {
        result=result*10+(*s-'0');
        }
        else
        {
            break;
        }
        s++;  
    }

    return result*flag;
}

int My_write_line(char *ptr,FILE*fp)
{
    fwrite(ptr,1,my_strlen(ptr),fp);
    fwrite("\n",1,my_strlen("\n"),fp);
    return 0;
}

char * my_iota(int i)
{
    static char s[1006];
    int c=i;
    int n=0;
    while(c>0)
    {
        *(s+n)='0'+c%10;
        c=c/10;
        n++;
    }
    *(s+n)='\0';
    for(int v=0;v<n/2;v++)
    {
        char temp=*(s+v);
        *(s+v)=*(s+n-1-v);
        *(s+n-1-v)=temp;
    }
    return s;
}