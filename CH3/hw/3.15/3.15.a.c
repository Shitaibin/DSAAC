
/* Here I just give out the function Find */

void Find(ElementType X, ElementType *A, int N)
{
	int i;
	for(i=0; i<N &&A[i]!=X; i++)
		;

	if(i == N)
		return ;

	int t = A[i];
	for(; i>0; i--)
		A[i] = A[i-1];
	A[0] = t;

	return ;
}	
