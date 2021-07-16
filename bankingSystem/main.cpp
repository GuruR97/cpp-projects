#include <iostream>
#include <string>
#include <vector> 
#include "bank.h"
 using namespace std;


int main()
{

	int input = 0;


while (1)
{
	menu(&input);

	switch (input) 
	{
	case 1:
		makeAccount();
		break;
	case 2:
		depositAccount();
		break;
	case 3:
		withdrawAccount();
		break;
		
	case 4:
		transfer();
		break;
		
	case 5:
		printAccount();
		break;
		
	case 6:
		ActiveDeactive();
		break;
	case 7:
		deleteAccount();
		break;
	case 8:
		printAllAccount();
		break;
	case 9: 
		exit(0);
		break;
	default:
		std::cout << "you entered an invalid option" << std::endl;
	}
	
}
}
