#ifndef _CUSTOMERS_H
#define _CUSTOMERS_H

#include "templateClass.h"

class _customers : public templateClass
{
private:
    int point;
    QString phoneNumber;
public:
    _customers(){}

    _customers(QString new_name = "none", QString new_dob = "none", QString new_phoneNumber = "none", int new_point = 0)
    {

        setName(string_standardizing(new_name));
        setDOB(new_dob);
        setPhoneNumber(new_phoneNumber);
        setPoint(new_point);
        setID(generate_ID());
    }

    _customers(int new_point = 0, QString new_phoneNumber = "none",  QString new_dob = "none",
               QString new_name = "none", QString newDate = "none", QString newID = "none")
    {
        setName(string_standardizing(new_name));
        setDOB(new_dob);
        setPhoneNumber(new_phoneNumber);
        setPoint(new_point);
        setID(newID);
        setDate(newDate);
    }


    void setPhoneNumber(QString phoneNumber){
        this->phoneNumber = phoneNumber;
    }

    void setPoint(int point){
        this->updateLatestModification();
        this->point = point;
    }

    QString getPhoneNumber() const {
        return this->phoneNumber;
    }

    int getPoint() const {
        return this->point;
    }

    bool operator == (_customers o){
        if(
               this->getName() != o.getName()
            || this->getID() != o.getID()
            || this->getPhoneNumber() != o.getPhoneNumber()
            || this->getDOB() != o.getDOB()
          )
            return false;
        return true;
    }

    _customers operator = (_customers o){
        this->getName() = o.getName(),
        this->getID() = o.getID(),
        this->getPhoneNumber() = o.getPhoneNumber(),
        this->getDOB() = o.getDOB();
        return o;
    }
};

#endif // _CUSTOMERS_H
