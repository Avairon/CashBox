#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctime>

#define CRT_SECURE_NO_WARNINGS

using namespace std;

time_t seconds = time(NULL);
tm* timeinfo = localtime(&seconds);

//C:\check расположение всех файлов

int userIDInt, pinCodeInt, cardBallance;

void OpenFiles()
{
	ifstream pinCode;
	pinCode.open("pinCode.txt");
	pinCode >> pinCodeInt;

	ifstream cardBallanceFile;
	cardBallanceFile.open("cardBallance.txt");
	cardBallanceFile >> cardBallance;
	cardBallanceFile.close();

	ifstream userID;
	userID.open("userID.txt");
	userID >> userIDInt;
}



//тут мы задаем значения для проверки без работы с файлами

//userIDInt = 12345678;
//pinCodeInt = 1234;
int cardStatus = 1;
int mobileBallance = 100;
int JKHcheque = 500;
int newPinCode;
int oldPinCode;
int JKHchoise;

int inputUserID;
int inputPinCode;


int loginning()
{
	cout << "Insert you user ID" << "\n";
	cin >> inputUserID;
	while (inputUserID != userIDInt)
	{
		cin >> inputUserID;
		if (inputUserID == userIDInt) { cout << "user ID is correct" << "\n"; break; }
		else cout << "user ID is not correct" << "\n";
	}

	if (inputUserID != userIDInt) return 1;

	int trying;

	if (cardStatus == 1)
	{
		cout << "Insert you pin code" << "\n";
		cin >> inputPinCode;
		if (inputPinCode == pinCodeInt) { cout << "pin code is correct" << "\n"; return 1;}
		else
		{
			inputPinCode = 0;
			cout << "pin code is not correct, please, try again. Attempts left: 2" << "\n";
			cin >> inputPinCode;
			if (inputPinCode == pinCodeInt) { cout << "pin code is correct" << "\n"; return 1;}
			else
			{
				inputPinCode = 0;
				cout << "pin code is not correct, please, try again. Attempts left: 1" << "\n";
				cin >> inputPinCode;
				if (inputPinCode == pinCodeInt) { cout << "pin code is correct" << "\n"; return 1; }
				else
				{
					inputPinCode = 0;
					cout << "bye!" << "\n";
					return 0;
				}
			}
		}
	}

	cout << "Welcome!" << "\n";
}
int userChange;



int nalMoney;

int main()
{
	OpenFiles();

	std::ofstream Logs;
	Logs.open("logs.txt", std::ofstream::app);

	if (loginning() == 0) return 0;

	Logs << "User in system" << "\n";

	while (true)
	{
		cout << "top up your account - 1, withdraw from the account - 2, top up your mobile - 3, change pin code - 4, services JKH - 5, leave from terminal - 6" << "\n";
		cin >> userChange;
		switch (userChange)
		{
		case 1:
			cout << "insert a sum(above 100)" << "\n";
			cin >> nalMoney;
			if (nalMoney >= 100)
			{
				cardBallance += nalMoney;
				cout << "money deposited, current balance: " << cardBallance << "\n";
				Logs << "money deposited: " << nalMoney << " " << asctime(timeinfo) << "\n";
			}
			else cout << "wrong number, please try again" << "\n";
			nalMoney = 0;
			break;

		case 2:
			cout << "insert a sum(above 100)" << "\n";
			cin >> nalMoney;
			if (nalMoney >= 100 && nalMoney <= cardBallance)
			{
				cardBallance -= nalMoney;
				cout << "money withdrawn, current balance: " << cardBallance << "\n";
				Logs << "money withdrawn: " << nalMoney << " " << asctime(timeinfo) << "\n";
			}
			else cout << "wrong number, please try again" << "\n";
			nalMoney = 0;
			break;

		case 3:
			cout << "insert a sum(above 100)" << "\n";
			cin >> nalMoney;
			if (nalMoney >= 100)
			{
				mobileBallance += nalMoney;
				cout << "the mobile account has been replenished, the balance is on the account: " << mobileBallance << "\n";
				Logs << "Money deposited on mobile ballance" << asctime(timeinfo) << "\n";
			}
			else cout << "wrong number, please try again" << "\n";
			nalMoney = 0;
			break;

		case 4:
			cout << "insert old pin code";

			cin >> oldPinCode;

			if (oldPinCode == pinCodeInt)
			{
				cout << "insert new pin code";
				cin >> newPinCode;
				if (newPinCode > 9999 or newPinCode < 0) cout << "wrong pin code, please insert up to 4 characters and retry" << "\n"; break;
				pinCodeInt = newPinCode;
				cout << "pin code has been changed!" << "\n";
				Logs << "Pin code has been changed on: " << pinCodeInt << " " << asctime(timeinfo) << "\n";
			}
			else cout << "wrong old pin code, please try again" << "\n";
				break;

		case 5:
			cout << "you JKH cheque is: " << JKHcheque << " can you pay? (1 - yes, 0 - no)" << "\n";
			cin >> JKHchoise;
			if (JKHchoise == 1 or JKHchoise == 0)
			{
				if (JKHchoise == 1)
				{
					if (JKHcheque <= cardBallance) { cardBallance -= JKHcheque; JKHcheque = 0; cout << "you has pay of all JKH cheque! You card ballance: " << cardBallance << "\n"; Logs << "Payed for all JKH cheques" << " " << asctime(timeinfo) << "\n"; }
					else cout << "Insufficient funds! Please try again" << "\n";
					break;
				}
				break;

			}
			else cout << "Uncorrect answer! Please try again" << "\n";
			break;

		case 6:
			cout << "Thanks for using me!" << "\n";
			Logs << "User leave at system" << " " << asctime(timeinfo) << "\n";
			return 0;
			break;

		default:
			cout << "Please, select a number from the list!" << "\n";
				break;
		}
	}
	ofstream cardBallanceFile;
	cardBallanceFile.open("cardBallance.txt", ios::trunc | ios::out);
	cardBallanceFile << cardBallance;
}