#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	
	//Check to make sure enough arguments are included on the command line
	if (argc < 2) {
		cout << "Error. Please be sure to include your input file." << endl;
		exit(1);
	}
	//Assign name of input file to string
	string argument = argv[1];
	
	//Declare input and output files
	ifstream input;
	ofstream output;
	ofstream output2;
	ofstream output3;
	
	//Open input file and if it doesn't exist, output error to the terminal
	//If it does exist, open the output files for writing
	input.open(argument + ".txt");
	if (!input) {
        cout << "Unable to open file, please try again." << endl;
        exit(1);
    } 
    else {
    	output.open(argument + "_set.txt");
    	output2.open(argument + "_vector.txt");
    	output3.open(argument + "_1_1.txt");
    }
	
	//Declare vector and set for storing words from the input file
	vector <string> userVector;
	set <string> userSet;
    string nextLine;
    
    while (getline(input, nextLine)) {
        istringstream iss(nextLine);
        string token;
        while (iss >> token) {
            string nopunct = "";
            //Remove Punctuation 
            for(auto &c : token) {      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
		        //Add each word to the vector and set
		        userVector.push_back(nopunct);
		        userSet.insert(nopunct);
	    }
    }
   
	//Write the contents of the set to the "_set.txt" output file
    for (set<string>::iterator iter=userSet.begin(); iter!=userSet.end(); ++iter) {
    	output << *iter << endl;
    }
    
    //Write the contents of the vector to the "_vector.txt" output file
    for(vector<string>::iterator iter = userVector.begin(); iter != userVector.end(); ++iter) {
    	output2 << *iter << endl;
	}
	
	//Declare map1
	map<string, string> map1;
	string last="";
	
	//Assign the first word in the vector as the key and second as the value to map1
	for (vector<string>::iterator iter=userVector.begin(); iter!=userVector.end(); iter++) {
		map1[last]=*iter;
		last = *iter;
	}
	
	//Write the contents of the map to the "_1_1.txt" output file
	for (map<string, string>::iterator iter=map1.begin(); iter!=map1.end(); ++iter) {
        output3 << iter->first << ", " << iter->second << endl;
	}
	
	//Generate 100 words and print to the terminal
	string state = "";
	for(int i = 0; i < 100; i++) {
		cout << map1[state] << " ";
		state = map1[state];
	}
	cout << endl;
	
	//Declare map2
	map<string, vector<string>> map2;
	string state2 = "";
	
	//Assign the values from the vector to the new map2
	for (vector<string>::iterator iter=userVector.begin(); iter!=userVector.end(); iter++) {
		map2[state2].push_back(*iter);
		state2 = *iter;
	}
	
	//Print out the vector of words that correspond to the 6th entry in map2
	int i = 0;
	for (map<string, vector<string>>::iterator iter=map2.begin(); iter!=map2.end(); ++iter) {
		if (i == 6) {
			cout << endl << (*iter).first << ": ";
			vector <string> inVect = (*iter).second;
			for (unsigned j=0; j<inVect.size(); j++){
        		cout << inVect[j] << ", ";
    		}
		} 
		i++;
	}
	cout << endl;

	//Generate random 100 word sermon from map2 and print to terminal
	srand(time(NULL));
	string state3 = "";
	cout << endl;
	for (int i = 0; i < 100; i++) {
	int ind = rand() % map2[state].size();
	cout << map2[state][ind] << " ";
	state3 = map2[state][ind];
	}
	cout << endl << endl;
	
	//Declare map3 and list
	int M=2;
	map<list<string>, vector<string>> map3;
	list<string> state4;
	for (int i = 0; i < M; i++) {
    	state4.push_back("");
	}
    
    //Assign value to new map from previous vector of words                    
	for (vector<string>::iterator it=userVector.begin(); it!=userVector.end(); it++) {
    	map3[state4].push_back(*it);
    	state4.push_back(*it);
    	state4.pop_front();
	}
	state4.clear();
	for (int i = 0; i < M; i++) {
    	state4.push_back("");
	}
	
	//Print out better 100 word sermon from map3 to the terminal
	for (int i = 0; i < 100; i++) {
    	int ind = rand() % map3[state4].size();
    	cout << map3[state4][ind]<<" ";
    	state4.push_back(map3[state4][ind]);
    	state4.pop_front();
	}
	cout << endl;
	
	//Close our input and output files
	input.close();
	output.close();
	output2.close();
	output3.close();
	return 0;
}