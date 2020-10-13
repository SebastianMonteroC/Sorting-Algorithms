#include "Ordenador.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <ctime>
#include <chrono>


int main(){ 

    Ordenador sorter;
        srand(time(0)); //GENERATES A NEW SEED EVERY TIME
        int intArray[50000];

        for(int i = 0; i < 50000; i++){
            intArray[i] = (rand()%100000)-50000;
        }
        auto tiempo_inicial = std::chrono::high_resolution_clock::now(); //TAKES THE TIME AT WHICH THE EXECUTION BEGAN

        sorter.radixsort(intArray,50000);

        auto tiempo_final = std::chrono::high_resolution_clock::now(); // TAKES THE TIME AT WHICH THE EXECUTION ENDED
        double tiempo_calculado = std::chrono::duration<double, std::milli>(tiempo_final-tiempo_inicial).count();//CALCULATES THE TIME THAT HAS PASSED

        std::cout << tiempo_calculado / 1000 << endl; //TIME IS TAKEN IN MILLISECONDS, SO DIVIDING BY 1000 RESULTS IN TIME IN SECONDS
        
    /*
    srand(time(0)); //GENERATES A NEW SEED EVERY TIME
    int intArray[50000];

    for(int i = 0; i < 50000; i++){
        intArray[i] = rand() % 2147483646-1;
    }

    auto tiempo_inicial = std::chrono::high_resolution_clock::now(); //TAKES THE TIME AT WHICH THE EXECUTION BEGAN

    sorter.seleccion(intArray,50000);

    auto tiempo_final = std::chrono::high_resolution_clock::now(); // TAKES THE TIME AT WHICH THE EXECUTION ENDED
    double tiempo_calculado = std::chrono::duration<double, std::milli>(tiempo_final-tiempo_inicial).count();//CALCULATES THE TIME THAT HAS PASSED

    std::cout << tiempo_calculado << endl;
    //sorter.insercion(intArray,150000);
    //sorter.seleccion(intArray,150000);
    //sorter.mergesort(intArray,150000);
    int arraySeleccion[50000];
    int arrayInsercion[50000];
    int arrayMerge[50000];

    for(int i = 0; i < 50000; i++){
        arraySeleccion[i] = rand() % 2147483647-1;
        arrayInsercion[i] = rand() % 2147483647-1;
        arrayMerge[i] = rand() % 2147483647-1;
    }
    sorter.seleccion(arraySeleccion,50000);
    sorter.insercion(arrayInsercion,50000);
    sorter.mergesort(arrayMerge,50000);
    */
    return 0;
};