#include "Heap.hpp"
#include <iostream>

using namespace std;
int main(){
	int n=6;
	int l=4;
	int A[n]={90,75,100,60,65,95};
	
	
	Heap H(n);
	for(int i=0;i<n;i++){
		H.insertar(A[i]);
	}
    H.imprimir();
    
    cout<<"**********************************************************"<<endl;
    cout<<endl;
    
   H.obtenerMax();
   cout<<endl;
   H.imprimir();
   cout<<"*****************************************************"<<endl;
   H.insertar(92);
   H.imprimir();
   H.insertar(34);
   H.Anchura();
   cout<<endl;
   cout<<"*****************************************************"<<endl;
   H.eliminar(2);
   H.Anchura();
return 0;
}