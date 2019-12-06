//In many ways it would be better if all fractions were maintained in lowest terms right from the start. 
//Modify the constructor for the Fraction class so that GCD is used to reduce fractions immediately. 
//Notice that this means the + function no longer needs to reduce. Make the necessary modifications.

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

		friend ostream &operator << (ostream &out, const Fraction &f);
};
ostream &operator << (ostream &out, const Fraction &f){
	int divisor = gcd(f.num,f.den);
	out << f.num/divisor << "/" << f.den/divisor << endl;
	return out;
};
int main(){
	Fraction frac(10,15);
	cout << frac << endl;
	//cout << gcd(10,15) << endl;
	return 0;
}
