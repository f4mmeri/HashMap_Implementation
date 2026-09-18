#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Queue{
    private:
        T* array;
        int frente, rear, tamaño, capacidad;
    public:
    
        Queue(): array(new T[100000]), frente(0), rear(0), tamaño(0), capacidad(100000){}
        Queue(int valor): array(new T[valor]), frente(0), rear(0), tamaño(0), capacidad(valor){}

        bool empty(){
            return tamaño==0;
        }

        int size(){
            return tamaño;
        }

        T front(){
            if(tamaño==0){
                throw runtime_error("La cola es vacia");
            }
            return array[(frente+1)%capacidad];
        }

        T back(){
            if(tamaño==0){
                throw runtime_error("La cola es vacia");
            }
            return array[rear];
        }

        void push(T valor){
            if((rear+1)%capacidad!=frente){
                rear = (rear+1) % capacidad;
                array[rear] = valor;
                tamaño++;
            }
            else{
                throw runtime_error("La cola esta llena");
            }

        }

        void pop(){
            if(frente!=rear){
                frente = (frente+1)%capacidad;
                tamaño--;
            }
            else{
                throw runtime_error("La cola esta vacia");
            }
            
        }

        ~Queue(){delete[] array;}
};
