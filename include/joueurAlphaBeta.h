#ifndef JOUEURALPHABETA_HH
#define JOUEURALPHABETA_HH
#include <iostream> 
#include "grille.hh"
#include "reserve.hh"

class joueurAlphaBeta{
private:
	int * selectCoords;
	int * playCoords;
	int profondeur;
public:
	joueurAlphaBeta();
	~joueurAlphaBeta();
	int maxi(int a, int b){ return ((a>b)? a:b); }
  	int mini(int a, int b){ return ((a<b)? a:b); }
  	int calcul(grille * g, int x, int y, bool myTurn);
  	//elle prend un tableau des coordonnées à selectionner, et un jeu et renvoie des coordonnées à jouer
	void play(int * s, grille * g, Reserve * r);
	//elle prend des coordonnées à selectionner, des coordonnées à jouer, un booléen pour l'état max et l'état min
	//un entier pour la profondeur, pour alpha et pour beta. elle renvoie une valeur entière 
	int valeurAlphaBeta(int rx,int ry,int gx,int gy, bool myTurn, grille * g, Reserve * r, int depth, int alpha, int beta, int * x,int * y);
	int * getPlayCoords(){
		return playCoords;
	}
	int * getSelectCoords(){
		return selectCoords;
	}
};
#endif
