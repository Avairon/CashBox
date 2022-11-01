#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include <ctime>

#define CRT_SECURE_NO_WARNINGS

using namespace std;

time_t seconds = time(NULL);
tm* timeinfo = localtime(&seconds);

//C:\check расположение всех файлов

FILE* userID, *pinCode, *logs;

//int userIDInt, pinCodeInt, cardStatus;

char userIdFile[] = "userID.txt";
//userID = fopen(userIdFile, "r");
//fscanf(userID, "%d", &userIDInt, "%d", &cardStatus);
//fclose(userID);

//pinCode = fopen("C:\check\pinCode.txt", "r");
//fscanf(pinCode, "%d", &pinCodeInt);
//fclose(pinCode);


//тут мы задаем значения для проверки без работы с файлами

int userIDInt = 12345678;
int pinCodeInt = 1234;
int cardStatus = 1;

int cardBallance = 2000;
int mobileBallance = 100;
int JKHcheque = 500;
int newPinCode;
int oldPinCode;
int JKHchoise;
int nalMoney;

char c = ' ';
int inputUserID;

int loginning()
{
	cout << "Insert you user ID ";

	while (inputUserID != userIDInt)
	{
		
		cin >> inputUserID;
		if (inputUserID == userIDInt) { cout << "user ID is correct "; break;}
		else cout << "user ID is not correct";
	}

	cout << "Insert you pin code";

		int trying;
		int inputPinCode;

	if (cardStatus == 1)
	{
		for (trying = 2; trying > -1; trying -= 1)
		{
			
			cin >> inputPinCode;
			if (inputPinCode == pinCodeInt) { cout << "pin code is correct "; break; }
			else cout << "pin code is not correct, please, try again. Attempts left: " << trying << c;
		}
		if (inputPinCode != pinCodeInt) return 1;
	}

	cout << "Welcome!";
	return 0;
}
int userChange;

//logs = fopen("C:\check\output.txt", "w");


int main()
{
	if (loginning() == 1) { cout << "bye";  return 0; }

	//fprintf(logs, "User in system");

	while (true)
	{
		cout << "top up your account - 1, withdraw from the account - 2, top up your mobile - 3, change pin code - 4, services JKH - 5, leave from terminal - 6   ";
		cin >> userChange;

		switch (userChange)
		{
		case 1:
			cout << "insert a sum(above 100)";
			cin >> nalMoney;
			if (nalMoney >= 100)
			{
				cardBallance += nalMoney;
				cout << "money deposited, current balance: " << cardBallance;
				
				//fprintf(logs, "money deposited: " + nalMoney + c + (int)asctime(timeinfo));
			}
			else cout << "wrong number, please try again";

			break;

		case 2:
			cout << "insert a sum(above 100)";
			cin >> nalMoney;
			if (nalMoney >= 100 && nalMoney <= cardBallance)
			{
				cardBallance -= nalMoney;
				cout << "money withdrawn, current balance: " << cardBallance;
				//fprintf(logs, "money withdrawn: " + nalMoney + c + (int)asctime(timeinfo));
			}
			else cout << "wrong number, please try again";
			break;

		case 3:
			cout << "insert a sum(above 100)";
			cin >> nalMoney;
			if (nalMoney >= 100)
			{
				mobileBallance += nalMoney;
				cout << "the mobile account has been replenished, the balance is on the account: " << mobileBallance;
				//fprintf(logs, "Money deposited on mobile ballance" + (int)asctime(timeinfo));
			}
			else cout << "wrong number, please try again";
			break;

		case 4:
			cout << "insert old pin code";

			cin >> oldPinCode;

			if (oldPinCode == pinCodeInt)
			{
				cout << "insert new pin code";
				cin >> newPinCode;
				if (newPinCode > 9999 or newPinCode < 0) cout << "wrong pin code, please insert up to 4 characters and retry"; break;
				pinCodeInt = newPinCode;
				cout << "pin code has been changed!";
				//fprintf(logs, "Pin code has been changed on: " + pinCodeInt + c + (int)asctime(timeinfo));
			}
			else cout << "wrong old pin code, please try again";
				break;

		case 5:
			cout << "you JKH cheque is: " << JKHcheque << " can you pay? (1 - yes, 0 - no)";
			cin >> JKHchoise;
			if (JKHchoise == 1 or JKHchoise == 0)
			{
				if (JKHchoise == 1)
				{
					if (JKHcheque <= cardBallance) { cardBallance -= JKHcheque; JKHcheque = 0; cout << "you has pay of all JKH cheque! You card ballance: " << cardBallance; fprintf(logs, "Payed for all JKH cheques" + (int)asctime(timeinfo)); }
					else cout << "Insufficient funds! Please try again";
					break;
				}
				break;

			}
			else cout << "Uncorrect answer! Please try again";
			break;

		case 6:
			cout << "Thanks for using me!";
			//fprintf(logs, "User leave at system" + (int)asctime(timeinfo));
			return 0;
			break;

		default:
			cout << "Please, select a number from the list!";
				break;
		}
	}
}
