//Modify the constructor for the fraction class so that it checks to make sure that the numerator and denominator are both integers. 
//If either is not an integer the constructor should raise an exception.
#include<iostream>
using namespace std;
int gcd(int a , int b){
	while(a % b != 0){
		int old_a = a;
		int old_b = b;

		a = old_b;
		b = old_a % old_b;
	}
	return b;
};
class Fraction{
	private:
		int num;
		int den;
	public:
		Fraction(int numerator, int denominator){
			num = numerator;
			den = denominator;
		}

		Fraction(){
			num = 1;
			den = 1;
		}
		friend Fraction operator + (const Fraction &frac, const Fraction &other_frac);
		friend Fraction operator - (const Fraction &frac, const Fraction &other_frac);
		friend Fraction operator * (const Fraction &frac, const Fraction &other_frac);
		friend Fraction operator / (const Fraction &frac, const Fraction &other_frac);
		friend bool operator < (const Fraction &frac, const Fraction &other_frac);
		friend bool operator > (const Fraction &frac, const Fraction &other_frac);
		friend bool operator == (const Fraction &frac, const Fraction &other_frac);
		friend bool operator <= (const Fraction &frac, const Fraction &other_frac);
		friend bool operator >= (const Fraction &frac, const Fraction &other_frac);
		friend bool operator != (const Fraction &frac, const Fraction &other_frac);
		friend ostream &operator << (ostream &out, const Fraction &f);
};
Fraction operator + (const Fraction &frac, const Fraction &other_frac){
	int temp_num = frac.num*other_frac.den + other_frac.num*frac.den;
	int temp_den = frac.den * other_frac.den;
	return Fraction(temp_num,temp_den);
};
Fraction operator - (const Fraction &frac, const Fraction &other_frac){
        int temp_num = frac.num*other_frac.den - other_frac.num*frac.den;
        int temp_den = frac.den * other_frac.den;
        return Fraction(temp_num,temp_den);
};
Fraction operator * (const Fraction &frac, const Fraction &other_frac){
        int temp_num = frac.num * other_frac.num;
        int temp_den = frac.den * other_frac.den;
        return Fraction(temp_num,temp_den);
};
Fraction operator / (const Fraction &frac, const Fraction &other_frac){
        int temp_num = frac.num * other_frac.den;
        int temp_den = frac.den * other_frac.num;
        return Fraction(temp_num,temp_den);
};
bool operator == (const Fraction &frac, const Fraction &other_frac){
	return (frac.num*other_frac.den == other_frac.num*frac.den);
};
bool operator != (const Fraction &frac, const Fraction &other_frac){
	return (frac.num*other_frac.den != other_frac.num*frac.den);
};
bool operator < (const Fraction &frac, const Fraction &other_frac){
	return (frac.num*other_frac.den < other_frac.num*frac.den);
};
bool operator > (const Fraction &frac, const Fraction &other_frac){
	return (frac.num*other_frac.den > other_frac.num*frac.den);
};
bool operator <= (const Fraction &frac, const Fraction &other_frac){
	return (frac.num*other_frac.den <= other_frac.num*frac.den);
};
bool operator >= (const Fraction &frac, const Fraction &other_frac){
	return (frac.num*other_frac.den >= other_frac.num*frac.den);
};

ostream &operator << (ostream &out, const Fraction &f){
	int divisor = gcd(f.num,f.den);
	int n = f.num/divisor;
	int d = f.den/divisor;
	if(n == 1 && d == 1){
		out << 1 << endl;
	}
	else if (n == 0){
		out << 0 << endl ;
	}
	else {
		out << f.num/divisor << "/" << f.den/divisor << endl;
	}
	return out;
};

int main(){
	Fraction frac1(5,15);
	Fraction frac2(10,15);
	cout << "frac1: " << frac1 << endl;
	cout << "frac2: " << frac2 << endl;
	cout << "sum: " << frac1+frac2 << endl;
	cout << "difference: " << frac1-frac2 << endl;
	cout << "division: " << frac1/frac2 << endl;
	cout << "=: " << (frac1 == frac2) << endl;
	cout << "!=: " << (frac1 != frac2) << endl;
	cout << "<: " << (frac1 < frac2) << endl;
	cout << ">: " << (frac1 > frac2) << endl;
	cout << "<=: " << (frac1 <= frac2) << endl;
	cout << ">=: " << (frac1 >= frac2) << endl;
	return 0;
}
