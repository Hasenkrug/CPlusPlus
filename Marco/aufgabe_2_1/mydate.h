#ifndef MYDATE_H
#define MYDATE_H


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

        unsigned int value();

        operator unsigned int()const{
            return m_days;
        }


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
            unsigned int value()const{return m_months;}
            operator unsigned int()const{
                return m_months;
            }
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
            unsigned int value()const{return m_years;}
            operator unsigned int()const{
                return m_years;
            }
    };
}




#endif // MYDATE_H
