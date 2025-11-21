//linked list 

typedef struct Node
{
   int data;
   struct node* next;
}node;

typedef struct queue
{
   node *head;
   node *tail;
   int size;
}queue;

void create_queue(){
   queue* q= malloc(sizeof(queue));
   q->head=NULL;
   q->tail=NULL;
   q->size=0;
   return q;
}


void enqueue(queue* queue ,int memutilization){
   node* newnode= malloc(sizeof(queue));
   newnode->data = memutilization;
   newnode->next=NULL;

   if(queue->tail==NULL){
      queue->head=newnode;
      queue->tail=newnode;
   }
   else
   {
      queue->tail->next=newnode;
      queue->tail=newnode;
   }
}
