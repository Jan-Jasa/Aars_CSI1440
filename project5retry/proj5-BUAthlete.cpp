#include "proj5-BUAthlete.hpp"
#include <sstream>

void BUAthlete::setEvaluation(int eval){
    this->evaluation = eval;
}

void BUAthlete::setPosition(Position pos){
    this->bestFit = pos;
}
int BUAthlete::getEvaluation(){
    return this->evaluation;
}

Position BUAthlete::getPosition(){
    return this->bestFit;
}

string BUAthlete::toString(){
    ostringstream out;
    out << "ID: " << this->athleteID << endl;
    out << "Name: " << this->athleteName << endl;

    if( this->athleteLOI ){
        out << "School: " << this->schoolChoice << endl;
    } else {
        out << "Available" << endl;
    }
    out << "Evaluation: " << this->evaluation << endl;
    out << "Position: ";
    if (this->bestFit == 0) {
        out << "OL";
    } else if (this->bestFit == 1) {
        out << "QB";
    } else if (this->bestFit == 2) {
        out << "RB";
    } else if (this->bestFit == 3) {
        out << "WR";
    } else if (this->bestFit == 4) {
        out << "TE";
    } else if (this->bestFit == 5) {
        out << "DL";
    } else if (this->bestFit == 6) {
        out << "DE";
    } else if (this->bestFit == 7) {
        out << "LB";
    } else if (this->bestFit == 8) {
        out << "CB";
    } else if (this->bestFit == 9) {
        out << "S";
    } else if (this->bestFit == 10) {
        out << "K";
    }
    out << endl;

    return out.str();
}
