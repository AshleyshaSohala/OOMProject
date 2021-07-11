#include <iostream>
#include <fstream>
#include <string>
#include "admin.h"
#ifndef BILLING_SYSTEM_H
#define BILLING_SYSTEM_H
 
using namespace std;


class bill
{
    public: // variables
		int code;
		float price,discount;
		string name;
	public: // functions
		void list();
		void invoice();

};

#endif