#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    int x = 0;
    int y = 0;
    int count = 1;
    bool flag = false;
    vector<int> numArray;
    fstream file("sortedInts", ios::in | ios::out | ios::binary);

    //checks if file is opened
    if(!file){
        cerr << "Error: bad file";
        return 1;
    }


    //outputs the ints to the screen
    while(file.read((char*)&y, sizeof(int))){
        numArray.push_back(y);
    }
    cout << "Stored integers: " << endl;
    for(int i=0; i< numArray.size(); i++){
        cout << numArray[i] << " ";
    }
    cout << endl;

    cout << "Input int X into file: ";
    cin >> x;
    cout << endl;

    //insert x into file
    //flag indicates if x has been inserted
    while(count <= numArray.size() + 1 && !flag){
        file.seekg((count)*-sizeof(int),ios::end);
        file.read((char*) &y,sizeof(int));
        if (x >= y){
            flag = true;
            file.write((char*)&x,sizeof(int));
        }
        else{
            file.write((char*)&y,sizeof(int));
        }
    }

    //if x is always less than y
    if(!flag){
        file.seekg(0,ios::beg);
        file.write((char*)&x, sizeof(int));
    }

    for(int i = 0; i < numArray.size() + 1; ++i){
        file.seekg((i)*sizeof(int), ios::beg);
        file.read((char*)&y, sizeof(int));
        cout << y << endl;
    }

    file.close();

    return 0;
}
