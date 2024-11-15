//zakupy.hpp  
#include <iostream>
#include <cstdlib>   
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

struct zakupy{
	string nazwa[50];
};

void KonfiguracjaZa();
void ZerowanieZa();
void WyswietlanieZa();
void OdczytZa();
void ZapisZa();
void OdchaczZa();

int w=50;

zakupy zak;
fstream zaku;

void DodajZa() {
	//system("cls");
	cout<<"--------------------------------------------------------------";
	for(int i=1; i<w; i++)
		if(zak.nazwa[i]=="-") { 
			cout<<"\nPodaj nazwe: "; 	//cin>>zak.nazwa[i];
			do{
				getline(cin,zak.nazwa[i]);
			} while(zak.nazwa[i].size()<=0 || zak.nazwa[i].size()>=254);
			break;
		}
 }

void ZerowanieZa() {
	
	//system("cls");
	for(int i=1; i<w; i++){
		zak.nazwa[i]="-";
	} 
	//cout<<"Wyzerowano cala liste.";
}

void WyswietlanieZa() {

	cout<<"Lista zakupow:"<<endl<<endl;	
	for(int i=1; i<w; i++) {
        if(zak.nazwa[i]!="-") {
			cout<<i<<". "<<zak.nazwa[i]<<endl;
		} 
    } cout<<endl;
}

void OdczytZa() {

	zaku.open("pliki/zakupy.txt", ios::in);
	if(zaku.is_open()) {
		for(int i=1; i<w; i++) {
			getline(zaku,zak.nazwa[i]);
		}	
		zaku.close();
	}else cout<<"Blad otwarcia pliku.";	
	//system("pause");
}

void ZapisZa() {
	cout<<"--------------------------------------------------------------";
	//system("cls");
	zaku.open("pliki/zakupy.txt", ios::out);
	if(zaku.is_open()) {
		cout<<"\nZapisano dane do pliku."<<endl;
		for(int i=1; i<w; i++) {
			zaku<<zak.nazwa[i]<<endl;
		}
		zaku.close();
	}else cout<<"Blad zapisu pliku.";  
}

void OdchaczZa() {
	cout<<"--------------------------------------------------------------";
	//system("cls");
	//WyswietlanieZa();
	cout<<"\nPodaj nr rzeczy, ktora chcesz odznaczyc: "; int nr; cin>>nr;
	zak.nazwa[nr]="-";
}

