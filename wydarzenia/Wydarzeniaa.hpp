#include <iostream>    
#include <cstdlib>   
#include <fstream>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <string>
//moje bibloteki
#include "archiwizacja.hpp"
#include "kalendarz.hpp"
#include "dzien_tygodnia.hpp"
#include "wydarzenia.hpp"

using namespace std;

int MenuWyd() {
	system("cls");
	//system("Color 74");
	
	cout<<"/ 1:Wydarz \\ 2:Plan | 3:Zakupy | 4:Zwyczaje | 5:Info | 6:Notki | 7:Hasla | 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"            -----------------------------------------------------------------------------------------------------"<<endl;
	
//Wyswietlanie kalendarza graficznie
	Kalendarz();
//Wyœwietlanie trzech dni
	TerazniejszyCzas();
	
	int y;
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"   1:Wyswietl   2:Dodaj   3:Zapisz   4:Kasuj   5:Urodziny   <>:Wyjscie\n"<<endl<<endl;
	
	cout<<"Wybierz: ";
	cin>>y;
	return y;
	
}

int Wydarzenia() {
	//system("cls");  //czyszczenie ekranu
	char c='n';
	
//archiwizacja i zerowanie plików z dniem 31 grudnia 
	NowyRok();	

//ODCZYTANIE DANYCH Z PLIKU	
	ZerowanieW();
	OdczytajW();	
	
	do {
		int wybor=MenuWyd();
		switch(wybor) {
	
			//Wypisz dane
			case 1: WypiszW(); break;
			
			//Dodaj dane
			case 2: DodajW(); break;

			//Zapisz do pliku
			case 3: ZapiszW(); break;
			
			//Kasowanie danych
			case 4: KasujW(); break;
			
			//dodawanie urodzin		
			case 5: UrodzinyW(); break;
					
			//Koniec	
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

/* */
