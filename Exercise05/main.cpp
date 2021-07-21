#include <iostream>

#include <regex>
#include <string>

void PrintMatches(std::string str, std::regex reg){
    std::smatch matches;
    std::cout << std::boolalpha;
    // regex_search: first: string we are looking at, second: where the matches go, third: the regex we use for searching
    while(std::regex_search(str, matches, reg)){
        std::cout << matches.str(1) << std::endl;
        str = matches.suffix().str(); // we make the matches to a string
        std::cout << matches.position() << std::endl;
    }
}

void PrintMatches2(std::string str, std::regex reg){
    std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
    std::sregex_iterator lastMatch;
    while(currentMatch != lastMatch){
        std::smatch match = *currentMatch;
        std::cout << match.str() << std::endl;
        currentMatch++;
        //std::cout << std::endl;
    }
}


int main(int argc, char *argv[]) {

    std::string str = "The ape was at the apex";

    std::regex reg ("(ape[^ ]?)"); // we search for the word ape, and for words that start with ape and are followed by not a whitespace
    // but that is not required for a match, therefore a question mark (?)

    PrintMatches(str, reg);

    std::string str2 = "I picked. the pickle";
    std::regex reg2 ("\\w+"); // get all words without special characters (truncated)
    std::regex reg4 ("pick([^ ^.]+)?");
    //PrintMatches2(str2, reg2);
    PrintMatches2(str2, reg4);

    std::string str3 = "Cat rat fat pat";
    std::regex reg5 ("[Crfp]");


}