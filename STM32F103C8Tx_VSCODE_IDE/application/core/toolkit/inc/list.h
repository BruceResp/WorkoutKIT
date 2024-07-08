#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
    struct ListNode* pre; 
    struct ListNode* next;
    uint8_t serialNo;       //序号

    void * datatype;
}ListNode_t;




#endif