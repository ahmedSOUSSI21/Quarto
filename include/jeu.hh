#ifndef JEU_HH
#define JEU_HH
#include "grille.hh"
#include "reserve.hh"
class jeu{
private:
    Reserve * r;
    grille *g;
    int * pieceSelected; //la case 0 contient la coordonnée X de la pièce choisie dans la reserve
    //la case 1 contient la coordonnée Y de la pièce choisie.
    int * piecePlayed;//la case 0 contient la coordonnée X de la pièce jouée sur la grille
    //la case 1 contient la coordonnée Y de la pièce jouées.
    int tour;
public:
    jeu(); //constructeur de jeu 
    jeu(grille * gr, Reserve * re,int *,int*);
    void reset(); //réinitialisation de la grille
    grille * getGrille(){
        return g;
    }
    Reserve * getReserve(){
        return r;
    }
    int GetTour(){
        return tour;
    }
    void unplay(int *sC, int *pC);
    int* getCoordsSelected(){
        return pieceSelected;
    }
    int* getCoordsPlayed(){
        return piecePlayed;
    }
    Piece * getPieceSelected(){
    	return r->getPiece(pieceSelected[0],pieceSelected[1]);
    }
    Piece * getPiecePlayed(){
    	return r->getPiece(piecePlayed[0],piecePlayed[1]);
    }
    void selectPiece(int,int);
    void playPiece(int,int);
    bool isFinish(); //vérifie si la partie est finie 
    void affichageGrille();
    void affichageReserve();
};

#endif // JEU_HH
