#include "Heap.hpp"
#include <iostream>

using namespace std;
int main(){
	int n=10;
	int l=4;
	int A[n]={90,75,100,60,65,95,92,1,2,3};
	
	
	Heap H(n);
	for(int i=0;i<n;i++){
		H.insertar(A[i]);
	}
    H.imprimir();
    
    /*cout<<"ingrese el nodo para calcular su padre"<<endl;
    cout<<"error aqui"<<endl;
    cout<<"el hijo de "<<H.getElemento(l)<<"  es "<<H.getI(l)<<endl;
    cout<<"el tamaño del arbol es "<<H.getSize()<<endl;
    cout<<H.getElemento(9)<<endl;
    
   H.obtenerMax();
   cout<<endl;
   H.imprimir();
   cout<<"el tamaño del arbol es "<<H.getSize()<<endl;*/
   cout<<"*****************************************************"<<endl;
   cout<<endl;
   H.Anchura();
    
return 0;
}