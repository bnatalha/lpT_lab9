/**
* @file
* @brief Testes com myPilha.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 18/06/2017
* @date --
* @sa --
*/

#ifndef TESTAR_PILHA_H
#define TESTAR_PILHA_H

#include "natalia.h"

template <typename T >
void test_size_empty(edb1::myPilha<T>& test, const char queue_name);

template <typename T >
void try_top(edb1::myPilha<T>& test, const char queue_name);

template <typename T >
void try_pop(edb1::myPilha<T>& test, const char queue_name);

template <typename T >
void try_push(edb1::myPilha<T>& test, const char queue_name, const T element);

/**
* @brief Realiza testes com objetoss da classe myPilha
*/
void testar_lista()
{

	edb1::myLista<int> aaa;
	edb1::myLista<int> bbb;
	edb1::myLista<int> ccc;
	edb1::myLista<int> ddd;
	
	// preenchendo listas
	for (int i = 0; i <= 10; ++i)
	{
		aaa.push_back(i);
		if(i != 0 )ddd.push_back(i);
		else ddd.push_back(34);
		if(i%2 == 0) bbb.push_back(i);
	}
	
	ccc = aaa;

	// imprimindo listas
	cout << "aaa: [ ";
	for (auto &e : aaa)
		cout << e << " ";
	cout << "]" << endl;
	cout << "bbb: [ ";
	for (auto &e : bbb)
		cout << e << " ";
	cout << "]" << endl;
	cout << "ccc: [ ";
	for (auto &e : ccc)
		cout << e << " ";
	cout << "]" << endl;
		cout << "ddd: [ ";
	for (auto &e : ddd)
		cout << e << " ";
	cout << "]" << endl;

	// comparando listas
	cout << "aaa e bbb" << (aaa == bbb?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ccc" << (aaa == ccc?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ddd" << (aaa == ddd?" ":" não ") << "são iguais" << endl;	
}

/**
* @brief Imprime no terminal o tamanho de um objeto edb1::myPilha e se ele está vazio ou não.
* Testa edb1::myPilha<T>::size() e edb1::myPilha<T>::empty()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void test_size_empty(edb1::myPilha<T>& test, const char queue_name)
{
	cout << queue_name << ".size(): " << test.size() << "\t";
	cout << "'" << queue_name <<"'" << (test.empty()? "":" não") << " está vazia." << endl;
}

/**
* @brief Imprime no terminal o primeiro e ultimo elemento de um objeto edb1::myPilha, se não cair em uma exceção
* Testa edb1::myPilha<T>::front() e edb1::myPilha<T>::back()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_top(edb1::myPilha<T>& test, const char queue_name)
{
	// tenta acessar elemento da frente da fila
	try	{
		cout << queue_name << ".top(): " << test.top();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myPilha<T>::pop()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop(edb1::myPilha<T>& test, const char queue_name)
{
	// tenta remover o elemento mais velho da fila
	try	{
		cout << queue_name << ".pop();" << endl;
		test.pop();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa edb1::myPilha<T>::push()
* @param test Referência para um objeto edb1::myPilha
* @param queue_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push(edb1::myPilha<T>& test, const char queue_name, const T element)
{
	// tenta colocar um elemento ao fim da fila
	try	{
		cout << queue_name << ".push("<< element << ");" << endl;
		test.push(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

#endif