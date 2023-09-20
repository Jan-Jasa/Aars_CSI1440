/*
 * file: proj6-modularMain3.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment: project 6
 * due date: 3/27/2023
 *
 * date modified: 3/25/2023
 *      -work finished
 */

 #include <iostream>
 #include <fstream>

 using namespace std;

 const int PLIST_SIZE=10;

 /*
     * readPerson
     *
     * reads in person information from a istream
     *
     * Parameters:
     *      istream: in
     *      string: name
     *      int: age
     *
     * Output:
     *      return:  none
     *      reference parameters:  name, age
     *      stream:  in
*/
 void readPerson(istream &in, string &name, int &age) {
  getline(in, name);
  in >> age;
  in.ignore(3, '\n');
}


/*
     * readCustomer
     *
     * reads in customer information from a istream
     *
     * Parameters:
     *      istream: in
     *      string: name
     *      int: age
     *      double: shippingRate
     *
     * Output:
     *      return:  none
     *      reference parameters:  name, age, shippingRate
     *      stream:  in
*/
void readCustomer (istream &in, string &name, int &age, double &shippingRate){
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');
    in >> shippingRate;
    in.ignore(3, '\n');

}

/*
     * writePerson
     *
     * cout person information
     *
     * Parameters:
     *      ostream: out
     *      string: name
     *      int: age
     *
     * Output:
     *      return:  none
     *      reference parameters:  name, age
     *      stream:  out
*/
void writePerson(ostream &out, string name, int age){
    out << name << endl;
    out << age << endl;
}


/*
     * writeCustomer
     *
     * cout customer information
     *
     * Parameters:
     *      ostream: out
     *      string: name
     *      int: age
     *
     * Output:
     *      return:  none
     *      reference parameters:  name, age
     *      stream:  out
*/
void writeCustomer( ostream &out, string name, int age, double shippingRate ) {
    out << name << endl;
    out << age << endl;
    out << shippingRate << endl;
}


/*
     * requestInfo
     *
     * requests info from the user
     *
     * Parameters:
     *      ostream: out
     *      string: msg
     *
     * Output:
     *      return:  none
     *      reference parameters:  none
     *      stream:  out
*/
void requestInfo(ostream &out, string msg) {
    out << msg << endl;
}

/*
     * readAgain
     *
     * asks if user wants to read in another person
     *
     * Parameters:
     *      ostream: out
     *      istream: in
     *
     * Output:
     *      return:  string
     *      reference parameters:  none
     *      stream:  in, out
*/
string readAgain( ostream &out, istream &in ) {
    string choice;

    out << "Do you want to read in another person (yes/no)? " << endl;
    in >> choice;
    in.ignore(3, '\n');

    return choice;
}

/*
     * findPerson
     *
     * finds a person from their name
     *
     * Parameters:
     *      string: pList
     *      string: name
     *
     * Output:
     *      return:  int
     *      reference parameters:  none
     *      stream:  none
*/
int findPerson( string pList[], string name ) {
    int pos = -1, index = 0;

    while( pos == -1 && index < PLIST_SIZE ) {
        if( pList[index] == name ) {
            pos = index;
        }
        index++;
    }

    return pos;
}

int main(){
    string pNameArray[PLIST_SIZE], cNameArray[PLIST_SIZE];
    int pAgeArray[PLIST_SIZE], cAgeArray[PLIST_SIZE];
    double shippingRateArray[PLIST_SIZE];
    string choice, pTypeChoice;
    int index = 0;
    bool fileRead = false;
    ifstream pfile;
    ofstream opfile;

    cout << "Would you like to read the data from a file (yes/no)? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    if (choice == "yes") {
        fileRead = true;
        pfile.open("iperson.txt");
        if (!pfile) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }

        pfile >> pTypeChoice;
        pfile.ignore(3, '\n');
    }
    else {
        cout << "What type of Person? (person/customer)" << endl;
        cin >> pTypeChoice;
        cin.ignore(3, '\n');
    }

    if( pTypeChoice == "person" ) {
        opfile.open("operson.txt");
        choice = "yes";

        if (fileRead) {
           readPerson(pfile, pNameArray[index], pAgeArray[index]);
            if (!pfile) {
                choice = "no";
            }
        }

        while (choice != "no" && index < PLIST_SIZE) {
            if (!fileRead) {
                requestInfo(cout, "Please enter your name followed by your age.");
                //pList[index].readPerson(cin);
                readPerson(cin, pNameArray[index], pAgeArray[index]);
            }

            writePerson(opfile, pNameArray[index], pAgeArray[index]);

            index++;
            if (!fileRead) {
                choice = readAgain(cout, cin);
            }
            else {
                //pList[index].readPerson(pfile);
                readPerson(pfile, pNameArray[index], pAgeArray[index]);
                if (!pfile) {
                    choice = "no";
                }
            }
        }

        if (fileRead) {
            pfile.close();
        }
        opfile.close();

        cout << "Which person are you looking for? " << endl;
        getline(cin, choice);

        if ((index = findPerson(pNameArray, choice)) != -1) {
            cout << "Found your person: " << endl;
            //pList[index].writePerson(cout);
            writePerson(cout, pNameArray[index], pAgeArray[index]);
        }
        else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    }
    else {
        opfile.open("ocustomer.txt");
        choice = "yes";

        if (fileRead) {
            //cList[index].readPerson(pfile);
            readCustomer(pfile, cNameArray[index], cAgeArray[index], shippingRateArray[index]);
            if (!pfile) {
                choice = "no";
            }
        }

        while (choice != "no" && index < PLIST_SIZE) {
            if (!fileRead) {
                requestInfo(cout, "Please enter your name followed by your age then shipping rate");
                //cList[index].readPerson(cin);
                readCustomer(cin, cNameArray[index], cAgeArray[index], shippingRateArray[index]);
            }

            //cList[index].writePerson(opfile);
            writeCustomer(opfile, cNameArray[index], cAgeArray[index], shippingRateArray[index]);

            index++;
            if (!fileRead) {
                choice = readAgain(cout, cin);
            }
            else {
                //cList[index].readPerson(pfile);
                readCustomer(cin, cNameArray[index], cAgeArray[index], shippingRateArray[index]);
                if (!pfile) {
                    choice = "no";
                }
            }
        }

        if (fileRead) {
            pfile.close();
        }
        opfile.close();

        cout << "Which person are you looking for? " << endl;
        getline(cin, choice);

        if ((index = findPerson(cNameArray, choice)) != -1) {
            cout << "Found your person: " << endl;
            //cList[index].writePerson(cout);
            writeCustomer(opfile, cNameArray[index], cAgeArray[index], shippingRateArray[index]);
        }
        else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    }

    return 0;

}
