//archiwizacja.hpp
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;

void ArchiwumRok() { //archiwum calego roku (stosowany przy funkcji NowyRok)
	system("cls");  //czyszczenie ekranu
	string nazwa1, nazwa2;
	string poczatek1 = "mkdir archiwum\\koniec_roku\\" , poczatek2 = "copy pliki archiwum\\koniec_roku\\";

//pobieranie czasu systemowego	
	time_t now = time(0);
	tm *ltm = localtime(&now);

  float rok=1900+ltm->tm_year; //pobranie terazniejszego roku
	char Cstr[100];

	//konwersja z float na char
   gcvt(rok, 7, Cstr);
	 //cout << Cstr;
	 
	cout<<"Archiwizacja calego roku."<<endl;
//tworzenie nowego katalogu
		nazwa1=poczatek1 + Cstr;
		system( nazwa1.c_str() );
//kopiowanie plików
		nazwa2=poczatek2 + Cstr;
		system( nazwa2.c_str() );
	

	system("pause");
}

 

