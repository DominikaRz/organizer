#include <iostream>
#include <cstdlib>
//moje biblioteki
#include "wydarzenia/Wydarzeniaa.hpp"
#include "planLekcji/plan.hpp"
#include "zakupy/listaZakupow.hpp"
#include "zwyczaje/listaZwyczajow.hpp"
#include "przydatneInformacje/Przydatne.hpp"
#include "hasla/Haslla.hpp"
#include "notatnik/Notatniik.hpp"
#include "dzienniczekOcen/Dzienniczek.hpp"
#include "archiwum/Archiwum.hpp"

using namespace std;

int MenuGl() {
	
	cout<<"| 1:Wydarz | 2:Plan | 3:Zakupy | 4:Zwyczaje | 5:Info | 6:Notki | 7:Hasla | 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Wybor: "; int w;  cin>>w;
	return w;
	
}

int main() {
	char c='n';

	do {
		system("cls");	
		
		int wybor=MenuGl();
		switch(wybor) {
				case 1: system("cls"); Wydarzenia();	break;
				case 2: system("cls"); Plan();			break;
				case 3: system("cls"); ListaZakupow();	break;
				case 4: system("cls"); Zwyczaje();		break;
				case 5: system("cls"); Informacje();	break;
				case 6: system("cls"); Notatnik();		break;
				case 7: system("cls"); Hasla();			break;
				case 8: system("cls"); Dzienniczek();	break;
				case 9: system("cls"); Archiwum();		break;
				
				default:system("cls"); 
						cout<<"Czy na pewno chcesz zamknac baze: [t]ak, [n]ie  ";	cin>>c;
						if(c=='t') continue; else c='n';
					break;
		}
		cin.ignore();
		getchar();
	} while(c=='n');
	
	return 0;
}



