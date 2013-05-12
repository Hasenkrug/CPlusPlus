#ifndef MYDATE_H
#define MYDATE_H

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

            unsigned int day() const;
            unsigned int month() const;
            unsigned int year() const;
            bool operator==(const Date& rhs) const;
            bool operator!=(const Date& rhs) const;
            bool operator<(const Date& rhs) const;
    };
}

#endif // MYDATE_H
