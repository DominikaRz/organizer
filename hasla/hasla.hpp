//hasla.hpp  
#include <iostream>
#include <cstdlib>   
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string.h>

using namespace std;

struct hasla{
	string nazwa;
	string login;
	string haslo;	
};

void KonfiguracjaH();
void ZerowanieH();
void WyswietlanieH();
void OdczytH();
void ZapisH();
void deszyfrowanie();
int szyfrowanie(int);
int codeToText(int, int);
int textToCode( int, int);
void szyfrowanie(string, int);
void odszyfrowanie(string);

int l=20; //iloœæ hase³
int znac=0, przesuniecie=8;
string nazwa[20], login[20], haslo[20], nazwa1[20], login1[20], haslo1[20];  //szyfr
string kluczz, kluczo;  // o-odszyfrowany, z-zaszyfrowany

hasla has[20];
fstream hasl;

void DodajH() {
 	cout<<"------------------------------------------------------------------------------------\n";
	for(int i=1; i<l; i++)
		if(has[i].nazwa=="") { 
			cout<<"Podaj nazwe strony: "; 	cin>>has[i].nazwa;
			cout<<"Podaj login: "; 			cin>>has[i].login;
			cout<<"Podaj haslo: "; 			cin>>has[i].haslo;
			szyfrowanie(i);
			break;
		}		
	//system("pause");
 }

void ZerowanieH() {

	for(int i=1; i<l; i++){
		if((has[i].nazwa=="")&&(has[i].login=="")&&(has[i].haslo=="")) {
		has[i].nazwa="-";
		has[i].login="-";
		has[i].haslo="-";
		}
	
	}
}

void WyswietlanieH() {
	for(int j=1; j<l; j++) {
        if(has[j].nazwa!="") {
			cout<<setw(10)<<has[j].nazwa; cout<<" | ";
			cout<<setw(10)<<has[j].login; cout<<" | ";
			cout<<setw(10)<<has[j].haslo; cout<<" | ";
			cout<<endl;
		} 
  } cout<<endl;
}

void KonfiguracjaH() {
	
	cout<<"Ile hasel chcesz wpisac na poczatek?: "; int o; cin>>o; o+=1;
	
	for(int i=1; i<o; i++){
		cout<<"Podaj nazwe strony: "; 	cin>>has[i].nazwa;
		cout<<"Podaj login: ";			cin>>has[i].login;
		cout<<"Podaj haslo: "; 			cin>>has[i].haslo;
		
		szyfrowanie(i);
	} 
	
	//Wyswietlanie();
}

//operacje na plikach
void OdczytH() {
	hasl.open("pliki/hasla.txt", ios::in);
	if(hasl.is_open()) {
		//cout<<"Odczytano dane z pliku."<<endl;
		hasl>>znac;
		hasl>>kluczz;
	//odszyfrowywanie has³a
/**/	for( int i = 0; i < kluczz.length(); i++ ){
			if(kluczz[i]=='†') {kluczo +='z'; continue;}
			else kluczo += codeToText( kluczz[i], 12);
		} 
		
		for(int i=1; i<l; i++) {
			hasl>>nazwa[i];
			hasl>>login[i];
			hasl>>haslo[i];			
		}	
		hasl.close();
	}else cout<<"Blad otwarcia pliku.";	
	//deszyfrowanie();
}

void ZapisH() {
	cout<<"------------------------------------------------------------------------------------\n";
	hasl.open("pliki/hasla.txt", ios::out);
	if(hasl.is_open()) {
		cout<<"Zapisano dane do pliku."<<endl;
		hasl<<znac<<endl;
	//szyfrowanie hasla
/**/	hasl<<kluczz<<endl;		
		for(int i=1; i<l; i++) {
			hasl<<nazwa[i]<<" ";
			hasl<<login[i]<<" ";
			hasl<<haslo[i]<<" ";
			hasl<<endl;
		}
		hasl.close();
	}else cout<<"Blad zapisu pliku.";  
	//system("pause");
}

//szyfrowanie pliku
int szyfrowanie(int j) {
    //for(int j=1; j<l; j++){
    	
		if((has[j].nazwa!="-")&&(has[j].login!="-")&&(has[j].haslo!="-")) {
	    	for( int i = 0; i < has[j].nazwa.length(); i++ )
	         	nazwa[j] += textToCode( has[j].nazwa[i], przesuniecie );
	        for( int i = 0; i < has[j].login.length(); i++ )
	         	login[j] += textToCode( has[j].login[i], przesuniecie );
	        for( int i = 0; i < has[j].haslo.length(); i++ )
	         	haslo[j] += textToCode( has[j].haslo[i], przesuniecie );
		//}
		
	}   	
    //cout << endl;
}

void deszyfrowanie() {
	
	
	for(int j = 1; j < l; j++){	
		if((nazwa[j]!="-")&&(login[j]!="-")&&(haslo[j]!="-")) {	
			for( int i = 0; i < nazwa[j].length(); i++ ) {
				if(nazwa[j][i]=='‚') {has[j].nazwa +='z'; continue;}
				else has[j].nazwa += codeToText( nazwa[j][i], przesuniecie );
			} 
	    for( int i = 0; i < login[j].length(); i++ ) {
			  if(login[j][i]=='‚'){has[j].login +='z'; continue;}
	    	else has[j].login += codeToText( login[j][i], przesuniecie );
			}
	    for( int i = 0; i < haslo[j].length(); i++ ) {
	    	if(haslo[j][i]=='‚'){has[j].haslo +='z'; continue;}
	    	else has[j].haslo += codeToText( haslo[j][i], przesuniecie );
			}
	    }
	} 
}

int textToCode( int menu, int przesuniecie ) {
    for( int i = 0; i <= 255; i++ ){
        int j = i + przesuniecie;
        if( menu == i ) return j;
    }
}

int codeToText( int menu, int przesuniecie ) {
    for( int i = 0; i <= 255; i++ ) {
        int j = i + przesuniecie;
        if( menu == j ) return i;
    }
}

