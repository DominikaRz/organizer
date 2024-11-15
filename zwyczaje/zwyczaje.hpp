//zwyczaje.hpp  
#include <iostream>
#include <cstdlib>   
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

struct zwyczaje{
	bool mies[13][31];
	string nazwa;
};

void KonfiguracjaZ();
void ZerowanieZ();
void WyswietlanieZ();
void WyswietlCaloscZ();
void SzukajZ();
void OdczytZ();
void ZapisZ();
void ZaznaczZ();

//pobieranie czasu systemowego	
//time_t now = time(0); 
//tm *ltm = localtime(&now); 	//zamiana z czasu kalendarzowego na lokalny
//zmienne
int d=ltm->tm_mday; 		//terazniejszy dzien
int mi=1+ltm->tm_mon;		//teraüniejszy miesiπc
int const u=21, n=13, m=32; 

zwyczaje zwy[21];
fstream zwycz;
int znacznik=0;

void DodajZ() {
 	cout<<"-------------------------------------------------------------------------------\n";
	for(int i=0; i<u; i++)
		if(zwy[i].nazwa=="-") { 
			cout<<"Podaj 'zwyczaj': "; 
			do{
				getline(cin,zwy[i].nazwa);
			} while(zwy[i].nazwa.size()<=1 || zwy[i].nazwa.size()>=19);
			//cin>>zwy[i].nazwa;
			break;
		}
	//system("pause");
 }

void ZerowanieZ() {
	cout<<"Czy na pewno chcesz wyzerowac?: [t]ak lub [n]ie  "; char c; cin>>c;
	if(c=='t') {
		for(int i=0; i<u; i++)
		for(int j=0; j<n; j++) {
			zwy[i].nazwa="-";
			for(int k=0; k<m; k++)
				zwy[i].mies[j][k]=false;
		}
	} 
	
}

void WyswietlCaloscZ() {
	
	cout<<"Ktory miesiac chcesz wyswietlic?: "; int w; cin>>w;
	
	switch(w) {
		case 1:	cout<<setw(22)<<"STYCZEN";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-1)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<m; j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 2:	cout<<setw(22)<<"LUTY  ";
			for(int h=0; h<(m-2); h++) {
				cout<<setw(2)<<h;
				if(h<(m-3)) cout<<"|";
	    		else  cout<<endl;
			}
		
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<(m-2); j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;
					} 
				} 
			} break;
		case 3:	cout<<setw(22)<<"MARZEC";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-1)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<(m-1); j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 4:	cout<<setw(22)<<"KWIECIEN";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-2)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<(m-1); j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;		
		case 5: cout<<setw(22)<<"MAJ";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-1)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<m; j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 6:	cout<<setw(22)<<"CZERWIEC";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-2)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<(m-1); j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 7: cout<<setw(22)<<"LIPIEC";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-1)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<m; j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 8:	cout<<setw(22)<<"SIERPIEN";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-1)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<m; j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 9: cout<<setw(22)<<"WRZESIEN";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-2)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<(m-1); j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 10: cout<<setw(22)<<"PAZDZIERNIK";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-1)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<m; j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 11: cout<<setw(22)<<"LISTOPAD";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-2)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<(m-1); j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			} break;
		case 12: cout<<setw(22)<<"PAZDZIERNIK";
			for(int h=0; h<m; h++) {
				cout<<setw(2)<<h;
				if(h<(m-1)) cout<<"|";
		    	else  cout<<endl;
			}
			//cout<<endl;
			for(int i=0; i<u; i++) {
				if(i!=0){
					if(zwy[i].nazwa!="-") {
						cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
		        		cout<<"|";
						for (int j=0; j<m; j++) {
							cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
				            if(j<m) cout<<"|";
				            else  cout<<endl;
		        		} cout<<endl;	
					}
				} 
			}				
		}
}

void WyswietlanieZ() {

	if(mi==1){
		cout<<setw(22)<<"STYCZEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}
	}
	if(mi==2){
		cout<<setw(22)<<"LUTY  ";
		for(int h=0; h<(m-2); h++) {
			cout<<setw(2)<<h;
			if(h<(m-3)) cout<<"|";
    		else  cout<<endl;
		}
	
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-2); j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;
				} 
			} 
		}
	}
	if(mi==3){
    	cout<<setw(22)<<"MARZEC";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}	
	}
	if(mi==4){
		cout<<setw(22)<<"KWIECIEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}		
	}
	if(mi==5){
    	cout<<setw(22)<<"MAJ";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}	
	}
	if(mi==6){
		cout<<setw(22)<<"CZERWIEC";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}			
	}
	if(mi==7){
		cout<<setw(22)<<"LIPIEC";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}		
	}
	if(mi==8){
		cout<<setw(22)<<"SIERPIEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}		
	}
	if(mi==9){
		cout<<setw(22)<<"WRZESIEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}				
	}
	if(mi==10){
		cout<<setw(22)<<"PAZDZIERNIK";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}			
	}
	if(mi==11){
		cout<<setw(22)<<"LISTOPAD";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}					
	}
	if(mi==12){
		cout<<setw(22)<<"PAZDZIERNIK";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mi][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}				
	}
}

void SzukajZ() {
  cout<<"-------------------------------------------------------------------------------\n";
  cout<<"Podaj miesiac, ktory chcesz zobaczyc: "; int mie; cin>>mie;
  cout<<"-------------------------------------------------------------------------------\n";
	if(mie==1){
		cout<<setw(22)<<"STYCZEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}
	}
	if(mie==2){
		cout<<setw(22)<<"LUTY  ";
		for(int h=0; h<(m-2); h++) {
			cout<<setw(2)<<h;
			if(h<(m-3)) cout<<"|";
    		else  cout<<endl;
		}
	
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-2); j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;
				} 
			} 
		}
	}
	if(mie==3){
    	cout<<setw(22)<<"MARZEC";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}	
	}
	if(mie==4){
		cout<<setw(22)<<"KWIECIEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}		
	}
	if(mie==5){
    	cout<<setw(22)<<"MAJ";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}	
	}
	if(mie==6){
		cout<<setw(22)<<"CZERWIEC";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}			
	}
	if(mie==7){
		cout<<setw(22)<<"LIPIEC";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}		
	}
	if(mie==8){
		cout<<setw(22)<<"SIERPIEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}		
	}
	if(mie==9){
		cout<<setw(22)<<"WRZESIEN";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}				
	}
	if(mie==10){
		cout<<setw(22)<<"PAZDZIERNIK";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}			
	}
	if(mie==11){
		cout<<setw(22)<<"LISTOPAD";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-2)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<(m-1); j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}					
	}
	if(mie==12){
		cout<<setw(22)<<"PAZDZIERNIK";
		for(int h=0; h<m; h++) {
			cout<<setw(2)<<h;
			if(h<(m-1)) cout<<"|";
	    	else  cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<u; i++) {
			if(i!=0){
				if(zwy[i].nazwa!="-") {
					cout<<setw(2)<<i<<"| "<<setw(17)<<zwy[i].nazwa;
	        		cout<<"|";
					for (int j=0; j<m; j++) {
						cout<<setw(2)<<zwy[i].mies[mie][j]; // Wyúwietl zawartoúÊ komÛrki na 4 miejscach
			            if(j<m) cout<<"|";
			            else  cout<<endl;
	        		} cout<<endl;	
				}
			} 
		}				
	}
}

void OdczytZ() { 
 
	zwycz.open("pliki/zwyczaje.txt", ios::in);
	if(zwycz.is_open()) {
		//cout<<"Odczytano dane z pliku."<<endl;
		zwycz>>znacznik;
		for(int i=0; i<u; i++) {
			getline(zwycz,zwy[i].nazwa);
			//zwycz>>zwy[i].nazwa;	
		} 
		for(int i=1; i<u; i++)
			for(int j=1; j<n; j++)
				for(int k=1; k<m; k++) 
					zwycz>>zwy[i].mies[j][k];
					
		zwycz.close();
	}else cout<<"Blad otwarcia pliku.";	
	//system("pause");
}

void ZapisZ() {

	cout<<"-------------------------------------------------------------------------------\n";
	zwycz.open("pliki/zwyczaje.txt", ios::out);
	if(zwycz.is_open()) {
		cout<<"Zapisano dane do pliku."<<endl;
		zwycz<<znacznik<<endl;
		for(int i=1; i<u; i++) {
			zwycz<<zwy[i].nazwa<<"\n";
		} 
		for(int i=1; i<u; i++){
			for(int j=1; j<n; j++){
				for(int k=1; k<m; k++)
					zwycz<<zwy[i].mies[j][k]<<" ";
				zwycz<<endl;
			} zwycz<<endl;
		} 
		zwycz.close();
	}else cout<<"Blad zapisu pliku.";  
	//system("pause");
}
	
void KonfiguracjaZ() {
	
	cout<<"Ile 'zwyczajow' chcesz wpisac?: "; int o; cin>>o; o+=1;
	
	for(int i=1; i<o; i++){
		cout<<"Podaj nazwe 'zwyczaju': "; 
		do{
			getline(cin,zwy[i].nazwa);
		} while(zwy[i].nazwa.size()<=1 || zwy[i].nazwa.size()>=19);
	} 
}

void ZaznaczZ() {
	//system("cls");
	cout<<"-------------------------------------------------------------------------------\n";	
	cout<<"Podaj ktory 'zwyczaj' chcesz zaznaczyc jako wykonany: "; int w; cin>>w;
	zwy[w].mies[mi][d]=true;
		
}


