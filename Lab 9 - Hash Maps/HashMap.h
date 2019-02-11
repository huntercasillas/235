#include <iostream>
#include <vector>
using namespace std;

const int CONSIZE=10;
int hashme(string param, int tablesize) {
    unsigned char *ptr = (unsigned char *)param.c_str();
    int sum = 0;
    for(int i = 0; i < param.size(); i++) {
        sum += ptr[i];
    }
    int hashval = sum%tablesize;
    return hashval;
}
template <class Name, class Value>
class HashMap {
	private:
	struct node {
		pair<Name, Value> context;
		node *next;
	};
	
	node *context_array[CONSIZE];
	
	public:
	HashMap() {
		for(int i = 0; i < CONSIZE; i++) {
			context_array[i] = NULL;
		}
	}
	Value &operator[](Name opname) {
		return at(opname);
	}
	
	Value &at(Name name) {
		int hashval = hashme(name, CONSIZE); // Compute the hash value for this name, for now assume it is 0
		node *ptr = context_array[hashval];
		while(ptr != NULL) {
			if(name == ptr->context.first) { // We found it
				break;
			} else {
			  ptr = ptr->next;
			}
		}
		if(ptr == NULL) { // We need to create a new node, put it on the front of the list
			ptr = new node;
			ptr->next = context_array[hashval];
			context_array[hashval] = ptr;
			ptr->context.first = name;
		}
		return(ptr->context.second);
	}
};