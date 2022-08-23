#include<stdio.h>
#include<stdlib.h>

typedef struct line{
    struct line * prior;
    int data;
    struct line * next;
}line;

line * initLine(line * head);
//双链表插入元素，add为插入位置
line * insertLine(line * head,int data,int add);

line * delLine(line * head,int data);

int selectElem(line * head,int elem);
//更改指定位置节点中存储的数据，add为更改位置
line *amendElem(line * p,int add,int newElem);

void display(line * head);



int main(){
    line * head = NULL;
    //创建双链表
    head = initLine(head);
    display(head);
    //在3的位置插入元素7
    head = insertLine(head,7,3);
    display(head);
    //删除元素2
    head = delLine(head,2);
    display(head);

    printf("元素 3 的位置是: %d\n",selectElem(head,3));
    //更改第三个节点中的数据为存储6
    head = amendElem(head,3,6);
    display(head);
    return 0;
}

line * initLine(line * head){
    head = (line*)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    line * list = head;
    for (int i = 2; i <= 5; i++)
    {
        line * body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        body->prior = list;
        list = list->next;
    }
    return head;
}

line * insertLine(line * head,int data,int add){
    //创建数据域为data的节点
    line * temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    //插入到链表头，要特殊考虑
    if(add == 1){
        temp->next = head;
        head->prior = temp;
        head = temp;
    }else{
        line * body = head;
        //找到要插入位置的前一个结点
        for (int i = 1; i < add-1; i++)
        {
            body = body->next;
        }
        //判断为真，插入位置为尾
        if(body->next == NULL){
            body->next = temp;
            temp->prior = body;
        }else
        {
            body->next->prior = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;
        }
        
        
    }
    return head;
}

line * delLine(line * head,int data){
    line * temp = head;
    //遍历链表
    while (temp)
    {
        //判断当前结点中数据域和data是否相等，若相等则摘除该结点
        if(temp->data == data){
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}

//head为原双链表，elem表示被查找元素
int selectElem(line * head,int elem){
    //新建一个指针t，初始化为头指针head
    line * t = head;
    int i = 1;
    while (t)
    {
        if(t->data == elem){
            return i;
        }
        i++;
        t = t->next;
    }
    //查找失败
    return -1;
}

line *amendElem(line * p,int add,int newElem){
    line * temp = p;
    //遍历到被删除结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->data = newElem;
    return p;
}

void display(line * head){
    line * temp = head;
    while (temp)
    {
        if(temp->next == NULL){
            printf("%d\n",temp->data);
        }else
        {
            printf("%d-> ",temp->data);
        }
        temp = temp->next;
    }
    
}