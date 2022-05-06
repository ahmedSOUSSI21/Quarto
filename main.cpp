#include <iostream>
#include "piece.hh"
#include "jeu.hh"
#include "randomPlayer.hh"
using namespace std;

int main(){
   jeu j = jeu();
   randomPlayer * p1 = new randomPlayer();
   randomPlayer * p2 = new randomPlayer();
   while (!j.isFinish()){
   			std::cout<<"**********************Player1************************"<<endl;
   			j.affichageReserve();
			p1->select(j);
			std::cout<<"**********************Player2************************"<<endl;
			j.affichageGrille();
			if(p2->play(j)){
				std::cout<<"Player 2 won !!"<<endl;
				j.affichageGrille();
				break;
			}
			j.affichageReserve();
			p2->select(j);
			std::cout<<"**********************Player1************************"<<endl;
			j.affichageGrille();
			if(p1->play(j)){
				std::cout<<"Player 1 won !! "<<endl;
				j.affichageGrille();
				break;
			}
   }
   			
   return 0;
}
