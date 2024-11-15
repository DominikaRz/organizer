//planLekcji.hpp  
#include <cstdlib>   
#include <fstream>
#include <iomanip>

using namespace std;

struct planLekcji{
	string lekcja[10];
	string godzina;
	string nazwa;
};

void KonfiguracjaPl();
void ZerowaniePl();
void WyswietlaniePl();
void OdczytPl();
void ZapisPl();
void ZamianaPl();
int IloscLekcji();


int const y=6, g=10;
planLekcji plan[10];
fstream planl;
int zna, le;
string dz;

int IloscLekcji(){
	cout<<"Ile dni w tygodniu masz lekcje?: "; int g; cin>>g; g+=1; 
	cout<<"Ile najwiecej masz lekcji?: "; int m; cin>>m; m+=1; 
}

void ZerowaniePl() {
	cout<<"Czy na pewno chcesz wyzerowac?: [t]ak lub [n]ie  "; char c; cin>>c;
	if(c=='t') {
	for(int i=1; i<g; i++)
		for(int j=1; j<y; j++){
			plan[i].godzina="-";
			plan[i].lekcja[j]="-";
		}
	zna=0;
	}
}

void ZamianaPl() {
	cout<<"\nPodaj plan i godzine lekcjna, ktora chcesz zamienic: "; cin>>dz>>le;
			if((dz=="Pn")||(dz=="pn")) {
			cout<<"Podaj nazwe: "; do{
					getline(cin,plan[le].lekcja[1]);
				} while(plan[le].lekcja[1].size()<=0 || plan[le].lekcja[1].size()>=254);
			}	
			if((dz=="Wt")||(dz=="wt")) {
				cout<<"Podaj nazwe: "; 
				do{
					getline(cin,plan[le].lekcja[2]);
				} while(plan[le].lekcja[2].size()<=0 || plan[le].lekcja[2].size()>=254);
			}		
			if((dz=="Sr")||(dz=="sr")) {
				cout<<"Podaj nazwe: "; 
				do{
					getline(cin,plan[le].lekcja[3]);
				} while(plan[le].lekcja[3].size()<=0 || plan[le].lekcja[3].size()>=254);
			}		
			if((dz=="Cz")||(dz=="cz")) {
				cout<<"Podaj nazwe: "; 
				do{
					getline(cin,plan[le].lekcja[4]);
				} while(plan[le].lekcja[4].size()<=0 || plan[le].lekcja[4].size()>=254);
			}		
			if((dz=="Pt")||(dz=="pt")) {
				cout<<"Podaj nazwe: "; 
					do{
					getline(cin,plan[le].lekcja[5]);
				} while(plan[le].lekcja[5].size()<=0 || plan[le].lekcja[5].size()>=254);
			}		
		}

void WyswietlaniePl() {
	cout<<setw(11)<<"godz"; cout<<setw(16)<<"Pn"; cout<<setw(19)<<"Wt"; cout<<setw(19)<<"Sr"; cout<<setw(19)<<"Cz"; cout<<setw(19)<<"Pt"; 
	for (int i=1; i<g; i++) {
        cout<<endl;
		cout<<setw(11)<<plan[i].godzina;
        cout<<" |";
        for (int j=1; j<y; j++) {
			cout<<setw(17)<<plan[i].lekcja[j]; // Wyœwietl zawartoœæ komórki na 17 miejscach
            if(j<g) cout<<" |";
            else  cout<<endl;
        }
    } cout<<endl;
}
    
void OdczytPl() {
	planl.open("pliki/planLekcji.txt", ios::in);
	if(planl.is_open()) {
		//cout<<"Odczytano dane z pliku."<<endl;
		planl>>zna;
		for(int i=1; i<g; i++){
			planl>>plan[i].godzina;
			for(int j=1; j<y; j++) {
				getline(planl,plan[i].lekcja[j]);
				//plan>>plan[i].lekcja[j];
			}	
		}
		planl.close();
	}else cout<<"Blad otwarcia pliku."<<endl;	
}

void ZapisPl() {
//	system("cls");
	planl.open("pliki/planLekcji.txt", ios::out);
	if(planl.is_open()) {
		cout<<"Zapisano dane do pliku."<<endl;
		planl<<zna<<endl;
		for(int i=1; i<g; i++) {
			planl<<plan[i].godzina<<" ";
			for(int j=1; j<y; j++){
				planl<<plan[i].lekcja[j]<<" ";
				planl<<endl;
			}	
		}
		planl.close();
	}else cout<<"Blad zapisu pliku."<<endl;  
}
	
void KonfiguracjaPl() {
	//IloscLekcji();
	for(int i=1; i<g; i++){
		cout<<i<<" lekcja"<<endl;
		cout<<"Podaj zakres godzin lekcji: "; 
		cin>>plan[i].godzina;
		for(int j=0; j<y; j++){
			if(j!=0) {
				cout<<"Podaj nazwe lekcji: "; 
				do{
					getline(cin,plan[i].lekcja[j]);
				} while(plan[i].lekcja[j].size()<=0 || plan[i].lekcja[j].size()>=17);
			}
			else cout<<"";
		} 	
		cout<<endl;
	}
}


