#include "proj5-BUAthleteList.hpp"
#include <sstream>
#include <iostream>

void BUAthleteList::resizeArray(){
    this->capacity += 2;
    BUAthlete *temp = this->list;
    this->list = new BUAthlete[this->capacity];
    for(int i = 0; i < this->size; ++i){
        this->list[i] = temp[i];
    }
    delete[] temp;
}

BUAthleteList::BUAthleteList(){
    this->size = 0;
    this->capacity = 2;
    this->list = new BUAthlete[this->capacity];
}

BUAthleteList::~BUAthleteList(){
  delete[] this->list;
}

BUAthleteList::BUAthleteList(BUAthleteList& that){
    this->size = that.size;
    this->capacity = that.capacity;
    this->list = new BUAthlete[this->capacity];
    for(int i = 0; i < this->size; ++i){
        this->list[i] = that.list[i];
    }
}

BUAthleteList& BUAthleteList::operator=(BUAthleteList& that){
    if(this != &that){
        delete[] this->list;
        this->size = that.size;
        this->capacity = that.capacity;
        this->list = new BUAthlete[this->capacity];
        for(int i = 0; i < this->size; ++i){
            this->list[i] = that.list[i];
        }
    }
    return *this;
}
void BUAthleteList::addNCAAAthlete(int id, string name, string loi, string school){
    if(this->size == this->capacity){
        resizeArray();
    }
    this->list[this->size].setID(id);
    this->list[this->size].setName(name);
    this->list[this->size].setLOI(loi);
    this->list[this->size].setSchool(school);
    this->size++;
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval){
    this->list[index].setPosition(pos);
    this->list[index].setEvaluation(eval);
}
int BUAthleteList::findById(int id){
    int lo = 0;
    int hi = this->size - 1;
    int mid;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(this->list[mid].getID() < id){
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if(this->list[lo].getID() == id){
        return lo;
    }
    else if(this->list[hi].getID() == id){
        return hi;
    }
    else{
        return -1;
    }
}


void BUAthleteList::sortByID(){
    //need quicksort couldn't figure out
    BUAthlete temp;
    for(int i = 0; i < this->size; ++i){
        for(int j = 0; j < this->size - i - 1; ++j){
            if(this->list[j].getID() >
               this->list[j+1].getID()){
                temp = this->list[j];
                this->list[j] = this->list[j+1];
                this->list[j+1] = temp;
            }
        }
    }
}

void BUAthleteList::sortByPosition(){
    BUAthlete temp;
    for(int i = 0; i < this->size; ++i){
        for(int j = 0; j < this->size - i - 1; ++j){
            if(this->list[j].getPosition() >
            this->list[j+1].getPosition()){
                temp = this->list[j];
                this->list[j] = this->list[j+1];
                this->list[j+1] = temp;
            }
        }
    }
}

void BUAthleteList::sortByEvaluation(){
    //need quicksort couldn't figure out
    BUAthlete temp;
    for(int i = 0; i < this->size; ++i){
        for(int j = 0; j < this->size - i - 1; ++j){
            if(this->list[j].getEvaluation() <
            this->list[j+1].getEvaluation()){
                temp = this->list[j];
                this->list[j] = this->list[j+1];
                this->list[j+1] = temp;
            }
        }
    }
}

BUAthlete& BUAthleteList::operator[](int ndx){
    return this->list[ndx];
}

string BUAthleteList::toString(){
    ostringstream out;
    for(int i = 0; i < this->size; ++i){
        out << "[ " << i << " ]" << endl;
        out << this->list[i].toString();
    }
    return out.str();
}
