#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QString>
#include <QVector>
#include <algorithm>

using namespace std ;

class templateClass
{
private:
    QString name;
    QString ID;
    QString path; // path to file
    QString   BOD;

public:

    class _time{
    private:
        int _date, _month, _year;
        int _second, _minute, _hour;
    public:

        QString int_to_QString(int num, int fill_zero = 0){
            static QChar _convert_QChar[10] = {'0', '1', '2', '3','4','5','6','7','8','9'};
            QString res;
            while(num){
                res.push_back( _convert_QChar[num%10] );
                num /= 10;
            }
            if(fill_zero == 0 && num == 0) fill_zero = 1;
            while(fill_zero - int(res.size()) > 0 ) res.push_back(QChar('0'));
            reverse(res.begin(), res.end());
            return res;
        }

        _time(int _date = 1, int _month = 1, int _year = 1901, int _hour = 0,
              int _minute = 0, int _second = 0){
            this->_date = _date;
            this->_month = _month;
            this->_year = _year;
            this->_hour = _hour;
            this->_minute = _minute;
            this->_second = _second;
        }

        bool check_DDMMYYYY(){
            #define DD _date
            #define MM _month
            #define YYYY _year
            if( DD < 1 || MM < 1 || YYYY < 1901 || YYYY > 2099 || MM > 12) return false;
            QVector<int> normal_year = {0, /*Jan*/ 31, /*Feb*/28, /*Mar*/31, /*Apr*/30, /*May*/31, /*Jun*/30,
                                           /*Jul*/31, /*Aug*/31, /*Sep*/30, /*Oct*/31, /*Nov*/30, /*Dec*/31};

            QVector<int> leap_year = {0, /*Jan*/ 31, /*Feb*/29, /*Mar*/31, /*Apr*/30, /*May*/31, /*Jun*/30,
                                           /*Jul*/31, /*Aug*/31, /*Sep*/30, /*Oct*/31, /*Nov*/30, /*Dec*/31};

            if( (YYYY % 100 != 0)  && (YYYY % 4 == 0) )
                return bool(leap_year.at(MM) >= DD);

            return bool(normal_year.at(MM) >= DD);
        }

        bool check_HHMMSS(){
            int &HH = _hour, &MM = _minute, &SS = _second;
            if( HH < 0 || HH > 23 || MM < 0 || MM > 59 || SS < 0 || SS > 59)
                return false;
            return true;
        }

        //the range of DDMMYYYY between 1901->2099
        void set_DDMMYYYY(int DD, int MM, int YYYY){
            if( _time(DD, MM, YYYY).check_DDMMYYYY() == false ) return;
            _date = DD, _month = MM, _year = YYYY;
        }

        //
        void set_HHMMSS(int HH, int MM, int SS){
            if( _time( 1, 1, 1901, HH, MM, SS).check_HHMMSS() == false ) return;
            _hour = HH, _minute = MM, _second = SS;
        }


        //format: DD/MM/YYYY
        QString get_date(){
            QString _result;

            //DATE
            _result += int_to_QString( this->_date, 4 );

            //MONTH
            _result.push_back(QChar('/'));
            _result += int_to_QString( this->_month, 2 );

            //YEAR
            _result.push_back(QChar('/'));
            _result += int_to_QString( this->_year, 4 );


            return _result;
        }

        QString get_time(){
            QString _result;

            //HOUR
            _result += int_to_QString( this->_hour, 2 );

            //MINUTE
            _result.push_back(QChar('/'));
            _result += int_to_QString( this->_minute, 2);

            //SECOND
            _result.push_back(QChar('/'));
            _result += int_to_QString( this->_second, 2 );

            return _result;
        }

        //the end of _time class!
    };

    templateClass(QString name = "none",
                  QString ID = "none",
                  QString path = "none")
    {
        this->name = name;
        this->ID = ID;
        this->path = path;
    }

    ~templateClass(){
    }

    virtual void setBOD(int DD, int MM, int YYYY){
        this->BOD = _time(DD, MM,YYYY).get_date();
    }

    virtual QString getBOD(){
        return this->BOD;
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
