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
		virtual void setNextPin(bool source){
		}

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
		 virtual void  setNextPin(bool source){
		 	if(!pinATaken){
				pinA = source;
				this->pinATaken = true;
			}
			else if(!pinBTaken){
				pinB = source;
				this->pinBTaken = true;
			}
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
		virtual void setNextPin(bool source){
			if(!pinTaken){
				pin = source;
				this->pinTaken = true; 
			}
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
class NandGate : public BinaryGate {
	public:
		NandGate(string n): BinaryGate(n){};
		virtual bool performGateLogic(){
			bool a = getPinA();
			bool b = getPinB();
			if(a==1 && b == 1)
				return false;
			return true;
		}
};
class NorGate : public BinaryGate {
	public:
		NorGate(string n): BinaryGate(n){};
		virtual bool performGateLogic(){
			bool a = getPinA();
			bool b = getPinB();
			if(a==1 || b==1)
				return false;
			return true;
		}
};
class XorGate: public BinaryGate {
	public:
		XorGate(string n): BinaryGate(n){};
		virtual bool performGateLogic(){
			bool a = getPinA();
			bool b = getPinB();
			if((a == 1 && b == 0) || (a==0 && b == 1))
				return 	true;
			return false;
		}
};
class Connector{
	private:
		LogicGate *fromgate;
		LogicGate *togate;
	public:
		Connector(LogicGate *fgate, LogicGate *tgate){
			fromgate = fgate;
			togate = tgate;
			tgate->setNextPin(fromgate->getOutput());
		}
		LogicGate *getFrom(){
			return fromgate;
		}
		LogicGate *getTo(){
			return togate;
		}
};
int main(){
	AndGate gand1("gand1");
	AndGate gand2("gand2");
	OrGate gor1("gor1");
	NotGate gnot1("gnot1");
	NandGate gnand1("gnand1");
	NorGate gnor1("gnor1");
	XorGate gxor1("gxor1");
	

	Connector c1(&gand1,&gor1);
	Connector c2(&gand2,&gor1);
	Connector c3(&gor1, &gnot1);

	cout << gnot1.getOutput() << endl ;

	//cout << gand1.getOutput() << endl;
	//cout << gor1.getOutput() << endl;
	//cout << gnot1.getOutput() << endl;
	//cout << gnand1.getOutput() << endl;
	//cout << gnor1.getOutput() << endl;
	//cout << gxor1.getOutput() << endl;
	return 0;
}
