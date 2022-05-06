#include <iostream>
#include "reserve.hh"
using namespace std;

Reserve::Reserve(){
    //On crée toute les pièces du jeu et on les met dans la reserve
    //ça aurait été possible de faire une boucle, mais
    //on a 16 pièce donc  les faire manuellement ne pose pas problême
    // et nous évite de nous tromper dans les différents cas
    Piece *p1 = new Piece(false,false,false,false);
    Piece *p2 =new Piece(false,false,false,true);
    Piece *p3 =new Piece(false,false,true,false);
    Piece *p4 =new Piece(false,false,true,true);
    Piece *p5 =new Piece(false,true,false,false);
    Piece *p6 =new Piece(false,true,false,true);
    Piece *p7 =new Piece(false,true,true,false);
    Piece *p8 =new Piece(false,true,true,true);
    Piece *p9 =new Piece(true,false,false,false);
    Piece *p10 =new Piece(true,false,false,true);
    Piece *p11 =new Piece(true,false,true,false);
    Piece *p12 =new Piece(true,false,true,true);
    Piece *p13 =new Piece(true,true,false,false);
    Piece *p14 =new Piece(true,true,false,true);
    Piece *p15 =new Piece(true,true,true,false);
    Piece *p16 =new Piece(true,true,true,true);
    reserve[0][0].addPiece(p1);
    reserve[0][1].addPiece(p2);
    reserve[0][2].addPiece(p3);
    reserve[0][3].addPiece(p4);
    reserve[1][0].addPiece(p5);
    reserve[1][1].addPiece(p6);
    reserve[1][2].addPiece(p7);
    reserve[1][3].addPiece(p8);
    reserve[2][0].addPiece(p9);
    reserve[2][1].addPiece(p10);
    reserve[2][2].addPiece(p11);
    reserve[2][3].addPiece(p12);
    reserve[3][0].addPiece(p13);
    reserve[3][1].addPiece(p14);
    reserve[3][2].addPiece(p15);
    reserve[3][3].addPiece(p16);
}
Reserve::~Reserve(){}
Piece * Reserve::removePiece(int x, int y){
    return reserve[x][y].removePiece();
}
void Reserve::addPiece(int x,int y,Piece * p){
    reserve[x][y].addPiece(p);
}
Piece * Reserve::getPiece(int x, int y){
    return reserve[x][y].getPiece();
}
