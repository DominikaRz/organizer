//archiwum.hpp
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include "archiwizacja.hpp"

using namespace std;

int MenuAr() {
	system("cls");
	//system("Color 74");
	
	cout<<"| 1:Wydarz | 2:Plan | 3:Zakupy | 4:Zwyczaje | 5:Info | 6:Notki | 7:Hasla | 8:Dziennik / 9:Archiwum \\ <>:Wyjscie |"<<endl;
	cout<<"--------------------------------------------------------------------------------------              -------------"<<endl<<endl;
	
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<"           1:Archiwizuj    2:Przegladaj    <>:Wyjscie "<<endl<<endl;
	
	cout<<"\nWybierz: "; int e; cin>>e;
	return e;
}

int Archiwum() {
	char c='n';
	
	
	do {
		int wybor=MenuAr();
		switch(wybor) {
			case 1: Archiwa(); break;
			case 2: SzukajAr(); break;
			default: system("cls"); 
					cout<<"Czy na pewno chcesz zamknac baze: [t]ak, [n]ie  ";	cin>>c;
					if(c=='t') continue; else c='n';
				break;				
		}
		cin.ignore();
		getchar();
	} while(c=='n');
	

	system("pause"); //zatrzymanie programu do odczytu
	return 0;
}
