#include <iostream>
#include <cstdlib>
#include "hasla.hpp"

using namespace std;

int MenuH() {
	system("cls");
	cout<<"| 1:Wydarz | 2:Plan | 3:Zakupy | 4:Zwyczaje | 5:Info | 6:Notki / 7:Hasla \\ 8:Dziennik | 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"---------------------------------------------------------------           ---------------------------------------"<<endl;
	
	WyswietlanieH();
		 
	cout<<"--------------------------------------------------"<<endl;
	cout<<"         1:Zapisz    2:Dodaj    <>:Wyjscie  "<<endl<<endl;
	
	cout<<"Wybor: "; int w;  cin>>w;
	return w;
	
}

int Hasla() {
	char c='n';
	string ha;
/**/	
	//ZerowanieH();
	OdczytH();
	deszyfrowanie();
	
	if (znac==0){	
			cout<<"Podaj haslo pamietajac, ze bedzie ono potem uzywane: "; cin>>kluczo;
			for( int i = 0; i < kluczo.length(); i++ )
	    	kluczz += textToCode( kluczo[i], 12); 
			ZerowanieH();
			KonfiguracjaH();
			znac=1;
			ZapisH();
		} 
	else { 
		cout<<"Podaj haslo: "; cin>>ha;
		if(kluczo==ha) {
			system("cls");
			//WyswietlanieH();	
		}	
		else {
			cout<<"\nNiestety, podales zle chaslo. \nNastapi zamkniecie podprogramu.\n\n";
			system("pause");
			exit( 0 );
		} 
	}
			
	do {		
		
		 		
		int wybor=MenuH();
		switch(wybor) {
				case 1: ZapisH();  			break;
				case 2: DodajH();			break;
				//case 3: WyswietlanieH();	break;
				//case 4: szyfrowanie();	break;
				//case 5: deszyfrowanie();	break;
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


