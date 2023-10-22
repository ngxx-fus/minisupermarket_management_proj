#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include "templateClass.h"

class customers : public templateClass
{
private:

    QString numberPhone;
    unsigned int accumulationPoint;

public:

    customers(QString name = "none",
              QString ID = "none",
              QString numberPhone = "none",
              unsigned int accumulationPoint = 0)
    {
        this->setName(name);
        this->setID(ID);
        this->numberPhone = numberPhone;
        this->accumulationPoint = accumulationPoint;
    }

    void setNumberPhone(QString numberPhone){
        this->numberPhone = numberPhone;
    }

    void setAccumulationPoint(unsigned int accumulationPoint){
        this->accumulationPoint = accumulationPoint;
    }

    QString getNumberPhone(){
        return this->numberPhone;
    }

    int getAccumulationPoint(){
        return this->accumulationPoint;
    }


};

#endif // CUSTOMERS_H
