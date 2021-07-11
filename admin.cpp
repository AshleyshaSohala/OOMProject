#include<conio.h>
#include "admin.h"
#include "bill.h"
#include "customer.h"
using namespace std;

void Admin::admin() // Admin function of bill class
	{
		p:
		system("cls");
		int choice;
		cout<<"\n\n\t\t\tAdmin Panel";
		cout<<"\n\n 1. Add Dish";
		cout<<"\n 2. Search Dish";
		cout<<"\n 3. Edit Dish";
		cout<<"\n 4. Delete Dish";
		cout<<"\n 5. Show Dishes";
		cout<<"\n 6. Go Back";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
				search();
				break;
			case 3:
				edit();
				break;
			case 4:
				del();
				break;
			case 5:
				show();
				break;
			case 6:
				menu();
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		goto p;
	}

   void Admin::menu() // define menu function of bill class
    {
        p:
        system("cls");
        int choice;
        char ch;
        string email,pass;
        cout<<"\n\n\t\t\tMain Menu";
        cout<<"\n\n 1. Admin";
        cout<<"\n 2. Customer";
        cout<<"\n 3. Exit";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                system("cls");
                cout<<"\n\n\t\t\tLogin System";
                cout<<"\n\n E-mail : ";
                cin>>email;
                cout<<"\n\n Password : ";
                for(int i=1;i<=6;i++)
                {
                    ch = getch();
                    pass += ch;
                    cout<<"*";
                }
                if(email == "LCI2020028@gmail.com" && pass == "oompro")
                {
                    admin();
                }
                else
                {
                    cout<<"\n\n Invalid E-mail & Password...";
                }
                break;
            case 2:
			{
                Customer c;
				c.customer();
			}
            case 3:
                exit(0);
            default:
                cout<<"\n\n Invalid Value...Please Try Again...";
        }
        getch();
        goto p;
    }
    void Admin::add() // Add Product function in bill class
	{
		p:
		system("cls");
		fstream file;
		int c,found=0;
		float p,d;
		string n;
		cout<<"\n\n\t\t\tAdd New Dish";
		cout<<"\n\n Dish Code : ";
		cin>>code;
		cout<<"\n\n Name : ";
		cin>>name;
		cout<<"\n\n Price : ";
		cin>>price;
		cout<<"\n\n Discount in % : ";
		cin>>discount;
		file.open("product.txt",ios::in);
		if(!file)
		{
			file.open("product.txt",ios::app|ios::out);
			file<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
			file.close();
		}
		else
		{
			file>>c>>n>>p>>d;
			while(!file.eof())
			{
				if(c == code)
				{
					found++;
				}
				file>>c>>n>>p>>d;
			}
			file.close();
			if(found == 1)
			goto p;
			else
			{
				file.open("product.txt",ios::app|ios::out);
				file<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
				file.close();	
			}
		}
		cout<<"\n\n\t\t Record Inserted Successfully...";
	}
	void Admin::search() // search function of bill class
	{
		system("cls");
		fstream file;
		int p_c,found=0;
		cout<<"\n\n\t\t\tSearch Dish";
		cout<<"\n\n Dish Code : ";
		cin>>p_c;
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Opening Error...";
		}
		else
		{
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				if(p_c == code)
				{
					system("cls");
					cout<<"\n\n\t\t\tSearch Dish";
					cout<<"\n\n Dish Code : "<<code;
					cout<<"\n\n Name : "<<name;
					cout<<"\n\n Price : "<<price;
					cout<<"\n\n Discount : "<<discount<<"%";
					found++;
				}
				file>>code>>name>>price>>discount;
			}
			file.close();
			if(found == 0)
			cout<<"\n\n Record Can't Found...";
		}
	}
	void Admin::edit() // edit function of bill class
	{
		system("cls");
		fstream file,file1;
		int p_c,found=0,c;
		float p,d;
		string n;
		cout<<"\n\n\t\t\tEdit Dish";
		cout<<"\n\n Dish Code : ";
		cin>>p_c;
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Opening Error...";
		}
		else
		{
			file1.open("product1.txt",ios::app|ios::out);
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				if(p_c == code)
				{
					cout<<"\n\n Dish New Code : ";
					cin>>c;
					cout<<"\n\n Name : ";
					cin>>n;
					cout<<"\n\n Price : ";
					cin>>p;
					cout<<"\n\n Discount in % : ";
					cin>>d;
					file1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
					cout<<"\n\n\n\t\tRecord Edited Successfully...";
					found++;
				}
				else
				{
					file1<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
				}
				file>>code>>name>>price>>discount;
			}
			file.close();
			file1.close();
			remove("product.txt");
			rename("product1.txt","product.txt");
			if(found == 0)
			cout<<"\n\n Record Can't Be Found...";
		}
	}
	void Admin::del() // delete function of bill class
	{
		system("cls");
		fstream file,file1;
		int p_c,found=0;
		cout<<"\n\n\t\t\tDelete Dish";
		cout<<"\n\n Dish Code : ";
		cin>>p_c;
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File opening error...";
		}
		else
		{
			file1.open("product1.txt",ios::app|ios::out);
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				if(code == p_c)
				{
					cout<<"\n\n Dish Deleted Successfully...";
					found++;	
				}
				else
				{
					file1<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
				}
				file>>code>>name>>price>>discount;
			}
			file.close();
			file1.close();
			remove("product.txt");
			rename("product1.txt","product.txt");
			if(found == 0)
			cout<<"\n\n Record Can't Be Found...";
		}
	}
	void Admin::show() // show function of bill class
	{
		system("cls");
		fstream file;
		cout<<"\n\n\t\t\tShow Dishes";
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File opening error...";
		}
		else
		{
			cout<<"\n\n Code\tName\t\tPrice\t\tDiscount %";
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				cout<<"\n "<<code<<"\t "<<name<<"\t   "<<price<<"\t\t\t"<<discount;
				file>>code>>name>>price>>discount;
			}
			file.close();
		}
	}