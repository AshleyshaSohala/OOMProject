#ifndef CUSTOMER_SYSTEM_H
#define CUSTOMER_SYSTEM_H
#include "bill.h"
#include "admin.h"

class Customer : public bill 
{
   public:
    void customer();
};

#endif