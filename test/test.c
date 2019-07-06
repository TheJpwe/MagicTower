#include <stdio.h>
#define N 10
void fun(int b[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
	{
		t = b[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (b[j] > t)
				b[j + 1] = b[j];
			else if (b[j] <= t)
			{
				b[j + 1] = t;
				break;
			}
		}

	}

}
	int main()
	{
		int a[N] = { 12,63,32,75,42,13,52,25,31,19 };
		int i;
		fun(a, N);
		for (i = 0; i < N; i++)
			printf("%4d", a[i]);
	}