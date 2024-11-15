#include <iostream>    
#include <cstdlib>   
#include <fstream>
#include <ctime>
#include <iomanip>
#include "DzienniczekUcznia.hpp"

using namespace std;

int Menu(){
	
  	system("cls");
  	cout<<"| 1:Wydarz | 2:Plan | 3:Zakupy | 4:Zwyczaje | 5:Info | 6:Notki | 7:Hasla / 8:Dziennik \\ 9:Archiwum | <>:Wyjscie |"<<endl;
	cout<<"-------------------------------------------------------------------------              --------------------------"<<endl;
      
  	if(znak==0){
  		Konfiguracja();
  		znak=1;
		Zapisz();
  		
	} 
	else WyswietlCalosc();
     
	cout<<"\n-------------------------------------------------------------"<<endl;
	cout<<"        1:Zapisz    2:Dodaj    3:Czysc   <>:Wyjscie  "<<endl<<endl; 
	
	cout<<"Wybor: "; int w;  cin>>w;
	return w;
  	
  }
    
  
  
int Dzienniczek() {
	char c='n';
	
	Zerowanie();
	OdczytajDz();
	

	do {
		system("cls");	
		//	cout<<"Zamiast ' ' wpisz '_' "<<endl<<endl;
		
		
		int wybor=Menu();
		switch(wybor) {
				case 1: ZapiszDz();			break;
				case 2: DodajDz();  		break;
				//case 3: Szukaj();			break;
				//case 3: Konfiguracja();	break;
				//case 3: Usun();			break;
				case 3: ZerowanieDz();		break;
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



