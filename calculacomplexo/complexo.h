#ifndef COMPLEXO_H
#define COMPLEXO_H
#include <QString>
namespace tp2{
    class complexo{
    private:
        float real;
        float imag;
    public:
        complexo();
        complexo(float real,float imag);
        QString getComplexo()const;
        void setComplexo(float real,float imag);

        complexo operator + (complexo &valor);
        complexo operator - (complexo &valor);
        complexo operator * (complexo &valor);
        complexo operator / (complexo &valor);
        void operator = (complexo &valor);
        void operator = (QString &valor);
        bool operator == (complexo &valor);
        bool operator != (complexo &valor);
    };
}

#endif // COMPLEXO_H
