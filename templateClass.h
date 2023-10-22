#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <QListWidgetItem>
#include <QString>
#include <bits/stdc++.h>
using namespace std ;

class templateClass {
private:
    QString name;
    QString ID;
    QString Path;

public:
    templateClass(){}
    templateClass(QString name);
    templateClass(QString defaultName, QString defaultID, QString defaultPath);

    ~templateClass(){}

    void setName(QString newName) {
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
        Path = newPath;
    }

    virtual QString getPath() {
        return Path;
    }
};


#endif // TEMPLATECLASS_H
