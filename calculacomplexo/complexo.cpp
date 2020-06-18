#include "complexo.h"
namespace tp2{

    complexo::complexo(){
        this->real=0;
        this->imag=0;

    }
    complexo::complexo(float real,float imag){
        this->real=real;
        this->imag=imag;
    }
    void complexo::setComplexo(float real,float imag){
        this->real=real;
        this->imag=imag;
    }
    complexo complexo::operator + (complexo &valor){
        complexo res;
        res.setComplexo(this->real+valor.real,this->imag+valor.imag);
        return res;
    }

    complexo complexo::operator - (complexo &valor){
        complexo res;
        res.setComplexo(this->real-valor.real,this->imag-valor.imag);
        return res;
    }

    complexo complexo::operator * (complexo &valor){
        complexo res;
        res.setComplexo((this->real*valor.real)-(this->imag*valor.imag),(this->real*valor.imag)+(this->imag*valor.real));
        return res;
    }

    complexo complexo::operator / (complexo &valor){
        complexo res;
        res.setComplexo(((this->real*valor.real)+(this->imag*valor.imag))/
                        ((this->imag*this->imag)+(valor.imag*valor.imag)),
                        ((this->imag*valor.real)-(this->real*valor.imag))/
                        ((this->imag*this->imag)+(valor.imag*valor.imag)));
        return res;

    }

    void complexo::operator = (complexo &valor){
        this->real=valor.real;
        this->imag=valor.imag;
    }

    bool complexo::operator == (complexo &valor){
        if ((this->real==valor.real)&&(this->imag==valor.imag))
            return true;
        else
            return false;
    }
    bool complexo::operator != (complexo &valor){
        if ((this->real==valor.real)&&(this->imag==valor.imag))
            return false;
        else
            return true;
    }

}
