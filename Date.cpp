#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
class Date {
private:
	int day;
	int month;
	int year;
    bool leapYear;
    string dateInString;
public:
	Date (string _strDate) {
        char strDate[12];
        strcpy(strDate, _strDate.c_str());

		char* ptr;
		ptr = strtok(strDate, "/");
        
		this->year = stoi(ptr);
		ptr = strtok(NULL, "/");
		this->month = stoi(ptr);
		ptr = strtok(NULL, "/");
		this->day = stoi(ptr);

        this->leapYear = false;

        setMonth();
        setYear();
        setDay();
	}
	void setMonth() {
		if(this->month < 1 || this->month > 12) {
			cout << "Month " << this->month << " is invalid" << endl;
			this->month = 1;
            year++;
            setYear();
		}
	}
	void setYear() {
		if(this->year < 1450 || this->year > 2050) {
			cout << "Year " << this->year << " is invalid" << endl;
			this->year = 2022;
		}

        if (this->year %4 == 0) {
            if (this->year %100 == 0) {
                if (this->year %400 == 0) {
                    leapYear = true;
                }
            }
            else {
                leapYear = true;
            }
        }
	}
    void setDay() {
        if (this->month == 2) {
            if (this->leapYear) {
                if (this->day < 1 || this->day > 29) {
                    cout << "Day " << this->day << " is invalid" << endl;
			        this->day = 1;
                    month++;
                    setMonth();
                }
            }
            else {
                if (this->day < 1 || this->day > 28) {
                    cout << "Day " << this->day << " is invalid" << endl;
			        this->day = 1;
                    month++;
                    setMonth();
                }
            }
        }
        else if (this->month==4 || this->month==6 || this->month==9 || this->month==11){
            if (this->day < 1 || this->day > 30) {
                cout << "Day " << this->day << " is invalid" << endl;
			    this->day = 1;
                month++;
                setMonth();
            }
        }
        else {
            if (this->day < 1 || this->day > 31) {
                cout << "Day " << this->day << " is invalid" << endl;
			    this->day = 1;
                month++;
                setMonth();
            }
        }
    }
    void calendar() {
        if (leapYear) {
            cout << "Leap Year" << endl;
        }
        cout << "Year: " << this->year << endl;
        cout << "Month: " << this->month << endl;
        cout << "Day: " << this->day << endl;
    }
    Date& operator ++() {
        day++;
        setDay();
        return *this;
    }
    operator const char*() {
        ostringstream f;
        f << month << "/" << day << "/" << year;
        dateInString = f.str();
        return dateInString.c_str();
    }
};

int main()
{
    char opt;
    do {
        system("cls");

        char strDate[12];
        Date* objDate;

        cout << "Enter the date: " << endl;
        cin >> strDate;

        cout << endl;
        cout << endl;
        objDate = new Date(strDate);
        cout << *objDate << endl;
        for (int c = 0; c < 5; c++)
        {
            cout << endl;
            ++*objDate;
            cout << *objDate << endl;
        }

        delete objDate;

        cout << endl;
        cout << endl;
        
        cout << "Enter 'p' to exit, other to restart:" << endl;
        cin >> opt;
    } while (opt != 'p');
	return 0;
}