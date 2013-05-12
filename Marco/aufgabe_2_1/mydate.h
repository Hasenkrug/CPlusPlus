#ifndef MYDATE_H
#define MYDATE_H


namespace MyDate{
    class Days
    {
        unsigned int days;
        public:
        Days(unsigned int d){
            days = d;
        }
        Days()
            :days(0)
        {
        }

        unsigned int value()const{return days;}

        operator unsigned int()const{
            return days;
        }


    };
    class Months
    {
        unsigned int months;
        public:
            Months(unsigned int m){
                months = m;
            }
            Months()
                :months(0)
            {
            }
            unsigned int value()const{return months;}
    };
    class Years
    {

        unsigned int years;
        public:
            Years(unsigned int y){
                years = y;
            }
            Years()
                :years(0)
            {
            }
            unsigned int value()const{return years;}

    };
}




#endif // MYDATE_H
