#pragma once

#include <iostream>
#include <iomanip>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(int Number, int From, int To) {

		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(short Number, short From, short To) {

		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	
	static bool IsNumberBetween(float Number, float From, float To) {

		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To) {

		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {

		if (!clsDate::IsDate1BeforeDate2(From, To))
			clsUtil::SwapDates(From, To);

		if (clsDate::CompareDates(Date, From) == clsDate::Before
			|| clsDate::CompareDates(Date, To) == clsDate::After) {

			return false;
		}
		else {

			return true;
		}

	}

	static int ReadIntNumber(string ErrorMassage = "Invalid Number, Enter a valid one ?")
	{
		int Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMassage << endl;
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMassage) {

		int Number;
		Number = ReadIntNumber();
		
		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMassage << endl;
			Number = ReadIntNumber();

		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter a valid one ?")
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMassage) {

		double Number;
		Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMassage << endl;
			Number = ReadDblNumber();

		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter a valid one ?")
	{
		float Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			cin >> Number;
		}

		return Number;
	}

	static float ReadFloatBetween(float From, float To, string ErrorMassage) {

		float Number;
		Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMassage << endl;
			Number = ReadFloatNumber();

		}

		return Number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter a valid one ?")
	{
		short Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			cin >> Number;
		}

		return Number;
	}

	static short ReadShortBetween(short From, short To, string ErrorMassage) {

		short Number;
		Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMassage << endl;
			Number = ReadShortNumber();

		}

		return Number;
	}

	static bool IsValideDate(clsDate Date) {

		return clsDate::IsValidDate(Date);
	}

	static bool ValidateUsername(string str) {

		if (str == "" || str.length() < 4 || str.length() > 25) {

			return false;
		}

		if (str[0] == '_' || str[str.length() - 1] == '_') {

			return false;
		}

		for (short i = 0; i < str.length(); i++) {

			if (str[i] >= 48 && str[i] <= 122) {

				if (str[i] >= 58 && str[i] <= 64 || str[i] >= 91 && str[i] <= 94 || str[i] == 96) {

					return false;
				}
			}
			else {

				return false;
			}
		}

		return true;
	}

	static string IsValidUserName(string ErrorMessage = "Invalid user name, it must contain letters and numbers and underscore character.") {

		string str;
		cout << "Enter user name\n";
		cin >> str;

		while (!ValidateUsername(str)) {

			cout << ErrorMessage << endl;
			cin >> str;
			ValidateUsername(str);
		}
		return str;
	}

	static string ReadString() {

		string str = "";
		getline(cin >> ws, str);

		return str;
	}

	static char ReadChar() {

		char character;
		cin >> character;
		return tolower(character);
	}

};

