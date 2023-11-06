#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H
#include "_time.h"

#include <QListWidgetItem>
#include <QString>
using namespace std ;

class templateClass : public QListWidgetItem {
private:
    QString name;
    QString ID;
    QString path; // path to file
    QString DOB;
    _time   latestModification; //latest modification
    QString Date;
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


    ~templateClass(){}
    //format: YYYYMMDDHHMMSS - MM 1st is month,  MM 2nd is minute
    QString generate_ID(QString text = ""){
        static int count_t = 1;
        if(count_t > 100001) count_t  = 0;
        QString res;
        _time _t;
        _t.set_current_date_time();//set current time
        res += _t.get_year() + _t.get_month() + _t.get_day();
        res.push_back(QChar('.'));
        res += _t.get_hour() + _t.get_minute() + _t.get_second();
        res.push_back(QChar('.'));
        res += _t.int_to_QString((count_t = (++count_t*123)%1001));
        if(text.size()){
            res.push_back(QChar('.'));
            res += text;
        }
        return res;
    }
    virtual void setDate(QString newDate){
        this->Date = newDate;
    }

    virtual QString getDate(){
        return this->Date;
    }
    void setName(QString newName) {
        this->name = newName;
    }

    QString getName() const {
        return this->name;

    }

    virtual void setID(QString newID) {
        this->ID = newID;
    }

    QString getID() const  {
        return this->ID;
    }

    virtual void setPath(QString newPath) {
        path = newPath;
    }

    virtual QString getPath() {
        return path;
    }

    virtual void setDOB(QString newDOB){
        this->DOB = newDOB;
    }

    //date of birth
    virtual QString getDOB() const {
        return this->DOB;
    }
    void updateLatestModification()
    {
        this->latestModification.set_current_date_time();
    }

    void setLatestModification(_time t){
        this->latestModification = t;
    }

    _time getLatestModification(){
        return this->latestModification;
    }

};


#endif // TEMPLATECLASS_H
