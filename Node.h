//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2566 BE.
//
#ifndef Node_h
#define Node_h

struct node
{
    int data;
    struct node *nextPtr;
};

typedef struct node Node;
typedef struct node* NodePtr;


void enqueue(NodePtr * head, NodePtr* tail, int x){
  Node* new_node=(NodePtr) malloc(sizeof(Node));
if(new_node){ 
  /*Fill in data information*/
    new_node -> data = x;
    new_node -> nextPtr=NULL;
    /*Finish queue*/

    //หัวแถว
    if((*head)==NULL) /* *head is the pointer in main which point value of head*/
    {
      *head = new_node;
    }
    //ต่อท้าย
    else
    {
      (*tail) -> nextPtr = new_node;
    }
    *tail = new_node;
 }
}


int dequeue(NodePtr* head, NodePtr* tail){ //change new head
  NodePtr t=*head;
   if(t){
    int value= t->data;
   
   //Normal case
      *head = t->nextPtr;
      
      /* Finish dequeue*/
      if(*head==NULL) 
      {
        *tail=NULL;
      }

      free(t);
      return value;
   }

   printf("Empty queue\n");
   return 0;
}



#endif
