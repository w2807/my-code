#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define FILENAME "maillist"
typedef struct  person
{
  char name[20];
  char address[40];
  long zip;
  char phone[15];
}PERSON;
typedef struct address
{
    char name[20];
    char address[40];
    long zip;
    char phone[15];
    struct address*next;
}ADDRESS;
typedef ADDRESS*AD_LIST;
AD_LIST load(void);
int menu_select(void);
AD_LIST insert(AD_LIST head);
void show(AD_LIST head);
void find(AD_LIST head);
AD_LIST deletenode(AD_LIST head);
void save(AD_LIST head);
int main(void)
{
    AD_LIST head;
    char choice;
    head=load();
    for(;;)
    {
        choice=menu_select();
        switch(choice)
        {
            case 1:
            head=insert(head);
            break;
            case 2:
            show(head);
            break;
            case 3:
            find(head);
            break;
            case 4:
            deletenode(head);
            break;
            case 5:
            save(head);
            break;
            case 6:
            return 0;
        }
    }
    return 0;
}
int menu_select(void)
{
    char s[80];
    int c;
    printf("\t\t     通信录管理系统\n");
    printf("\t\t========================\n");
    printf("\t\t    1.插入一条记录\n");
    printf("\t\t    2.显示所有记录\n");
    printf("\t\t    3.按姓名查找\n");
    printf("\t\t    4.按姓名删除\n");
    printf("\t\t    5.存盘\n");
    printf("\t\t    6.退出\n");
    do
    {
       printf("\n\n\t请选择(~6):");
       gets(s);
       printf("\n");
       c=atoi(s);
    }while(c<0||c>6);
    return c;
}
AD_LIST load(void)
{
    AD_LIST p,q,head;
    PERSON per;
    FILE*fp;
    q=head=NULL;
    if((fp=fopen(FILENAME,"rb"))==NULL)
    {
        printf("Can not open file%s\n",FILENAME);
        return head;
    }
    else
    {
        while(!feof(fp))
        if(fread(&per,sizeof(PERSON),1,fp)==1)
        {
            p=(AD_LIST)malloc(sizeof(ADDRESS));
            strcpy(p->name,per.name);
            strcpy(p->address,per.address);
            p->zip=per.zip;
            strcpy(p->phone,per.phone);
            head=p;
            p->next=q;
            q=head;
        }
        fclose(fp);
        return(head);
    }
}
AD_LIST insert(AD_LIST head)
{
    AD_LIST temp,p;
    p=head;
    temp=(AD_LIST)malloc(sizeof(ADDRESS));
    printf("\n\t请输入姓名:");
    gets(temp->name);
    printf("\n\t请输入通信地址:");
    gets(temp->address);
    fflush(stdin);
    printf("\n\t请输入位邮政编码:");
    scanf("%ld",&temp->zip);
    fflush(stdin);
    printf("\n\t请输入电话号码:");
    gets(temp->phone);
    fflush(stdin);
    head=temp;
    temp->next=p;
    return head;
}
void save(AD_LIST head)
{
    AD_LIST p;
    FILE*fp;
    PERSON per;
    if((fp=fopen(FILENAME,"wb"))==NULL)
    {
        printf("Can not open file%s\n",FILENAME);
        return;
    }
    else
    {
        p=head;
        while(p!=NULL)
        {
            strcpy(per.name,p->name);
            strcpy(per.address,p->address);
            per.zip=p->zip;
            strcpy(per.phone,p->phone);
            if(fwrite(&per,sizeof(PERSON),1,fp)!=1)
            printf("File write error.\n");
            p=p->next;
        }
        fclose(fp);
    }
}
void show(AD_LIST head)
{
    AD_LIST p;
    p=head;
    printf("%-30s%-40s%-20s%-40s\n","姓名","地址","邮编","电话号码");
    while(p!=NULL)
    {
        printf("%-30s",p->name);
        printf("%-40s",p->address);
        printf("%-20ld",p->zip);
        printf("%-40s\n\n",p->phone);
        p=p->next;
    }
}
void find(AD_LIST head)
{
    AD_LIST p;
    char name[20];
    int flag=0;
    printf("请输入要查找的人的姓名:");
    gets(name);
    p=head;
    while(p!=NULL)
    {
        if(strcmp(name,p->name)==0)
        {
            printf("Name:%s\n",p->name);
            printf("Address:%s\n",p->address);
            printf("Zip:%ld\n",p->zip);
            printf("Phone:%s\n\n",p->phone);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0)
    printf("\n\t\t查无此人\n\n");
}
AD_LIST deletenode(AD_LIST head)
{
    AD_LIST p,q;
    char name[20];
    int flag=0;
    printf("请输入要删除的人的姓名:");
    gets(name);
    p=q=head;
    while(p!=NULL)
    {
        if(strcmp(name,p->name)==0)
        {
            if(head==p)
            head=p->next;
            else
            q->next=p->next;
            free(p);
            p=q->next;
            flag=1;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    if(flag==0)
    printf("\n\t\t查无此人\n\n");
    return head;
}