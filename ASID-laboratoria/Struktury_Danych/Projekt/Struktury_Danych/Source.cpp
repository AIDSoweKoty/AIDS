#include <iostream>
#include <ctime>
#include <random>
#include "QuickSort.h"
#include <chrono>
#include <fstream>
#include "ArrayCreating.h"
#include "ListStruc.h"
#include "Lista.h"
#include "BST.h"
#include "Searching.h"
#include <Windows.h>
#include "BSTStruc.h"
#define S 10
 
int main()
{
	std::ofstream CB,SSB,SBB,CL,SL,CTR,HTR,STR,CTB,HTB,STB,ClS,SlS,CTRs, HTRs, STRs, CTBs, HTBs, STBs;
	CB.open("czas_tworzenia_kopii_i_sortowania.txt");
	SSB.open("czas_przeszukiwania_wycieczajacego.txt");
	SBB.open("czas_przeszukiwania_binarnego.txt");
	CL.open("czas_tworzenia_listy_L.txt");
	SL.open("czas_przeszukiwania_listy_L.txt");
	CTR.open("czas_tworzenia_drzewa_TR.txt");
	HTR.open("wysokoœæ_drzewa_TR.txt");
	STR.open("czas_przeszukiwania_drzewa_TR.txt");
	CTB.open("czas_tworzenia_drzewa_TB.txt");
	HTB.open("wysokoœæ_drzewa_TB.txt");
	STB.open("czas_przeszukiwania_drzewa_TB.txt");

	for (int i = 10000; i <= 2000000; i+=10000)
	{
		int* A;
		int* B;
		A = new int[i];
		B = new int[i];
		lista L;
		tree TR,TB;
		makeListWithUniqueElements(A, i);
		auto start = std::chrono::high_resolution_clock::now();
		CopyArray(A, B, i);
		QuickSortMid(B, i);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> time = end - start;
		CB<< i << " " << time.count() << " miloseconds" << std::endl;
		std::cout << i << " CB done" << std::endl;
		//Przeszukiwanie wyciêczaj¹ce
		auto SSB_start = std::chrono::high_resolution_clock::now();
		for (int j =0; j < i; j++)
		{
			BruteForce(B, A[j], i);
		}
		auto SSB_end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SSB_time = SSB_end - SSB_start;
		SSB<< i << " " << SSB_time.count() << " miloseconds" << std::endl;
		std::cout << i << " SSB done" << std::endl;
		//przeszukiwanie binarne
		auto SBB_start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			BinarySearch(B, A[j], 0, i);
		}
		auto SBB_end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SBB_time = SBB_end - SBB_start;
		SBB << i << " " << SBB_time.count() <<" miloseconds"<< std::endl;
		std::cout << i << " SBB done" << std::endl;
		//tworzenie L
		auto CLstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			L.dodajElement(A[j]);

		}
		auto CLend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> CLtime = CLend - CLstart;
		CL << i << " " << CLtime.count() << " miliseconds" << std::endl;
		std::cout << i << " CL done" << std::endl;
		//przeszukiwanie L
		auto SLstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			L.wyszukajElement(A[j]);

		}
		auto SLend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SLtime = SLend - SLstart;
		SL << i << " " << SLtime.count() << " miliseconds" << std::endl;
		std::cout << i << " SL done" << std::endl;
		//budowa TR
		auto CTRstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			TR.dodajElement(A[j]);
		}
		auto CTRend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> CTRtime = CTRend - CTRstart;
		CTR << i << " " << CTRtime.count() << " miliseconds" << std::endl;
		std::cout << i << " CTR done" << std::endl;
		//wysokoœæ TR
		HTR << i << " " << TR.zbadajWysokosc() << " wysokoœæ" << std::endl;
		std::cout << i << " HTR done" << std::endl;
		//przeszukiwanie TR
		auto STRstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			TR.czyJest(A[j]);
		}
		auto STRend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> STRtime = STRend - STRstart;
		STR << i << " " << STRtime.count() << " miliseconds" << std::endl;
		std::cout << i << " STR done" << endl;
		//tworzenie TB
		int* C;
		C = new int[i];
		BinaryPartition(B, C, i);
		auto CTBstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			TB.dodajElement(C[j]);
		}
		auto CTBend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> CTBtime = CTBend - CTBstart;
		CTB << i <<" "<< CTBtime.count() << " miliseconds" << std::endl;
		std::cout << i << " CBT done"<<std::endl;
		//wysokoœæ drzewa TB
		HTB << i << " " << TB.zbadajWysokosc() << " wysokoœæ" << std::endl;
		std::cout << i << " HTB done"<<std::endl;
		//przeszukiwanie TB
		auto STBstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			TB.czyJest(A[j]);
		}
		auto STBend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> STBtime = STBend - STBstart;
		STB << i << " " << STBtime.count() << " miliseconds" << std::endl;
		std::cout << i << " STB done" << std::endl;
	}
	system("pause");
}