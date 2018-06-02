#include <iostream>
#include "cmake-build-debug/plecak.h"

int main() {
    plecak P(10,0.5f);
    P.wypisz_plecak();
    //std::cout<<"GH1 "<<P.GH1()<<std::endl;
    //std::cout<<"GH2 "<<P.GH2()<<std::endl;
    //std::cout<<"GH3 "<<P.GH3()<<std::endl;
    //std::cout<<"GH4 "<<P.GH4()<<std::endl;
    P.bruteForce();
    P.bruteForceMadry();
    return 0;
}