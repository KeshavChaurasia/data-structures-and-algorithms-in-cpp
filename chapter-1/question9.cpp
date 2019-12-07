#include<iostream>
using namespace std;
class HalfAdder {
	protected:
		bool pinA;
		bool pinATaken;		
		bool pinB;
		bool pinBTaken;
		bool sum;
		bool carry;
	public:
		HalfAdder(){
			this->pinA = false;
			this->pinB = false;
			this->sum = false;
			this->carry = false;
		}
		HalfAdder(bool a, bool b){
			this->pinA = a;
			this->pinB = b;
		}
		void setPinA(bool a){
			this->pinA = a;
		}
		void setPinB(bool b){
			this->pinB = b;
		}	
		bool getSum(){
			if((this->pinA==1 && this->pinB==0) || (this->pinA==0 && this->pinB==1)){
				this->sum = 1;
			}
			else {
				this->sum = 0;
			}
			return this->sum;
		}
		bool getCarry(){
			if(this->pinA == 1 && this-> pinB == 1)
				this->carry = 1;
			else
				this->carry = 0;
			return this->carry;
		}
		virtual bool performSumLogic(){
			return false;
		}
		virtual bool performCarryLogic(){
			return false;
		}

};

class FullAdder {
	private:
		HalfAdder h1;
	        HalfAdder h2;
		bool pinA;
		bool pinB;
		bool pinC;
		bool sum;
		bool carry;

	public:
		FullAdder(){
		
		}
		FullAdder(bool a, bool b, bool c){
			this->pinA = a;
			this->pinB = b;
			this->pinC = c;
			h1.setPinA(this->pinA);
			h1.setPinB(this->pinB);
			h2.setPinA(this->pinC);
			h2.setPinB(h1.getSum());
			this->sum = h2.getSum();
			bool h2carry = h2.getCarry();
			bool h1carry = h1.getCarry();
			if(h1carry == 1 || h2carry == 1)
				this->carry = 1;
			else
				this->carry = 0;

		}
		bool getSum(){
			return this->sum;
		}
		bool getCarry(){
			return this->carry;
		}

};

int main(){
	//FullAdder fa[8];
	bool inputa[8];
	bool inputb[8];
	bool sum[8];
	bool defaultc = false;
	bool finalc = false;
	cout << "input a(a7....a0)" << endl;	
	for(int i=0;i<8;i++){
		cin >> inputa[7-i];	
	}
	cout << "input b(b7....b0)" << endl;
	for(int i=0;i<8;i++){
		cin >> inputb[7-i];
	}
	FullAdder fa(inputa[0],inputb[0],defaultc);
	sum[0] = fa.getSum();
	finalc = fa.getCarry();
	cout << "for fa 1" << " " << "sum :" << fa.getSum() << " carry: " << fa.getCarry() << endl;
	for(int i=1;i<8;i++){
		FullAdder fa(inputa[i],inputb[i],finalc);
		finalc = fa.getCarry();
		cout << "for fa " << i+1  << " " << "sum :" << fa.getSum() << " carry: " << fa.getCarry() << endl;
		sum[i]= fa.getSum();
	}
	cout << "final output c(c8.....c0)" << endl;
	cout << finalc << " ";
	for (int i=0; i<8;i++){
		cout << sum[7-i] << " " ;
	}
	cout << endl;
	//FullAdder fa1(1,1,1);
	//FullAdder fa2(
	//cout << fa1.getSum() << " " << fa1.getCarry() << endl;
	return 0;
}
