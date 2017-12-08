#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    string mystring;
    map<string, int> registers;
    int max = 0;

    while (getline(cin, mystring))
	{
	    // cout << mystring << endl;
	    // parse the string
	    
	    stringstream ss(mystring);
	    string buf;
	    vector<string> tokens;
	    while (ss >> buf) {
	    	tokens.push_back(buf);
	    }

	    // Read the first token
	    pair<map<string, int>::iterator, bool> ret;
	    map<string, int>::iterator it;
	    ret = registers.insert( pair<string, int>(tokens[0], 0) );

	    if (ret.second == false) {
	    	// Update the iterator
	    	it = ret.first;
	    }

	    // Check the condition
	    // the forth token
	    it = registers.find(tokens[4]);
	    if (it == registers.end()) {
	    	// Create a new map
	    	registers.insert( pair<string, int>(tokens[4], 0) );
	    }

	    // If it is true or not.
	    bool cond = false;
	    if (tokens[5].compare("==") == 0) {
	    	cond = registers[tokens[4]]  == atoi(tokens[6].c_str());
	    } else if (tokens[5].compare("!=") == 0) {
	    	cond = registers[tokens[4]]  != atoi(tokens[6].c_str());
	    } else if (tokens[5].compare(">=") == 0) {
	    	cond = registers[tokens[4]]  >= atoi(tokens[6].c_str());
	    } else if (tokens[5].compare(">") == 0) {
	    	cond = registers[tokens[4]]  >  atoi(tokens[6].c_str());
	    } else if (tokens[5].compare("<") == 0) {
	    	cond = registers[tokens[4]]  <  atoi(tokens[6].c_str());
	    } else if (tokens[5].compare("<=") == 0) {
	    	cond = registers[tokens[4]]  <= atoi(tokens[6].c_str());
	    }

	    if (cond) {
	    	if (tokens[1].compare("inc") == 0) {
	    		registers[tokens[0]] += atoi(tokens[2].c_str());
	    	} else if (tokens[1].compare("dec") == 0) {
	    		registers[tokens[0]] -= atoi(tokens[2].c_str());
	    	}
	    	// For part 2
	    	if (registers[tokens[0]] > max) {
	    		max = registers[tokens[0]];
	    	}
	    }
	}

	map<string, int>::iterator max_it = registers.begin();
	for (auto ite = registers.begin(); ite != registers.end(); ++ite) {
		if (ite->second > max_it->second) {
			max_it = ite;
		}
	} 

	printf("Max: %s: %d\n", max_it->first.c_str(), max_it->second);
	cout << "The maximum " << max << endl;
}
