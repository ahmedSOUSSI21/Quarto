#ifndef BOX_HH
#define BOX_HH
#include "piece.hh"


class box
{
private:
    Piece * p;
public:
    box();//initialise une case non définie
    box(Piece * pie); //initialise une case qui contient la pièce pie
    virtual ~box(); //destructeur
    void addPiece(Piece * pie);
    // méthode qui retire la pièce de la case s'il
    // il y a déjà une pièce
    Piece * removePiece();
    // permet de savoir si la case est vide
    bool isEmpty();
    // Obtient l'instance de pièce de la case
    Piece* getPiece();
};

#endif // BOX_HH
