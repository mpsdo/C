#include <iostream>
using namespace std;

void quickSort(int A[], int left, int right);

int main()
{
	int A[5]= {2,3,5,8,9};
	
	quickSort(A,0,4);
	
	for(int i = 0; i < 5 ; i++)
	{
		cout << A[i] << endl;
	}
	
	return 0;
}


void quickSort(int A[], int left, int right)
{

	int i = left, j = right;

	int tmp; // Temporizador

	int pivot = A[(left + right) / 2]; // Pivo

	/* partition */

	while (i <= j)
	{

		while (A[i] < pivot)
			i++;

		while (A[j] > pivot)
			j--;

		if (i <= j)
		{

			tmp = A[i];

			A[i] = A[j];

			A[j] = tmp;

			i++;

			j--;

		}

	};

	/* recursion */

	if (left < j)

		quickSort(A, left, j);

	if (i < right)

		quickSort(A, i, right);

}
