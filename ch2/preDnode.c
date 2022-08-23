#include<stdio.h>
#include<stdlib.h>

//节点结构
typedef struct line
{
    struct line * prior;
    int data;
    struct line * next;
}line;

//双链表的创建函数
line * initLine(line * head);

//输出双链表的函数
void display(line * head);

line * initLine(line * head){
    //创建一个首元机节点，链表的头指针为head
    head = (line*)malloc(sizeof(line));
    //对节点初始化
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    //声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
    line * list = head;
    for (int i = 2; i <= 5; i++)
    {
        //创建新的节点并初始化
        line * body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        //新节点与链表最后一个节点建立联系
        list->next = body;
        body->prior = list;
        //list永远指向链表最后一个节点
        list = list->next;
    }
    //返回新创建的链表
    return head;
}

void display(line * head){
    line * temp = head;
    while (temp)
    {
        //如果该节点无后续节点，说明此节点是链表的最后一个节点
        if(temp->next == NULL){
            printf("%d\n",temp->data);
        }
        else{
            printf("%d <-> ",temp->data);
        }
        temp = temp->next;
    }
    
}


int main(){
    //创建一个头指针
    line * head = NULL;
    //调用链表创建函数
    head = initLine(head);
    //输出创建好的函数
    display(head);
    //显示双链表的优点
    printf("链表中第4个节点的直接前驱是: %d\n",head->next->next->next->prior->data);
    return 0;
}

