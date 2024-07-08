#include "list.h"

//目标：搭建自己的通用库，本库关于链表，结合网上资料实现 精简 易用 适用范围广

ListNode_t * newListNode(void){    
    ListNode_t *node;
    node = (ListNode_t *) malloc(sizeof(ListNode_t));
    node->next = NULL;
    node->pre = NULL;
    return node;
}


ListNode_t* newListInit(uint8_t nodeNum){

    if (nodeNum == 0 )      //节点数必须大于0
    {
        return NULL;
    }
    ListNode_t * HeadNode,*CurrNode,*NextNode;
    HeadNode = newListNode();
    CurrNode = HeadNode;
    if (nodeNum == 1)
    {
        return HeadNode;
    }
    /*考虑封装成一个方法，用 loop unrolling 提高并行性，提高速度*/
    while (--nodeNum > 0)
    {
        NextNode = newListNode();   //新建节点
        CurrNode->next = NextNode;  //建立前节点向后关系
        NextNode->pre = CurrNode;   //建立后节点向前关系
        CurrNode = NextNode;        //更新节点到最新节点，最后一个节点是尾节点
    }
    CurrNode->next = HeadNode;      //形成闭环双向链表
    HeadNode->pre = CurrNode;
    
    return HeadNode;                //返回头节点指针
}



void List_Add_FirstNode(ListNode_t* newNode,ListNode_t* headNode){

    newNode->pre = headNode->pre;   //新增节点双向分配
    newNode->next = headNode;
    headNode->pre->next = newNode;  //尾节点
    headNode->pre = newNode;        //头节点

}

void List_Insert_Node(ListNode_t* newNode,ListNode_t* nodeAfterNewOne){

    newNode->pre = nodeAfterNewOne->pre;   //新增节点双向分配
    newNode->next = nodeAfterNewOne;
    nodeAfterNewOne->pre->next = newNode;  //尾节点
    nodeAfterNewOne->pre = newNode;        //头节点

}

void List_Del_Node(){

}

void List_Del_List(){

}