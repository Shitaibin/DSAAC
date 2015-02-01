/**
 * Find the minimum positive subsequence sum.
 */

#include <stdio.h>

int MinSubsequenceSum( const int A[], int N)
{
	int MinSum = 0, CurSum = 0;
	for (int i = 0; i < N; i++)
	{
		CurSum += A[i];

		if (CurSum < MinSum && CurSum > 0)
			MinSum = CurSum;
		else if(CurSum < 0)
			CurSum = 0;
	}

	return MinSum;
}


int main()
{

	int A[6] = {2, 3, -5, 4,  -7, 8};
	
	int sum = MinSubsequenceSum(A, 7);

	printf("%d\n", sum);

	return 0;

}











