#include "graf.h"
#include "list.h"
#include "LIFO.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <chrono>

int main() {
	std::ofstream d2etykiety, d4etykiety, d2archesmatrix, d4archesmatrix, d2archessuccesors, d4archessuccesors, d2arches, d4arches;
	d2etykiety.open("d2_czasy_obliczania_etykiet.txt");
	d4etykiety.open("d4_czasy_obliczania_etykiet.txt");
	d2archesmatrix.open("d2_luki_macierz.txt");
	d4archesmatrix.open("d4_luki_macierz.txt"); 
	d2archessuccesors.open("d2_luki_nastepnikow.txt");
	d4archessuccesors.open("d4_luki_nastepniki.txt");
	d2arches.open("d2_luki_luki.txt");
	d4arches.open("d4_luki_luki.txt");
	for (int i = 200; i <= 2200; i+=200){
		graf G(i, 0.2f);
		//czas sortowania dla 0.2
		auto start = std::chrono::high_resolution_clock::now();
		G.DFSsort();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;
		d2etykiety << i << " " << diff.count()<<std::endl;
		//czas zliczania dla macierzy
		start = std::chrono::high_resolution_clock::now();
		d2archesmatrix<<i<<" "<<G.CountReturnArchForAdjacencyMatrix()<<" ";
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d2archesmatrix << diff.count() << std::endl;
		//czas ddla listy nastepnikow
		start = std::chrono::high_resolution_clock::now();
		d2archessuccesors << i << " " << G.CountReturnArchForListOfsucessors() << " ";
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d2archessuccesors<< diff.count() << std::endl;
		//czas dla listy krawedzi
		start = std::chrono::high_resolution_clock::now();
		d2arches << i << " " << G.CountReturnArchForListOfArches() << " ";
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d2arches << diff.count() << std::endl;
		std::cout << i << " 0.2 done"<<std::endl;
		//dla 0.4
		graf F(i, 0.4f);
		//czas sortowania dla 0.4
		start = std::chrono::high_resolution_clock::now();
		F.DFSsort();
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d4etykiety << i << " " << diff.count() << std::endl;
		//czas zliczania dla macierzy
		start = std::chrono::high_resolution_clock::now();
		d4archesmatrix << i << " " << F.CountReturnArchForAdjacencyMatrix() << " ";
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d4archesmatrix << diff.count() << std::endl;
		//czas ddla listy nastepnikow
		start = std::chrono::high_resolution_clock::now();
		d4archessuccesors << i << " " << F.CountReturnArchForListOfsucessors() << " ";
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d4archessuccesors << diff.count() << std::endl;
		//czas dla listy krawedzi
		start = std::chrono::high_resolution_clock::now();
		d4arches << i << " " << F.CountReturnArchForListOfArches() << " ";
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d4arches << diff.count() << std::endl;
		std::cout << i << " 0.4 done" << std::endl;

	}
	system("pause");
}