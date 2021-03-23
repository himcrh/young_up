#include<stdio.h>
#include<stdlib.h>
//typedef申明新的数据类型
typedef struct link{
    int data;   //定义数据域
    struct link *next; //定义指针域
}link;
link *AppendNode(link *head){
    //创建节点
    link *p = NULL,*pr = head;
    p=(link *)malloc(sizeof(link));
    if(p==NULL){
        //申请内存失败
        printf("error");
        exit(0);
    }
    if(head == NULL){
        head = p;
        //如果头指针为空，说明链表为空
    }
    else{
        while(pr->next!=NULL)
            pr = pr->next;
            //遍历链表找尾端
        pr->next = p;
        //将链表结尾链给p的地址
    }
    puts("Input node data");
    int data1;
    scanf("%d",&data1);
    p->data = data1;
    p->next = NULL;
    return head;
}
void DisplayNode(link *head){
    link *p = head;
    int i = 1;
    while(p != NULL){
        printf("%5d%10d\n",i,p->data);
        p=p->next;
        i++;
    }  
}
void DeleteMemory(link *head){
    //把链表从头到尾删掉
    link *p=head,*pr=NULL;
    while(p!=NULL){
        pr=p;
        p=p->next;
        free(pr);
    }
}
int main(){
    link *head = NULL;
    int i=0;
    char c;
    printf("append a new node (Y or N)");
    scanf("%c",&c);
    while (c=='y'||c=='Y'){
        head = AppendNode(head);
        DisplayNode(head);
        printf("append a new node (Y or N)");
        getchar()
;        scanf("%c",&c);
        i++;
    }
    printf("%d new nodes have been appended!\n",i);
    DeleteMemory(head);
    return 0;
}