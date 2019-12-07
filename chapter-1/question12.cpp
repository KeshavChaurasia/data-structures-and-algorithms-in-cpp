//Design a class to represent a playing card. Now design a class to represent a deck of cards. Using these two classes, implement a favorite card game.
//

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Card {
	private:
		int rank;
		int suit;
	public:
		Card(){
			this->rank = 0;
			this->suit = 0;
		}
		Card(int rank,int suit){
			this->rank = rank;
			this->suit = suit;
		}
		int getRank(){
			return this->rank;
		}
		int getSuit(){
			return this->suit;
		}	
};

class Cards {
	private:
		unordered_map<string, int> cardsmap;
		Card deck[52];
	public:
		Cards(){
			int count=0;
			while(count<52){
				int rank = (1 + (std::rand() % (int)(13)));
      				int suit = (1 + (std::rand() % (int)(4)));
				string s = to_string(rank) + "-" + to_string(suit);
				if(cardsmap.find(s) == cardsmap.end()){
					cardsmap[s]=1;
					Card c(rank,suit);
					deck[count] = c;
					count++;
				}
			}
		}
		Card drawRandomCard(){
			int key = (1+ (std::rand() % (int)(52)));
			return deck[key];
		}
		void play (Card p1,Card p2){
			cout << p1.getRank() << p2.getRank() << endl;
			if((p1.getRank() ==0) && (p2.getRank() != 0))
				cout << "p1 wins" << endl;
			if((p2.getRank() ==0) && (p2.getRank() !=0))
				cout << "p2 wins" << endl;
			if(p1.getRank() > p2.getRank())
				cout << "p1 wins" << endl;
			if(p2.getRank() > p1.getRank())
				cout << "p2 wins" << endl;
			if(p1.getRank()==p2.getRank())
				cout << "draw" << endl; 
			return;
		}
		void getCard(){
			for(int i=0; i<52;i++){
				cout << this->deck[i].getSuit() << " " << this->deck[i].getRank() << endl;
			}
			
		}
		
};
int main(){
	Cards cards;
	//cards.getCard();
	Card c1 = cards.drawRandomCard();
	Card h1 = cards.drawRandomCard();
	cards.play(c1,h1);
	return 0;
}
