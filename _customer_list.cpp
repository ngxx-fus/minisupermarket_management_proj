#include "_customer_list.h"


customer_list::customer_list(){
    m_data.push_back(_customers("NTP", "STD",34));
}

void customer_list::add_customer(_customers new_cus){
    m_data.push_back( new_cus );
}

void customer_list::remove_customer(_customers cus){//(using linear search)
    QVector<_customers>::iterator it;
    for( it = m_data.begin(); it != m_data.end(); it++){
        if( !((*it) == cus) ) {
            QVector<_customers>::iterator const const_it = it;
            m_data.erase(const_it);
            break;
        }
    }
}

//remove customer by searching ID (using linear search)
void customer_list::remove_customer_using_ID(QString cus_ID){
    QVector<_customers>::iterator it;
    for( it = m_data.begin(); it != m_data.end(); it++){
        if(it->getID() == cus_ID) {
            m_data.erase(it);
            break;
        }
    }
}

//remove customer by searching phoneNumber (using linear search)
void customer_list::remove_customer_using_phoneNumber(QString cus_phoneNumber){
    QVector<_customers>::iterator it;
    for( it = m_data.begin(); it != m_data.end(); it++){
        if(it->getID() == cus_phoneNumber) {
            m_data.erase(it);
            break;
        }
    }
}

//remove customer by searching Name and DOB (using linear search)
void customer_list::remove_customer_using_Name_DOB(QString cus_Name, QString cus_DOB){
    QVector<_customers>::iterator it;
    for( it = m_data.begin(); it != m_data.end(); it++){
        if(it->getID() == cus_Name && it->getDOB() == cus_DOB) {
            m_data.erase(it);
            break;
        }
    }
}
