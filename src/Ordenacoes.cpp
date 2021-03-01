#include "Ordenacoes.h"

void Ordenacoes::ReverterVetor(string* lines, int tam)
{
	string* aux;
	aux = new string[tam];
	for (int i = 0; i < tam; i++)
	{
		aux[i] = lines[i];
	}
	int j = tam - 1;
	for (int i = 0; i < tam; i++)
	{
		lines[i] = aux[j]; 
		j--;
	}
	free(aux);
}

#pragma region Insertion
void Ordenacoes::InsertionSort(ifstream* FileToOrder, int NumbersToTest, string* lines)
{
	int numbers[NumbersToTest];
	int n;
	// passa a infomação do arquivo para os vetores
	for (n = 0; n < NumbersToTest; n++)
	{
		*FileToOrder >> lines[n] >> numbers[n];
		lines[n].append(" ");
		lines[n].append(to_string(numbers[n]));
	}
	// inicio InsertionSort
	int i, j;
	int aux;
	string aux2;
	for (i = 1; i < n; i++)
	{
		aux = numbers[i];
		aux2 = lines[i];
		j = i - 1;
		while ((j >= 0) && aux < numbers[j])
		{
			numbers[j + 1] = numbers[j];
			lines[j + 1] = lines[j];
			j--;
		}
		numbers[j + 1] = aux;
		lines[j + 1] = aux2;
	}

	ReverterVetor(lines, NumbersToTest);
}
#pragma endregion

#pragma region Merge
void Ordenacoes::Merge(string* lines, string* StringAux, int* saida, int* auxiliar, int inicio, int meio, int fim) {
	int i, j, k;
	i = inicio;
	j = meio + 1;
	k = inicio;
	while (i <= meio && j <= fim) {
		if (auxiliar[i] < auxiliar[j]) {
			saida[k] = auxiliar[i];
			lines[k] = StringAux[i];
			i++;
		}
		else {
			saida[k] = auxiliar[j];
			lines[k] = StringAux[j];
			j++;
		}
		k++;
	}

	while (i <= meio) {
		saida[k] = auxiliar[i];
		lines[k] = StringAux[i];
		i++;
		k++;
	}

	while (j <= fim) {
		saida[k] = auxiliar[j];
		lines[k] = StringAux[j];
		j++;
		k++;
	}
	//Copia os elementos que foram ordenados para o auxiliar
	for (int p = inicio; p <= fim; p++)
	{
		auxiliar[p] = saida[p];
		StringAux[p] = lines[p];
	}
}

void Ordenacoes::MergeSort_Implementation(string* lines, string* StringAux, int* saida, int* auxiliar, int inicio, int fim) {
	if (inicio < fim) {
		int meio = (inicio + fim) / 2;
		MergeSort_Implementation(lines, StringAux, saida, auxiliar, inicio, meio);
		MergeSort_Implementation(lines, StringAux, saida, auxiliar, meio + 1, fim);
		Merge(lines, StringAux, saida, auxiliar, inicio, meio, fim);
	}
}

void Ordenacoes::MergeSort(ifstream* FileToOrder, int NumbersToTest, string* lines)
{
	int numbers[NumbersToTest];
	int n;
	// passa a infomação do arquivo para os vetores
	for (n = 0; n < NumbersToTest; n++)
	{
		*FileToOrder >> lines[n] >> numbers[n];
		lines[n].append(" ");
		lines[n].append(to_string(numbers[n]));
	}

	// declara variaveis auxiliares
	int auxiliar[NumbersToTest];
	for (int i = 0; i < NumbersToTest; i++)
	{
		auxiliar[i] = numbers[i];
	}
	string* StringAux;
	StringAux = new string[NumbersToTest];
	for (int i = 0; i < NumbersToTest; i++)
	{
		StringAux[i] = lines[i];
	}
	MergeSort_Implementation(lines, StringAux, numbers, auxiliar, 0, n-1);
	ReverterVetor(lines, NumbersToTest);
	free(StringAux);
}
#pragma endregion

#pragma region QuickSort
void Ordenacoes::QuickSort_Implementation(string* lines, int values[], int began, int end)
{
	int i, j, pivo, aux;
	string aux2;
	i = began;
	j = end - 1;
	pivo = values[(began + end) / 2];
	while (i <= j)
	{
		while (values[i] < pivo && i < end)
		{
			i++;
		}
		while (values[j] > pivo && j > began)
		{
			j--;
		}
		if (i <= j)
		{
			aux = values[i];
			aux2 = lines[i];
			values[i] = values[j];
			lines[i] = lines[j];
			values[j] = aux;
			lines[j] = aux2;
			i++;
			j--;
		}
	}
	if (j > began)
		QuickSort_Implementation(lines, values, began, j + 1);
	if (i < end)
		QuickSort_Implementation(lines, values, i, end);
}

void Ordenacoes::QuickSort(ifstream* FileToOrder, int NumbersToTest, string* lines)
{
	int numbers[NumbersToTest];
	int n;
	// passa a infomação do arquivo para os vetores
	for (n = 0; n < NumbersToTest; n++)
	{
		*FileToOrder >> lines[n] >> numbers[n];
		lines[n].append(" ");
		lines[n].append(to_string(numbers[n]));
	}
	QuickSort_Implementation(lines, numbers, 0, NumbersToTest);
	ReverterVetor(lines, NumbersToTest);
}
#pragma endregion

#pragma region QuickSortModificado
void Ordenacoes::QuickSortModificado_Implementation(string* lines, int values[], int began, int end)
{
	int i, j, pivo, aux;
	string aux2;

	// pivo sendo mediana de 3
	// if para garantir que meio0, meio e meio1 existem
	if (end > 1)
	{
		int meio0 = values[((began + end) / 2) - 1];
		int meio = values[(began + end) / 2];
		int meio1 = values[((began + end) / 2) + 1];
		if (meio > meio0)
		{
			// se meio for a mediana
			if (meio < meio1)
			{
				pivo = meio;
			}
			// se meio for o maior
			else
				pivo = meio0 > meio1 ? meio0 : meio1;
		}
		else if (meio > meio1)
		{
			// se meio for a mediana
			if (meio < meio0)
			{
				pivo = meio;
			}
			// se meio for o maior
			else
				pivo = meio1 > meio0 ? meio1 : meio0;
		}
		// se meio for o menor
		else
		{
			pivo = meio1 > meio0 ? meio0 : meio1;
		}
	}
	else pivo = values[(began + end) / 2];

	i = began;
	j = end - 1;
	while (i <= j)
	{
		while (values[i] < pivo && i < end)
		{
			i++;
		}
		while (values[j] > pivo && j > began)
		{
			j--;
		}
		if (i <= j)
		{
			aux = values[i];
			aux2 = lines[i];
			values[i] = values[j];
			lines[i] = lines[j];
			values[j] = aux;
			lines[j] = aux2;
			i++;
			j--;
		}
	}
	if (j > began)
		QuickSortModificado_Implementation(lines, values, began, j + 1);
	if (i < end)
		QuickSortModificado_Implementation(lines, values, i, end);
}

void Ordenacoes::QuickSortModificado(ifstream* FileToOrder, int NumbersToTest, string* lines)
{
	int numbers[NumbersToTest];
	int n;
	// passa a infomação do arquivo para os vetores
	for (n = 0; n < NumbersToTest; n++)
	{
		*FileToOrder >> lines[n] >> numbers[n];
		lines[n].append(" ");
		lines[n].append(to_string(numbers[n]));
	}
	QuickSortModificado_Implementation(lines, numbers, 0, NumbersToTest);
	ReverterVetor(lines, NumbersToTest);
}
#pragma endregion

void Ordenacoes::GnomeSort(ifstream* FileToOrder, int NumbersToTest, string* lines)
{
	int numbers[NumbersToTest];
	int n;
	// passa a infomação do arquivo para os vetores
	for (n = 0; n < NumbersToTest; n++)
	{
		*FileToOrder >> lines[n] >> numbers[n];
		lines[n].append(" ");
		lines[n].append(to_string(numbers[n]));
	}

	// inicio GnomeSort
	int i = 1;
	int aux;
	string aux2;
	while (i < NumbersToTest)
	{
		if (i == 0 || numbers[i - 1] <= numbers[i])
		{
			i++;
		}
		else
		{
			aux = numbers[i - 1];
			numbers[i - 1] = numbers[i];
			numbers[i] = aux;
			aux2 = lines[i - 1];
			lines[i - 1] = lines[i];
			lines[i] = aux2;
			--i;
		}
	}
	ReverterVetor(lines, NumbersToTest);
}
