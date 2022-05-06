#include <iostream>
#include "grille.hh"
using namespace std;

grille::grille(){
}
grille::~grille(){
}

// méthode qui ajoute une pièce à la case (x,y) si elle n'est pas déjà occupé,
// sinon renvoie une erreur
void grille::addPiece(int x, int y, Piece* pie){
    grid[x][y].addPiece(pie);
}
// Obtient la pièce de la case (x,y)
Piece* grille::getPiece(int x, int y){
    return grid[x][y].getPiece();
}
// Obtient et retire la pièce de la case (x,y)
Piece* grille::removePiece(int x,int y){
    return grid[x][y].removePiece();
}
// Permet de vérifier si le dernier coup aux coordonnées (x,y)
// est gagnant, retourne la ligne gagnante.
int** grille::checkVictory(int x, int y){
    int** patern = new int*[4];

    // check la verticale
    for (int i = 0; i < 4; i++){
        patern[i] = new int[2]{x,i};
    }
    if(checkPatern(patern))
        return patern;

    // check l'horizontale
    for (int i = 0; i < 4; i++){
        patern[i] = new int[2]{i,y};
    }
    if(checkPatern(patern))
        return patern;
    //check diagonale droit
    if(x == y){
        for (int i = 0; i < 4; i++){
            patern[i] = new int[2]{i,i};
        }
        if(checkPatern(patern))
            return patern;
    }

    //check diagonale inversé
    if(x == 3 - y){
        for (int i = 0; i < 4; i++){
            patern[i] = new int[2]{i,3 - i};
        }
        if(checkPatern(patern))
            return patern;
    }
    // pas gagnant
    return NULL;
}

// vérifie si la pattern aligne quatre pièces gagnantes,
// retourne true si c'est vérifié, sinon false
bool grille::checkPatern(int** patern){
    int size = 4;
    // check si la ligne a au moins 4 pièces
    for(int i = 0; i < size; i++){
        if(grid[patern[i][0]][patern[i][1]].getPiece() == NULL)
            return false;
    }

    // récupère les attributs des pièces
    bool ** attributs = new bool*[size];
    for(int i = 0; i < size; i++){
        attributs[i] = grid[patern[i][0]][patern[i][1]].getPiece()->getAllAtribute();
    }

    // vérifie TOUT
    // pour chaque attributs
    for(int i = 0; i < 4; i++){
        bool flag = false;
        int j = 1;
        // vérifie les quatres pièces
        while(j < 4 && !flag){

            if(attributs[j][i] != attributs[j-1][i])
                flag = true;
            j++;
        }
        // si quatre identique
        if(!flag) return true;
    }

    return false;

}
