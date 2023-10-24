#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QString>
#include <QVector>
#include <algorithm>

using namespace std ;

class templateClass : public QListWidgetItem
{
protected:
    QVector< QChar > int_to_QChar = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
private:
    QString name;
    QString ID;
    QString path; // path to file
    QString BOD;  //birth of day

public:

    bool checkDate(int DD, int MM, int YYYY){
        if( DD < 1 || MM < 1 || YYYY < 1901 || YYYY > 2052 || MM > 12) return false;
        //                    Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
        QVector<int> normalYear = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        QVector<int> leapYear = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if( (YYYY % 100!=0)  && (YYYY % 4 == 0) )
            return bool(leapYear.at(MM) >= DD);
        
        return bool(normalYear.at(MM) >= DD);
    }

    templateClass(QString name = "none",
                  QString ID = "none",
                  QString path = "none")
    {
        this->name = name;
        this->ID = ID;
        this->path = path;
    }

    ~templateClass(){}

    virtual void setBOD(QString BOD){
        this->BOD = BOD;
    }

    virtual void setBOD(QString BOD){
        this->BOD = BOD;
    }

    virtual void setBOD(int DD, int MM, int YYYY){
        if( checkDate(DD,MM,YYYY) == false ) return;
        this->BOD.clear();
        //DATE
        this->BOD.push_back( int_to_QChar.at(DD/10) );
        this->BOD.push_back( int_to_QChar.at(DD%10) );

        this->BOD.push_back(QChar('/'));

        //MONTH
        if( MM < 10){
            this->BOD.push_back(QChar('0'));
            this->BOD.push_back( int_to_QChar.at(MM) );
        }else{
            this->BOD.push_back( QChar('1') );
            this->BOD.push_back( QChar((MM == 11)?('1'):('2')) );
        }
        this->BOD.push_back(QChar('/'));
        this->BOD.push_back( int_to_QChar.at(YYYY/1000) );
        YYYY%=1000;
        this->BOD.push_back( int_to_QChar.at(YYYY/100) );
        YYYY%=100;
        this->BOD.push_back( int_to_QChar.at( YYYY/10) );
        YYYY%=10;
        this->BOD.push_back( int_to_QChar.at(YYYY) );
    }

    virtual void setName(QString newName) 
    {
        this->name = newName;
    }


    virtual QString getName() {
        return this->name;

    }

    virtual QString getBirthOfDay() {
        return this->BOD;
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
};


#endif // TEMPLATECLASS_H
