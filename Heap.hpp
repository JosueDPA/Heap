#ifndef HEAP_H
#define HEAP_H
#include <math.h>
#include <iostream>

using namespace std;

class Heap{
	public:
		//Heap();
		Heap(int );
		void insertar(int);
		int obtenerMax();
		void imprimir();
		int getPadre(int );
		int getElemento(int );
		int getI(int);
		int getD(int);
		int getSize();
		void PostOrder();
		void InOrder();
		void PreOrder();
		void Anchura();
		
	
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