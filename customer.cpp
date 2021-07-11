#include "customer.h"
#include "bill.h"
#include "admin.h"
#include <conio.h>

using namespace std;

void Customer::customer() // Customer function of bill class
	{
		p:
		system("cls");
		int choice;
		cout<<"\n\n\t\t\tCustomer Panel ";
		cout<<"\n\n 1. Order Dish(Invoice)";
		cout<<"\n 2. Go Back";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				invoice();
				break;
			case 2:
			{
				Admin a;
				a.menu();
			}
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		goto p;
	}