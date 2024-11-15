#include <iostream>
#include <cstdlib>
#include "zwyczaje.hpp"

using namespace std;


int MenuZ() {
	system("cls");
	
	cout<<"| 1:Wydarz | 2:Plan | 3:Zakupy / 4:Zwyczaje \\ 5:Info | 6:Notki | 7:Hasla | 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"-------------------------------              --------------------------------------------------------------------"<<endl;
	
	if (znacznik==0){	
		KonfiguracjaZ();
		znacznik=1;
		system("cls");
		WyswietlanieZ();
		ZapisZ();	
	} 
	else { 
		WyswietlanieZ();
	} 
	
	cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<"         1:Zaznacz    2:Wypisz    3:Szukaj    4:Dodaj    5:Wyczysc    <>:Wyjscie  "<<endl<<endl;
	
	cout<<"Wybor: "; int b;  cin>>b;
	return b;
	
}

int Zwyczaje() {
	char c='n';
	
	ZerowanieZ();
	OdczytZ();
	
	do {
				
		int wybor=MenuZ();
		switch(wybor) {
				case 1: ZaznaczZ();		break;
				case 2: ZapisZ(); 		break;
				case 3: SzukajZ(); 		break;
				case 4: DodajZ(); 		break;
				case 5: ZerowanieZ(); 	break;
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


