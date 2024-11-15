#include <iostream>    
#include <cstdlib>   
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

//bibplik6
    
struct przedmioty {
	string nazwa;
	double oceny[31];
	double srednia; 
};

int Przeksztalcenie(int, int);
void Dodaj();
void WyswietlCalosc();
//void Szukaj();
void Srednia();
int Komunikat(int i);
void Zapisz();
void Odczytaj();
void Konfiguracja();
void Usun();
void Zerowanie();
int Menu();
  
int wt=21, io=26, ilosc=0 ; //wielkoœæ bazy danych = ilosc przedmiotow, iloscOcen 
char TN='n';				//Tak lub Nie

double so, sp, s; 			//suma wielkosci ocen, suma sredni przedmiotów, srednia
string przedmiot;
int znak=0;

przedmioty prz[21];
fstream przed;	
  
  
void Konfiguracja() {

	cout<<"Ile masz przedmiotow w tym semestrze?: "; int y; cin>>y;	  
    for(int i=1; i<=y; i++){
    	if (prz[i].nazwa=="-"){
        	cout<<"\nPrzedmiot: ";  cin>>prz[i].nazwa;
          	cout<<"Ile ocen chcesz wpisac?: "; int o; cin>>o;
          	cout<<"Oceny: ";
        	for(int j=1; j<=o; j++) {
        		cin>>prz[i].oceny[j];
			} //break;	
		} 
	}
}
    
void Srednia(){
 int l, l1=0;					//iloœæ liczb, ilosc liczb w œredniej ca³oœciowej
 
    for(int i=1; i<wt; i++) {
     	if(prz[i].nazwa!="-") {
			for(int j=1; j<io; j++) {
     		if(prz[i].oceny[j]!=0){
     			so+=prz[i].oceny[j];
				l=l+1;		
			}	
     		else continue;
		}
		prz[i].srednia=so/l;	//przypisanie œredni przedmiotom 
     	
			sp=sp+prz[i].srednia;
     	l1=l1+1;
		
		} 
	}
	s=sp/l1; //œrednia z wszystkich przedmiotów	 /* */
}

int Przeksztalcenie(int i, int j) { //oceny na + i 
	
	if(prz[i].oceny[j]==1) 		cout<<" 1,";
	if(prz[i].oceny[j]==1.5) 	cout<<"1+,";
	if(prz[i].oceny[j]==1.75) 	cout<<"2-,";
	if(prz[i].oceny[j]==2) 		cout<<" 2,";
	if(prz[i].oceny[j]==2.5) 	cout<<"2+,";
	if(prz[i].oceny[j]==2.75) 	cout<<"3-,";
	if(prz[i].oceny[j]==3) 		cout<<" 3,";
	if(prz[i].oceny[j]==3.5) 	cout<<"3+,";
	if(prz[i].oceny[j]==3.75)	cout<<"4-,";
	if(prz[i].oceny[j]==4) 		cout<<" 4,";
	if(prz[i].oceny[j]==4.5) 	cout<<"4+,";                                           
	if(prz[i].oceny[j]==4.75) 	cout<<"5-,";
	if(prz[i].oceny[j]==5) 		cout<<" 5,";
	if(prz[i].oceny[j]==5.5) 	cout<<"5+,";
	if(prz[i].oceny[j]==5.75) 	cout<<"6-,";
	if(prz[i].oceny[j]==6) 		cout<<" 6,";
}

void WyswietlCalosc() {
	
	cout<<setw(2)<<" NR|"<<setw(14)<<"PRZEDMIOT |"<<setw(40)<<"OCENA "<<setw(50)<<"| SREDNIA |"<<endl;
	Srednia();	
	for(int i=1; i<wt; i++) {
        if(prz[i].nazwa!="-") {
			cout<<setw(3)<<i<<"|"<<setw(13)<<prz[i].nazwa<<"|";
			for(int j=1; j<io; j++) {
	        	if(prz[i].oceny[j]!=0) {
	        	 	   cout<<setw(3);	Przeksztalcenie(i,j); //cout<<" ";  // Wyœwietl zawartoœæ komórki na 3 miejscach
	        		//if (j==io) cout<<"|"; cout << internal<<" ";
	        		
				} else cout<<setw(3)<<" ";
	        	//else  cout<<"|";   
			}
	       	//cout.width(6); //cout << right cout.width(6);
			   cout<<setw(6)<<" | "; printf("%.2f",prz[i].srednia); Komunikat(i); cout<<"|"; 
			cout<<endl;
        }
    }
	cout<<"\nSerdnia calosciowa: "<<s;
} 
 
/*void Szukaj(){
	
	cout<<"--------------------------------------------------------------------------------";
    cout<<"\nPodaj nazwe przedmiotu: ";   cin>>przedmiot;
    for(int i=1; i<wt; i++) {
		if(przedmiot==prz[i].nazwa) {
			cout<<i<<"|"<<prz[i].nazwa;
			for(int j=1; j<io; j++) {
				if(prz[i].oceny[j]!=0) {
					cout<<setw(3)<<prz[i].oceny[j];  // Wyœwietl zawartoœæ komórki na 3 miejscach
		        	if (j<io) cout <<", ";
		        	else  cout<<"|";   
	       		}
			}
	       	cout<<setw(10)<<prz[i].srednia; cout<<endl;
		}
	}
}    */
   
int Komunikat(int i) {
  	//cout<<"\n--------------------------------------------------------------------------------"; 
	 // for(int i=1; i<wt; i++) {
		  if ((prz[i].srednia<1)&&(prz[i].srednia>=2)) cout<<"  :(";
	      if ((prz[i].srednia=2)&&(prz[i].srednia>=3)) cout<<"  :|";
	      if ((prz[i].srednia=3)||(prz[i].srednia>=4)) cout<<"  :)";
	      if ((prz[i].srednia=4)&&(prz[i].srednia>=5)) cout<<"  ;)";
	      if ((prz[i].srednia=5)&&(prz[i].srednia>=6)) cout<<"  :D";
	      if ((prz[i].srednia=6)&&(prz[i].srednia>=7)) cout<<"  ;D";
	      
    //}
	//cout<<"POPRAW SIÊ W NAUCE!!! X(, Mog³o by byæ lepiej :(, Trochê lepiej :), Bardzo dobrze ;), Tak trzymaj :D, Wyœmienicie ;D";
    //cout<<"\n--------------------------------------------------------------------------------"; 
}
  /*  */ 
void OdczytajDz() {
	
	przed.open("pliki/dzienniczek.txt", ios::in);
	if(przed.is_open()) {
		przed>>znak;
		for(int i=1; i<wt; i++) {
			przed>>prz[i].nazwa;
			for(int j=1; j<io; j++) {
				przed>>prz[i].oceny[j];
			}
			przed>>prz[i].srednia;
		}
			
		przed.close();
	}else cout<<"Blad otwarcia pliku.";
}

void ZapiszDz() {
	
	Srednia();
	przed.open("pliki/dzienniczek.txt", ios::out);
	if(przed.is_open()) {
		cout<<"Zapisano dane do pliku."<<endl;
		przed<<znak<<endl;
		for(int i=1; i<wt; i++) {
			przed<<prz[i].nazwa<<" ";
			for(int j=1; j<io; j++) {
				przed<<prz[i].oceny[j]<<" ";
			}
			przed<<prz[i].srednia<<endl;
		}
		przed.close();
	}else cout<<"Blad zapisu pliku.";
	system("pause");
}
   
void DodajDz() {
  	
	cout<<"Podaj index przedmiotu: "; int f; cin>>f;
    cout<<"Ocena: ";
    for(int j=1; j<io; j++) {
    	if(prz[f].oceny[j]==0) {
    		cin>>prz[f].oceny[j];
    		break;
		} 
	} 
}
     
void Usun() {
	cout<<"Podaj index przedmiotu do usuniecia: "; int i; cin>>i;	
  	prz[i].nazwa="-";
  	for(int j=1; j<io; j++) {
  		prz[i].oceny[j]=0;
	  }
  	prz[i].srednia=0;	
	  
	if(prz[i].nazwa=="-") {
		for(int j=i; j<wt; j++) {
			swap(prz[j-1].nazwa, prz[j].nazwa);
			swap(prz[j-1].srednia, prz[j].srednia);
				for(int k=1; k<io; k++) {
				swap(prz[j-1].oceny[k], prz[j].oceny[k]);
			}  	break;
		}
	}
	
}
    
void ZerowanieDz() {
	cout<<"Czy na pewno chcesz wyzerowac?: [t]ak lub [n]ie  "; char c; cin>>c;
	if(c=='t') {
		for(int i=1; i<wt; i++){
  			prz[i].nazwa="-";
  			for(int j=1; j<io; j++) {
  				prz[i].oceny[j]=0;
			  }
  			prz[i].srednia=0;		
		}
		znak=0;
	}
  	
}
    
 
