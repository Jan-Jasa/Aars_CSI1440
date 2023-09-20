#ifndef PROJ5_1_BUATHLETELIST_HPP_INCLUDED
#define PROJ5_1_BUATHLETELIST_HPP_INCLUDED

#include "proj5-BUAthlete.hpp"

class BUAthleteList {
private:
    BUAthlete *list;
    int capacity;
    int size;
    void resizeArray();

public:
    BUAthleteList();
    ~BUAthleteList();
    BUAthleteList(BUAthleteList&);
    BUAthleteList& operator=(BUAthleteList&);
    void addNCAAAthlete(int, string, string, string);
    void setBUInfo(int, Position, int);
    int findById(int);
    void sortByID();
    void sortByPosition();
    void sortByEvaluation();
    BUAthlete& operator[](int);
    string toString();
};


#endif // PROJ5-BUATHLETELIST_HPP_INCLUDED
