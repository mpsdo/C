#include <iostream>
using namespace std;
void intercala(int A[], int start, int end,int half);
void mergeSort(int A[], int start , int end);
void quickSort(int A[], int left, int right);


int main()
{
	int A[5] = {3,2,4,1,5};
	
	int op;
	
	cout << "Qual ordenação deseja usar ? " << endl;
	cin >> op;
	
		switch(op)
		{
			case 1:
				quickSort(A,0,4);
			case 2:
				mergeSort(A,0,4);
		}
	
	for(int i = 0 ; i< 5; i++)
	{
		cout << "A numeração eh : " << A[i] << endl;
	}
	
	
	
	return 0;
}

void quickSort(int A[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot;
	
	
	pivot = A[(right + left)/2];
	
	while(i <= j)
	{
		while(i <= pivot)
			i++;
		
		while(j >= pivot )
			j--;
		
		if(i <= j)
		{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			// Fim da troca;
			
			i++;
			j--;
						
		}
		
		// Recursividade // 
		
		if( left < j)
			quickSort(A,left,j);
		
		if(right > i)
			quickSort(A,i,right);
		
	}
}

void mergeSort(int A[], int start , int end)
{
	int half = (start+end)/2;
	
	if(start < end)
	{
		mergeSort(A,start,half);
		mergeSort(A,half+1,end);
		intercala(A,start,end,half);
	}
}


void intercala(int A[], int start, int end, int half)
{
	int inicioA1 = start;
	int inicioA2 = half+1;
	int posLivre = start;
	int aux[5];
	
	while(inicioA1 <= half && inicioA2 <= end)
	{
		if(A[inicioA1] < A[inicioA2])
		{
			posLivre = A[inicioA1];
			inicioA1++;
		}
		else
		{
			posLivre = A[inicioA2];
			inicioA2++;
		}
		posLivre++;
	} // FIm do while
	
	// Inicio da parte de organizar os quadrados //
	
	for(int i = inicioA1 ; i < half ; i++)
	{
		A[posLivre] = A[i];
		posLivre++;
	}
	for(int i = inicioA2 ; i < end ; i++)
	{
		A[posLivre] = A[i];
		posLivre++;
	}	
	for(int i = start ; i <= end ; i++)
	{
		A[i] = aux[i];
	}
	
	// Fim do intercala // 
	
	
}


// Criar funcao menu

/*
int menu()
{
	
	return
}
*/