#include <iostream>
#include "piece.hh"
using namespace std;
Piece::Piece(bool b, bool h, bool c, bool d):
    bold(b),high(h),circle(c),dig(d)
{}
Piece::~Piece(){}
bool * Piece::getAllAtribute(){
    bool * attributes = new bool[4]{bold, circle,high,dig};
    return attributes;
}

void Piece::afficherPiece(){
     bool * attributs = getAllAtribute();	
     if(attributs[0]==true)
       	printf("%s","F"); //F pour Foncée
     else
    	printf("%s","C"); //C pour Claire
     if(attributs[1]==true)
    	printf("%s","R"); //R pour Ronde
     else
    	printf("%s","Sq"); //Sq pour Square
     if(attributs[2]==true)
    	printf("%s","H"); //H pour haute
     else
    	printf("%s","B"); //B pour basse
     if(attributs[3]==true)
    	printf("%s","Cr");//Cr pour Creuse 
     else
    	printf("%s","P");//P pour pleine
}
