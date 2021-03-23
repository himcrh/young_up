#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int id;
    char name[50];
    struct link *next;
}link;
link *create(int n);
void print(link *head);

int main(){
    int n;
    link *head = NULL;
    puts("创建节点个数：");
    scanf("%d",&n);
    head=create(n);
    print(head);
    return 0;
}

link *create(int n){
    link *head,*node,*end;
    head = (link *)malloc(sizeof(link));
    end = head;
    for(int i=0;i<n;i++){
        node = (link *)malloc(sizeof(link));
        scanf("%d %s",&node->id,node->name);
        end->next=node;
        end=node;
    }
    end->next=NULL;
    return head;
}

void print(link *head){
    link *p = head;
    int i=1;
    p=p->next;
    while(p!=NULL){
        printf("%d\t%d\t%s\n",i,p->id,p->name);
        i++;
        p = p->next;
    }
}