#include <iostream>
#include <cstdlib>
#include "informacje.hpp"

using namespace std;

int MenuI() {
	system("cls");
	cout<<"| 1:Wydarz | 2:Plan | 3:Zakupy | 4:Zwyczaje / 5:Info \\ 6:Notki | 7:Hasla | 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"--------------------------------------------          -----------------------------------------------------------"<<endl<<endl;
	
	cout<<"----------------------------------------------------"<<endl;
	cout<<"       1:Szukaj    2:Wyswietl   <>:Wyjscie "<<endl<<endl;
	
	cout<<"Wybor: "; int w;  cin>>w;
	return w;
	
}

int Informacje() {
	char c='n';

	OdczytI();
	
	do{
		int wybor=MenuI();
		switch(wybor) {
				case 1: SzukajI();  		break;
				case 2: WyswietlanieI();	break;
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


