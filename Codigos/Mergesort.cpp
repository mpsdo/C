// Mergesort

#include <iostream>
using namespace std;

void intercala (int v[], int inicio , int fim , int meio);
void mergesort(int v[], int inicio , int fim)
{
	if ( inicio < fim ) // Utilizado apenas para tirar vetor unitario, caso tenha
	{
		int meio = ( inicio + fim ) / 2; // achando o meio

		mergesort (v, inicio, meio); // Chamando mergesort entre ( inicio, meio, vetor)
		mergesort(v, meio+1, fim); // Chamando mergesort entre ( meio, fim, vetor)
		intercala(v, inicio, fim, meio); // Intercalando todos os valores de  ( inicio, meio, fim e vetor)
		
	}
}

void intercala (int v[], int inicio , int fim , int meio)
{
	int i;
	int inicioA1 = inicio;
	int inicioA2 = meio + 1;
	int posLivre = inicio;
	int aux[5];

	while(inicioA1 <= meio && inicioA2 <= fim)
	{
		if(v[inicioA1] > v[inicioA2])
		{
			aux[posLivre] = v[inicioA2];
			inicioA2++;
		}
		else
		{
			aux[posLivre] = v[inicioA1];
			inicioA1++;
		}

		posLivre++;

	} // Parte inicial do mergesort, aquela parte que serve pra poder verificar qual é maior que qual, dividir e organizar e termino do while

	
	// Inicio da parte de organizar as partes intercaladas
	for(i = inicioA1 ; i <= meio ; i++)
	{
		aux[posLivre] = v[i];
		posLivre++;
	}

	for(i = inicioA2; i <= fim; i++)
	{
		aux[posLivre] = v[i];
		posLivre++;
	}
	for(i = inicio; i <= fim ; i++)
	{
		v[i] = aux[i];
	}
}// Termino da parte de intercalar


int main()
{
	cout << "digite o valor " << endl;
	
	int A[5]; //= {1,0,4,5,2};  

	for(int i = 0 ; i < 5 ; i++)
	{
		cin >> A[i];
	}
	mergesort(A, 0, 4);

	for ( int i = 0 ; i < 5 ; i ++ )
	{
		cout << A[i] << endl;
	}

	return 0;
}


