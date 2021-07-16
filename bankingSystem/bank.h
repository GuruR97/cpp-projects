#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account
{
	int accountNumber;
	string name;
	double balance;
	bool status;
};



void menu(int*);

void printAllAccount();
void makeAccount();

void depositAccount();
void withdrawAccount();
void transfer();
void printAccount();
void ActiveDeactive();
void deleteAccount();
void sortAccounts();
bool validInput(int);
bool validInputdouble(double);
