/**
* @file
* @brief Implementação dos algoritmos do namespace natalia.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 26/03/2017
* @date 15/06/2017
* @sa --
*/

#include "natalia.h"

namespace edb1
{
	/**
	* @brief Pega duas variáveis int por referência os valores delas entre sí
	* @param a variável a ter seu valor trocado
	* @param b variável a ter seu valor trocado
	*/
	void mySwap( int &a, int &b){
	    int temp = a;
	    a = b;
	    b = temp;
	}

	/**
	* @brief Checa se o primeiro inteiro passado é maior do que o segundo
	* @param a primeiro inteiro
	* @param b segundo inteiro
	* @return 'true' se a' for maior do que 'b' e 'false' caso contrário
	*/
	bool maiorque(int a, int b) { return (a > b); }

	/**
	* @brief Checa se o primeiro inteiro passado é menor do que o segundo
	* @param a primeiro inteiro
	* @param b segundo inteiro
	* @return 'true' se a' for menor do que 'b' e 'false' caso contrário
	*/
	bool menorque(int a, int b) { return (a < b); }

	/**
	* @brief Simula o bubble sort, ordenando um array de int o deixando crescente.
	* @param v arranjo de initeiros que receberá a ordenação
	* @param ini posição inicial do arranjo
	* @param fim posição final do arranjo
	*/
	void myBubbleSort (int *v, int ini, int fim){
		// fim < ini 	(vazio)
		// fim == 0 	(um elemento)

		for ( 	; fim > ini ; fim--){
			for (int first = ini; first < fim; first++){
				if( maiorque( v[first], v[first+1] ) ) mySwap( v[first], v[first+1]);
			}
		}
	}

	/**
	* @brief Simula o insertion sort, ordenando um array de int o deixando crescente.
	* @param v arranjo de initeiros que receberá a ordenação
	* @param ini_plus1 posição inicial do arranjo + 1
	* @param fim posição final do arranjo
	*/
	void myInsertSort (int *v, int ini, int fim){ //Insert na head
		// ini+1 > fim 	(vazio)
		// fim == ini+1 	(um elemento)

		for ( 	; ini+1 <= fim ; ini++)
			for (int ord = ini+1;	ord > 0 and v[ord] < v[ord-1];	 ord--)
				mySwap( v[ord], v[ord-1]);
	}

	/**
	* @brief Simula o selection sort, ordenando um array de int o deixando crescente.
	* @param v arranjo de initeiros que receberá a ordenação
	* @param ini posição inicial do arranjo
	* @param fim posição final do arranjo
	*/
	void mySelectionSort (int *v, int ini, int fim){ //Retorna crescente
		for ( ; ini < fim; ini++)
			for (int ii = ini+1;		ii <= fim;	ii++)
				if( v[ini] > v[ii] ) mySwap( v[ini], v[ii]);
	}

	/**
	* @brief Cria as partições que serão utilizadas por myQuickSort
	* @param v arranjo de initeiros que receberá a ordenação
	* @param ini posição inicial do arranjo
	* @param fim posição final do arranjo
	*/
	int myQuickSortPartition(int *v, int ini, int fim){
		int myPivot = ini;

		for ( int menor = myPivot+1, Maior = fim; Maior >= menor ; )
		{
			if( v[menor]  >=  v[Maior] and menor != Maior ) mySwap( v[menor], v[Maior]);
			if( v[myPivot]>=  v[menor] )
			{
				mySwap( v[menor], v[myPivot]);
				menor++;
				myPivot++;
			}
			if( v[myPivot]<  v[Maior] ) Maior--;
		}

		return myPivot;
	}

	/**
	* @brief Simula o quick sort, ordenando um arranjo de int o deixando crescente.
	* @param v arranjo de initeiros que receberá a ordenação
	* @param ini posição inicial do arranjo
	* @param fim posição final do arranjo
	*/
	void myQuickSort (int *v, int ini, int fim){
		if( ini < fim and ini >= 0){
			int p = myQuickSortPartition(v,ini,fim);
			myQuickSort(v, ini, p-1);
			myQuickSort(v, p+1, fim);
		}
	}

	/**
	* @brief Simula o merge sort, que faz um arranjo ordenado de dois arranjos ordenados,
	* @oaram dir um dos arranjos que será usado para fazer o arranjo ordenado (o da dierita)
	* @param d_size tamanho de 'dir'
	* @oaram esq um dos arranjos que será usado para fazer o arranjo ordenado (o da esquerda)
	* @param e_size tamanho de 'esq'
	* @param v arranjo de initeiros que receberá a ordenação
	* @param fim posição final do arranjo 'v'
	*/
	void myMergeSort (int *dir, int d_size, int *esq, int e_size, int *v, int fim){
		for (int i = d_size-1, j = e_size-1; 	j >= 0 or i >= 0; )
		{
			// pra não comparar com índices negativos. se outro vetor ja acabou
			if		( dir[i] >  esq[j] or j < 0 ) v[fim--] = dir[i--]; 
			else if ( dir[i] <= esq[j] or i < 0 ) v[fim--] = esq[j--];
		}
	}

	/**
	* @brief Simula o Split sort, dividindo um arranjo em duas partes até não poder mais para começar a uní-las novamente com o merge sort
	* @oaram 
	* @param v arranjo de initeiros que receberá a ordenação
	* @param ini posição inicial do arranjo
	* @param fim posição final do arranjo 'v'
	*/
	void mySplitSort (int *v, int ini, int fim){
		int size = 1 + fim - ini;
		if( size > 1 ){

			int size_direita = (size/2) + (size%2); //direita sempre maior para ini = 0 e fim = par.
			int size_esquerda = (size/2);
			int *direita = new int[ size_direita ];
			int *esquerda = new int[ size_esquerda ];

			for (int i = 0, e = 0, d = 0; i <= fim; ++i)
			{
				if(i <= (fim-ini)/2 ) direita[d++] = v[i];	//fim = par, dir(fim) = par e dir > esq
				else esquerda[e++] = v[i];
			}

			mySplitSort(direita,  0, size_direita-1 );
			mySplitSort(esquerda, 0, size_esquerda-1 );

			myMergeSort(direita, size_direita, esquerda, size_esquerda, v, fim);

			delete[] direita;
			delete[] esquerda;
		}
	}
}