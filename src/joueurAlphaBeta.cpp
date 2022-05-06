#include "joueurAlphaBeta.h"
#include <stdio.h>
#include "grille.hh"
#include "reserve.hh"
joueurAlphaBeta::joueurAlphaBeta(){
	selectCoords = new int[2];
	playCoords = new int[2];
	profondeur = 16;
}

joueurAlphaBeta::~joueurAlphaBeta(){
	delete selectCoords;
	delete playCoords;
}

int joueurAlphaBeta::calcul(grille * g, int x, int y, bool myTurn){
	    int score = 0;
	    if(g->checkVictory(x,y) != NULL)
	        myTurn ? score = 100 :score = -100;
	    return score;
}
	
//elle prend un tableau des coordonnées à selectionner, et un jeu et renvoie des coordonnées à jouer
void joueurAlphaBeta::play(int * s, grille * g, Reserve * r){
 	    int v;
 	    int x;
 	    int y;
	    int alpha=0;
	    int * sC = new int[2];
	    if(s==NULL){
	    	do{
	    		sC[0] = rand()%4;
	    		sC[1] = rand()%4;
	    	}while(r->getPiece(sC[0],sC[1])==NULL);
	    }
	    else{
	    	sC=s;
	    }
	    int * bestpC = new int[2];
	    int * bestsC = new int [2];
	    for(int i=0;i<4;i++){
	    	for(int j=0;j<4;j++){
	    	   if(g->getPiece(i,j)==NULL){
	    	     g->addPiece(i,j,r->removePiece(sC[0],sC[1]));
	    	     v=valeurAlphaBeta(sC[0],sC[1],i,j,false,g,r,profondeur,alpha,-100,&x,&y);
	    	     r->addPiece(sC[0],sC[1],g->removePiece(i,j));
	    	     if(v > alpha){
	    	     	playCoords[0] = i;
	    	     	playCoords[1]=j;
	    	     	alpha=v;
	    	     }
	    	   }
	    	}
	    }
	    selectCoords[0]=x;
	    selectCoords[1]=y;
	    std::cout<<"selected: "<<x<<","<<y<<endl;
	    std::cout<<"to play :"<<playCoords[0]<<","<<playCoords[1]<<endl;
	    
}	
//elle prend des coordonnées à selectionner, des coordonnées à jouer, un booléen pour l'état max et l'état min
//un entier pour la profondeur, pour alpha et pour beta. elle renvoie une valeur entière 
int joueurAlphaBeta::valeurAlphaBeta(int rx, int ry,int gx,int gy, bool myTurn,grille * g,Reserve * r, int depth, int alpha, int beta,int *x,int *y){
	    if(g->checkVictory(gx,gy) != NULL)
	        return calcul(g,gx,gy,myTurn);
	    if(depth == 0)
	    	return calcul(g,gx,gy,myTurn);
	    else if(myTurn){
	    	for(int iG=0;iG<4;iG++){
	    	   for(int jG=0;jG<4;jG++){
	    	   	if(g->getPiece(iG,jG)==NULL){
	    	   	    
	    	   	    for(int iR=0;iR<4;iR++){
	    	   	    	for(int jR=0;jR<4;jR++){
	    	   	    	    if(r->getPiece(iR,jR)!=NULL){
					g->addPiece(iG,jG,r->removePiece(iR,jR));
	    	   	    	    	alpha=maxi(alpha,valeurAlphaBeta(iR,jR,iG,jG,!myTurn,g,r,depth-1,alpha,beta,x,y));
	    	   	    	    	r->addPiece(iR,jR,g->removePiece(iG,jG));
	    	   	    	    	//coupe alpha
	    	   	    	    	if (alpha>=beta){
	    	   	    	    	    return alpha;
	    	   	    	    	}
	    	   	    	    }
	    	   	    	}
	    	   	     }
	    	   	}
	    	    }
	    	}
	    	return alpha;
	    }else{
	    	for(int iG=0;iG<4;iG++){
	    	   for(int jG=0;jG<4;jG++){
	    	   	if(g->getPiece(iG,jG)==NULL){
	    	   	    
	    	   	    for(int iR=0;iR<4;iR++){
	    	   	    	for(int jR=0;jR<4;jR++){
	    	   	    	    if(r->getPiece(iR,jR)!=NULL){
					g->addPiece(iG,jG,r->removePiece(iR,jR));
	    	   	    	    	beta=mini(beta,valeurAlphaBeta(iR,jR,iG,jG,!myTurn,g,r,depth-1,alpha,beta,x,y));
	    	   	    	    	r->addPiece(iR,jR,g->removePiece(iG,jG));
	    	   	    	    	//coupe alpha
	    	   	    	    	if (beta<=alpha){
	    	   	    	    	    *x=iR;
	    	   	    	    	    *y=jR;
	    	   	    	    	    return beta;
	    	   	    	    	}
	    	   	    	    }
	    	   	    	}
	    	   	     }
	    	   	}
	    	    }
	    	}
	    	return beta;
	    		
            }

}
