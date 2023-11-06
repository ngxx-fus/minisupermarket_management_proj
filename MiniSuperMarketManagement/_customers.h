#ifndef _CUSTOMERS_H
#define _CUSTOMERS_H

#include "template_class.h"


inline QString string_standardizing(QString inp){
    QString res;
    bool flag = false;
    for(QChar qc:inp){
        if(qc == ' ') {//"   hdhdhe   ah      hshsh   "
            if(flag  == false)
                continue;
            else {
                flag = false;
                res.push_back(' ');
            }
        }else{
            if(flag  == false){
                flag = true;
                res.push_back(qc);
            }else
                res.push_back(qc);
        }
    }
    if(res.back() == ' ') res.erase(res.end()-1);
    return res;
}

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
//        setName(new_name);

        setDOB(new_dob);
        setPhoneNumber(new_phoneNumber);
        setPoint(new_point);
        setID(generate_ID());
    }

    _customers(int new_point = 0, QString new_phoneNumber = "none",  QString new_dob = "none",
               QString new_name = "none", QString newDate = "none", QString newID = "none")
    {
        setName(string_standardizing(new_name));
//        setName(new_name);

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
        this->setName( o.getName() ),
            this->setID( o.getID() ),
            this->setPhoneNumber( o.getPhoneNumber() ),
            this->setDOB( o.getDOB() ),
            this->setPoint( o.getPoint()),
            this->setLatestModification( o.getLatestModification() );
            ;
        return o;
    }
};

#endif // _CUSTOMERS_H
