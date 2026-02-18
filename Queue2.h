#ifndef Queue2_h
#define Queue2_h

#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x){
  Node *new_node=(Node*) malloc(sizeof(Node));

if(new_node){ 
  new_node->data=x;
  new_node->nextPtr=NULL;

  /*Finish enqueue */
  if(q->size==0) q->headPtr=new_node;
  else q->tailPtr->nextPtr = new_node;
  q->tailPtr = new_node;
  q->size ++;

 }
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   if(t){
   int value= t->data;

        int price = 100; // ราคาต่อชาม
        int total = value * price;
        int cash;
        
        printf("My order is %d\n", value); // แสดงตามโจทย์เก่า
        printf("You have to pay %d\n", total);
        
        do {
            printf("Cash: ");
            scanf("%d", &cash);
        } while(cash < total); // วนรับจนกว่าเงินจะพอ
        
        printf("Thank you\n");
        if(cash > total) {
            printf("Change is %d\n", cash - total);
        }

       /*Finish dequeue */
    q->headPtr=q->headPtr->nextPtr;
    if(q->size==1) q->tailPtr=q->headPtr;

    q->size--;
    free(t);
    return value;
   }
   printf("The queue is empty\n");
   return 0;
}

#endif

