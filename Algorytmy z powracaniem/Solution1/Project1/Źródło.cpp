#include <iostream>
#include "graf.h"
#include <windows.h>
#include <fstream>
#include <chrono>


#define L 5
#define P 14
#define L2 20
#define P2 100
#define pap 5

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
	d06cH.open("d06cH.txt");
	for (int i = L; i <= P; ++i) {
		graf graf(i);
		graf.wylosujgrafEulera(0.6f);
//		cout << "graf wygenerowano poprawnie" << endl;

			//czas szukania eulera dla 0.6
		auto start = std::chrono::high_resolution_clock::now();
		graf.obwodEulera();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;
		d06tE << i << " " << diff.count() << endl;
		cout << i << " tE 0.6 done" << endl;

		start = std::chrono::high_resolution_clock::now();
		graf.pojedynczyCyklHamiltona();
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d06tH1 << i << " " << diff.count()<<endl;
		cout << i << " tH1 0.6 done" << endl;

		start = std::chrono::high_resolution_clock::now();
		graf.cyklHamiltona();
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d06tHa << i << " " << diff.count()<<endl;
		cout << i << " tHA 0.6 done" << endl;

		d06cH << i << " " << graf.hamilton.ilosc << endl;
		cout << i << " cH 0.6 done" << endl;
	}
	///////////////////////// dla 0.6 wiekszy krok
	for (int i = L2; i <= P2;i+=pap) {
		graf graf1(i);
		graf1.wylosujgrafEulera(0.6f);
		//		cout << "graf wygenerowano poprawnie" << endl;

		//czas szukania eulera dla 0.6
		auto start = std::chrono::high_resolution_clock::now();
		graf1.obwodEulera();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;
		d06tE << i << " " << diff.count() << endl;
		cout << i << " tE 0.6 done" << endl;

		start = std::chrono::high_resolution_clock::now();
		graf1.pojedynczyCyklHamiltona();
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d06tH1 << i << " " << diff.count() << endl;
		cout << i << " tH1 0.6 done" << endl;

		d06tHa << i << " " << "-" << endl;
		d06cH << i << " " << "-" << endl;
		cout << i << " cH 0.6 done" << endl;
	}

	for (int i = L; i <= P; ++i) {
		graf graf2(i);
		graf2.wylosujgrafEulera(0.2f);
//		cout << "graf wygenerowano poprawnie" << endl;
		//czas szukania eulera dla 0.2
		auto start = std::chrono::high_resolution_clock::now();
		graf2.obwodEulera();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;
		d02tE << i << " " << diff.count() << endl;
		cout << i << " tE 0.2 done" << endl;

		start = std::chrono::high_resolution_clock::now();
		graf2.pojedynczyCyklHamiltona();
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d02tH1 << i << " " << diff.count() << endl;
		cout << i << " tH1 0.2 done" << endl;

		start = std::chrono::high_resolution_clock::now();
		graf2.cyklHamiltona();
		end = std::chrono::high_resolution_clock::now();
		diff = end - start;
		d02tHa << i << " " << diff.count()<<endl;
		cout << i << " tHA 0.2 done" << endl;

		d02cH << i << " " << graf2.hamilton.ilosc << endl;
		cout << i << " cH 0.2 done" << endl;
	}
	////////////////////////// 0.2 wiekszy krok
	for (int i = L2; i <= P2; i+=pap) {
		graf graf3(i);
		graf3.wylosujgrafEulera(0.2f);
		//		cout << "graf wygenerowano poprawnie" << endl;
		//czas szukania eulera dla 0.2
		auto start = std::chrono::high_resolution_clock::now();
		graf3.obwodEulera();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;
		d02tE << i << " " << diff.count() << endl;
		cout << i << " tE 0.2 done" << endl;

		if (i < 30) {
			start = std::chrono::high_resolution_clock::now();
			graf3.pojedynczyCyklHamiltona();
			end = std::chrono::high_resolution_clock::now();
			diff = end - start;
			d02tH1 << i << " " << diff.count() << endl;
		}
		else {
			d02tH1 << i << " " << "0.000" << endl;
		}

		cout << i << " tH1 0.2 done" << endl;

		d02tHa << i << " " << "-" << endl;
		d02cH << i << " " << "-"<< endl;
		cout << i << " cH 0.2 done" << endl;
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
