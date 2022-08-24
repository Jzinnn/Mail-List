#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//定义结构体
typedef struct node
{
    char name[32];
    int id;
    int age;
    char num[11];
    struct node *next;
}linklist;
//创建一个空的单链表
linklist* LinklistCreat();
//遍历单链表
void LinklistPrint(linklist *head);
//判断链表是否为空
bool LinklistIsEmpty(linklist *head);
//按顺序插入链表
void LinklistSort(linklist *head,linklist *l);
//尾插法
void LinklistTail(linklist *head,linklist *l);
#endif 