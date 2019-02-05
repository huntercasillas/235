#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() 
{
    vector <string> fisherman;
    string fishSearch = "test";
    ifstream myFile;
    myFile.open("final.txt");
    
    if(!myFile.is_open()) {
            cout << "Could not open file" << endl;
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
                fishSearch = number;
            }
        for(vector<string>::iterator it=fisherman.begin();
        it!=fisherman.end(); it++) {
          cout << *it;
          if *it.contains
    } 
    if (fishSearch != "test") {
        cout << endl << "Type wanted: " << fishSearch;
    }
    return 0;
}
