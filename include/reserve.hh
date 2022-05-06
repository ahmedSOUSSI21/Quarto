#ifndef RESERVE_HH
#define RESERVE_HH
#include <ostream>
#include "box.hh"
#include "piece.hh"


class Reserve
{
    public:
        Reserve(); //constructeur
        virtual ~Reserve(); //destructeur
        const int defaultSize = 4;
        Piece * removePiece(int, int);
        void addPiece(int x,int y,Piece * p);
        Piece* getPiece(int, int);
    private:
        box reserve[4][4];
};
#endif // RESERVE_HH
