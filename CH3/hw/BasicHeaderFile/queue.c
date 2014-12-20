
#include "queue.h"


int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}


Queue CreateQueue(int MaxElements)
{
	Queue Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
	{
		FatalError("Out of space!");
		return Q;	
	}

	Q->Array = malloc(sizeof(ElementType) * MaxElements);
	if (Q->Array == NULL)
	{
		FatalError("Out of space!");
		return NULL;
	}
	
	// initialize value
	Q->Capacity = MaxElements;
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
	
	return Q;
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
		Error("Queue is full!");
	else
	{
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
		Q->Size++;
	}
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
		Error("Queue is empty!");
	else
	{
		Q->Front = Succ(Q->Front, Q);
		Q->Size--;
	} 	
}


int Succ(int value, Queue Q)
{
	if (++value == Q->Capacity)
		value = 0;
	return value;
}

ElementType Front(Queue Q)
{
	if (IsEmpty(Q))
		Error("Queue is empty!");
	else
		return Q->Array[Q->Front];
}

ElementType FrontAndDequeue(Queue Q)
{
	ElementType X;

	if (IsEmpty(Q))
		Error("Queue is empty!");
	else
	{
		X = Q->Array[Q->Front];
		Q->Front = Succ(Q->Front, Q);
		Q->Size--;
		return X;
	} 	
}




