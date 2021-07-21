//
// Created by Yves Boutellier on 20.11.20.
//



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
    string str;
    int pos;
    smatch matches; //match_results for string objects
    char command; // user defines it
    string text = "";
    regex r; // for words to be replaced
    regex reg("\\w+"); // for parsing in full words (omitting punctuation)
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
    text = str_stream.str(); // text as one string, words get exchanged

    text_ifs.close();
    ifstream ifs(textfile); // for reading words
    pset<string> dict(dictfile); // creating pset instance
    for(;;) {

        ifs >> word;
        cout << word << endl;
        if (!ifs.good()) break;

        // this is to exclude other characters form words.
        regex_search(word, matches, reg);
        word = matches[0];

        // we check if this word is in the dictionary
        if (dict.find(word) == dict.end()) {

            // user decides what to do with this new/misspelled word
            cout << word << endl;
            cout << "(a)dd (r)eplace (i)gnore?" << endl;
            cin >> command;
            switch (command) {
                case 'a':
                    dict.insert(word);
                    break;

                case 'r':
                    cin >> new_word;
                    //pos = text.find(word); //will fail with Kangaroo meat
                    str = word+ "([^\\w+])";
                    r.assign(str);
                    regex_search(text, matches, r); //check for the first identical occurrence
                    // replace based on position
                    pos = matches.position();
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

