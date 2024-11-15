//informacje.hpp  
#include <iostream>
#include <string>   
#include <cstdlib>   
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

struct informacje{
	string miod[10];
	string aroma[30];
	string naprawa[90];
	string choroby[40];
	string zapachy[30];
	string porady[60];
	string czyszczenie[250];
};

void WyswietlanieI();
void OdczytI();
void SzukajI();

informacje inf;
fstream info;


void szukajWTekscie( std::string & tekst, std::string szukanaFraza ) {
	
    size_t znalezionaPozycja = tekst.rfind( szukanaFraza );
    if( znalezionaPozycja == std::string::npos ) return;
    else cout<<tekst<<endl<<"-----------------------------------------"<<endl;
}

void WyswietlanieI() {
	const int m=10, a=30, n=90, c=40, p=60, z=250;
	cout<<"------------------------------------------------------------------------------------"<<endl;
	cout<<"  1:Czyszczenie  2:Porady  3:Naprawa  4:Zapachy  5:Choroby  6:Miod  7:Aromaterapia  "<<endl;
	
	cout<<"Co chcesz wyswietlic: "; int wybor; cin>>wybor;
	switch(wybor) {
		case 1: cout<<"JAK WYCZYSCIC NIEMAL WSZYSTKO\n";
			for(int i=0; i<z; i++) {
				cout<<"----------------------------------------------------------------------\n";
				cout<<inf.czyszczenie[i]<<endl;
			} cout<<endl;
			break;
			
		case 2: cout<<"ROZNE PORADY\n";
			for(int i=0; i<p; i++) {
				cout<<"----------------------------------------------------------------------\n";
				cout<<inf.porady[i]<<endl;
			} cout<<endl;
			break;
		case 3: cout<<"JAK NAPRAC NIEMAL WSZYSTKO\n";
			for(int i=0; i<n; i++) {
				cout<<"----------------------------------------------------------------------\n";
				cout<<inf.naprawa[i]<<endl;
			} cout<<endl;
			break;
		case 4: cout<<"JAK USUWAC NIEPRZYJEMNE ZAPACHY\n";
			for(int i=0; i<a; i++) {
				cout<<"----------------------------------------------------------------------\n";
				cout<<inf.zapachy[i]<<endl;
			} cout<<endl;
			break;
		case 5: cout<<"DOMOWE SPOSOBY NA CHOROBY\n";
			for(int i=0; i<c; i++) {
				cout<<"----------------------------------------------------------------------\n";
				cout<<inf.choroby[i]<<endl;
			} cout<<endl;
			break;
		case 6: cout<<"LECZNICZE WLASCIWOSCI MIODU\n";
			for(int i=0; i<m; i++) {
				cout<<"----------------------------------------------------------------------\n";
				cout<<inf.miod[i]<<endl;
			} cout<<endl;
			break;
		case 7: cout<<"ABC AROMATERAPII\n";
			for(int i=0; i<a; i++) {
				cout<<"----------------------------------------------------------------------\n";
				cout<<inf.aroma[i]<<endl;
			} cout<<endl;
			break;
	}
		
} 

void OdczytI() {
const int m=10, a=30, n=90, c=40, p=60, z=250;
//--------------------------------------------------------------------	
	info.open("pliki/NaWszystkoJestRada/Aromaterapia.txt", ios::in);
	if(info.is_open()) {
		for(int i=0; i<a; i++) {
			getline(info,inf.aroma[i]);		
		}	
		info.close();
	}else cout<<"Blad otwarcia pliku.";	
//--------------------------------------------------------------------		
	info.open("pliki/NaWszystkoJestRada/Czaszczenie.txt", ios::in);
	if(info.is_open()) {
		for(int i=0; i<z; i++) {
			getline(info,inf.czyszczenie[i]);		
		}	
		info.close();
	}else cout<<"Blad otwarcia pliku.";	
//--------------------------------------------------------------------		
	info.open("pliki/NaWszystkoJestRada/Miod.txt", ios::in);
	if(info.is_open()) {
		for(int i=0; i<m; i++) {
			getline(info,inf.miod[i]);		
		}	
		info.close();
	}else cout<<"Blad otwarcia pliku.";	
//--------------------------------------------------------------------	
	info.open("pliki/NaWszystkoJestRada/Naprawa.txt", ios::in);
	if(info.is_open()) {
		for(int i=0; i<n; i++) {
			getline(info,inf.naprawa[i]);		
		}	
		info.close();
	}else cout<<"Blad otwarcia pliku.";	
//--------------------------------------------------------------------		
	info.open("pliki/NaWszystkoJestRada/Porady.txt", ios::in);
	if(info.is_open()) {
		for(int i=0; i<p; i++) {
			getline(info,inf.porady[i]);		
		}	
		info.close();
	}else cout<<"Blad otwarcia pliku.";	
//--------------------------------------------------------------------		
	info.open("pliki/NaWszystkoJestRada/UsuwanieZapachow.txt", ios::in);
	if(info.is_open()) {
		for(int i=0; i<a; i++) {
			getline(info,inf.zapachy[i]);		
		}	
		info.close();
	}else cout<<"Blad otwarcia pliku.";	
//--------------------------------------------------------------------		
	info.open("pliki/NaWszystkoJestRada/SposobNaChoroby.txt", ios::in);
	if(info.is_open()) {
		for(int i=0; i<c; i++) {
			getline(info,inf.choroby[i]);		
		}	
		info.close();
	}else cout<<"Blad otwarcia pliku.";	
	
}

void SzukajI() {
const int m=10, a=30, n=90, c=40, p=60, z=250;
	cout<<"----------------------------------------------------------------------\n";
	cout<<"Podaj slowo kluczowe: "; string slowo; cin>>slowo;
	
	cout<<"1 - Wyszukaj we wszystkich\n2 - Wyszukaj w jednym\nWybor: "; int q; cin>>q;
	switch(q) {
		case 1: cout<<"\n\nJAK WYCZYSCIC NIEMAL WSZYSTKO\n";
				for(int i=0; i<z; i++) {
						szukajWTekscie(inf.czyszczenie[i], slowo);
					} cout<<endl;
					
				cout<<"\n\nROZNE PORADY\n";
					for(int i=0; i<p; i++) {
						szukajWTekscie(inf.porady[i], slowo);
					} cout<<endl;
					
				cout<<"\n\nJAK NAPRAC NIEMAL WSZYSTKO\n";
					for(int i=0; i<n; i++) {
						szukajWTekscie(inf.naprawa[i], slowo);	
					} cout<<endl;
					
				cout<<"\n\nJAK USUWAC NIEPRZYJEMNE ZAPACHY\n";
					for(int i=0; i<a; i++) {
						szukajWTekscie(inf.zapachy[i], slowo);
					} cout<<endl;
					
				cout<<"\n\nDOMOWE SPOSOBY NA CHOROBY\n";
					for(int i=0; i<c; i++) {
						szukajWTekscie(inf.choroby[i], slowo);	
					} cout<<endl;
					
			 	cout<<"\n\nLECZNICZE WLASCIWOSCI MIODU\n";
					for(int i=0; i<m; i++) {
						szukajWTekscie(inf.miod[i], slowo);	
					} cout<<endl;
					
			 	cout<<"\n\nABC AROMATERAPII\n";
					for(int i=0; i<a; i++) {
						szukajWTekscie(inf.aroma[i], slowo);	
					} cout<<endl;
				break;
				
		case 2: cout<<"------------------------------------------------------------------------------------"<<endl;
				cout<<"  1:Czyszczenie  2:Porady  3:Naprawa  4:Zapachy  5:Choroby  6:Miod  7:Aromaterapia  "<<endl;
				
				cout<<"Co chcesz wyswietlic: "; int wybor; cin>>wybor;
				switch(wybor) {
					case 1: cout<<"\n\nJAK WYCZYSCIC NIEMAL WSZYSTKO\n";
							for(int i=0; i<z; i++) {
								szukajWTekscie(inf.czyszczenie[i], slowo);
							} cout<<endl;
							break;
					case 2: cout<<"\n\nROZNE PORADY\n";
							for(int i=0; i<p; i++) {
								szukajWTekscie(inf.porady[i], slowo);	
							} cout<<endl;
						break;
					case 3: cout<<"\n\nJAK NAPRAC NIEMAL WSZYSTKO\n";
							for(int i=0; i<n; i++) {
								szukajWTekscie(inf.naprawa[i], slowo);	
							} cout<<endl;
						break;
					case 4: cout<<"\n\nJAK USUWAC NIEPRZYJEMNE ZAPACHY\n";
							for(int i=0; i<a; i++) {
								szukajWTekscie(inf.zapachy[i], slowo);
							} cout<<endl;
						break;
					case 5: cout<<"\n\nDOMOWE SPOSOBY NA CHOROBY\n";
							for(int i=0; i<c; i++) {
								szukajWTekscie(inf.choroby[i], slowo);	
							} cout<<endl;
					    break;
					case 6: cout<<"\n\nLECZNICZE WLASCIWOSCI MIODU\n";
							for(int i=0; i<m; i++) {
								szukajWTekscie(inf.miod[i], slowo);
							} cout<<endl;
						break;
					case 7: cout<<"\n\nABC AROMATERAPII\n";
							for(int i=0; i<a; i++) {
								szukajWTekscie(inf.aroma[i], slowo);	
							} cout<<endl;
						break;
				}
	}	
}

