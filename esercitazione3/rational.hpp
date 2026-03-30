#include <iostream>
#include <concepts>

template<typename I> requires std::integral<I>
class rational { 
    //elementi privati, non accessibili da esterno
    I num_;
    I den_;
    bool is_nan_;
    bool is_inf_;

    //MCD e semplificazione
    I mcd(I a, I b){
        a=abs(a);
        b=abs(b);
        int cd=1;
        int k=2;
        while (k<=a && k<=b){
            if(a%k==0 && b%k==0){
                cd=k; //se resto divisione per k è 0 sia al denominatore che al numeratore aggiorno il mio mcd. se frazione è già semplificata cd rimane 1.
            }
            k++;
        }
        return cd;
    }
    void semplifica(){
        if(den_<0){ // decido per semplicità di considerare il denominatore sempre positivo e sposto il segno al numeratore
            num_=-num_;
            den_=-den_;
        }
        I max_com_div=mcd(num_,den_);
        num_=num_/max_com_div;
        den_=den_/max_com_div;
    }

public:
//costruttore di default
    rational()
        : num_(0),den_(1)
    {}

//costruttore user-defined
    rational(const I& numeratore, const I& denominatore)
        : num_(numeratore),den_(denominatore), is_nan_(false), is_inf_(false)
    {if (denominatore==0){
        //suggerimento prof: gestione errore con bool
        if (numeratore==0){ // 0/0
            is_nan_=true;
        }
        else{
            is_inf_=true;
            if (num_>0){ // +x/0
                num_=+1;
            }
            else{ // -x/0
                num_=-1;
            }
        }
    }
    else{
        semplifica();  
    }};
    I num() const {return num_;} //num_ è privato (elemento della classe)-> quando suono fuoi dalla classe lo chiamo con num()
    I den() const {return den_;}
    bool is_nan() const {return is_nan_;}
    bool is_inf() const {return is_inf_;}

                            //ricorda che *this è una dereferenziazione del puntatore -> indica il razionale corrente: num_/den_
    //+= 
    rational& operator+=(const rational& other){ // const: other non viene modificato
        if (is_nan_ || other.is_nan_){ //almeno uno dei due è NaN
            is_nan_=true;
            return *this;
        }
        if(is_inf_ && other.is_inf_){ // somma di inf segni
            if (num_!=other.num_){ 
                is_nan_=true; // +inf -inf 
                is_inf_=false;
                return *this;
            }
        }
        if (is_inf_ || other.is_inf_){ //uno dei due è inf
            is_inf_=true;
            if (is_inf_){ //se è il primo ad essere inf prendo suo segno
                num_=num_;
            }
            else{ //altrimenti prendo altro segno
                num_=other.num_;
            }
            return *this;
        }
        // ci arrivo solo se tutti precedenti if erano falsi: a/b+c/d=(ad+bc)/bd
        num_ = num_*other.den_+den_*other.num_;
        den_ = den_*other.den_;
        semplifica();
        return *this;
        }

    //+
    rational operator+(const rational& other) const {
        rational ret=*this;
        ret += other; 
        return ret;
    }

    //-=
    rational& operator-=(const rational& other){
        if (is_nan_ || other.is_nan_){ //almeno uno dei due è NaN
            is_nan_=true;
            return *this;
        }
        if(is_inf_ && other.is_inf_){ //entrambi inf
            if(num_==other.num_) {//concordi
                is_inf_=false;
                is_nan_=true;
                return *this;
            }
            else{ //segni diversi, il risultato tiene il segno di num_ -> faccio solo return (+inf -(-inf))=+inf (-inf-(+inf))=-inf
                return *this;
            }
        }
        if (is_inf_ || other.is_inf_){ //uno dei due è inf
            if(is_inf_){ // + o - inf -x = + o - inf
                return *this; 
            }
            else{ // x-(+ o -inf) = - o + inf
                is_inf_=true;
                num_=-other.num_; 
                return *this;
            }
        }
        // a/b-c/d=(ad-bc)/bd
        num_ = num_*other.den_-den_*other.num_;
        den_ = den_*other.den_;
        semplifica();
        return *this;
    }
    //-
    rational operator-(const rational& other) const{
        rational ret=*this;
        ret -= other; 
        return ret;
    }

    //*=
    rational& operator*=(const rational& other){
        if(is_nan_ || other.is_nan_){ //almeno uno dei due è NaN
            is_nan_=true;
            return *this;
        }
        if(is_inf_ && other.is_inf_){ //entrambi inf
            if(num_==other.num_) {//concordi
                num_=1;
                return *this;
            }
            else{
                num_=-1;
                return *this;
            }
        }
        if (is_inf_ || other.is_inf_){ //uno dei due è inf
            is_inf_=true; //il risultato è in ogni caso inf, con segno:
            if(num_*other.num_>0){ //concordi
                num_=1;
                return *this;
            }
            else {
                num_=-1;
                return *this;
            }
        }
        //(a/b*c/d)=ac/bd
        num_=num_*other.num_;
        den_=den_*other.den_;
        semplifica();
        return *this;
        }
    //*
    rational operator*(const rational& other) const{
        rational ret=*this;
        ret *= other;
        return ret;
    }

    // /=
    rational& operator/=(const rational& other) { // gestisco eccezioni, poi per caso normale faccio reciproco del *
        if (is_nan_|| other.is_nan_){ //almeno uno dei due è NaN
            is_nan_=true;
            return *this;
        }
        if (is_inf_ && other.is_inf_){//entrambi inf
            is_inf_=false;
            is_nan_=true;
            return *this;
        }
        if (other.is_inf_){ //x/inf=0
            is_inf_=false;
            num_=0;
            den_=1;
            return *this;
        }
        if (is_inf_){// inf/x=inf, segno:
            if (num_*other.num_>0){
                num_=1;
            }
            else{
                num_=-1;
            }
            return *this;
        }
        if (other.num_==0) {
            if (num_==0){ // 0/0
                is_nan_=true;
                return *this;
            }
            else{ //x/0 =inf con segno +
                is_inf_=true;
                if (num_>0){
                    num_=1;
                }
                else{
                    num_=-1;
                }
                return *this;
            }
        }
        //a/b / c/d = a/b*d/c
        rational reciproco(other.den_, other.num_); 
        *this *= reciproco;
        return *this;
    }
    rational operator/(const rational& other) const{
        rational ret=*this;
        ret /= other;
        return ret;
    }
};

//operatore << per la stampa dell'oggetto, lo metto fuoi poichè in cout << rational il primo parametro non è razionale
template <typename I>
std :: ostream&
operator<<(std::ostream& os, const rational <I>& r)
{  //gestire NaN e inf con is_nan e is_inf
    if(r.is_nan()){
        os<<"NaN";
    }
    else if(r.is_inf()){
        if(r.num()>0){
            os<<"+Inf";
        }
        else{
            os<<"-Inf";
        }
    }
    else{
        os << r.num()<<"/"<<r.den();
    }
    return os;
}   