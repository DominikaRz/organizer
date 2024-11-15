//archiwizacja.hpp
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;

int OdczytAr(int r) {
	
	char Cstr[100];

	string poczatek="archiwum/koniec_roku/", miesiac="/miesiac.txt", dziennik="/dzienniczek.txt",
	hasla="/hasla.txt", plan="/planLekcji.txt", zakupy="/zakupy.txt",	zwyczaje="/zwyczaje.txt",
	notatnik="/notatnik.txt";
	
	string nazwa1=poczatek+Cstr+miesiac;
	string nazwa2=poczatek+Cstr+dziennik;
	string nazwa3=poczatek+Cstr+hasla;
	string nazwa4=poczatek+Cstr+plan;
	string nazwa5=poczatek+Cstr+zwyczaje;
	string nazwa6=poczatek+Cstr+notatnik;
		
//Odczytanie pliku miesiêcy
		plik.open(nazwa1.c_str(), ios::in);
		if(plik.is_open()) {
			for(int h=1; h<wm; h++) {
				for(int d=1; d<wd; d++) {
					getline(plik,mie[h].wydarzenie[d][0]);
					for(int i=1; i<ww; i++) {
						plik>>mie[h].godzina[d][i];
						getline(plik,mie[h].wydarzenie[d][i]);
					}
					for(int i=0; i<wu; i++) 
						getline(plik,mie[h].urodziny[d][i]);
				}
			}
			plik.close();
			
		
//Odczytanie pliku dzienniczka ocen
		plik.open(nazwa2.c_str(), ios::in);
		if(plik.is_open()) {
			przed>>znak;
			for(int i=1; i<wt; i++) {
				przed>>prz[i].nazwa;
				for(int j=1; j<io; j++) {
					przed>>prz[i].oceny[j];
				}
				przed>>prz[i].srednia;
			}
		}
		plik.close();
	
		
//Odczytanie pliku hase³
		plik.open(nazwa3.c_str(), ios::in);
		if(plik.is_open()) { 
			hasl>>znac;
			hasl>>kluczz;
		//odszyfrowywanie has³a
			for( int i = 0; i < kluczz.length(); i++ ){
				if(kluczz[i]=='†') {kluczo +='z'; continue;}
				else kluczo += codeToText( kluczz[i], 12);
			} 
			for(int i=1; i<l; i++) {
				hasl>>nazwa[i];
				hasl>>login[i];
				hasl>>haslo[i];			
			}	
				
		}
		plik.close();
			
/*//Odczytanie pliku planu lekcji
		plik.open(nazwa4.c_str(), ios::in);
		if(plik.is_open()) {
			planl>>zna;
			for(int i=1; i<10; i++){
				planl>>plan[i].godzina;
				for(int j=1; j<6; j++) {
					getline(planl,plan[i].lekcja[j]);
				}	
			}
		}
		plik.close(); */
		
		
//Odczytanie pliku zwyczajów	
		plik.open(nazwa5.c_str(), ios::in);
		if(plik.is_open()) {
			zwycz>>znacznik;
			for(int i=0; i<u; i++) {
				getline(zwycz,zwy[i].nazwa);
				//zwycz>>zwy[i].nazwa;	
			} 
			for(int i=1; i<u; i++)
				for(int j=1; j<n; j++)
					for(int k=1; k<m; k++) 
						zwycz>>zwy[i].mies[j][k];	
		}
		plik.close();
	
		
//Odczytanie pliku notatnika
		plik.open(nazwa6.c_str(), ios::in);
		if(plik.is_open()) {
			for(int i=0; i<x; i++) {
				getline(notat,nota[i].notka);		
			}	
		}
		plik.close();
	}

}

void SzukajAr() {
	
	
	string poczatek="archiwum/koniec_roku/", miesiac="/miesiac.txt";
	char Cstr[100]; char b='n';
	
	cout<<"------------------------------------------------------------------------------------\n";
	cout<<"Podaj rok, ktory chcesz wyswietlic: "; float r; cin>>r;
	gcvt(r, 7, Cstr); //konwersja z float na char
	string nazwa1=poczatek+Cstr+miesiac;
	
	if((access(nazwa1.c_str(), F_OK))!=0) {
	
		OdczytAr(r);		
			do {
				system("cls");
				cout<<"\n                                 ROK "<<r<<endl<<endl;
			
				cout<<"| 1:Wydarz | 2:Plan | 3:Zwyczaje | 4:Notki | 5:Hasla | 6:Dziennik | <>:Wyjscie |"<<endl;
				cout<<"--------------------------------------------------------------------------------"<<endl;
			
				cout<<"Wybor: ";				
				int wybor; cin>>wybor;
				
				switch(wybor) {
					//Wypisz dane
					case 1: Wypisz(); break;
					case 2: WyswietlaniePl(); break;
					case 3: WyswietlCaloscZ(); break;
					case 4: WyswietlanieN(); break;
					case 5: WyswietlanieH(); break;
					case 6: WyswietlCalosc(); break;
					//Koniec	
					default: system("cls"); 
							cout<<"Czy na pewno chcesz zamknac baze: [t]ak, [n]ie  ";	cin>>b;
							if(b=='t') continue; else b='n';
						break;				
				}
				cin.ignore();
				getchar();
			} while(b=='n');
	}
	else cout<<"Niestety w tym roku nie przeprowadzano archiwizacji. Sproboj ponownie pozniej :)";
	
}

void Archiwa() {
	system("cls");  //czyszczenie ekranu	
	string nazwa, nazwa1, nazwa2, nazwa3;
	string poczatek1 = "mkdir archiwum\\" , poczatek2 = "copy pliki archiwum\\", poczatek3 = "archiwum\\";
	
	cout<<"Podaj nazwe archiwum: "; cin>>nazwa;
	nazwa3=poczatek3 + nazwa;
	
//kopiowanie plików	jeœli katalog nieistnieje
	if((access(nazwa3.c_str(), F_OK))!=0) {
//tworzenie nowego katalogu
		nazwa1=poczatek1 + nazwa;
		system( nazwa1.c_str() );
//kopiowanie plików
		nazwa2=poczatek2 + nazwa;
		system( nazwa2.c_str() );
	}
	else{
		cout<<"Nie mozna zarchiwizowac plikow, poniewaz katalog o nazwie "<<nazwa<<endl<<
			 " juz istnieje i mogloby to spowodowac nadpisanie plikow."<<endl<<endl
			 <<"Jeœli chcesz nadpisaæ pliki naciœnij [t]ak lub [n]ie: "; char wy='n'; cin>>wy;
			 if(wy=='t'){
			 	nazwa2=poczatek2 + nazwa;
				system( nazwa2.c_str() );
			 }
			 else system("pause");		
	} 

	system("pause");
}

