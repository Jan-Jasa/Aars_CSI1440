#include "proj5-BUAthleteList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    BUAthleteList list;
    ifstream f1;
    ifstream f2;
    int id;
    int eval;
    int index;
    Position pos;
    string name;
    string loi;
    string school;
    istringstream inSS;
    string buffer;

    f1.open("proj5-NCAAAthlete.csv");

    while(getline(f1,buffer,',')){
        inSS.clear();
        inSS.str(buffer);
        inSS >> id;
        getline(f1,buffer,',');
        name = buffer;
        getline(f1,buffer,',');
        loi = buffer;
        getline(f1,buffer);
        school = buffer;
        list.addNCAAAthlete(id, name, loi, school);
    }

    list.sortByID();
    f1.close();
    f2.open("proj5-BUAthlete.csv");

    while(getline(f2,buffer,',')) {
        inSS.clear();
        inSS.str(buffer);
        inSS >> id;
        getline(f2, buffer, ',');
        if (buffer == "OL") {
            pos = OL;
        } else if (buffer == "QB") {
            pos = QB;
        } else if (buffer == "RB") {
            pos = RB;
        } else if (buffer == "WR") {
            pos = WR;
        } else if (buffer == "TE") {
            pos = TE;
        } else if (buffer == "DL") {
            pos = DL;
        } else if (buffer == "DE") {
            pos = DE;
        } else if (buffer == "LB") {
            pos = LB;
        } else if (buffer == "CB") {
            pos = CB;
        } else if (buffer == "S") {
            pos = S;
        } else if (buffer == "K") {
            pos = K;
        }
        getline(f2, buffer);
        inSS.clear();
        inSS.str(buffer);
        inSS >> eval;

        index = list.findById(id);
        list[index].setEvaluation(eval);
        list[index].setPosition(pos);
    }

    list.sortByEvaluation();
    list.sortByPosition();

    cout << list.toString();

    return 0;
}
