#include "mydate.h"
#include "iostream"

namespace MyDate {

    unsigned int Days::value() const { return Days::days; }
    Days::operator unsigned int() const { return Days::days; }

    unsigned int Months::value() const { return Months::months; }
    Months::operator unsigned int() const { return Months::months; }

    unsigned int Years::value() const { return Years::years; }
    Years::operator unsigned int() const { return Years::years; }

    unsigned int Date::day() const { return days; }
    unsigned int Date::month() const { return months; }
    unsigned int Date::year() const { return years; }

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

    bool Date::isLeapYear(Years y) {
        if(y % 4 == 0) {
            if(y % 100 == 0) {
                if(y % 400 == 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    Days Date::daysInMonth(Months m) {
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            return 31;
        } else {
            if(m == 2) {
                return 28;
            } else {
                return 30;
            }
        }
    }

    Days Date::daysInMonth(Months m, Years y) {
        if(m == 2) {
            if(isLeapYear(y)) {
                return 29;
            } else {
                return 28;
            }
        } else {
            return daysInMonth(m);
        }
    }

    Date& Date::operator+=(Days d) {
        for(int i = 1; i <= d; i++) {
            if(Date::day() == daysInMonth(Date::month(), Date::year())) {
                if(Date::month() == 12){
                    *this = Date(1, 1, Date::year() + 1);
                } else {
                    *this = Date(1, Date::month() + 1, Date::year());
                }
            } else {
                *this = Date(Date::day() + 1, Date::month(), Date::year());
            }
        }
        return *this;
    }

    Date& Date::operator+=(Months m) {
        for(int i = 1; i <= m; i++) {

            if(Date::month() == Months(12)) {
                *this = Date(Date::day(), 1, Date::year() + 1);
            } else {
                *this = Date(Date::day(), Date::month() + 1, Date::year());
            }
        }

        if(daysInMonth(Date::month(), Date::year()) < Date::day()) {
            *this = Date(daysInMonth(Date::month(), Date::year()), Date::month(), Date::year());
        }

        return *this;
    }

    Date& Date::operator+=(Years y) {
        *this = Date(Date::day(), Date::month(), Date::year() + y);
        return *this;
    }

    /*
    Date& Date::operator+=(int i) {
        return *this;
    }
    */

    Date& Date::operator+(Days d) const {
        Date date(*this);
        return date += d;
    }

    Date& Date::operator+(Months m) const {
        Date date(*this);
        return date += m;
    }

    Date& Date::operator+(Years y) const {
        Date date(*this);
        return date +=y;
    }

    /*
    Date& Date::operator+(int i) {
        return *this;
    }
    */
}

std::ostream& operator<<(std::ostream &lhs, const MyDate::Date &rhs) {
    lhs << " Day= " << rhs.day() << " Month= " << rhs.month() << " Year= " << rhs.year();
    return lhs;
}
