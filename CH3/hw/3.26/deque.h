
#ifndef _Queue_H_

#include "basic.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Inject( ElementType X, Queue Q);
ElementType Front( Queue Q);
ElementType Eject( Queue Q);
ElementType FrontAndEject( Queue Q );
int Succ(int value, Queue Q);

int Succ2(int value, Queue Q);
void Push(ElementType X, Queue Q);
ElementType Pop(Queue Q);

#endif // _Queue_H_

#define MinQueueSize 5

struct QueueRecord
{
	int Capacity;
	int Size;
	int Front;
	int Rear;
	ElementType *Array;
};
