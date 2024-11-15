//notatnik.hpp  
#include <iostream>
#include <cstdlib>   
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

struct notatki{
	string notka;
};

void ZerowanieN();
void WyswietlanieN();
void OdczytN();
void ZapisN();

int x=50;
notatki nota[50];
fstream notat;

void DodajN() {
 	cout<<"----------------------------------------------------------------------\n";
	for(int i=0; i<x; i++)
		if(nota[i].notka=="-") { 
			cout<<"	"; 	//cin>>nota[i].notka;
			do{
					getline(cin,nota[i].notka);
				} while(nota[i].notka.size()<=0 || nota[i].notka.size()>=254);
			break;
		}
	//system("pause");
 }

void ZerowanieN() {
	for(int i=0; i<x; i++){
		nota[i].notka="-";
	}
}

void KasowanieN() {
	cout<<"----------------------------------------------------------------------\n";
	cout<<"Wybierz numer notatki do usuniecia?: "; int f; cin>>f;
	nota[f].notka="";
}

void WyswietlanieN() {
	for(int i=0; i<x; i++) {
    //if(i==0) {cout<<"     "; }
	if(nota[i].notka!="-") {
		cout<<"----------------------------------------------------------------------\n";
		cout<<i<<".  "<<nota[i].notka<<endl;
	} 
  } cout<<endl;
}

void OdczytN() {
	notat.open("notatnik.txt", ios::in);
	if(notat.is_open()) {
		//cout<<"Odczytano dane z pliku."<<endl;
		for(int i=0; i<x; i++) {
			getline(notat,nota[i].notka);		
		}	
		notat.close();
	}else cout<<"Blad otwarcia pliku.";	
	//system("pause");
}

void ZapisN() {
	cout<<"----------------------------------------------------------------------\n";
	notat.open("notatnik.txt", ios::out);
	if(notat.is_open()) {
		cout<<"Zapisano dane do pliku."<<endl;
		for(int i=0; i<x; i++) {
			notat<<nota[i].notka<<endl;
		}
		notat.close();
	}else cout<<"Blad zapisu pliku.";  
	//system("pause");
}

