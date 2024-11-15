#include <iostream>
#include <cstdlib>
#include "zakupy.hpp"

using namespace std;

int MenuZa() {
	system("cls");
	
	cout<<"| 1:Wydarz | 2:Plan / 3:Zakupy \\ 4:Zwyczaje | 5:Info | 6:Notki | 7:Hasla | 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"--------------------            ---------------------------------------------------------------------------------"<<endl;
	
	WyswietlanieZa();
	
	cout<<"------------------------------------------------------------------------------"<<endl;
	cout<<"        1:Dodaj    2:Zapisz    3:Odchacz   4:Wyczysc   <>:Wyjscie  "<<endl<<endl;
	
	cout<<"Wybor: "; int a;  cin>>a;
	return a;
	
}

int ListaZakupow() {
	char c='n';
	
	ZerowanieZa();
	OdczytZa();
	

	do {
		int wybor=MenuZa();
		switch(wybor) {
				case 1: DodajZa();		break;
				case 2: ZapisZa();  	break;
				case 3: OdchaczZa();	break;
				case 4: ZerowanieZa();	break;
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


