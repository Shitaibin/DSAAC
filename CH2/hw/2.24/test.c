#include <stdio.h>
#include <stdlib.h>
#include <time.h>




/**
 * using divide and conquer to get the 
 * maximum subsequence sum
 */

int Max3(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	else if (b > a && b > c)
		return b;
	else 
		return c;
}


static int
MaxSubSum (const int A[], int l, int r)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum, Center;

	if (l == r)
	{
		if (A[l] >= 0)
			return A[l];
		else
			return 0;
	}
	
	Center = (l+r)/2;
	MaxLeftSum = MaxSubSum(A, l, Center);
	MaxRightSum = MaxSubSum(A, Center+1, r);

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (int i = Center; i >= l; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (int i = Center+1; i <= r; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum,
			MaxLeftBorderSum+MaxRightBorderSum);

}

int MaxSubsequenceSum(const int A[], int N)
{
	return MaxSubSum(A, 0, N-1);
}

	




int main()
{
	int n;
	scanf("%d", &n);


	int *A = malloc(sizeof(int) * n);
	int i;

	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		printf("%d ", A[i]);
	}

	int sum = MaxSubsequenceSum(A, n);

	printf(" -> %d\n", sum);


	return 0;
}




