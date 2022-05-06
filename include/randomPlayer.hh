#ifndef RANDOMPLAYER_HH
#define RANDOMPLAYER_HH
#include "jeu.hh"
class randomPlayer{
private:
	int * selected;
	int * toPlay;
public:
	randomPlayer();
	~randomPlayer();
	int * getSelected(){
		return selected;
	}
	int * getPlay(){
		return toPlay;
	}
	void setSelected(int *s){
		selected=s;
	}
	void setToPlay(int * p){
		toPlay=p;
	}
	bool play(jeu & game);
	void select(jeu & game);
};
#endif
