#ifndef GRILLE_HH
#define GRILLE_HH
#include <iostream>
#include "box.hh"
#include "piece.hh"
using namespace std;

/*
    La classe Grille permet de représenter une instance
    d'un plateau de Quarto composé d'un tableau de
    Case de taille 4 sur 4.
*/
class grille
{
private:
    // tableau de cases (box) de taille 4 x 4
    box grid[4][4];
    // méthode vérifiant si le pattern en entrée est gagnant
    bool checkPatern(int**);
public:
        grille(); //initialise une grille vide
        virtual ~grille(); //destructeur
        // taille du plateau d'un jeu de Quarto (taille d'un coté)
        const int defaultSize = 4;

        // méthode qui ajoute un pièce à la case aux coordonnées (x,y)
        void addPiece(int, int, Piece *);
        // Obtient la pièce de la case (x,y)
        Piece* getPiece(int, int);
        // Obtient et retire la pièce de la case (x,y)
        Piece* removePiece(int,int);
        // Permet de vérifier si le dernier coup aux coordonnées (x,y)
        // est gagnant, retourne la ligne gagnante.
        int** checkVictory(int,int);

        // surcharge de <<
        friend std::ostream& operator<<(std::ostream&, const grille&);
};

#endif // GRILLE_HH
