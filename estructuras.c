// linked list
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
   int data;
   struct node *next;
} node;

typedef struct queue
{
   node *head;
   node *tail;
   int size;
} queue;

queue *create_queue()
{
   queue *q = malloc(sizeof(queue));
   q->head = NULL;
   q->tail = NULL;
   q->size = 0;
   return q;
}

void enqueue(queue *queue, int memutilization)
{
   node *newnode = malloc(sizeof(node));
   newnode->data = memutilization;
   newnode->next = NULL;

   if (queue->tail == NULL)
   {
      queue->head = newnode;
      queue->tail = newnode;
   }
   else
   {
      queue->tail->next = newnode;
      queue->tail = newnode;
   }
   queue->size++;
}
int deque(queue *queue)
{
   if (queue->head == NULL)
   {
      return -1;
   }

   node *temp = queue->head;
   int value = queue->head->data;
   queue->head = queue->head->next;

   if (queue->head == NULL)
   {
      queue->tail = NULL;
   }

   queue->size--;
   return value;
}

int peek(queue *queue)
{
   if (queue->head == NULL)
   {
      return -1;
   }
   return queue->head->data;
}
