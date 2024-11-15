#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class Cal {

	public:
		Cal(void);
		void getrokly(int rok);

	protected:
		int mrok;
		string mmiesiacs[13];
		string mWeekDays [8];
		int mDays [13];
		int pierwszyDzienMiesiaca(int miesiac, int rok);

		static const int rok_ROW_WIDTH  = 35; // width of a row in rokly display

};

/**
 * Constructor - initialize data 
 *
 */
Cal::Cal(void) {
		mmiesiacs[0] = "";	// miesiac starts from 1
		mmiesiacs[1] = "Styczen";
		mmiesiacs[2] = "Luty";
		mmiesiacs[3] = "Marzec";
		mmiesiacs[4] = "Kwiecien";
		mmiesiacs[5] = "Maj";
		mmiesiacs[6] = "Czerwiec";
		mmiesiacs[7] = "Lipiec";
		mmiesiacs[8] = "Sierpien";
		mmiesiacs[9] = "Wrzesien";
		mmiesiacs[10] = "Pazdziernik";
		mmiesiacs[11] = "Listopad";
		mmiesiacs[12] = "Grudzien";

		mDays[0] =0;
		mDays[1] = 31;
		mDays[2] = 28;
		mDays[3] = 31;
		mDays[4] = 30;
		mDays[5] = 31;
		mDays[6] = 30;
		mDays[7] = 31;
		mDays[8] = 31;
		mDays[9] = 30;
		mDays[10] = 31;
		mDays[11] = 30;
		mDays[12] = 31;

		mWeekDays[0] = "";
		mWeekDays[7] = "Nd";
		mWeekDays[1] = "Pn";
		mWeekDays[2] = "Wt";
		mWeekDays[3] = "Sr";
		mWeekDays[4] = "Cz";
		mWeekDays[5] = "Pt";
		mWeekDays[6] = "So";


}

/**
 * Using a standard c++ algorithm to find day of week for a date
 * Parameters:
 *  miesiac - miesiac number
 *  rok - rok
 * Returns:
 *	dow = day of week, sun =0, mon=1 etc.
 */
int Cal::pierwszyDzienMiesiaca(int miesiac, int rok) {
	int dow = 0;
	int day = 7;

    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    rok -= miesiac < 3;
    dow = ( rok + rok/4 - rok/100 + rok/400 + t[miesiac-1] + day) % 7;

	return dow;
}

/**
 * Print rokly calendar
 * Parameters:
 *  rok - rok to print for
 */
void Cal::getrokly(int rok) {
	time_t now = time(0);
	tm *ltm = localtime(&now);

	mrok = rok;
	if (mrok < 1900 || mrok > 2100) {
		std::cout << "rok must be between 1900 and 2100" << endl;
		return;
	}

	// check for leap rok
	if ((mrok % 4 == 0 && mrok % 100 != 0) || (mrok % 400 == 0))
		mDays[2] = 29;

	int leftPadding = 0;
	for (int i =1; i <=12; i ++) {
		int mies=1+ltm->tm_mon;
		int mie=mies;
		
		if((i>=mies)&&(i<=(mie+1))) {
			// center mounth label
			leftPadding = (rok_ROW_WIDTH - mmiesiacs[i].size()) / 2;
			for (int x =0; x < leftPadding; x++) {
				cout << " ";
			}
			cout << mmiesiacs[i] << endl;
			
			//print weekday labels
			for (int j = 1; j <= 7; j++) {
				cout << setw(3) << mWeekDays[j] << setw(1) << " |";
			}
			cout << endl;
	
			// print days
			int daysPrinted = 0;
			for (int j = 1; j <= mDays[i]; j++) {
				// move display head to the correct day of week for 1st
				if (j == 1) {
					int dow = pierwszyDzienMiesiaca(i, mrok);
					for (int spaces=0; spaces < dow; spaces++) {
							cout << setw(2) << " " << setw(3) << "  ";
							daysPrinted ++;	
					}
				}
	
				cout << setw(3) << j << setw(1) << " |";
				daysPrinted ++;
				if (daysPrinted % 7 == 0) {
					cout << endl;
					daysPrinted = 0;
				}
			}
			cout << endl << setw(35) << "----------------------------------" << endl;	
		}	
		
	}
}

int Kalendarz() {
//POBIERANIE CZASU TERAZNIEJSZEGO
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
   int rok=1900+ltm->tm_year;

	
	Cal cal;
	cal.getrokly(rok);

}

