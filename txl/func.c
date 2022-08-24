#include "func.h"
#include "extra.h"
#include "linklist.h"
#include <string.h>
//菜单
void menu()
{
    printf("------------------------------\n");
    printf("    1:添加用户   2:查看用户    \n");
    printf("    3:搜索用户   4:删除用户    \n");
    printf("    5:修改用户   6:退出        \n");
    printf("------------------------------\n");
}

//读取通讯录内容
void Read(linklist *head)
{
    //打开文件读取通讯录
    FILE *fp = fopen("txl.txt", "r");
    if(fp==NULL)
    {
        printf("file txl error\n");
        exit(1);
    }
    fseek(fp,0,SEEK_SET);

    while(!feof(fp))
    {   
        linklist *r=(linklist*)malloc(sizeof(linklist));
        char buf[256],buf1[256],buf2[256],buf3[256];
        My_read_line(buf,1,sizeof(buf)-1,fp);
        my_strcpy(r->name,buf);
        My_read_line(buf1,1,sizeof(buf1)-1,fp);
        r->id=my_atoi(buf1);
        My_read_line(buf2,1,sizeof(buf2)-1,fp);
        r->age=my_atoi(buf2);
        My_read_line(buf3,1,sizeof(buf3)-1,fp);
        my_strcpy(r->num,buf3);
        LinklistTail(head,r);
    }
    fclose(fp);
}
//刷新文件内容
void Fresh(linklist *head)
{
    FILE *fp;
    fp=fopen("txl.txt","w");
    linklist *r=head->next;
    while(r)
    {
        if(r->next)
        {
            My_write_line(r->name,fp);
            My_write_line(my_iota(r->id),fp);
            My_write_line(my_iota(r->age),fp);
            My_write_line(r->num,fp);
        }
        else
        {
            My_write_line(r->name,fp);
            My_write_line(my_iota(r->id),fp);
            My_write_line(my_iota(r->age),fp);
            fwrite(r->num,1,my_strlen(r->num),fp);
        }
        r=r->next;
    }
    fclose(fp);
}

//判断
int Judge_id(linklist *j,linklist *head)
{
    linklist *r=head->next;
    int flag=1;
    while(r)
    {
        if(r->id==j->id&&r!=j)
        {
            printf("ID不可重复\n");
            flag=0;
            return 0;
        }
        r=r->next;
    }
    if(flag)
    {
        return 1;
    }
}
int Judge_num(linklist *j,linklist *head)
{
            int v=0;
        while(*(j->num+v)!='\0')
        {
            if((*(j->num+v))<'0'||(*(j->num+v)>'9'))
            {
                printf("添加失败，格式错误\n");
                return 0;
                break;
            }
            v++;
        } 
        if (v!=11)
        {
            printf("添加失败，号码长度错误\n");
            return 0;
        }
        if(v==11)
        {
        return 1;
        }
}
//添加用户
void Add(linklist *head)
{
    int flag=1;

    do
    {    printf("请按 名字 id 年龄 电话号码的顺序输入用户信息\n");
        linklist *l=(linklist*)malloc(sizeof(linklist));
        l->next=NULL;
        scanf("%s",(l->name));
        scanf("%d",&(l->id));
        scanf("%d",&(l->age));
        scanf("%s",(l->num));
        flag=Judge_num(l,head)*Judge_id(l,head);
        if(flag==0) 
        {
            printf("请重新输入\n");
            continue;            
        }
        
        if(flag==1)
        {
            LinklistSort(head,l);
            Fresh(head);
            printf("添加成功\n按任意键回车继续添加，按'q'退出添加\n");   
            getchar(); 
        }
        
    }while(getchar()!='q');
    
    // return i;
}

//查看用户
void View(linklist* head)
{
    if(head->next==NULL)
    {
        printf("此通讯录为空！\n");
        return;
    }
    printf("名字              ID    年龄  电话\n");
    // printf("名字              ID    电话\n");
    LinklistPrint(head);
    return;
}

//搜索用户
void Search(linklist *head)
{
    int d;
    while(1)
    {
        printf("根据ID搜索请按1，根据名字搜索请按2\n");
        scanf("%d",&d);
        getchar();
        if((d==1)||(d==2))
        {
            break;
        }
        else
        {
            printf("请输入1或2！！！\n");
        }
    }
    //按ID查找
    if(d==1)
    {
        int flag=0;
        printf("请输入ID\n");
        int s_id;
        scanf("%d",&s_id);
        linklist *j=head->next;
        while(j)
        {
            if(j->id==s_id)
            {
                printf("名字              ID    年龄  电话\n");
                printf("%s\t %3d %5d %s\n",j->name,j->id,j->age,j->num);
                flag=1;
            }
            j=j->next;
        }
        if(flag==0)
        {
            printf("查找失败，没有此ID。\n");
        }
    }
    //按名字查找
    if(d==2)
    {
        int flag=0;
        printf("请输入名字\n");
        char c[32]={0};
        scanf("%s",c);
        linklist *j=head->next;
        while(j)
        {
            if(my_strcmp(j->name,c))
            {
                printf("名字              ID    年龄  电话\n");
                printf("%s\t %3d %5d %s\n",j->name,j->id,j->age,j->num);
                flag=1;
            }
            j=j->next;
        }
        if(flag==0)
        {
            printf("查找失败，没有此ID。\n");
        }
    }
}


//删除用户
void delete(int b,linklist *j)
{
    if((b!=1)&&(b!=2))
    {
         printf("请输入1或2！！！\n");
         return ;
    }
    if(b==2)
    {
        return ;
    }
    if(b==1)
    {
        linklist *s=j->next;
        j->next=s->next;
        free(s);
        printf("删除成功\n");
        return ;
    }
}
void Delete(linklist *head)
{
    int flag=0;
    int d;
    while(1)
    {
        printf("根据ID搜索请按1，根据名字搜索请按2\n");
        scanf("%d",&d);        
        getchar();
        if((d!=1)&&(d!=2))
        {
            printf("请输入1或2！！！\n");
        }
        if((d==1)||(d==2))
        {
            break;
        }
    }
    //按ID查找
    if(d==1)
    {
        printf("请输入ID\n");
        int s_id;
        // getchar();
        scanf("%d",&s_id);
        linklist *j=head;
        while(j->next)
        {
            if((j->next)->id==s_id)
            {
                flag=1;
                linklist *j2=j->next;
                printf("名字              ID    年龄  电话\n");
                printf("%s\t %3d %5d %s\n",j2->name,j2->id,j2->age,j2->num);
                printf("是否删除该条信息？是：1，否：2\n");
                int b=0;
                scanf("%d",&b);
                getchar();
                delete(b,j);
                Fresh(head);
                break;
            }
            j=j->next;
        }
        if(flag==0)
        {
            printf("查找失败，没有此ID。\n");
        }
        return;
    }
    //按名字查找
    if(d==2)
    {
        printf("请输入名字\n");
        char c[32];
        // getchar();
        scanf("%s",c);
        linklist *j=head;
        while(j->next)
        {
            
            if(my_strcmp(j->next->name,c))
            {
                flag=1;
                linklist *j2=j->next;
                printf("名字              ID    年龄  电话\n");
                printf("%s\t %3d %5d %s\n",j2->name,j2->id,j2->age,j2->num);
                printf("是否删除该条信息？是：1，否：2\n");
                int b=0;
                scanf("%d",&b);
                getchar();
                delete(b,j);
                Fresh(head);
                break;
            }
            j=j->next;
        }
        if(flag==0)
        {
            printf("查找失败，没有此名字。\n");
        }
        return;
    }

}

//修改用户
void change(linklist *j,int b,linklist *head)
{
    // printf("2%d\n",b);
    if((b!=1)&&(b!=2))
    {
         printf("请输入1或2！！！\n");
         return;
    }
    if(b==2)
    {
        return ;
    }
    if(b==1)
    {
        int flag=1;
        do
        {
        printf("请按 名字 id 电话号码的顺序输入修改的信息\n");
        scanf("%s",(j->name));
        scanf("%d",&(j->id));
        scanf("%d",&(j->age));
        scanf("%s",(j->num));
        flag=Judge_num(j,head)*Judge_id(j,head);
        if(flag==0) 
        {
            printf("请重新输入\n");    
        }

        }while(flag!=1);
        linklist *r=head;
        while(r->next!=j)
        {
            r=r->next;
        }
        r->next=j->next;
        j->next=NULL;
        LinklistSort(head,j);
        printf("修改成功\n");
        return ;
    }
}
void Change(linklist *head)
{
    int d;
    while(1)
    {
        printf("根据ID搜索请按1，根据名字搜索请按2\n");
        scanf("%d",&d);
        getchar();
        if((d!=1)&&(d!=2))
        {
            printf("请输入1或2！！！\n");
        }
        if((d==1)||(d==2))
        {
            break;
        }
    }
    //按ID查找
    if(d==1)
    {
        int flag=0;
        printf("请输入ID\n");
        int s_id;
        scanf("%d",&s_id);
        linklist *j=head->next;
        while(j)
        {
            if(s_id==j->id)
            {
                printf("名字              ID    年龄  电话\n");
                printf("%s\t %3d %5d %s\n",j->name,j->id,j->age,j->num);
                printf("是否修改该条信息？是：1，否：2\n");
                int b=0;
                scanf("%d",&b);
                getchar();
                change(j,b,head);
                Fresh(head);
                flag=1;
                break;
            }
            j=j->next;
        }
        if(flag==0)
        {
            printf("查找失败，没有此ID。\n");
        }
        return;
    }
        
    //按名字查找
    if(d==2)
    {
        int flag=0;
        printf("请输入名字\n");
        char c[32]={0};
        scanf("%s",c);
        linklist *j=head->next;
        while(j)
        {
            if(my_strcmp(c,j->name))
            {
                printf("名字              ID    年龄  电话\n");
                printf("%s\t %3d %5d %s\n",j->name,j->id,j->age,j->num);
                printf("是否修改该条信息？是：1，否：2\n");
                int b=0;
                scanf("%d",&b);
                getchar();
                change(j,b,head);
                Fresh(head);
                flag=1;
                break;
            }
            j=j->next;
        }
        if(flag==0)
        {
            printf("查找失败，没有此名字。\n");
        }
        return;
    }
        
}

