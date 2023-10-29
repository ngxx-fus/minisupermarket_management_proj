#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H


#include <QListWidgetItem>
#include <QtGui>
#include <QtWidgets>
#include <QTableWidget>
#include <QMainWindow>
#include <math.h>
#include "_time.h"

using namespace std ;

class templateClass
{
private:
    QString name;
    QString ID;
    QString path; // path to file
    QString DOB;
    _time   latestModification; //latest modification

public:

    templateClass(QString name = "none",
                  QString ID = "none",
                  QString path = "none")
    {
        this->name = name;
        this->ID = ID;
        this->path = path;
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

        res += _t.int_to_QString((count_t = (++count_t*12*count_t)%100001));
        if(sufix_.size()){
            res.push_back(QChar('.'));
            res += sufix_;
        }
        return res;
    }

    virtual void setDOB(QString newDOB){
        this->DOB = newDOB;
    }

    //date of birth
    virtual QString getDOB(){
        return this->DOB;
    }

    virtual void setName(QString newName)
    {
        this->name = newName;
    }


    virtual QString getName() {
        return this->name;

    }

    virtual void setID(QString newID) {
        this->ID = newID;
    }

    virtual QString getID() {
        return this->ID;
    }

    virtual void setPath(QString newPath) {
        this->path = newPath;
    }

    virtual QString getPath() {
        return this->path;
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
