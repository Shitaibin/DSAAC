
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>

#define MinQueueSize 5
#define ElementType char

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( ElementType X, Queue Q);
ElementType Front( Queue Q);
void Dequeue( Queue Q);
ElementType FrontAndDequeue( Queue Q );
int Succ(int value, Queue Q);

struct QueueRecord
{
	int Capacity;
	int Size;
	int Front;
	int Rear;
	ElementType *Array;
};
#endif // _Queue_H_


