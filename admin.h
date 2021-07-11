#ifndef ADMIN_SYSTEM_H
#define ADMIN_SYSTEM_H
#include "bill.h"


class Admin :public bill
{
    public:
        void admin();
        void add();
		void search();
		void edit();
		void del();
		void show();
		void menu();

};

#endif