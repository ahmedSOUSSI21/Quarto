#include <iostream>
#include <string>
#include "jeu.hh"
#include "reserve.hh"
#include <stdio.h>
using namespace std;

jeu::jeu(){
    g=new grille();
    r=new Reserve();
    pieceSelected =NULL;
    piecePlayed = NULL;
    tour=1;
}
jeu::jeu(grille * gr, Reserve * re,int *sC,int *pC){ 
    g=gr;
    r=re;
    pieceSelected =sC;
    piecePlayed = pC;
}
void jeu::reset(){
    delete g;
    delete r;
    g = new grille();
    r = new Reserve();
    tour = 1;
}
void jeu::selectPiece(int x,int y){
    if(r->getPiece(x,y)==NULL){
        throw new string("ERREUR : la case est vide");
    }
    else{
        pieceSelected= new int [2]{x,y};
    }
}
void jeu::playPiece(int x,int y){
    if(g->getPiece(x,y)!=NULL){
        throw new string("ERREUR : la case est occupée par une pièce");
    }
    if(pieceSelected == NULL)
            throw new string("Erreur: Aucune case séléctioné");
    piecePlayed = new int [2]{x,y};
    g->addPiece(x,y,r->removePiece(pieceSelected[0],pieceSelected[1]));
    pieceSelected=NULL;
    tour++;
}
bool jeu::isFinish(){
    if(piecePlayed == NULL)
        return false;
    return g->checkVictory(piecePlayed[0],piecePlayed[1]) || tour >= 16;
}
void jeu::unplay(int *sC, int *pC){
     r->addPiece(sC[0],sC[1],g->removePiece(pC[0],pC[1]));
}
void jeu::affichageGrille(){
    printf("***************La grille**************\n");
    for(int i=0; i<4;i++){
    	printf("*");
    	for(int j=0;j<4;j++){
    		if(g->getPiece(i,j)==NULL){
     			printf("----");
     			continue;
     		}
    		g->getPiece(i,j)->afficherPiece();
    		printf("**");
    	}
    	printf("*");
    	printf("\n");
   }
}
void jeu::affichageReserve(){
    printf("***************La reserve**************\n");
    for(int i=0; i<4;i++){
    	printf("*");
    	for(int j=0;j<4;j++){
    		if(r->getPiece(i,j)==NULL){
     			printf("----");
     			continue;
     		}
    		r->getPiece(i,j)->afficherPiece();
    		printf("**");
    	}
    	printf("*");
    	printf("\n");
   }
}
