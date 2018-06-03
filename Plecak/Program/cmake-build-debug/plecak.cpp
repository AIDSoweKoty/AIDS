//
// Created by Piotr on 01.06.2018.
//
#include <random>
#include <time.h>
#include <iostream>
#include "plecak.h"

//tab[i][0] - ciężar s(a)
//tab[i][1] - wartość w(a)

#define s_left 10
#define s_right 1000

#define w_left 100
#define w_right 10000

plecak::plecak(int s, float b) {
    srand(time(nullptr));
    size = s;
    tab = new int*[size];
    for (int i = 0; i < size; ++i) {
        tab[i] = new int[2];
    };
    int tmp =0;
    for (int j = 0; j < size ; ++j) {
        tab[j][0] = rand() % (s_right - s_left) + s_left;
        tab[j][1] = rand() % (w_right - w_left) + w_left;
        tmp += tab[j][0];
    }
    ladownosc = (int)(b * tmp);
    //pomocnicze do rekursjid
    this->tmp=new bool[s];
    this->tmp2=new bool[s];
    for(int i=0;i<s;i++){
        this->tmp[i]=0;
        this->tmp2[i]=0;
    }
    m=0;
    ////przyklad co na zajeciach
    /*
    ladownosc=10;
    tab[0][1]=3;
    tab[1][1]=4;
    tab[2][1]=2;
    tab[3][1]=6;
    tab[4][1]=1;

    tab[0][0]=5;
    tab[1][0]=3;
    tab[2][0]=2;
    tab[3][0]=4;
    tab[4][0]=3;
     */
    /////
};

void plecak::wypisz_plecak(){
    std::cout<<"###############"<<std::endl;
    std::cout<<"ładowność: "<<ladownosc<<std::endl;
    std::cout.width(5);
    std::cout.right;
    std::cout<<"s(a)"<<"  "<<"w(a)"<<std::endl;
    for (int i = 0; i < size ; ++i) {
        std::cout.width(5);
        std::cout.right;
        std::cout<<tab[i][0]<<"  "<<tab[i][1]<<std::endl;
    }
};

void plecak::sortuj_plecak(bool po_s, bool rosnaco ){
    auto B = new int*[size];
    for (int i = 0; i <size ; ++i) {
        B[i] = new int[2];
        B[i][0]=-1;
        B[i][1]=-1;
    };

    if (po_s){  //tutaj jak sortujemy po s to uzupełniamy C
        auto C = new int[s_right];
        for (int j = 0; j < s_right; ++j) {
            C[j] = 0;
        }
        for (int i = 0; i < size; ++i) {
            C[tab[i][0]] ++;
        }
        for (int i = 1; i<s_right; ++i){
            C[i]+=C[i-1];
        }
        for (int k = size-1; k >= 0; --k) {
            B[ C[ tab[k][0] ]-1 ][1] = tab[k][1];
            B[ --C[ tab[k][0]  ] ][0] = tab[k][0];
            }


        if(rosnaco) {
            for (int i = 0; i < size; ++i) {
                tab[i][0] = B[i][0];
                tab[i][1] = B[i][1];
            }
        }
        else{
                int tmp = size -1;
                for (int i = 0; i < size; ++i) {
                    tab[tmp][0] = B[i][0];
                    tab[tmp][1] = B[i][1];
                    --tmp;
                }
            }
            delete C;
        }
        if(!po_s) {
            auto C = new int[w_right];
            for (int i = 0; i < w_right; ++i) {
                C[i] = 0;
            }
            for (int i = 0; i < size; ++i) {
                C[tab[i][1]]++;
            }
            for (int i = 1; i < w_right; ++i) {
                C[i] += C[i - 1];
            }
            for (int k = size - 1; k >= 0; --k) {
                B[ C[tab[k][1]]-1][1] = tab[k][1];
                B[--C[tab[k][1]]][0] = tab[k][0];
            }
            if (rosnaco) {
                for (int i = 0; i < size; ++i) {
                    tab[i][0] = B[i][0];
                    tab[i][1] = B[i][1];
                }
            } else {
                int tmp = size - 1;
                for (int i = 0; i < size; ++i) {
                    tab[tmp][0] = B[i][0];
                    tab[tmp][1] = B[i][1];
                    --tmp;
                }
            }
            delete C;
        }
    for(int i = 0; i<size; ++i)
        delete B[i];
    delete B;
};

int plecak::GH1(){
    int score = 0;
    int waga = 0;
    auto pom = new int[size];
    for (int i = 0; i < size; ++i){
        pom[i] =-1;
    };
    int cun = 0,b,tmp = rand() % size;
    score += tab[tmp][1];
    waga += tab[tmp][0];
    pom[cun++] = tmp;
    b = tmp;
    while(b==tmp){
        tmp = rand()%size;
    }
    while (waga + tab[tmp][0] < ladownosc){
        score += tab[tmp][1];
        waga += tab[tmp][0];
        int i= 0;
        pom[cun++] = tmp;
        while(pom[i] != -1){
            if (tmp == pom[i]){
                tmp = rand()%size;
                i =0;
            }
            ++i;
        }
    }
    std::cout<<"waga: "<<waga<<std::endl;
    return score;
};

int plecak::GH2() {
    sortuj_plecak(true,true);
    int i =0,score= 0, waga =0;
    while (waga + tab[i][0] < ladownosc){
        score += tab[i][1];
        waga += tab[i][0];
        ++i;
    }
    std::cout<<"waga: "<<waga<<std::endl;
    return score;

};

int plecak::GH3() {
    sortuj_plecak(false,false);
    int i =0,score= 0, waga =0;
    while (waga + tab[i][0] < ladownosc){
        score += tab[i][1];
        waga += tab[i][0];
        ++i;
    }
    std::cout<<"waga: "<<waga<<std::endl;
    return score;

};

void plecak::sortuj_polecak_po_sredniej(){
    auto B = new int*[size];
    auto D = new int*[size];
    for (int i = 0; i <size ; ++i) {
        D[i] = new int[2];
        B[i] = new int[3];
        B[i][0]= tab[i][0];
        B[i][1]= tab[i][1];
        B[i][2] = tab[i][1]/tab[i][0];
    };
    auto C = new int[w_right];
    for (int i = 0; i < w_right; ++i) {
        C[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        C[B[i][2]]++;
    }
    for (int i = 1; i < w_right; ++i) {
        C[i] += C[i - 1];
    }
    for (int k = size - 1; k >= 0; --k) {
        D[C[B[k][2]] - 1][1] = tab[k][1];
        D[--C[B[k][2]]][0] = tab[k][0];
    }
        int e = size -1;
        for (int i = 0; i < size; ++i) {
            tab[e][0] = D[i][0];
            tab[e][1] = D[i][1];
            e--;
        }
};

int plecak::GH4() {
    sortuj_polecak_po_sredniej();
    int i =0,score= 0, waga =0;
    while (waga + tab[i][0] < ladownosc){
        score += tab[i][1];
        waga += tab[i][0];
        ++i;
    }
    std::cout<<"waga: "<<waga<<std::endl;
    return score;

};

void plecak::bruteForce(int waga,int wartosc,int bit){
  if(bit==size){
      if(waga<=ladownosc&&wartosc>m){
          for(int i=0;i<size;i++){
              tmp2[i]=tmp[i];
          }
          m=wartosc;
      }

      return;
  }
  bruteForce(waga,wartosc,bit+1);
  tmp[bit]=1;
  waga+=tab[bit][0];
  wartosc+=tab[bit][1];
  bruteForce(waga,wartosc,bit+1);
  tmp[bit]=0;
  if(bit==0){
      std::cout<<m<<" najlepsze brute force"<<std::endl;
      for(int i=0;i<size;i++){
          tmp[i]=0;
          tmp2[i]=0;
      }
      m=0;
  }
  return;
};

void plecak::bruteForceMadry(int waga,int wartosc,int bit){
    if(bit==size){
        if(waga<=ladownosc&&wartosc>m){
            for(int i=0;i<size;i++){
                tmp2[i]=tmp[i];
            }
            m=wartosc;
        }
        return;
    }
    bruteForceMadry(waga,wartosc,bit+1);
    tmp[bit]=1;
    waga+=tab[bit][0];
    wartosc+=tab[bit][1];
    if(waga<=ladownosc){
        bruteForceMadry(waga,wartosc,bit+1);
    }
    tmp[bit]=0;
    if(bit==0){
        std::cout<<m<<" najlepsze brute force Madry"<<std::endl;
        for(int i=0;i<size;i++){
            std::cout<<tmp2[i];
            tmp[i]=0;
            tmp2[i]=0;
        }
        m=0;
        std::cout<<std::endl;
    }
};

void plecak::programowanieDynamiczne() {                                    //1-wartość 0-waga
    /*
    int **prog  = new int *[ladownosc+1];
    for(int j=0;j<ladownosc+1;j++){
        prog[j]=new int[size+1];
    }*/

    int prog[1000][250];

    for(int i=0;i<size+1;i++)
        for (int j = 0; j < ladownosc + 1; j++)
            prog[i][j]=0;

    //return;       //jeżeli odkomentujesz return to wywali błąd ten sam problem jest przy deklaracji pamięci nie wiem jaki
    int nowaWartosc=0;
    for(int i=0;i<size+1;i++){
        for(int j=0;j<ladownosc+1;j++){
            //std::cout<<i<<" "<<j<<std::endl;
            if(i==0||j==0){
                continue;
            }
            /*
            std::cout<<"************"<<std::endl;
            for(int i1=0;i1<size+1;i1++) {
                for (int j1 = 0; j1 < ladownosc + 1; j1++)
                    std::cout << prog[i1][j1] << "   ";
                std::cout << std::endl;
            }
            std::cout<<"************"<<std::endl;
            */
            if(tab[i-1][0]<=j){
                if(j-tab[i-1][0]>0){
                    nowaWartosc=prog[i-1][j-tab[i-1][0]]+tab[i-1][1];
                }
                else{
                    nowaWartosc=tab[i-1][1];
                }
                //std::cout<<nowaWartosc<<" "<<tab[i-1][1]<<" "<<i<<std::endl;
                if(nowaWartosc>prog[i-1][j])
                    prog[i][j]=nowaWartosc;
                else
                    prog[i][j]=prog[i-1][j];
            }
            else{
               prog[i][j]=prog[i-1][j];
            }
        }
    }
    /*
    for(int i=0;i<size+1;i++) {
        for (int j = 0; j < ladownosc + 1; j++) {
            std::cout << prog[i][j] << "   ";
        }
        std::cout<<std::endl;
    }
    */
};

