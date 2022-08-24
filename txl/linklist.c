#include "linklist.h"


//创建一个空的单链表
linklist* LinklistCreat()
{
    //定义一个头结点，在堆区开辟空间
    linklist *head =(linklist*)malloc(sizeof(linklist));
    //给指针域赋初始值为空
    head->next = NULL;
    return head;
}

//遍历单链表
void LinklistPrint(linklist *head)
{
    //定义一个指针遍历保存第一个有数据的结点的地址
    linklist *p=head->next;

    //循环遍历单链表，知道p的指针域为空，结束循环遍历
    while(p)
    {
            printf("%s\t %3d %5d %s \n",p->name,p->id,p->age,p->num);
            //p指向下一个结点（p保存下一个结点的地址）
            p=p->next;
    }
}

//判断链表是否为空
bool LinklistIsEmpty(linklist *head)
{
    return head->next == NULL ?1:0;
}

//尾插法
void LinklistTail(linklist *head,linklist *l)
{
    linklist *r=head;
    while(r->next)
    {
        r=r->next;
    }
    l->next=r->next;
    r->next=l;
    return;
}

//按顺序插入结构体
void LinklistSort(linklist *head,linklist *l)
{
        linklist *r=head;
        while(r)
        {
            if(r->next==NULL||*(l->name)<=*((r->next)->name))
            {
                l->next=r->next;
                r->next=l;
                return;
            }
            r=r->next;
        }
}
