#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include "VectorMap.h"
#include "HashMap.h"

using namespace std;

list <string> lst;
int main(int argc, char **argv)
{
  if (argc < 2) {
		cout << "Error. Please be sure to include your input file." << endl;
		exit(1);
	}
  
  ifstream file(argv[1]);
  if (!file) {
        cout << "Unable to open file, please try again and include file extensions." << endl;
        exit(1);
    } 
    
  // Read data
  while (!file.eof()) {
    string word, nopunct="";
    file >> word;
    
    for(auto &c : word) { // Remove Punctuation      
      if (isalpha(c)) {
        nopunct +=c;       
      }
    }
    lst.push_back(nopunct);
  }
  clock_t oldtime, newtime; // To time the functions
  double seconds;
  oldtime = clock();
  VectorMap<string, vector<string>> wordmap;
  string state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    wordmap[state].push_back(*it);
    state = *it;
  }
  
  
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 1000; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind] << " ";
    state = wordmap[state][ind];
  }
  cout << endl;
  newtime = clock();
  seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
  cout << endl << "Vector Map took "<< seconds << endl << endl;
  
  oldtime = clock();
  HashMap<string, vector<string>> hashwordmap;
  state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    hashwordmap[state].push_back(*it);
    state = *it;
  }
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 1000; i++) {
    int ind = rand() % hashwordmap[state].size();
    cout << hashwordmap[state][ind] << " ";
    state = hashwordmap[state][ind];
  }
  cout << endl;
  newtime = clock();
  seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
  cout << endl << "Hash Map took " << seconds << endl;
}
