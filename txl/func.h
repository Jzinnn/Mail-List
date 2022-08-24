#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int Judge_age(linklist *j,linklist *head);
int Judge_id(linklist *j,linklist *head);
int Judge_num(linklist *j,linklist *head);
//修改函数
void change(linklist * j,int b,linklist *head);
//修改用户
void Change(linklist *head);
//删除函数
void delete(int b,linklist *head);
//菜单
void menu();
//添加用户
void Add(linklist *head);
//查看用户
void View(linklist *head);
//删除用户
void Delete(linklist *head);
//搜索用户
void Search(linklist *head);
//刷新文件内容
void Fresh(linklist *head);
//读取通讯录内容
void Read(linklist *head);
