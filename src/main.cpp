/**
* @file
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 13/06/2017
* @date --
* @sa --
*/

#include "header.h"
#include "natalia.h"
#include "testar_ordenacao.h"

void test_myLista();

/**
* @brief Função principal
*/
int main(int argc, char const *argv[])
{
	
	cout << "Iniciando testes da biblioteca..." << endl;
	/*
	cout << "Testando TADS:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "================ myLista ================="
	test_myLista();
	cout << "=======================================fim" << endl;
	cout << "================ myPilha ================="
	// test myPilha
	cout << "=======================================fim" << endl;
	cout << "================ myFila =================="
	// test myFila
	cout << "=======================================fim" << endl;
	cout << "================ myDeque ================="
	// test myDeque
	cout << "=======================================fim" << endl;
	cout << "============== myTabelaHash =============="
	// test myDeque
	cout << "=======================================fim" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------FIM-------------------------------------" << endl << endl;
	*/
	cout << "Testando algoritmos de ordenação:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	testar_ordenacao();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------FIM-------------------------------------" << endl << endl;

	cout << "Saindo do programa de testes..." << endl;
	return 0;
}