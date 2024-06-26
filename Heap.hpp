#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include <iostream>

using namespace std;

class Heap{
	public:
		//Heap();
		Heap(int );
		void insertar(int);
		int obtenerMax();
		void imprimir();
		void PostOrder();
		void InOrder();
		void PreOrder();
		void Anchura();
		int eliminar(int );
		
	
	private:
		int *H;
		int size=0;
		int maxtam;
		int Padre(int);
		int hijoI(int);
		int hijoD(int);
		void subir(int);
		void bajar(int);	
	    int PostORDER(int);
	    int InORDER(int );
	    int PreORDER(int );
};

#endif