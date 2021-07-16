#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include "bank.h"
#include <iostream>

int accountcount = 0; 

vector<Account> bankAccounts;

// = { { 1001,"Joe",5000.00,1 },{ 1002,"Kim",2000.00,1 } };

void menu(int *num)

{

	int select = 0;

	cout << "Welcome! Select options below:" << std::endl;

	cout << "\t1. Make new account."

		<< "\n\t2. Deposit to an account."

		<< "\n\t3. Withdraw from an account."

		<< "\n\t4. Transfer money."

		<< "\n\t5. Print account."

		<< "\n\t6. Activate/Deactivate an account."

		<< "\n\t7. Delete an account."

		<< "\n\t8. Display all accounts."

		<< "\n\t9. Quit."

		<< std::endl;

	cout << "Selection:\t";

	cin >> select;

	*num = select;

}


void makeAccount()

{
	Account temp;
	  
	temp.accountNumber = rand() % 8999 + 1000;

	cout << "This bank account is index number: "<< temp.accountNumber << endl;

	cout << "Name: " << endl;

	cin >> temp.name;

	cout << "Starting Balance :" << endl;

	cin >> temp.balance;
	if (validInputdouble(temp.balance) == false)
		return;
	temp.status = true;

	bankAccounts.push_back(temp);

	sortAccounts();
}

void printAllAccount()
{ 

	cout << "accountNumber \t Name \t Balance \t Status \t\n";
	 
	vector<Account>::iterator i;
	for (i = bankAccounts.begin(); i != bankAccounts.end(); i++) {
		cout << (*i).accountNumber << "\t";
		cout <<"  "<< "\t"<<(*i).name << "\t";
		cout << " "<< (*i).balance << "\t";

		if ((*i).status == true)
			cout << "\t active";
		else
			cout << "\t inactive";

		cout << "\n";
	}
	 
	 
	return;
}

void depositAccount()
{

	int depositAccount;
	double depositAmount;

	cout << "From which account would you like to make a deposit to? Please enter account number: " << endl;

	cin >> depositAccount;
	if (validInput(depositAccount) == false)
		return;

	cout << "How much would you like to deposit? :" << endl;

	cin >> depositAmount;


	if (validInputdouble(depositAmount) == false)
		return;

	bool found = false;

	vector<Account>::iterator i;
	for (i = bankAccounts.begin(); i != bankAccounts.end(); i++) {
		if ((*i).accountNumber == depositAccount)
		{
			found = true;
			(*i).balance = (*i).balance + depositAmount;
		}
	}

	if (!found)
	{
		cout << "Deposit account not found." << endl;
		return;
	} 
}

void withdrawAccount()
{

	int withdrawAccount;
	double withdrawAmount;

	cout << "From which account would you like to withdraw? Please enter account number: " << endl;

	cin >> withdrawAccount;
	if (validInput(withdrawAccount) == false)
		return;

	
	cout << "How much would you like to withdraw? :" << endl;

	cin >> withdrawAmount ;

	if (validInputdouble(withdrawAmount) == false)
		return;


	bool found = false;

	vector<Account>::iterator i;
	for (i = bankAccounts.begin(); i != bankAccounts.end(); i++) {
		if ((*i).accountNumber == withdrawAccount)
		{
			if ((*i).balance < withdrawAmount) {
				cout << "Insufficient funds." << endl;
				return;
			}
			found = true;
			(*i).balance = (*i).balance - withdrawAmount;
		}
	}

	if (!found)
	{
		cout << "Withdraw account not found." << endl;
		return;
	}
}

void transfer()
{


	int accountFrom, accountTo;

	double transAmount;


	cout << "From which account would you like to make a transfer from? Please enter account number: " << endl;

	cin >> accountFrom;

	cout << endl

		<< "From which account would you like to make a transfer to? Please enter account number: " << endl;

	cin >> accountTo;

	cout << "How much would you like to transfer? :" << endl;

	cin >> transAmount;

	bool found = false;


	vector<Account>::iterator fromAccountIt;
	vector<Account>::iterator toAccountIt;

	
	for (fromAccountIt = bankAccounts.begin(); fromAccountIt != bankAccounts.end(); fromAccountIt++) {
		if ((*fromAccountIt).accountNumber == accountFrom)
		{
			if ((*fromAccountIt).balance < transAmount) {
				cout << "Insufficient funds." << endl;
				return;
			}
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Source account Invalid ." << endl;
		return;
	}

	for (toAccountIt = bankAccounts.begin(); toAccountIt != bankAccounts.end(); toAccountIt++) {
		if ((*toAccountIt).accountNumber == accountTo)
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Receiver account Invalid ." << endl;
		return;
	}

	
	(*fromAccountIt).balance = (*fromAccountIt).balance - transAmount;
	(*toAccountIt).balance = (*toAccountIt).balance + transAmount;


}

void printAccount()

{
	int inputaccountnumber;

	cout << "What account would you like to view? " << endl;

	cin >> inputaccountnumber;
	if (validInput(inputaccountnumber) == false)
		return;

	bool found = false;

	vector<Account>::iterator i;
	for (i = bankAccounts.begin(); i != bankAccounts.end(); i++) {
		if ((*i).accountNumber == inputaccountnumber)
		{
			cout <<"account number: "<<(*i).accountNumber << "\t";
			cout <<"account name: "<< (*i).name << "\t";
			cout <<"account balance: "<< (*i).balance << "\t";
			cout << "status: ";

			if ((*i).status == true)
				cout << "\tactive";
			else
				cout << "\tinactive";

			cout << "\n";
			found = true;
		}
	}




	if (!found)
	{
		cout << "Invalid Account Number." << endl;
	}
}	  

void ActiveDeactive()
{
	int AcctNum;
	int ad;
	int adindex;
	bool found = false;

	cout << "What account would you like to activate or deactivate?" << endl;
	cin >> AcctNum;

	cout << "Do you want to activate or deactivate this account, (press 1 for activate and 0 for deactivate)?";
	cin >> ad;

	vector<Account>::iterator i;

	for (i = bankAccounts.begin(); i != bankAccounts.end(); i++)
	{
		if ((*i).accountNumber == AcctNum)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "This account not found." << endl;
		return;
	}

	if (ad == 1)
	{
		if ((*i).status == true)
			cout << "Account already active!";
		else
			(*i).status = true;
	}
	if (ad == 0)
	{
		if ((*i).status== false)
			cout << "Account already deactive!";
		else
			(*i).status = false;
	}
	if (ad < 0 || ad > 1) {
		cout << "Invalid Input!";
	}


}

void deleteAccount()
{

	int deleteAccount;

	cout << "Which account would you like to delete? Please enter account number: " << endl;

	cin >> deleteAccount;
	if (validInput(deleteAccount) == false)
		return;


	bool found = false;

	vector<Account>::iterator i;
	for (i = bankAccounts.begin(); i != bankAccounts.end(); i++) {
		if ((*i).accountNumber == deleteAccount)
		{
			found = true;
			bankAccounts.erase(i);
			break;
		}
	}

	if (!found)
	{
		cout << "Account not found to delete" << endl;
		return;
	}
}

bool myFunc(Account i, Account j) { return (i.accountNumber < j.accountNumber); }

void sortAccounts()

{
	sort(bankAccounts.begin(), bankAccounts.end(), myFunc);
}

bool validInput(int i){
	if (i < 0) {
		cout << "Invalid input\n";
		return false;
	}
	else
		return true;
}

bool validInputdouble(double i) {
	if (i < 0) {
		cout << "Invalid input\n";
		return false;
	}
	else
		return true;
}
	
