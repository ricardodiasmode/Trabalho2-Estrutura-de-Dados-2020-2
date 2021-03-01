
#include "Ordenacoes.h"
#include "string.h"
#include <time.h> 
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) 
{
    using namespace std;

    ifstream InfoFile (argv[1]);
    if (!InfoFile)
    {
        cout << "Impossivel abrir info file";
        return -1;
    }
    // Declarando variavel para contagem de tempo
    clock_t inicio = clock();
    string* SortedArray;
    SortedArray = new string[stoi(argv[2])];

    cout << "Aguarde estou realizando a ordenacao..." << endl;
    //Ordenacoes::InsertionSort(&InfoFile, stoi(argv[2]), SortedArray);
    //Ordenacoes::MergeSort(&InfoFile, stoi(argv[2]), SortedArray);
    //Ordenacoes::QuickSort(&InfoFile, stoi(argv[2]), SortedArray);
    //Ordenacoes::QuickSortModificado(&InfoFile, stoi(argv[2]), SortedArray);
    //Ordenacoes::GnomeSort(&InfoFile, stoi(argv[2]), SortedArray);

    clock_t agora = clock() - inicio;

    // printing sorted array
    /*for (int i = 0; i < stoi(argv[2]); i++)
    {
        cout << SortedArray[i] << endl;
    }*/
    cout << "Tempo para ordenar: " << (double)agora / CLOCKS_PER_SEC << " milisegundos." << endl;
    InfoFile.close();
    if(SortedArray) free(SortedArray);
    return 0;
}