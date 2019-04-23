#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "malloc.h"

typedef struct Queue
{
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->storage = malloc(capacity * sizeof(int));
    queue->length = 0;
    queue->capacity = capacity;

    return queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (q->length >= q->storage)
    {
        q = resize_memory(q, q->capacity, q->capacity + 1);
    }

    q->storage[q->length] = item;
    q->length += 1;
    q->capacity += 1;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    if (q->length == 0)
    {
        return -1;
    }
    int *q_copy = q;

    q += 1;
    q->length -= 1;
    q->capacity -= 1;
    printf("%d\n", *q_copy);
    return *q_copy;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
}

#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif