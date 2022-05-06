#ifndef PIECE_HH
#define PIECE_HH
#include <iostream>
#include <string>
using namespace std;
class Piece
{
    private:
        bool bold; // Vrai si la pièce est foncée, faux sinon
        bool high; // Vrai si la pièce est haute, faux sinon
        bool circle; //Vrai si la pièce est ronde, faux sinon
        bool dig; //Vrai si la pièce est creuse, faux sinon
    public:
        Piece(bool b, bool h, bool c, bool d); // Le constructeur
        virtual ~Piece();//destructeur
        bool getBold()const{
            return bold;
        }//accesseur bold
        bool getHigh()const{
            return high;
        }//accesseur high
        bool getCircle()const{
            return circle;
        }//accesseur circle
        bool getDig()const{
            return dig;
        }//accesseur dig
        void setBold(bool b){
            bold=b;
        }//mutateur bold
        void setHigh(bool h){
            high=h;
        }//mutateur high
        void setCircle(bool c){
            circle=c;
        }//mutateur circle
        void setDig(bool d){
            dig=d;
        }//mutateur dig
        bool * getAllAtribute(); //permet de récuperer tout les attributs dans un tableau de booléens
        void afficherPiece();
        std::string toString(){
            std::string str="La piece est ";
            if (high){
                str+=" haute";
            }
            else{
                str+=" basse";
            }
            if(bold){
                str+=" foncee";
            }
            else{
                str+=" claire";
            }
            if(circle){
                str+=" ronde";
            }
            else{
                str+=" carree";
            }
            if(dig){
                str+=" creuse";
            }
            else{
                str+=" pleine";
            }
            return str;
        }

};

#endif // PIECE_HH
