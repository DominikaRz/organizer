#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int dtyg(int d, int m, int r) { //dzien tygodnia

   int w;
   if (m > 2)   m -= 2;
   else {
      m += 10;
      r--;
   }
   w = r/100;
   r %= 100;
   return (d + (13*m-1)/5 + r + r/4 + w/4 + 5*w) % 7;
}

int DzienTyg() {
	system("cls");

//POBIERANIE CZASU TERAZNIEJSZEGO
	time_t now = time(0);
	tm *ltm = localtime(&now);
   
   cout << "Dzien: "<< ltm->tm_mday<<endl;
   cout << "Miesiac: "<<1+ltm->tm_mon<<endl;
   cout << "Rok: " <<1900+ltm->tm_year<<endl<<endl;
      
   int rok=1900+ltm->tm_year;
   int miesiac=1+ltm->tm_mon;
   int dzien=ltm->tm_mday;
   
  
  int q=dtyg(dzien,miesiac,rok);
/* cout<<"Dzis jest: ";
	if(q==1) cout<<"Poniedzialek";
	if(q==2) cout<<"Wtorek";
	if(q==3) cout<<"Sroda";
	if(q==4) cout<<"Czwartek";
	if(q==5) cout<<"Piatek";
	if(q==6) cout<<"Sobota";
	if(q==7) cout<<"Niedziela"; */
  
	return q;
}


