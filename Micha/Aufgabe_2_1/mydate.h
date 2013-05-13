#ifndef MYDATE_H
#define MYDATE_H

#include "iostream"

namespace MyDate {

    class Days {
        unsigned int days;

        public:
            Days(unsigned int d) {
                days = d;
            }

            Days()
                : days(0)
            {}

        unsigned int value() const;
        operator unsigned int() const;
    };

    class Months {
        unsigned int months;

        public:
            Months(unsigned int m) {
                months = m;
            }

            Months()
                : months(0)
            {}

            unsigned int value() const;
            operator unsigned int() const;
    };

    class Years {
        unsigned int years;

        public:
            Years(unsigned int y) {
                years = y;
            }

            Years()
                : years(0)
            {}

            unsigned int value() const;
            operator unsigned int() const;
    };

    class Date {
        Days days;
        Months months;
        Years years;

        public:
            Date(unsigned int d, unsigned int m, unsigned int y) {
                days = Days(d);
                months = Months(m);
                years = Years(y);
            }

            Date()
                : days(0), months(0), years(0)
            {}

            unsigned int day() const;
            unsigned int month() const;
            unsigned int year() const;
            bool operator==(const Date& rhs) const;
            bool operator!=(const Date& rhs) const;
            bool operator<(const Date& rhs) const;
            static bool isLeapYear(Years y);
            static Days daysInMonth(Months m);
            static Days daysInMonth(Months m, Years y);
            Date& operator+=(Days d);
            Date& operator+=(Months m);
            Date& operator+=(Years y);
            Date& operator+=(int i);
            Date operator+(Days d) const;
            Date operator+(Months m) const;
            Date operator+(Years y)const;
    };
}

std::ostream& operator<<(std::ostream &lhs, const MyDate::Date &rhs);

#endif // MYDATE_H

