#include "Heap.hpp"

Heap::Heap(int tam){
	int aux;
	aux=ceil(log2(tam));
	this->maxtam=pow(2,aux)-1;
	this->H=new int(this->maxtam);
}

void Heap::insertar(int v){
	if(this->size!=this->maxtam){
		H[size]=v;
	    subir(size);
	    size++;
	}else{
		cout<<"esta lleno"<<endl;
	}
	
}



void Heap::subir(int i){
	int aux;
	while(i>=1 && (H[Padre(i)] < H[i])){
		aux= H[Padre(i)];
		H[Padre(i)]=H[i];
		H[(i)]=aux;
		i=Padre(i);
	}
}

int Heap::Padre(int i){
	return ((i-1)/2);
}

int Heap::obtenerMax(){
	int max=H[0];
	H[0]=H[size-1];
	size=size-1;
	bajar(0);
	
	return max;
}

void Heap::bajar(int i){
int aux1=i;
int aux2=i;	
int max;
int L=hijoI(i);
int R=hijoD(i);
int aux;

if(L < size && H[L] >= H[aux1]){
	aux1=L;
}

if(R < size && H[R] >= H[aux2]){
	aux2=R;
}

if(aux1 == i && aux2!=i){
	aux= H[i];
	H[i]= H[aux2];
	H[aux2]= aux;
	
	bajar(aux2);
	}
if(aux1 != i && aux2==i){
	aux= H[i];
	H[i]= H[aux1];
	H[aux1]= aux;
	
	bajar(aux1);
	}

if(aux1 != i && aux2!=i){
	if(H[aux1]>=H[aux2]){
		max=aux1;
	}else{
		max=aux2;
	}
	aux= H[i];
	H[i]= H[max];
	H[max]=aux;
	
	bajar(max);
}
if(aux1==i && aux2==i){
	cout<<"arbol vacio"<<endl;
}
}
int Heap::hijoI(int i){
	return (2*i+1);
}

int Heap::hijoD(int i){
	return (2*(i+1));
}

void Heap::imprimir(){
	
	for(int i=0; i < size; i++){
		cout<<H[i]<<" ";
		cout<<endl;
	}
}

int Heap::getPadre(int i){
	return H[Padre(i)];
}
int Heap::getElemento(int i){
	return H[i];
}
int Heap::getI(int i){
	if(2*i+1>=size){
		cout<<"no tiene hijo izquierdo"<<endl;
		return i;
	}else{
		return H[2*i+1];
	}
}
int Heap::getD(int i){
	if(2*(i+1)>=size){
		cout<<"no tiene hijo derecho"<<endl;
		return i;
	}else{
		return H[2*(i+1)];
	}
}
int Heap::getSize(){
	return this->size;
}
void Heap::PostOrder(){
	
	PostORDER(0);
}
int Heap::PostORDER(int i){
	
	if(i>=this->size){
		return i;
	}
	
	PostORDER(hijoI(i));
	
	PostORDER(hijoD(i));
	cout<<H[i]<<"  ";
	return i;
}
void Heap::InOrder(){
	InORDER(0);
}
int Heap::InORDER(int i){
	if(i>=this->size){
		return i;
	}
	InORDER(hijoI(i));
	cout<<H[i]<<"  ";
	InORDER(hijoD(i));
	return i;
}
void Heap::PreOrder(){
	PreORDER(0);
}
int Heap::PreORDER(int i){
	if(i>=this->size){
		return i;
	}
	cout<<H[i]<<"  ";
	PreORDER(hijoI(i));
    PreORDER(hijoD(i));
	return i;
}
void Heap::Anchura(){
	int l=0;
	int aux=0;
	cout<<" || ";
	for(int i=0;i<this->size;i++){
		
		   if(i<pow(2,l)+aux){
			  cout<<H[i]<<" ";
		   }else{
		   	cout<<" || "<<endl;
			   cout<<" || "<<H[i]<<" ";
			   aux=i;
			   l=l+1;
		   }	
		}
		
		
	

}
int Heap::eliminar(int i){
	int E;
	E=H[i];
	H[i]=H[this->size-1];
	this->size=size-1;
	subir(i);
	bajar(i);
	return E;
	
}