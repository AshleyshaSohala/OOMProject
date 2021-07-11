#include "bill.h"
#include <conio.h>

using namespace std;

void bill::list() // list function of bill class
	{
		fstream file;
		file.open("product.txt",ios::in);
		cout<<"\n\n====================================================\n";
		cout<<"P.NO.\t\tNAME\t\tPRICE\n";
		cout<<"====================================================\n";
		file>>code>>name>>price>>discount;
		while(!file.eof())
		{
			cout<<code<<"\t\t"<<name<<"\t\t"<<price<<"\n";
			file>>code>>name>>price>>discount;
		}
		file.close();
	}
	void bill::invoice() // invoice function of bill class
	{
		system("cls");
		fstream file;
		char choice;
		int o_c[50],o_q[50],c=0;
		float amt=0,dis=0,total=0;
		cout<<"\n\n\t\t\t Invoice ";
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n Data Base is Empty...";
		}
		else
		{
			file.close();
			list();
			cout<<"\n============================";
			cout<<"\n    PLACE YOUR ORDER";
			cout<<"\n============================\n";
			do
			{
				p:
				cout<<"\n\n Dish Code : ";
				cin>>o_c[c];
				cout<<"\n Dish Quantity : ";
				cin>>o_q[c];
				for(int i=0;i<c;i++)
				{
					if(o_c[c] == o_c[i])
					{
						cout<<"\n\n Duplicate Dish Code...";
						goto p;
					}	
				}
				c++;
				cout<<"\n\n Do You Want To Place Another Order? (Y,N) : ";
				cin>>choice;	
			}while(choice == 'Y' || choice == 'y');
			system("cls");
			cout<<"\n\n********************************INVOICE************************\n";
			cout<<"\nPr No.\tPr Name \tQuantity \t\tPrice \tAmount \t\tAmount after discount\n";
			for(int i=0;i<c;i++)
			{
				file.open("product.txt",ios::in);
				file>>code>>name>>price>>discount;
				while(!file.eof())
				{
					if(code == o_c[i])
					{
						amt = price*o_q[i];
						dis = amt - (amt/100*discount);
						total += dis;
						cout<<"\n"<<code<<"\t"<<name<<"\t"<<o_q[i]<<"\t"<<price<<"\t"<<amt<<"\t"<<dis;	
					}
					file>>code>>name>>price>>discount;
				}
				file.close();
			}
			cout<<"\n\n======================================";
			cout<<"\n Total Amount : "<<total;
		}
	}
	