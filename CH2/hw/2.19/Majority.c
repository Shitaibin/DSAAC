/**
 * This algorithm is not right, If without function Valid().
 * Because it does not verify the return of
 * Majority() is valid, the number of it appears
 * should bigger than n/2.
 * 
 * T(n) = O(N)
 *
 * In the worst case:
 * all the elem is the same. the var size becomes a half 
 * every time. like this: n, n/2, n/4 ..., .
 * the execute times of `for (i=0; ...` is
 * n/2 + n/4 + n/8 + n/16 + ... 
 * = n ( 1/2 + 1/4 + 1/8 + ...)
 * = n * 1 
 *
 * time complexity of Valid() is O(N).   
 *
 * If you sort A, and get the the midian elem, the
 * time complexity is T(n) = O(NlogN). 
 */

#include <stdio.h>


int Majority( int A[], int N )
{
	int size = N;

	while (size > 1)
	{
		int p = 0;
		int i;
		for (i=0; i < size; i+=2)
		{
			if (i+1 == size || A[i] == A[i+1])
				A[p++] = A[i];	

		}	

		size = p;
	}

	return A[0];
}

int Valid(int A[], int N, int Maj)
{
	int i, count = 0;
	for(i = 0; i < N; i++)
	{
		if (A[i] == Maj)
			count++;
	}

	if (count > N/2)
		return 1;
	else
		return 0;
}


int main()
{
	int A[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};	
	int N = 9;

	int B[] = {1, 2, 1, 2, 3};
	int NN = 5;
	
	int ma = Majority(A, 9);
	int mb = Majority(B, 5);

	// valid verifacation
	if (Valid(A, N, ma))
		printf("majority of A is %d\n", ma);
	else 
		printf("no majority in A\n");

	if (Valid(A, NN, mb))
		printf("majority of B is %d\n", mb);
	else
		printf("no majority in B\n");


	return 0;

}










