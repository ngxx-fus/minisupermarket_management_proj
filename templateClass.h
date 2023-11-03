#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <math.h>
#include "_time.h"

using namespace std ;

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
    return res;
}

class templateClass
{
private:
    QString name;
    QString ID;
    QString DOB;
    _time   latestModification; //latest modification
    QString Date;

public:

    templateClass()
    {
        this->name = name;
        this->ID = ID;
        latestModification.set_current_date_time();
    }

    //format: YYYYMMDDHHMMSS - MM 1st is month,  MM 2nd is minute
    QString generate_ID(QString prefix_ = "", bool date_ = true, bool time_ = true, QString sufix_ = ""){
        static int count_t = 1;
        if(count_t > 100001) count_t  = 0;
        QString res;
        _time _t;
        _t.set_current_date_time();//set current time
        if(prefix_.size()){
            res += prefix_;
            res.push_back(QChar('.'));
        }
        if(date_) {
            res += _t.get_year() + _t.get_month() + _t.get_day();
            res.push_back(QChar('.'));
        }
        if(time_){
            res += _t.get_hour() + _t.get_minute() + _t.get_second();
            res.push_back(QChar('.'));
        }

        res += _t.int_to_QString((count_t = (++count_t*95)%1001));
        if(sufix_.size()){
            res.push_back(QChar('.'));
            res += sufix_;
        }
        return res;
    }

    virtual void setDate(QString newDate){
        this->Date = newDate;
    }

    virtual QString getDate() const  {
        return this->Date;
    }

    virtual void setDOB(QString newDOB){
        this->DOB = newDOB;
    }

    //date of birth
    virtual QString getDOB() const {
        return this->DOB;
    }

    virtual void setName(QString newName)
    {
        this->name = newName;
    }

    virtual QString getName() const {
        return this->name;

    }

    virtual void setID(QString newID) {
        this->ID = newID;
    }

    virtual QString getID() {
        return this->ID;
    }

    void updateLatestModification()
    {
        this->latestModification.set_current_date_time();
    }

    _time getLatestModification(){
        return this->latestModification;
    }

    ~templateClass()
    {

    }
};


#endif // TEMPLATECLASS_H
