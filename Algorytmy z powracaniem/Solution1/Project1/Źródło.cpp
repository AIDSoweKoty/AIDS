#include <iostream>
#include "graf.h"
#include <windows.h>
#include <fstream>
#include <chrono>

using namespace std;

int main() {
	std::ofstream d02tE, d06tE, d02tH1, d06tH1, d02tHa, d06tHa, d02cH, d06cH;
	d02tE.open("d02tE.txt");
	d06tE.open("d06tE.txt");
	d02tH1.open("d02tH1.txt");
	d06tH1.open("d06tH1.txt");
	d02tHa.open("d02tHa.txt");
	d06tHa.open("d06tHa.txt");
	d02cH.open("d02cH.txt");
	d06cH.open("d06xH.txt");
	for (int i = 6; i <= 30; ++i) {
		graf graf(i);
		graf.wylosujgrafEulera(0.6f);
			//czas szukania eulera dla 0.6
		auto start = std::chrono::high_resolution_clock::now();
		graf.obwodEulera();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;
		d06tE << i << " " << diff.count();
		cout << i << " tE 0.6 done" << endl;



		//graf.cyklHamiltona();
		//graf.hamilton.wypiszElementy();

		//graf.pojedynczyCyklHamiltona();
		//for (int i = 0; i < graf.r; i++) {
		//	cout << graf.pojCyklHam[i] << " ";
		//}
		//cout << graf.czyZna << endl;
	}

	for (int i = 20; i <= 30; ++i) {
		graf graf2(i);
		graf2.wylosujgrafEulera(0.2f);

		//czas szukania eulera dla 0.2
		auto start = std::chrono::high_resolution_clock::now();
		graf2.obwodEulera();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;
		d02tE << i << " " << diff.count();
		cout << i << " tE 0.2 done" << endl;

	}
	d02tE.close();
	d06tE.close();
	d02tH1.close();
	d06tH1.close();
	d02tHa.close();
	d06tHa.close();
	d02cH.close();
	d06cH.close();
	system("pause");
}
