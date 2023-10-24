#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include "templateClass.h"

class customers : public templateClass, public QListWidget, public QTableWidget
{
private:

    QString phoneNumber;
    int accumulationPoint;

public:

    customers(QString name = "none",
              QString ID = "none",
              QString BOD = "none",
              QString phoneNumber = "none",
              int accumulationPoint = 0)
    {
        this->setName(name);
        this->setID(ID);
        this->phoneNumber = phoneNumber;
        this->accumulationPoint = accumulationPoint;
        this->setBOD(BOD);
    }

    void setphoneNumber(QString phoneNumber){
        this->phoneNumber = phoneNumber;
    }

    void setAccumulationPoint(unsigned int accumulationPoint){
        this->accumulationPoint = accumulationPoint;
    }

    QString getphoneNumber(){
        return this->phoneNumber;
    }

    int getAccumulationPoint(){
        return this->accumulationPoint;
    }


};

#endif // CUSTOMERS_H
