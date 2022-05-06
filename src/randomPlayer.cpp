#include <cstdlib>
#include <cstdio>
#include <string>
#include "randomPlayer.hh"
randomPlayer::randomPlayer(){
	selected = new int[2];
	toPlay= new int[2];
}
randomPlayer::~randomPlayer(){
	delete selected;
	delete toPlay;
}
bool randomPlayer::play(jeu & game){
	int randX,randY;
	if(game.getCoordsSelected()==NULL)
		throw new string("aucun coordonnée séléctionnée\n");
	else{
		
		do{
			randX = rand()%4;
			randY = rand()%4;
		}while(game.getGrille()->getPiece(randX,randY)!=NULL);
		game.playPiece(randX,randY);
	}
	return game.getGrille()->checkVictory(randX,randY);
}
void randomPlayer::select(jeu & game){
		int randX,randY;
		do{
			randX = rand()%4;
			randY = rand()%4;
		}while(game.getReserve()->getPiece(randX,randY)==NULL);
		
		game.selectPiece(randX,randY);
}
		
			
