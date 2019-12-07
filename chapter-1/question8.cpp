//Research other types of gates that exist (such as NAND, NOR, and XOR). Add them to the circuit hierarchy. How much additional coding did you need to do?

#include<iostream>
using namespace std;

class LogicGate {
	protected:
		string label;
		bool output;
	public:
		LogicGate(string n){
			label = n;
		}

		string getLabel(){
			return label;
		}
		bool getOutput(){
			output = performGateLogic();
			return output;
		}
		virtual bool performGateLogic(){
			return false;
		};
};

class BinaryGate  : public LogicGate {
	protected:
		bool pinA;
		bool pinATaken;
		bool pinB;
		bool pinBTaken;
	public:
		BinaryGate(string n) : LogicGate(n){
			pinATaken = false;
			pinBTaken = false;
		}
		 bool getPinA(){
		 	if(pinATaken == false){
				cout << "Enter Pin input for gate " <<  getLabel() << ": ";
			      	cin >> pinA;
				pinATaken = true;
			}
			return pinA;
		 }

		 bool getPinB(){
			 if(pinBTaken == false){
				 cout << "Enter Pin input for gate " << getLabel() << ": ";
				 cin >> pinB;
				 pinBTaken = true;
			 }
			 return pinB;
		 }
};
class UnaryGate : public LogicGate {
	protected:
		bool pin;
		bool pinTaken;
	public:
		UnaryGate(string n) : LogicGate(n) {
			pinTaken = false;
		}
		bool getPin(){
			if(pinTaken == false){
				cout << "Enter pin input for gate " << getLabel() << ": ";
				cin >> pin;
				pinTaken = true;
			}
			return pin;
		}
};
class AndGate : public BinaryGate {
	public:
		AndGate(string n) : BinaryGate(n){};
		virtual bool performGateLogic(){
			bool a = getPinA();
			bool b = getPinB();
			if(a==1 && b==1)
				return true;
			return false;
		}
};
class OrGate : public BinaryGate {
	public:
		OrGate(string n): BinaryGate(n){};
		virtual bool performGateLogic(){
			bool a = getPinA();
			bool b = getPinB();
			if(a==1 || b==1)
				return true;
			return false;
		}
};
class NotGate : public UnaryGate {
	public:
	       	NotGate(string n) : UnaryGate(n){};
		virtual bool performGateLogic(){
			return !getPin();
		}
};
int main(){
	AndGate gand1("gand1");
	OrGate gor1("gor1");
	NotGate gnot1("gnot1");
	cout << gand1.getOutput() << endl;
	cout << gor1.getOutput() << endl;
	cout << gnot1.getOutput() << endl;
	return 0;
}
