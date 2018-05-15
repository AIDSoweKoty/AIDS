#include <iostream>
#include "graf.h"
#include <windows.h>
using namespace std;



int main() {
	graf graf(5);
	graf.pisz();
	graf.cyklHamiltona();
	
	graf.hamilton.wypiszElementy();

	//graf.obwodEulera();
	//graf.wypiszObwodEulera();

	graf.pojedynczyCyklHamiltona();
	for (int i = 0;i < graf.r;i++) {
		cout << graf.pojCyklHam[i] << " ";
	}
	cout << graf.czyZna << endl;
	system("pause");
	return 0;
}
