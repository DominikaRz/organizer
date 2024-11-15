//wydarzenia.hpp
#include <cstdlib>
#include <iomanip>  
#include <fstream>
#include <ctime>

using namespace std;

struct miesiac {
	double godzina[32][20];      //wyswietlanie po kropce
	string wydarzenie[32][20];
	string urodziny[32][10];
};

void ZerowanieW();
void OdczytajW();
void DodajW();
void WypiszW();
int  WypiszTerazW(int,int);
void ZapiszW();
void KasujW();
int SortowanieW(int);
void UrodzinyW();
void NowyRok();

const int wm=13, wd=32, ww=20, wu=10; //wielkoœæ miesi¹ca, wielkosc dni, wielkosc wydarzenia, wielkoœæ urodzin
int rekord;
double ppom, godz;
string wyd, pom;

miesiac mie[13];
fstream plik;

//POBIERANIE AKTUALNEGO CZASU Z SYSTEMU
time_t now = time(0); 
tm *ltm = localtime(&now); //zamiana z czasu kalendarzowego na lokalny

int rok= 1900+ltm->tm_year;
int mies = 1+ltm->tm_mon;
int dzien = ltm->tm_mday;

void ZerowanieW() {
	for(int h=1; h<wm; h++)
		for(int d=1; d<wd; d++){
			for(int i=1; i<ww; i++) {
				mie[h].godzina[d][i]=0;
				mie[h].wydarzenie[d][i]="-";
			}
			for(int i=0; i<wu; i++){
				mie[h].urodziny[d][i]="-";
			}	
		}
			
}

void UrodzinyW() {
	
	cout<<" Podaj miesiac urodzin: "; int m; cin>>m;
	cout<<" Podaj dzien urodzin: "; int d; cin>>d;
	for(int i=1; i<wu; i++) {
		if(mie[m].urodziny[d][i]=="-") { 
			cout<<" Kto ma w tym dniu urodziny?: ";	
			do{
				getline(cin,mie[m].urodziny[d][i]);
			} while(mie[m].urodziny[d][i].size()<=0 || mie[m].urodziny[d][i].size()>=254);
			break;
		} 
	}	
}

int SortowanieW(int m) {	
	for(int d=1; d<wd; d++)
		for(int j=1; j<wd-1; j++)
			for(int i=1; i<ww; i++) 
			//	if(mie[d].godzina[i]!=0) 
					if((mie[m].godzina[d][i]>mie[m].godzina[d][i+1])&&(mie[m].godzina[d][i+1]!=0)) {
						swap(mie[m].godzina[d][i], mie[m].godzina[d][i+1]);
						swap(mie[m].wydarzenie[d][i], mie[m].wydarzenie[d][i+1]);
					} 
}

void DodajW() {
 cout<<"------------------------------------------------------------------------------------\n";
	cout<<" Podaj miesiac: "; int m; cin>>m;
	cout<<" Podaj dzien: "; int d; cin>>d;
	for(int i=1; i<ww; i++)
		if((mie[m].wydarzenie[d][i]=="-")&&(mie[m].godzina[d][i]==0)) { 
			cout<<" Podaj godzine: ";		cin>>mie[m].godzina[d][i];
			cout<<" Podaj wydarzenie: "; 	//cin>>mie[m].wydarzenie[d][i];
			do{
				getline(cin,mie[m].wydarzenie[d][i]);
			} while(mie[m].wydarzenie[d][i].size()<=1 || mie[m].wydarzenie[d][i].size()>=254);
			break;
		} 
 }
 
void WypiszW() {
	cout<<"------------------------------------------------------------------------------------\n";
	cout<<"Podaj miesiac: "; int m; cin>>m;
	Sortowanie(m);	
	for(int d=1; d<wd; d++) {
		cout<<"\n";
		cout<<setw(2)<<d;
	    cout<<"| ";
	    //else  cout<<endl;
	    for(int i=1; i<ww; i++) {
				if((mie[m].godzina[d][i]!=0)&&(mie[m].wydarzenie[d][i]!="-")){
					cout<<setw(14)<<" "; printf("%.2f",mie[m].godzina[d][i]); 
					cout<<" "<<mie[m].wydarzenie[d][i]; 
		        	if(i<ww) cout<<" | "<<endl;
		        	else  cout<<endl;
			}
	    }
	} cout<<endl;
}

int WypiszTerazW(int d, int m) {
	Sortowanie(m);
		cout<<"\n";
		cout<<setw(2)<<d;
        cout<<"|  ";
        if(mie[m].wydarzenie[d][0]!="-") {
        	cout<<mie[m].wydarzenie[d][0]; cout<<"   Ur: ";
			for(int i=1; i<wu; i++){
				if(mie[m].urodziny[d][i]!="-") 
	         		cout<<mie[m].urodziny[d][i]<<", ";
			} cout<<endl;
		} 
		else  cout<<endl;
        for(int i=1; i<ww; i++) {
					if((mie[m].wydarzenie[d][i]!="-")&&(mie[m].godzina[d][i]!=0)){
						printf("    %.2f",mie[m].godzina[d][i]); cout<<" "<<mie[m].wydarzenie[d][i]<<endl;
				//cout<<"    "<<mie[d].godzina[i]<<" "<<mie[d].wydarzenie[i]<<endl; 
			}
        } cout<<endl;
}

void KasujW() {
	cout<<"------------------------------------------------------------------------------------\n";
	cout<<"Podaj dzien: ";	cin>>rekord;
	cout<<"Podaj godzine:";  cin>>godz;
	for(int i=1; i<ww; i++)
		if(mie[mies].godzina[rekord][i]==godz){
			mie[mies].godzina[rekord][i]=0;
			mie[mies].wydarzenie[rekord][i]="-";
		}
}

void ZapiszW() {
	cout<<"------------------------------------------------------------------------------------\n";
	plik.open("pliki/miesiac.txt", ios::out);
	if(plik.is_open()) {
		cout<<"Zapisano dane do pliku."<<endl;
		for(int h=1; h<wm; h++)
			for(int d=1; d<wd; d++) {
				plik<<mie[h].wydarzenie[d][0]<<endl;
				for(int i=1; i<ww; i++) {
					plik<<mie[h].godzina[d][i]<<" ";
					plik<<mie[h].wydarzenie[d][i]<<endl;
				} 
				for(int i=0; i<wu; i++) {
					plik<<mie[h].urodziny[d][i]<<endl;
				} //plik<<endl;	
		}
		plik.close();
	}else cout<<"Blad zapisu pliku.";
}

void OdczytajW() {
	plik.open("pliki/miesiac.txt", ios::in);
	if(plik.is_open()) {
		//cout<<"Odczytano dane z pliku."<<endl;
		for(int h=1; h<wm; h++) {
			for(int d=1; d<wd; d++) {
				getline(plik,mie[h].wydarzenie[d][0]);
				for(int i=1; i<ww; i++) {
					plik>>mie[h].godzina[d][i];
					//plik>>mie[h].wydarzenie[d][i];
					getline(plik,mie[h].wydarzenie[d][i]);
				}
				for(int i=0; i<wu; i++) 
					getline(plik,mie[h].urodziny[d][i]);
			}
		}
			
		plik.close();
	}else cout<<"Blad otwarcia pliku.";
}

void TerazniejszyCzasW() {
	//d=DzienTyg();
	

/*	if(mies==1) {
		cout<<"mieCZEN"<<endl;
		for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
			WypiszTerazmie(i); 
		} 	
	} */
	
//WYPISZ TERANIEJSZE DANE
	switch(mies) {
		case 1:  
				cout<<"STYCZEN"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==31){
					cout<<"LUTY"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
						 
				if(dzien==30){
					cout<<"LUTY"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 2:  
				cout<<"LUTY"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=28) ;i++){
					WypiszTeraz(i,mies); 
				}
				if(dzien==28) {
					cout<<"MARZEC"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
				
				if(dzien==27) {
					cout<<"MARZEC"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 3: 
				cout<<"MARZEC"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
					WypiszTeraz(i, mies); 
				} 
				if(dzien==31) {
					cout<<"KWIECIEN"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==30){
					cout<<"KWIECIEN"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 4: 
				cout<<"KWIECIEN"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=30) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==30){
					cout<<"MAJ"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==29) {
					cout<<"MAJ"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 5: 
				cout<<"MAJ"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==31) {
					cout<<"CZERWIEC"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==30) {
					cout<<"CZERWIEC"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 6:  
				cout<<"CZERWIEC"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=30) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==30) {
					cout<<"LIPIEC"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==29) {
					cout<<"LIPIEC"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 7:  
				cout<<"LIPIEC"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==31) {
					cout<<"SIERPIEN"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==30) {
					cout<<"SIERPIEN"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 8:  
				cout<<"SIERPIEN"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==31) {
					cout<<"WRZESIEN"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==30) {
					cout<<"WRZESIEN"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 9:  
				cout<<"WRZESIEN"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=30) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==30) {
					cout<<"PAZDZIERNIK"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==29) {
					cout<<"PAZDZIERNIK"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 10: 
				cout<<"PAZDZIERNIK"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==31) {
					cout<<"LISTOPAD"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==30) {
					cout<<"LISTOPAD"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 11: 
				cout<<"LISTOPAD"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=30) ;i++){
					WypiszTeraz(i,mies); 
				} 
				if(dzien==30) {
					cout<<"GRUDZIEN"<<endl;
					for(int i=1; i<=2 ;i++){
						WypiszTeraz(i,(mies+1));
					}
				}
					
				if(dzien==29) {
					cout<<"GRUDZIEN"<<endl;
					for(int i=1; i<1 ;i++){
						WypiszTeraz(i,(mies+1)); 
					} 
				}
					
			break;
		case 12: 
				cout<<"GRUDZIEN"<<endl;
				for(int i=dzien; (i<(dzien+3))&&(i<=31) ;i++){
					WypiszTeraz(i,mies); 
				} 
			break;
	}
} 

void NowyRok() {

//ZEROWANIE PLIKÓW 
   if((mies==12)&&(dzien==31)){
//archiwizacja ca³ego poprzedniego roku		
 		ArchiwumRok();
//zerowanie
		Zerowanie(); //Dzienniczek
		ZerowaniePl();//plan
		ZerowanieZ();//zwyczaje
//przypisywanie œwi¹t sta³ych
	//Styczen		
		mie[1].wydarzenie[1][0] ="Nowy Rok";
		mie[1].wydarzenie[6][0] ="Trzech Kroli";
		mie[1].wydarzenie[21][0]="Dzien Babci";
		mie[1].wydarzenie[22][0]="Dzien Dziadka";
	//Luty		
		mie[2].wydarzenie[14][0]="Walentynki";
	//Marzec		
		mie[3].wydarzenie[8][0] ="Dzien Kobiet";
	//Maj		
		mie[5].wydarzenie[1][0]="Swieto Pracy";
		mie[5].wydarzenie[2][0]="Swieto Flagi RP";
		mie[5].wydarzenie[3][0]="Swieto Konmietucji 3 Maja";
		mie[5].wydarzenie[26][0]="Dzien Matki";
	//Czerwiec		
		mie[6].wydarzenie[1][0]="Dzien Dziecka";
		mie[6].wydarzenie[23][0]="Dzien Ojca";
	//Sierpieñ	
		mie[8].wydarzenie[15][0]="Swieto Wojska Polskiego / Wniebowziecia NMP";
	//Wrzesieñ	
		mie[9].wydarzenie[30][0]="Dzien Chlopaka";
	//PaŸdziernik	
		mie[10].wydarzenie[14][0]="Dzien Nauczyciela / Edukacji Narodowej";
	//Listopad
		mie[11].wydarzenie[1][0]="Wszystkich Swietych";
		mie[11].wydarzenie[2][0]="Zaduszki";
		mie[11].wydarzenie[11][0]="Swieto Niepodleglosci";
		mie[11].wydarzenie[29][0]="Andrzejki";
		
		mie[12].wydarzenie[4][0]="Barbórka";
		mie[12].wydarzenie[6][0]="Mikolajki";
		mie[12].wydarzenie[24][0]="Wigilia Bozego Narodzenia";
		mie[12].wydarzenie[25][0]="Boze Narodzenie";
		mie[12].wydarzenie[26][0]="Boze Narodzenie";
		mie[12].wydarzenie[31][0]="Sylwester";
	
		
//zapisywanie		
		Zapisz();
	}
}

