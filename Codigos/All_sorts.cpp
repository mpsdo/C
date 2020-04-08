#include <iostream>
using namespace std;
#define tam 6
int menu();
void mergeSort(int A[], int inicio, int fim);
void intercala(int A[], int inicio, int fim, int meio);
void quickSort(int A[], int esq, int dir);
void insertSort(int A[]);
void selectionSort(int A[]);
void bubbleSort(int A[]);

int main(int argc, char** argv)
{
	int A[tam] = {105, 75, 80, 30, 56, 94};

	int op;

	do
	{
		op = menu();
		if(op >= 0)
		{
			switch(op)
			{
			case 1:
				mergeSort(A, 0, 4);
				for(int i = 0; i < tam ; i++)
					cout << "\t" << A[i];
				break;
			case 2:
				quickSort(A, 0, 4);
				for(int i = 0; i < tam ; i++)
					cout << "\t" <<  A[i];
				break;
			case 3:
				insertSort(A);
				for(int i = 0; i < tam ; i++)
					cout << "\t" <<  A[i];
				break;
			case 4:
				selectionSort(A);
				break;
			case 5:
				bubbleSort(A);
				break;
			default:
				cout << "Valor incorreto, tente novamente " << endl;
			}
		}
		else
		{
			cout << "Valor incorreto, tente novamente " << endl;
		}
	}
	while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5);

	return 0;
}

void mergeSort(int A[], int inicio, int fim)
{


	if(inicio < fim)
	{
		int meio = (inicio + fim) / 2;
		mergeSort(A, inicio, meio);
		mergeSort(A, meio + 1, fim);
		intercala(A, inicio, fim, meio);
	}
}

void intercala(int A[], int inicio, int fim, int meio)
{

	int posLivre = inicio;
	int inicioA1 = inicio;
	int inicioA2 = meio + 1;
	int aux[tam];

	while(inicioA1 <= meio && inicioA2 <= fim)
	{
		if(A[inicioA1] < A[inicioA2])
		{
			aux[posLivre] = A[inicioA1];
			inicioA1++;
		}
		else
		{
			aux[posLivre] = A[inicioA2];
			inicioA2++;
		}
		posLivre++;
	}//Fim do while

	// Começo da ordem

	for(int i = inicioA1 ; i <= meio ; i++)
	{
		aux[posLivre] = A[i];
		posLivre++;
	}
	for(int i = inicioA2; i <= fim ; i++)
	{
		aux[posLivre] = A[i];
		posLivre++;
	}
	for(int i = inicio; i <= fim ; i++)
	{
		A[i] = aux[i];
	}

	// fim do for

}

int menu()
{
	int op;
	cout << "Digite 1 para organizar com mergeSort " << endl;
	cout << "Digite 2 para organizar com quickSort " << endl;
	cout << "Digite 3 para organizar com InsertSort" << endl;
	cout << "Digite 4 para organizar com SelectionSort" << endl;
	cout << "Digite 5 para organizar com bubbleSort" << endl;
	cout << "Digite 0 para sair " << endl;
	cin >> op;


	return op;
}

void quickSort(int A[], int esq, int dir)
{
	int meio = (esq + dir) / 2;
	int pivot = A[meio];
	int i = esq , j = dir;
	int tmp;

	while(i <= j)
	{
		while(A[i] < pivot)
			i++;

		while(A[j] > pivot)
			j--;

		if(i <= j) // Condicional porque o i < j e assim a gente pode fazer uma sequencia
		{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;

			i++;

			j--;

		};
	} // Fim do while

	// Recursividade

	if(esq < j)
		quickSort(A, esq, j);
	if(dir > i)
		quickSort(A, i, dir);

} // Fim do quickSort

// Insert sort

void insertSort(int A[])
{
	int aux, j;

	for(int i = 1 ; i <= tam - 1; i++ )
	{
		aux = A[i];
		j = i - 1;

		while(aux < A[j] && j >= 0)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = aux;
	}
}// fim do insert sort

// Selection Sort
void selectionSort(int A[])
{
	int aux, menor, loc;
	// Inicio da ordenacao
	for(int i = 0 ; i < tam ; i++)
	{
		menor = A[i];
		loc = i;
		for(int j = i + 1 ; j < tam; j++)
		{
			if(A[j] < menor)
			{
				menor = A[j];
				loc = j;
			}
		}

		aux = A[i];
		A[i] = A[loc];
		A[loc] = aux;
	}

	// Fim da ordenacao
	for(int i = 0 ; i < tam; i++)
	{
		cout << A[i] << "\t";
	}
}

// Fim do Sort

// Inicio do bubble Sort
void bubbleSort(int A[])
{
	int aux;

	for(int i = 0 ; i < tam ; i ++)
	{
		for(int j = i + 1 ; j < tam ; j++ )
		{
			if(A[i] > A[j])
			{
				aux = A[i];
				A[i] = A[j];
				A[j] = aux;
			}
		}
	}

	for(int i = 0; i < tam ; i++)
	{
		cout << "\t" << A[i];
	}

}
// Fim do Sort

