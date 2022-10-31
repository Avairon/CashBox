#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <locale.h>

#define CRT_SECURE_NO_WARNINGS

using namespace std;;

//C:\check расположение всех файлов

//FILE * userID, * pinCode;

int userIDInt, pinCodeInt, cardStatus, cardBallance;


//userID = fopen("C:\check\userID.txt", "r")
//fscanf (userID, "*f", &userIDInt, "*f", &cardStatus);
//fclose (userID);

//pinCode = fopen("C:\check\pinCode.txt", "r")
//fscanf(pinCode, "*f", &pinCodeInt);
//fclose(pinCode);

//тут мы задаем значения для проверки без работы с файлами

userIDInt = 12345678;
pinCodeInt = 1234;
cardStatus = 1;
int cardBallance = 2000;
int mobileBallance = 100;
int JKHcheque = 500;
int newPinCode;
int oldPinCode;
int JKHchoise;

void loginning()
{
	cout << "Insert you user ID";

	while (inputUserID != userIDInt)
	{
		int inputUserID << cin;
		if (inputUserID == userIDInt) cout << "user ID is correct"; break;
		else cout << "user ID is not correct";
	}

	if (inputUserID != userIDInt) return 1;

	cout << "Insert you pin code"

	int trying;

	if (cardStatus == 1)
	{
		for (trying = 3, trying > 0, trying -= 1)
		{
			int inputPinCode << cin;
			if (inputPinCode == pinCodeInt) cout << "pin code is correct"; break;
			else cout << "pin code is not correct, please, try again. Attempts left: " << trying;
		}
	}
	
	cout << "Welcome!";
}
int userChange;
int main()
{
	if (loginning() == 1) cout << "bye";  return 0;
	
	cout << "top up your account - 1, withdraw from the account - 2, top up your mobile - 3, change pin code - 4, services JKH - 5, leave from terminal - 6";
	cin >> userChange;
	while (true)
	{
		switch (userChange)
		{
		case 1:
			cout << "insert a sum(above 100)";
			cin >> int nalMoney;
			if (nalMoney >= 100)
			{
				cardBallance += nalMoney;
				cout << "money deposited, current balance: " << cardBallance;
			}
			else cout << "wrong number, please try again";

			break;

		case 2:
			cout << "insert a sum(above 100)";
			cin >> int nalMoney;
			if (nalMoney >= 100 && nalMoney <= cardBallance)
			{
				cardBallance -= nalMoney;
				cout << "money withdrawn, current balance: " << cardBallance;
			}
			else cout << "wrong number, please try again";
			break;

		case 3:
			cout << "insert a sum(above 100)";
			cin >> int nalMoney;
			if (nalMoney >= 100)
			{
				mobileBallance += nalMoney;
				cout << "the mobile account has been replenished, the balance is on the account: " << mobileBallance;
			}
			else cout << "wrong number, please try again";
			break;

		case 4:
			cout << "insert old pin code";

			cin << oldPinCode;
			
			if (pldPinCode == pinCodeInt)
			{
				cout << "insert new pin code";
				cin >> newPinCode;
				if (newPinCode > 9999 or newPinCode < 0) cout << "wrong pin code, please insert up to 4 characters and retry"; break;
				pinCodeInt = newPinCode;
				cout << "pin code has been changed!";
			}
			else cout << "wrong old pin code, please try again"
			break;
			
		case 5:
			cout << "you JKH cheque is: " << JKHcheque; << " can you pay? (1 - yes, 0 - no)";
			cin >> JKHchoise;
			if (JKHchoise == 1 or JKHchoise == 0)
			{
				if (JKHchoise == 1)
				{
					if (JKHcheque <= cardBallance) cardBallance -= JKHcheque; JKHcheque = 0; cout << "you has pay of all JKH cheque! You card ballance: " << cardBallance;
					else cout << "Insufficient funds! Please try again";
					break;
				}
				break;
				
			}
			else cout << "Uncorrect answer! Please try again";
			break;

		case 6:
			cout << "Thanks for using me!";
			return 0;
			break;

		default:
			cout << "Please, select a number from the list!"
			break;
		}
	}
}