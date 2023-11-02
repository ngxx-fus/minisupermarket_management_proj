#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <QListWidgetItem>
#include <QString>
using namespace std ;

class templateClass : public QListWidgetItem {
private:
    QString name;
    QString ID;
    QString Path;

public:
    templateClass(){}

    templateClass(QString name,QString ID ): name(name), ID(ID) {}

    templateClass(QString defaultName, QString defaultID, QString defaultPath);

    ~templateClass(){}

   void setName(QString newName) {
        this->name = newName;
    }

    QString getName() const   {
        return this->name;

    }

    virtual void setID(QString newID) {
        this->ID = newID;
    }

    QString getID() const  {
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
