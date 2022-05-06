#include <iostream>
#include "box.hh"
#include <stdio.h> 
using namespace std;

box::box(){
    p = NULL;
}
box::box(Piece * pie):p(pie){}
box::~box(){
    delete p;
}
void box::addPiece(Piece * pie)
{
    if (p != NULL){
        throw string("Erreur: La case contient déjà une autre instance de Pièce");
    }
    p=new Piece(pie->getBold(),pie->getHigh(),pie->getCircle(),pie->getDig());
}

// Obtient l'instance de la pièce dans la case
Piece* box::getPiece()
{
    return p;
}

// Obtient et retire la pièce de la case si la case n'est pas vide,
// sinon renvoie une erreur
Piece * box::removePiece()
{
    if (p == NULL)
        throw new string("Erreur: La case est vide");
    Piece * pie = p;
    p = NULL;
    return pie;
}

// Permet de savoir si la case est vide,
// retourne true si elle est vide, sinon false
bool box::isEmpty(){
    return (p == NULL);
}

    	
