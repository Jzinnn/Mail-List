#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "linklist.h"
#include "extra.h"


int main(int argc,char**argv)
{ 
    static int s=1;
    linklist *head=LinklistCreat();
    Read(head);
    while(1)
    {
        menu();
        int c=0;
        printf("请输入选择的功能数字：\n");
        scanf("%d",&c);
        getchar();
        if(!(c<7&&c>0))
        {
            printf("请输入1-6的数字!!\n");
            continue;
        }
        switch (c)
        {
        case 1:
            Add(head);
            break;
        case 2:
            View(head);
            break;
        case 3:
            Search(head);
            break;
        case 4:
            Delete(head);
            break;
        case 5:
            Change(head);
            break;
        case 6:
            exit(1);
            break;
        }
    }
}