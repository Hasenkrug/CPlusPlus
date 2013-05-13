#include "mydate.h"
#include <iostream>

namespace MyDate{

    unsigned int Days::value()const{return Days::m_days; }
    Days::operator unsigned int()const{return Days::m_days; }

    unsigned int Months::value() const { return Months::m_months; }
    Months::operator unsigned int() const { return Months::m_months; }

    unsigned int Years::value() const { return Years::m_years; }
    Years::operator unsigned int() const { return Years::m_years; }

    unsigned int Date::day() const { return m_days; }
    unsigned int Date::month() const { return m_months; }
    unsigned int Date::year() const { return m_years; }

    //unsigned int& Date::day() {return m_days;}
    //unsigned int& Date::month() {return m_months;}
    //unsigned int& Date::year() {return m_years;}

    bool Date::operator==(const Date& rhs) const {
        return day() == rhs.day() && month() == rhs.month() && year() == rhs.year();
    }

    bool Date::operator!=(const Date& rhs) const {
        return !(*this == rhs);
    }

    bool Date::operator<(const Date& rhs) const {
        if(year() < rhs.year()) return true;
        else if(year() > rhs.year()) return false;
        else if(month() < rhs.month()) return true;
        else if(month() > rhs.month()) return false;
        else if(day() < rhs.day()) return true;
        else if(day() > rhs.day()) return false;
        else return false;
    }


    bool Date::isLeapYear(Years y){
        if(y%4==0){
            if(y%100==0){
                if(y%400==0){
                    return true;
                }else{
                    return false;
                }
            }else{
                return true;
            }
        }else{
            return false;
        }

        //return (((jahr%4==0) && (jahr%100!=0))?1:(jahr%400==0)?1:0);
    }
    Days Date::daysInMonth(Months m, Years y){
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            return 31;
        }else{
            if(m==2){
                if(isLeapYear(y)){
                   return 29;
                }
                return 28;
            }else{
                return 30;
            }
        }
    }
    Date& Date::operator+=(Days d){

        for(int i = 1; i<=d; i++){
            if(Date::day()==daysInMonth(Date::month(),Date::year())){
                *this = Date(1,Date::month()+1,Date::year());
            }else{
                *this = Date(Date::day()+1,Date::month(),Date::year());
            }
        }

        return *this;
    }
}
