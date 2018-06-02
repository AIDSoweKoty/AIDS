#include <iostream>
#include "cmake-build-debug/plecak.h"
#include <fstream>
#include <chrono>

#define bf_koniec 30
#define bf_krok 2
#define bf_poczatek 10

#define h_koniec 10000
#define h_krok 1000
#define h_poczatek 1000


int main() {
    std::ofstream z2_25,z2_50,z2_75,z3_25,z3_50,z3_75;
    z2_25.open("zBF_25.txt");
    z2_50.open("zBF_50.txt");
    z2_75.open("zBF_75.txt");
    z3_25.open("bezBF_25.txt");
    z3_50.open("bezBF_50.txt");
    z3_75.open("bezBF_75.txt");

    for (int i = bf_poczatek; i <=bf_koniec ; i+=bf_krok) {
        plecak P(i,0.25f);
        z2_25<<i<<" ";
        auto start = std::chrono::high_resolution_clock::now();
        // tu bedzie P.PD();
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff = stop - start;
        z2_25<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.bruteForce();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_25<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.bruteForceMadry();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_25<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.GH4();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_25<<diff.count()<<std::endl;
    }

    for (int i = bf_poczatek; i <=bf_koniec ; i+=bf_krok) {
        plecak P(i,0.50f);
        z2_50<<i<<" ";
        auto start = std::chrono::high_resolution_clock::now();
        // tu bedzie P.PD();
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff = stop - start;
        z2_50<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.bruteForce();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_50<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.bruteForceMadry();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_50<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.GH4();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_50<<diff.count()<<std::endl;
    }

    for (int i = bf_poczatek; i <=bf_koniec ; i+=bf_krok) {
        plecak P(i,0.75f);
        z2_75<<i<<" ";
        auto start = std::chrono::high_resolution_clock::now();
        // tu bedzie P.PD();
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff = stop - start;
        z2_75<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.bruteForce();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_75<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.bruteForceMadry();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_75<<diff.count()<<" ";

        start = std::chrono::high_resolution_clock::now();
        P.GH4();
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        z2_75<<diff.count()<<std::endl;
    }

    for (int i = h_poczatek; i <=h_koniec ; i+=h_krok) {
        plecak P(i,0.25f);
        z3_25<<i<<" ";
        z3_25<<"wynik PD"<<" ";
        z3_25<<P.GH1()<<" ";
        z3_25<<P.GH2()<<" ";
        z3_25<<P.GH3()<<" ";
        z3_25<<P.GH4()<<std::endl;
    }

    for (int i = h_poczatek; i <=h_koniec ; i+=h_krok) {
        plecak P(i,0.50f);
        z3_50<<i<<" ";
        z3_50<<"wynik PD"<<" ";
        z3_50<<P.GH1()<<" ";
        z3_50<<P.GH2()<<" ";
        z3_50<<P.GH3()<<" ";
        z3_50<<P.GH4()<<std::endl;
    }


    for (int i = h_poczatek; i <=h_koniec ; i+=h_krok) {
        plecak P(i,0.75f);
        z3_75<<i<<" ";
        z3_75<<"wynik PD"<<" ";
        z3_75<<P.GH1()<<" ";
        z3_75<<P.GH2()<<" ";
        z3_75<<P.GH3()<<" ";
        z3_75<<P.GH4()<<std::endl;
    }


//
//    plecak P(10,0.5f);
//    P.wypisz_plecak();
//    std::cout<<"GH1 "<<P.GH1()<<std::endl;
//    std::cout<<"GH2 "<<P.GH2()<<std::endl;
//    std::cout<<"GH3 "<<P.GH3()<<std::endl;
//    std::cout<<"GH4 "<<P.GH4()<<std::endl;
//    P.wypisz_plecak();
//    //std::cout<<"GH1 "<<P.GH1()<<std::endl;
//    //std::cout<<"GH2 "<<P.GH2()<<std::endl;
//    //std::cout<<"GH3 "<<P.GH3()<<std::endl;
//    //std::cout<<"GH4 "<<P.GH4()<<std::endl;
//    P.bruteForce();
//    P.bruteForceMadry();
    return 0;
}