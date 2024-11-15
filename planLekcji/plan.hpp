#include <iostream>
#include <cstdlib>
#include <fstream>
#include "planLekcji.hpp"

using namespace std;

int MenuPl() {	
	system("cls");
	//cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"| 1:Wydarz / 2:Plan \\ 3:Zakupy | 4:Zwyczaje | 5:Info | 6:Notki | 7:Hasla | 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"-----------          --------------------------------------------------------------------------------------------"<<endl;
	
		
	if (zna==0){	
		cout<<"\nPOMOC: Podaj caly plan lekcji w formie poziomej(od prawej do lewej)."<<endl
		<<"Wpisz tylko 17 znakow/liter na jedna lekcje (od Pn do Pt, 8 lekcji)."<<endl
		<<"Jesli w danym czasie nie masz lekcji wpisz znak '-' "<<endl<<endl;
		KonfiguracjaPl();
		zna=1;
		ZapisPl();	
	} 
	else { 
		WyswietlaniePl();
	}
	
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"        1:Zamiana    2:Zapis    3:Wyzeruj    <>:Wyjscie  "<<endl<<endl;
	
	cout<<"Wybor: "; int f;  cin>>f;
	return f;
	
}

int Plan() {
	system("cls");
	char c='n';
	
	ZerowaniePl();
	OdczytPl();
	
	do {
	//	system("cls");
		int wybor=MenuPl();
		switch(wybor) {
				case 1: ZamianaPl(); 		break;
				case 2: ZapisPl();			break;
				case 3: ZerowaniePl();		break;				
				default: system("cls");
						cout<<"Czy na pewno chcesz zamknac baze: [t]ak, [n]ie  ";	cin>>c;
						if(c=='t') continue; else c='n';
					break;
				
		}
		cin.ignore();
		getchar();
	} while(c=='n');
	
/**/
	
	return 0;
}

