#ifndef FORMADDCOMMODITIES_H
#define FORMADDCOMMODITIES_H

#include <QDialog>

namespace Ui {
class FormAddCommodities;
}

class FormAddCommodities : public QDialog
{
    Q_OBJECT

public:
    explicit FormAddCommodities(QWidget *parent = nullptr);
    ~FormAddCommodities();
    QString getName() const;
    QString getId() const;
    unsigned int getAmount() const;
    QString getDate() const;
    QString getDateExp() const;
    double getPrice() const;

private slots:
    void on_btnSave_clicked();

private:
    Ui::FormAddCommodities *ui;
    QString name;
    QString id;
    unsigned int amount;
    QString date;
    QString dateExp;
    double price;
};

#endif // FORMADDCOMMODITIES_H
