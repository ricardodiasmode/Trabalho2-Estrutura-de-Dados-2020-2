#ifndef ORDENACOES_H
#define ORDENACOES_H

#include <stdio.h>
#include "string.h"
#include <fstream>
#include <iostream>

using namespace std;

class Ordenacoes 
{
public:
    static void ReverterVetor(string* lines, int tam);

    static void InsertionSort(ifstream* FileToOrder, int NumbersToTest, string* lines);
    
    // MergeSort functions
    static void Merge(string* lines, string* StringAux, int* saida, int* auxiliar, int inicio, int meio, int fim);
    static void MergeSort_Implementation(string* lines, string* StringAux, int* saida, int* auxiliar, int inicio, int fim);
    static void MergeSort(ifstream* FileToOrder, int NumbersToTest, string* lines);
   
    static void QuickSort_Implementation(string* lines, int values[], int began, int end);
    static void QuickSort(ifstream* FileToOrder, int NumbersToTest, string* lines);
    
    // A modificacao aqui foi pegar a mediana de 3
    static void QuickSortModificado_Implementation(string* lines, int values[], int began, int end);
    static void QuickSortModificado(ifstream* FileToOrder, int NumbersToTest, string* lines);
    
    static void GnomeSort(ifstream* FileToOrder, int NumbersToTest, string* lines);

};

#endif