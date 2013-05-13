#ifndef MYDATE_H
#define MYDATE_H

#include <iostream>

namespace MyDate{
    class Days
    {
        unsigned int m_days;
        public:
        Days(unsigned int d){
            m_days = d;
        }
        Days()
            :m_days(0)
        {
        }

        unsigned int value() const;
        operator unsigned int() const;


    };
    class Months
    {
        unsigned int m_months;
        public:
            Months(unsigned int m){
                m_months = m;
            }
            Months()
                :m_months(0)
            {
            }
            unsigned int value() const;
            operator unsigned int() const;

    };
    class Years
    {

        unsigned int m_years;
        public:
            Years(unsigned int y){
                m_years = y;
            }
            Years()
                :m_years(0)
            {
            }
            unsigned int value() const;
            operator unsigned int() const;

    };

    class Date {
        Days m_days;
        Months m_months;
        Years m_years;

        public:
            Date()
                :m_days(0),m_months(0),m_years(0)
            {
            }

            Date(unsigned int d, unsigned int m, unsigned int y) {
                m_days = Days(d);
                m_months = Months(m);
                m_years = Years(y);
            }

            unsigned int day() const;
            unsigned int month() const;
            unsigned int year() const;

            //unsigned int& day();
            //unsigned int& month();
            //unsigned int& year();


            bool operator==(const Date& rhs) const;
            bool operator!=(const Date& rhs) const;
            bool operator<(const Date& rhs) const;
            friend std::ostream& operator<<(std::ostream &lhs, const Date &rhs)
            {
                lhs << "(" << rhs.day() << "," << rhs.month() << "," << rhs.year() <<")";
                return lhs;
            }
            static bool isLeapYear(Years y);
            static Days daysInMonth(Months m, Years y);
            Date& operator+=(Days d);
    };
}





#endif // MYDATE_H
