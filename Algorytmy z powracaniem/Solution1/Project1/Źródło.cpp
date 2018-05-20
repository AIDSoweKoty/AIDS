#include <iostream>
#include "graf.h"
#include <windows.h>
using namespace std;



int main() {
		graf graf(6);
		graf.wylosujgrafEulera(0.6f);
		graf.pisz();
		cout << "#########" << endl;
	//graf.cyklHamiltona();
	//graf.hamilton.wypiszElementy();

	//graf.obwodEulera();
	//graf.wypiszObwodEulera();

	//graf.pojedynczyCyklHamiltona();
	//for (int i = 0; i < graf.r; i++) {
	//	cout << graf.pojCyklHam[i] << " ";
	//}
	//cout << graf.czyZna << endl;
	system("pause");
}
