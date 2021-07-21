
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

#include "pset.h"


using namespace std;

int main(int argc, char* argv[]) {
	string dictfile;
	string textfile;
	string word; 
	size_t pos;
	smatch matches;
	char command;
	string text = "";
	regex reg("[A-Za-z]+");
	string new_word;
	ostringstream str_stream;
	

	if (argc == 3) {
        textfile = argv[1];  // the filename of the file containing the text to check
	    dictfile = argv[2];  // the filename of the file containing the dictionary
	}
	else if (argc == 2) {
		textfile = argv[1];  // the filename of the file containing the text to check
		dictfile = "dict.txt";
	}
	
	ifstream text_ifs(textfile);
	str_stream << text_ifs.rdbuf(); //read the file
	text = str_stream.str();
	
	text_ifs.close();
	ifstream ifs(textfile);
	pset<string> dict(dictfile); // creating pset instance
	for(;;) {
		
		ifs >> word;
		if (!ifs.good()) break;

        // this is to exclude other characters form words.
        regex_search(word, matches, reg);
        word = matches[0];
		if (dict.find(word) == dict.end()) {
			

			cout << word << endl;
			cout << "(a)dd (r)eplace (i)gnore?" << endl;
			cin >> command;
			switch (command) {
				case 'a':
					dict.insert(word);
					break;
				case 'r':
					cin >> new_word;
					
					pos = text.find(word);
		
					text.replace(pos, word.length(), new_word);
					break;
				case 'i':
					break;
			}
			
		}
	
	}
	ifs.close();
	ofstream ofs(textfile);
	ofs << text;
	ofs.close();

}
