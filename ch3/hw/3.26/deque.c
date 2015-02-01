
#include "deque.h"


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

void Inject(ElementType X, Queue Q)
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

ElementType Eject(Queue Q)
{
	if (IsEmpty(Q))
		Error("Queue is empty!");
	else
	{
		ElementType E = Q->Array[Q->Rear];
		Q->Rear = Succ2(Q->Rear, Q);
		Q->Size--;
		return E;
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

ElementType FrontAndEject(Queue Q)
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

int Succ2(int value, Queue Q)
{
	if(--value == -1)
		value = Q->Capacity-1;
	return value;
}


void Push(ElementType X, Queue Q)
{
	if (IsFull(Q))
		Error("Queue is full!");
	else
	{
		Q->Front = Succ2(Q->Front, Q);
		Q->Array[Q->Front] = X;
		Q->Size++;
	}
}

ElementType Pop(Queue Q)
{	
	if (IsEmpty(Q))
		Error("Queue is empty!");
	else
	{
		ElementType E = Q->Array[Q->Front];
		Q->Front = Succ(Q->Front, Q);
		Q->Size--;
		return E;
	} 	
}



