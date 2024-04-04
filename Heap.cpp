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
//variables de cambio para condicionales
int l=i;
int r=i;
	
int max;//variable de condicional
int L=hijoI(i);//calculo de posicion de hijo izquierdo si existe
int R=hijoD(i);//calculo de posicion de hijo derecho si existe
int aux;//variable auxiliar

if(L < size && H[L] >= H[l]){ // se pregunta si el hijo izquierdo existe y si es mayor a nuestro nodo actual
	l=L;//se cambia l con la nocion de posible cambio en el hijo izquierdo	
}

if(R < size && H[R] >= H[r]){// se pregunta si el hijo derecho existe y si es mayor a nuestro nodo actual
	r=R;//se cambia r con la nocion de posible cambio en el hijo derecho
}

if(l == i && r!=i){//este es para cuando el hijo derecho existe y es mayor al padre
	aux= H[i];//toma el valor del padre
	H[i]= H[r];//padre toma valor del hijo
	H[r]= aux;//hijo toma valor del padre
	
	bajar(r);//se verifica la condicion de heap con el hijo
	}
    if(l != i && r==i){//este es para cuando el hijo izquierdo existe y es mayor al padre
	   aux= H[i];//toma el valor del padre
	   H[i]= H[l];//padre toma valor del hijo
	   H[l]= aux;//hijo toma valor del padre
	   
	   bajar(l);//se verifica la condicion de heap con el hijo
	}

   if(l != i && r!=i){// este es para el caso que los dos hijos existen y los dos son mayores que el padre
	  if(H[l]>=H[r]){//se calcula cual es mayor
		  max=l;
	   }else{
		  max=r;
	   }//anterior se toma la posicion del maximo
	  aux= H[i];//toma el valor del padre
	  H[i]= H[max];//toma el valor del maximo de los hijos
	  H[max]=aux;//el hijo que se reemplazo toma el valor del padre
	  
	  bajar(max);//se verifica la condion del heap con el hijo
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