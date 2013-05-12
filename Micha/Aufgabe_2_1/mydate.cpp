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
}


std::ostream& operator<<(std::ostream &lhs, const MyDate::Date &rhs) {
    lhs << "Day: " << rhs.day() << " Month: " << rhs.month() << " Year: " << rhs.year();
    return lhs;
}
