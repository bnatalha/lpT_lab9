#ifndef TESTAR_ORDENACAO_H
#define TESTAR_ORDENACAO_H

//#include <random>		// for std::default_random_engine and std::uniform_int_distribution;
#include <ctime>
#include "natalia.h"

void fillVector(int *v, int N);	/**< Preenche um arranjo de inteiros com valores aleatórios entre 0 e 30. */
void printVector(int *v, int N);	/**< Imprime o conteúdo de um arranjo de inteiros no terminal (cout) */
void sort_test(int *v, int N, void (*alg_sort) (int*,int,int) );	/**< Preenche um arranjo de inteiros com valores aleatorios e depois os ordena utilizando uma função sort */

void testar_ordenacao( )	
{

	// Teste com arranjos de tamanho 0, 1, 2, 3, 16 e 17.
	
	// tamanhos
	//int size_0 = 0 ;		/**< Aloca o tamanho do vetor */
	//int size_1 = 1 ;		/**< Aloca o tamanho do vetor */
	//int size_2 = 2 ;		/**< Aloca o tamanho do vetor */
	//int size_3 = 3 ;		/**< Aloca o tamanho do vetor */
	//int size_16 = 16 ;		/**< Aloca o tamanho do vetor */
	//int size_17 = 17 ;		/**< Aloca o tamanho do vetor */

	int sizes[6] = {0, 1, 2, 3, 16, 17};
	//				0  1  2  3   4   5
	
	// arranjos dinâmicos
	cout << "Alocando arranjos dinamicamente (tamanhos: 0, 1, 2, 3, 16 e 17)...";
	
	int** arrays = new int*[6];

	//int* a_0 = new int [size_0];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '0' */
	//int* a_1 = new int [size_1];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '1' */
	//int* a_2 = new int [size_2];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '2' */
	//int* a_3 = new int [size_3];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '3' */
	//int* a_16 = new int [size_16];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '32' */
	//int* a_17 = new int [size_17];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '17' */

	arrays[0] = new int [sizes[0]];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '0' */
	arrays[1] = new int [sizes[1]];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '1' */
	arrays[2] = new int [sizes[2]];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '2' */
	arrays[3] = new int [sizes[3]];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '3' */
	arrays[4] = new int [sizes[4]];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '32' */
	arrays[5] = new int [sizes[5]];	/**< Arranjo de inteiros dinamicamente alocado de tamanho '17' */

	cout << "Pronto." << endl;

	for(auto i = 0; i < 6; i++)
	//for(auto i = 2; i ==2; i++)
	{
		cout << "=======================================================================================" << endl;
		cout << " Testes com vetor de tamanho: ( " << sizes[i] << " )" << endl;
	/*	cout << "---------------- myBubbleSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myBubbleSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- myInsertSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myInsertSort);
		cout << "---------------------------------------------" << endl;
	*/	cout << "---------------- mySelectionSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::mySelectionSort);
		cout << "---------------------------------------------" << endl;
	/*	cout << "---------------- myQuickSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myQuickSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- mySplitSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::mySplitSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- myInsertSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myBubbleSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- myInsertSort----------------" << endl;
		sort_test(arrays[i], sizes[i], edb1::myBubbleSort);
		cout << "---------------------------------------------" << endl;
	*/	cout << "=======================================================================================" << endl;
	}

	cout << "Deletando arranjos alocados dinamicamente. " << endl;
	for (int i = 0; i < 6; i++) delete[] arrays[i];
	delete[] arrays;


}

/**
* @param v arranjo de inteiros a ser preenchido
* @param N tamanho do arranjo a ser preenchido
*/
void fillVector(int *v, int N)
{	
	srand (time(NULL));		// Usa o tempo de máquina atual como semente para gerar rand()

	for (int i = 0; i < N; ++i) v[i] = rand() % 31;	// Atribui a cada posição 'i' um valor aleatório que pertença a [0,30]
}

/**
* @param v arranjo de inteiros a ser impresso
* @param N tamanho do arranjo a ser impresso
*/
void printVector(int *v, int N)
{
	cout << "Arranjo: [ ";
	for (int i = 0; i < N; ++i) cout << v[i] << " ";
	cout << "]";
}

/**
* @param v arranjo de inteiros
* @param N tamanho do arranjo
* @param alg_sort ponteiro para a função de ordenação a ser utilizada
*/
void sort_test(int *v, int N, void (*alg_sort) (int*,int,int) )
{
	cout << "Preenchendo meu arranjo de inteiros com valores aleatorios...";
	fillVector(v,N);	// Preenche arranjo com valores aleatorios entre 0 e 30.

	cout << "Pronto." << endl;
	printVector(v,N);	// Mostra o conteudo do arranjo gerado aleatoriamente no terminal.

	cout << endl << "Ordenando arranjo...";
	alg_sort( v, 0, N-1);	// Ordena o arranjo usando o algoritmo escolhido.

	cout << "Pronto." << endl;
	printVector(v,N);	// Mostra o conteudo do arranjo após ter sido oredenado.
	cout << endl;
}

#endif