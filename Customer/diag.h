#ifndef DIAG_H
#define DIAG_H


#include <QString>
#include <QListWidgetItem>
#include <QMainWindow>

class diag
{
private:
    QString text;
public:
    diag(QString text){
        this->text = text;
    };
    void setText(QString text){
        this->text =  text;
    }
    QString getText(){
        return this->text;
    }
};

#endif // DIAG_H
