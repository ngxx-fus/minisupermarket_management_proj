#ifndef _CUSTOMER_LIST_H
#define _CUSTOMER_LIST_H

#include "_customers.h"

class customer_list
{
    QVector< _customers > m_data;
public:
    customer_list();

    void add_customer(_customers new_cus);

    void remove_customer(_customers cus);

    //remove customer by searching ID (using linear search)
    void remove_customer_using_ID(QString cus_ID);

    //remove customer by searching phoneNumber (using linear search)
    void remove_customer_using_phoneNumber(QString cus_phoneNumber);

    //remove customer by searching Name and DOB (using linear search)
    void remove_customer_using_Name_DOB(QString cus_Name, QString cus_DOB);

};

#endif // _CUSTOMER_LIST_H
