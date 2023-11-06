#ifndef _TIME_H
#define _TIME_H

#include <QString>
#include <QVector>
#include <algorithm>
#include <time.h>

using namespace std ;

class _time{
private:
    int _day, _month, _year;
    int _second, _minute, _hour;
public:

    QString int_to_QString(int num, int fill_zero = 0){
        QChar _convert_QChar[10] = {'0', '1', '2', '3','4','5','6','7','8','9'};
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
    //set date as the current
    void set_current_date(){
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        _day = aTime->tm_mday;
        _month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
        _year = aTime->tm_year + 1900; // Year is # years since 1900
    }

    //set time as the current
    void set_current_time(){
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        _hour = aTime->tm_hour;
        _minute = aTime->tm_min;
        _second = aTime->tm_sec;
    }

    //set time and date as current
    void set_current_date_time(){
        set_current_date();
        set_current_time();
    }

    void set_date_time_from_ID(QString ID){
        auto QC2I = [](QChar QC){
            return QString(QC).toInt();
        };

        _year = QC2I(ID[0])*1000 + QC2I(ID[1])*100 + QC2I(ID[2])*10 + QC2I(ID[3]);
        _month = QC2I(ID[4])*10 + QC2I(ID[5]);
        _day = QC2I(ID[6])*10 + QC2I(ID[7]);

        _hour = QC2I(ID[9])*10 + QC2I(ID[10]);
        _minute = QC2I(ID[11])*10 + QC2I(ID[12]);
        _second = QC2I(ID[13])*10 + QC2I(ID[14]);
    }

    _time(int _day = 1, int _month = 1, int _year = 1901,
          int _hour = 0, int _minute = 0, int _second = 0){
        this->_day = _day;
        this->_month = _month;
        this->_year = _year;
        this->_hour = _hour;
        this->_minute = _minute;
        this->_second = _second;
    }

    bool check_DDMMYYYY(){
        int &DD = _day;
        int &MM = _month;
        int &YYYY = _year;
        if( DD < 1 || MM < 1 || YYYY < 1901 || YYYY > 2101 || MM > 12) return false;
        QVector<int> normal_year = {0, /*Jan*/ 31, /*Feb*/28, /*Mar*/31, /*Apr*/30, /*May*/31, /*Jun*/30,
                                    /*Jul*/31, /*Aug*/31, /*Sep*/30, /*Oct*/31, /*Nov*/30, /*Dec*/31};

        QVector<int> leap_year = {0, /*Jan*/ 31, /*Feb*/29, /*Mar*/31, /*Apr*/30, /*May*/31, /*Jun*/30,
                                  /*Jul*/31, /*Aug*/31, /*Sep*/30, /*Oct*/31, /*Nov*/30, /*Dec*/31};

        if( ((YYYY % 100 != 0)  && (YYYY % 4 == 0)) || (YYYY % 400 == 0))
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
    bool set_DDMMYYYY(int DD, int MM, int YYYY){
        if( _time(DD, MM, YYYY).check_DDMMYYYY() == false ) return false;
        this->_day = DD,
            this->_month = MM,
            this->_year = YYYY;
        return true;
    }

    //
    bool set_HHMMSS(int HH, int MM, int SS){
        if( _time( 1, 1, 1901, HH, MM, SS).check_HHMMSS() == false ) return false;
        this->_hour = HH,
            this->_minute = MM,
            this->_second = SS;
        return true;
    }


    //format: DD/MM/YYYY
    QString get_date(){
        QString _result;

        //DAY
        _result += int_to_QString( this->_day, 2 );

        //MONTH
        _result.push_back(QChar('/'));
        _result += int_to_QString( this->_month, 2 );

        //YEAR
        _result.push_back(QChar('/'));
        _result += int_to_QString( this->_year, 4 );


        return _result;
    }

    //format: HH:MM:SS
    QString get_time(){
        QString _result;

        //HOUR
        _result += int_to_QString( this->_hour, 2 );

        //MINUTE
        _result.push_back(QChar(':'));
        _result += int_to_QString( this->_minute, 2);

        //SECOND
        _result.push_back(QChar(':'));
        _result += int_to_QString( this->_second, 2 );

        return _result;
    }
    QString get_day(){
        return int_to_QString(_day, 2);
    }
    QString get_month(){
        return int_to_QString(_month, 2);
    }
    QString get_year(){
        return int_to_QString(_year, 4);
    }
    QString get_hour(){
        return int_to_QString(_hour, 2);
    }
    QString get_minute(){
        return int_to_QString(_minute, 2);
    }
    QString get_second(){
        return int_to_QString(_second, 2);
    }

    int get_day_int(){return _day;}
    int get_month_int(){return _month;}
    int get_year_int(){return _year;}
    int get_hour_int(){return _hour;}
    int get_minute_int(){return _minute;}
    int get_second_int(){return _second;}

    _time operator = (_time o){
        this->set_DDMMYYYY(o.get_day_int(), o.get_month_int(), o.get_year_int());
        this->set_HHMMSS(o.get_hour_int(), o.get_minute_int(), o.get_second_int());
        return *this;
    }

    bool operator < (_time o){
        if(this->get_year_int() < o.get_year_int()) return true;
        if(this->get_month_int() < o.get_month_int()) return true;
        if(this->get_day_int() < o.get_day_int()) return true;
        if(this->get_hour_int() < o.get_hour_int()) return true;
        if(this->get_minute_int() < o.get_minute_int()) return true;
        if(this->get_second_int() < o.get_second_int()) return true;
        return false;
    }

    bool operator > (_time o){
        if(this->get_year_int() > o.get_year_int()) return true;
        if(this->get_month_int() > o.get_month_int()) return true;
        if(this->get_day_int() > o.get_day_int()) return true;
        if(this->get_hour_int() > o.get_hour_int()) return true;
        if(this->get_minute_int() > o.get_minute_int()) return true;
        if(this->get_second_int() > o.get_second_int()) return true;
        return false;
    }

    //the end of _time class!
};

#endif // _TIME_H
