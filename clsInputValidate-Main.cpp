#include <iostream>
#include <string>
#include "clsInputValidate.h"

using namespace std;

int main() {
	
	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
	cout << clsInputValidate::IsNumberBetween(4.90, 1.10, 10.90) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 2, 2024), clsDate(20, 1, 2025)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(20, 1, 2025), clsDate(1, 2, 2024)) << endl;

	cout << "Enter integer number : \n";
	int Number = clsInputValidate::ReadIntNumber("Invalid Number, Enter a valid one ?");
	cout << "Number = " << Number;

	cout << "\nEnter Number between 1 and 5 : \n";
	int NumberInRange = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within the range, Enter a valid one ?");
	cout << "Number in range 1 -> 5 = " << NumberInRange << endl;

	cout << "\nEnter Double number : \n";
	double DblNumber = clsInputValidate::ReadDblNumber("Invalid Number, Enter a valid one ? ");
	cout << "Double Number = " << DblNumber;

	cout << "\nEnter Number between 1.44 and 5.88 : \n";
	double DblNumberInRange = clsInputValidate::ReadDblNumberBetween(1.44, 5.88, "Number is not within the range, Enter a valid one ?");
	cout << "Number in range 1.44 -> 5.88 = " << NumberInRange << endl;

	cout << clsInputValidate::IsValideDate(clsDate(35, 12, 2024));

	string UserName = clsInputValidate::IsValidUserName();
	cout << "user name : " << UserName << endl;

	return 0;
}

