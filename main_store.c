#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue2.h"
#include "Store.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;

  intro();
  howto();

// For struct Queue
  Queue  q;
   q. headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;

   int i,x;
   

 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
            x=dequeue_struct(&q);
            //x=dequeue(&headPtr,&tailPtr);
            if(x!=0) printf("The queue is empty\n");
        }
        else {
          //enqueue(&headPtr,&tailPtr, atoi(argv[i]));
          enqueue_struct(&q, atoi(argv[i]));
           
        }

 }

 printf("===============================\n");
 printf("There are %d ppl left in the queue\n", q.size);

 printf("Clearing queue...\n");
    while(q.size > 0) {
        NodePtr temp = q.headPtr;
        q.headPtr = q.headPtr->nextPtr;
        free(temp);
        q.size--;
    }

  return 0;
}
