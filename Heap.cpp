#include "Heap.hpp"

Heap::Heap(int tam){
	int Nodos;
	Nodos=ceil(log2(tam));
	this->maxtam=pow(2,Nodos)-1;//calculo de cantidad de nodos totales
	this->H=new int(this->maxtam);
}

void Heap::insertar(int v){
	if(this->size!=this->maxtam){ //se pregunta si esta lleno
		H[size]=v;//se inserta el elemento
	    subir(size);//se verifica que cumpla el heap
	    size++;//se incrementa la cantidad de nodos
	}else{
		cout<<"esta lleno"<<endl;
	}	
}



void Heap::subir(int i){
	int aux; //variable auxiliar para guardar el dato del padre
	while(i>=1 && (H[Padre(i)] < H[i])){ //se pregunta si es mayor a su  padre
		aux= H[Padre(i)];//se almacena el dato del padre
		H[Padre(i)]=H[i];//el padre agarra el valor del hijo
		H[(i)]=aux;//el hijo agarra el valor del padre
		i=Padre(i);//se pregunta si el padre cumple la condicion del heap
	}
}

int Heap::Padre(int i){
	return ((i-1)/2);
}// funcion para calcular la posicion del padre de i

int Heap::obtenerMax(){
	int max=H[0];//el maximo esta en la primera posicion
	H[0]=H[size-1];//se toma como referencia el ultimo dato 
	size=size-1;//se reduce la cantidad de nodos
	bajar(0);//se verifica la condicion del heap
	
	return max;
}

void Heap::bajar(int i){
int aux=H[i];
int Maxindex=i;
int n=this->size;
if(hijoI(i)<n && H[hijoI(i)]>H[Maxindex]){
	Maxindex=hijoI(i);
}
if(hijoD(i)<n && H[hijoD(i)]>H[Maxindex]){
	Maxindex=hijoD(i);
}
if(i!=Maxindex){
	H[i]=H[Maxindex];
	H[Maxindex]=aux;
	bajar(Maxindex);
}
}
int Heap::hijoI(int i){//funcion para calcular el hijo izquierdo de i
	return (2*i+1);
}

int Heap::hijoD(int i){//funcion para calcular el hijo derecho de i
	return (2*(i+1));
}

void Heap::imprimir(){//se imprime el heap en su forma normal de arreglo
	
	for(int i=0; i < size; i++){
		cout<<H[i]<<" ";
		cout<<endl;
	}
}
void Heap::PostOrder(){//funcion auxiliar donde se inicializa PostOrder
	
	PostORDER(0);
}
int Heap::PostORDER(int i){//implementacion del algoritmo
	
	if(i>=this->size){
		return i;
	}
	
	PostORDER(hijoI(i));
	
	PostORDER(hijoD(i));
	cout<<H[i]<<"  ";
	return i;
}
void Heap::InOrder(){//funcion auxiliar donde se inicializa InOrder
	InORDER(0);
}
int Heap::InORDER(int i){//implementacion del algoritmo
	if(i>=this->size){
		return i;
	}
	InORDER(hijoI(i));
	cout<<H[i]<<"  ";
	InORDER(hijoD(i));
	return i;
}
void Heap::PreOrder(){//funcion auxiliar donde se inicializa PreOrder
	PreORDER(0);
}
int Heap::PreORDER(int i){//implementacion del algoritmo
	if(i>=this->size){
		return i;
	}
	cout<<H[i]<<"  ";
	PreORDER(hijoI(i));
    PreORDER(hijoD(i));
	return i;
}
void Heap::Anchura(){// se recorre como un arreglo normal con estetica de niveles
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
	int E;//variable para retornar valor eliminado
	E=H[i];//se toma el valor eliminado
	H[i]=H[this->size-1];//se toma el valor del ultimo nodo
	this->size=size-1;//se reduce la cantidad de nodos en el heap
	subir(i);//se npregunta si necesita subir
	bajar(i);//se pregunta si necesita bajar
	return E;
	
}