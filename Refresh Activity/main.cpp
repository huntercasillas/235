#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() 
{
    vector <string> fisherman;
    string fishSearch = "";
    ifstream myFile;
    myFile.open("final.txt");
    
    if(!myFile.is_open()) {
            cout << "Could not open file, please try again." << endl;
            exit(1);
        } 
        else {
            string name;
            string number;
            string fish;
            string combined;
            while(myFile >> name >> number >> fish && name != "Search") {
                combined = name + "     " + number + "  " + fish + "\n";
                fisherman.push_back(combined);
                }
                if (name == "Search") {
                    fishSearch = number;
                }
            }
        for(vector<string>::iterator it=fisherman.begin(); it!=fisherman.end(); it++) {
            cout << *it;
    } 
    cout << endl;
    
    if (fishSearch != "") {
        cout << "Type wanted: " << fishSearch;
        cout << endl << endl;
    }
    else {
        cout << "Error, the type of fish wanted was not specified." << endl << endl;
        exit(1);
    }
    
    return 0;
}