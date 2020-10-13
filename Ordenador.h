#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include "time.h"

using namespace std;

/*
Tarea I - Algoritmos de Ordenamiento
Hecho por: Sebastian Montero Castro - B95016
Algoritmos sacados de "Introduction to Algorithms" por Thomas H. Cormen et al.
*/
class Ordenador{
    private:
        void verifyOrder(int * sortedArray, int tamano){
            //printArreglo(sortedArray,tamano);
            bool sortedProperly = true;
            for(int i = 1; i < tamano; i++){
                if(sortedArray[i] < sortedArray[i-1]){
                    sortedProperly = false;
                }
            }
            std::cout << ((sortedProperly == true) ? "Funciona\n" : "Fallo\n");
        }
        void printArreglo(int * sortedArray, int tamano){
            for(int i = 0; i < tamano; i++){
                std::cout << sortedArray[i] << ((i == tamano-1) ? "\n" : ", ");
            }
        }
        void merge(int * arreglo, int p, int q, int r){ //METODO CON LA LOGICA DEL MERGE SACADO DEL LIBRO
            int n1 = q - p + 1;
            int n2 = r - q;
            int IZQ[n1+1], DER[n2+1], i, j; //subarreglo izquierdo y derecho

            for(i = 0; i < n1; i++){
                IZQ[i] = arreglo[p+i];
            }
            i = 0;

            for(j = 0; j < n2 ; j++){
                DER[j] = arreglo[q+j+1];
            }
            j = 0;

            IZQ[n1] = 2147483647; //Valor maximo de entero en C++
            DER[n2] = 2147483647;
            
            for(int k = p; k <= r; k++){
                if(IZQ[i] < DER[j]){
                    arreglo[k] = IZQ[i];
                    i++;
                }else{
                    arreglo[k] = DER[j];
                    j++;
                }
            }
        }
        void startSorting(int * arreglo, int primero, int ultimo){
            if(primero<ultimo){
                int mitad = (primero+ultimo)/2;
                
                startSorting(arreglo,primero,mitad); //llamado recursivo de la mitad izquierda del arreglo
                startSorting(arreglo,mitad+1,ultimo); //llamado recursivo de la mitad derecha del arreglo
                merge(arreglo,primero,mitad,ultimo);
            }
        }
        void maxHeapify(int * arreglo, int indice, int tamano){
            int IZQ = 2 * indice + 1;
            int DER = 2 * indice + 2;
            int largest = indice;
            if((IZQ < tamano) && (arreglo[IZQ] > arreglo[largest])){
                largest = IZQ;
            }
            if((DER < tamano) && (arreglo[DER] > arreglo[largest])){
                largest = DER;
            }
            if(largest != indice){
                int aux = arreglo[indice];
                arreglo[indice] = arreglo[largest];
                arreglo[largest] = aux;
                maxHeapify(arreglo,largest,tamano);
            }
        }
        void buildMaxHeap(int * arreglo, int tamano){
            for(int i = (tamano/2); i >= 0; i--){
                maxHeapify(arreglo,i,tamano);
            }
        }
        int partition(int * arreglo, int p, int tamano){
            int x = arreglo[tamano];
            int i = p - 1;
            int aux;
            for(int j = p; j < tamano; j++){
                if(arreglo[j] <= x){
                    i += 1;
                    aux = arreglo[i];
                    arreglo[i] = arreglo[j];
                    arreglo[j] = aux;
                }
                
            }
            aux = arreglo[i+1];
            arreglo[i+1] = arreglo[tamano];
            arreglo[tamano] = aux;
            return i+1;
        }
        void beginQuickSort(int * arreglo, int p, int tamano){
            if(p < tamano){
                int q = partition(arreglo,p,tamano);
                beginQuickSort(arreglo,p,q-1); //Particiona el arreglo y llama recursivamente ambas partes del arreglo
                beginQuickSort(arreglo,q+1,tamano);
            }
        }
        int obtenerMayor(int * arreglo, int tamano){
            int max = arreglo[0];
            for(int i = 1; i < tamano;i++){
                if(arreglo[i]>max){
                    max = arreglo[i];
                }
            }   
            return max;
        }
        void radixCount(int * arreglo, int digito, int tamano, int base){
            int contadores[base] = {0};
            int copiaArreglo[tamano];
            
            for(int j = 0; j < tamano; j++){
                contadores[(arreglo[j]/digito)%base ]++;
            }
            for(int i = 1; i < base; i++){
                contadores[i]+= contadores[i-1];
            }
            for(int j = tamano-1 ; j>=0; j--){
                copiaArreglo[contadores[(arreglo[j]/digito)%base ] -1] = arreglo[j];
                contadores[ (arreglo[j]/digito)%base ]--;
            }
            for(int i = 0; i < tamano; i++){
                arreglo[i] = copiaArreglo[i];
            }
        }
        
    public:
        Ordenador(){};
        ~Ordenador(){};

        void seleccion(int * arreglo, int tamano){
            int indiceMenor;
            int temp;
            for(int i = 0; i < tamano; i++){
                indiceMenor = i;
                for(int j = i+1; j < tamano; j++){
                    if(arreglo[j] < arreglo[indiceMenor]){
                        indiceMenor = j;
                    }
                }
                temp = arreglo[i];
                arreglo[i] = arreglo[indiceMenor];
                arreglo[indiceMenor] = temp;
            }
            verifyOrder(arreglo,tamano);
        }
        void insercion(int * arreglo, int tamano){
            for(int i = 1; i < tamano; i++){
                int temp = arreglo[i];
                int j = i-1;
                while(j >= 0 && arreglo[j] > temp){
                    arreglo[j+1] = arreglo[j];
                    j -= 1;
                }
                arreglo[j+1] = temp;
            }
            verifyOrder(arreglo,tamano);
        }
        void mergesort(int * arreglo, int tamano){
            startSorting(arreglo, 0, tamano-1);
            verifyOrder(arreglo,tamano);
        }
        void heapsort(int * arreglo, int tamano){
            int aux;
            buildMaxHeap(arreglo,tamano);
            for(int i = tamano-1; i >= 1; i--){
                aux = arreglo[0];
                arreglo[0] = arreglo[i];
                arreglo[i] = aux;
                maxHeapify(arreglo,0,i);
            }
            //verifyOrder(arreglo,tamano);
        }
	    void quicksort(int * arreglo, int tamano){
            beginQuickSort(arreglo, 0, tamano);
            //verifyOrder(arreglo,tamano);
        }
        /*
        El radix sort presenta una peculiaridad con respecto a los demas algoritmos de ordenamiento. A este se le dificulta ordenar
        arreglos con valores negativos, debido a la naturaleza de su proceso. Para corregir este error, se decidio utilizar el paradigma
        de divide y venceras, partiendo el arreglo original en 2: uno con solo numeros positivos y el otro con negativos. Despues de
        ordenarlos se juntan nuevamente para tener como resultado el arreglo ordenado, utilizando Radix Sort.
        */
	    void radixsort(int * arreglo, int tamano){
            int cantidadNegativos = 0;
            int base = floor(log2(tamano));
            for(int i = 0; i < tamano; i++){
                if(arreglo[i] < 0){
                    cantidadNegativos++;   
                }
            }
            if(cantidadNegativos > 0){ //Si se encuentran negativos, se divide el arreglo
                int arregloNegativos[cantidadNegativos], indiceNeg = 0;
                int arregloPositivos[tamano-cantidadNegativos], indicePos = 0;

                for(int i = 0; i < tamano; i++){ //Este es el arreglo encargado de dividir los positivos de los negativos
                    if(arreglo[i] < 0){ //Si encuentra elemento negativo, lo convierte en positivo (* -1) y lo inserta al arreglo de negativos
                        arregloNegativos[indiceNeg] = arreglo[i] * -1;
                        indiceNeg++;
                    }
                    else{ //Si encuentra elemento positivo, lo inserta al arreglo de positivos
                        arregloPositivos[indicePos] = arreglo[i];
                        indicePos++;
                    }
                }

                int maximoNegativos = obtenerMayor(arregloNegativos,cantidadNegativos);
                int maximoPositivos = obtenerMayor(arregloPositivos,tamano-cantidadNegativos); 
                
                for(int digitoNeg = 1; maximoNegativos/digitoNeg > 0; digitoNeg *= base){
                    radixCount(arregloNegativos,digitoNeg,cantidadNegativos,base); //Se ordena el arreglo negativo
                }
                for(int digitoPos = 1; maximoPositivos/digitoPos > 0; digitoPos *= base){
                    radixCount(arregloPositivos,digitoPos,tamano-cantidadNegativos,base); //Se ordena el arreglo positivo
                }

                for(int i = 0, j = cantidadNegativos-1; i < cantidadNegativos; i++,j--){
                    arreglo[i] = arregloNegativos[j] * -1; //Se insertan los elementos del arreglo negativo al original
                }
                for(int k = cantidadNegativos, m = 0; k < tamano; k++,m++){
                    arreglo[k] = arregloPositivos[m]; //Se insertan los elementos positivos despues de los negativos pues estos son mayores
                }
            }
            else{ //De no encontrarse negativos, se procede a hacer el radix sort como se haria usualmente
                int mayor = obtenerMayor(arreglo,tamano);
                for(int digito = 1; mayor/digito > 0; digito *= base){
                    radixCount(arreglo,digito, tamano,base);
                }
            }
            //verifyOrder(arreglo,tamano);
        }
};

#endif