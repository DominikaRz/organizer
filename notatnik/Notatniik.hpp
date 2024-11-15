#include <iostream>
#include <cstdlib>
#include "notatnik.hpp"

using namespace std;

int MenuN() {
	system("cls");
	cout<<"| 1:Wydarz | 2:Plan | 3:Zakupy | 4:Zwyczaje | 5:Info / 6:Notki \\ 7:Hasla | 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"-----------------------------------------------------           -------------------------------------------------"<<endl;
	
	WyswietlanieN();
	
	cout<<"-------------------------------------------------------------------"<<endl;
	cout<<"         1:Zapisz    2:Dodaj    3:Kasuj   <>:Wyjscie  "<<endl<<endl;
	
	cout<<"Wybor: "; int w;  cin>>w;
	return w;
	
}

int Notatnik() {
	char c='n';
	
	ZerowanieN();
	OdczytN();
	do{
		int wybor=MenuN();
		switch(wybor) {
				case 1: ZapisN();  		break;
				case 2: DodajN();		break;
				case 3: KasowanieN();	break;
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


