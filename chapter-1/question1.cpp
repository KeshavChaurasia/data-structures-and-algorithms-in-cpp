// 1. Implement the simple methods getNum and getDen that will return the numerator and denominator of a fraction.
#include<iostream>

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

	int getNum(){
		return num;
	}

	int getDen(){
		return den;
	}
};
int main(){
	Fraction frac(2,3);
	std::cout << frac.getNum() << std::endl;
	std::cout << frac.getDen() << std::endl;
 	return 0;
};
