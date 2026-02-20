#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

class clsString
{
public:
    static vector<string> Split(string s, string delimiter)
    {
        vector<string> v;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos)
        {
            token = s.substr(0, pos);
            v.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        v.push_back(s);
        return v;
    }
};

class clsDate
{
private:
    short Day;
    short Month;
    short Year;

public:
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        Day = now->tm_mday;
        Month = now->tm_mon + 1;
        Year = now->tm_year + 1900;
    }

    clsDate(string sDate)
    {
        vector<string> vDate;
        vDate = clsString::Split(sDate, "/");
        Day = stoi(vDate[0]);
        Month = stoi(vDate[1]);
        Year = stoi(vDate[2]);
    }

    clsDate(short day, short month, short year)
    {
        Day = day;
        Month = month;
        Year = year;
    }

    short getDay() { return Day; }
    void setDay(short day) { Day = day; }

    short getMonth() { return Month; }
    void setMonth(short month) { Month = month; }

    short getYear() { return Year; }
    void setYear(short year) { Year = year; }

    static bool IsValidDate(clsDate Date)
    {
        if (Date.Day < 1 || Date.Day > 31)
            return false;
        if (Date.Month < 1 || Date.Month > 12)
            return false;
        if (Date.Month == 2)
        {
            if (isLeapYear(Date.Year))
            {
                if (Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day > 28)
                    return false;
            }
        }
        short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > DaysInMonth)
            return false;
        return true;
    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true :
               (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
               (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false;
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year == Date2.Year) &&
               (Date1.Month == Date2.Month) &&
               (Date1.Day == Date2.Day);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }
};

class clsInputValidate 
{
public:
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number >= From) && (Number <= To);
    }
    
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number >= From) && (Number <= To);
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid input, please enter an integer: ")
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, enter again: ")
    {
        int Number = ReadIntNumber();
        
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid input, please enter a number: ")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }
    
    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, enter again: ")
    {
        double Number = ReadDblNumber();
        
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
};

int main()
{
    cout << "Testing IsNumberBetween (int): " << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << "Testing IsNumberBetween (double): " << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << "\nTesting ReadIntNumber:\n";
    cout << "Please Enter an Integer: ";
    int x = clsInputValidate::ReadIntNumber("Invalid Number, Enter again: ");
    cout << "x = " << x << endl;

    cout << "\nTesting ReadIntNumberBetween (1-5):\n";
    cout << "Please Enter a Number between 1 and 5: ";
    int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range, enter again: ");
    cout << "y = " << y << endl;

    cout << "\nTesting ReadDblNumber:\n";
    cout << "Please Enter a Double Number: ";
    double a = clsInputValidate::ReadDblNumber("Invalid Number, Enter again: ");
    cout << "a = " << a << endl;

    cout << "\nTesting ReadDblNumberBetween (1.0-5.0):\n";
    cout << "Please Enter a Double Number between 1 and 5: ";
    double b = clsInputValidate::ReadDblNumberBetween(1.0, 5.0, "Number is not within range, enter again: ");
    cout << "b = " << b << endl;

    cout << "\nTesting IsValideDate (Dec 35, 2022): ";
    cout << clsInputValidate::IsValideDate(clsDate(35,12,2022)) << endl;

    system("pause>0");
    return 0;
}
