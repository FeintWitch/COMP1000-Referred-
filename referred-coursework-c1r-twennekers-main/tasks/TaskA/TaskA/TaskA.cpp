#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <map>
#include <string>
using namespace std;

//See bottom of main
int findArg(int argc, char* argv[], string pattern);

///new comment now checking
/*
 *
 * The user can launch application as follows:
 *
 * TaskA <filename> <search term> [-regex]
 * 
 * <database file>              REQUIRED. Specifies the file to search (required). This is ALWAYS the first parameter. The file must exist in order to be searched
 * <search term>                REQUIRED. The search term as either a single word or a regular expression. 
                                This is a single word, made up of alpha-numeric characters only.
 * -regex                       OPTIONAL. If this flag is present, then the search term is a regular expression (as opposed to a single word). 
                                It must be a valid regex expression.
 *
 * ****************
 * *** EXAMPLES ***
 * ****************
 *
 * TaskA lorum.txt comp1000             Searches for the string comp1000 in the file lorum.txt
 * TaskA lorum.txt "^(\\d)\\d" -regex   Searches the file lorum.txt for all patterns that match the regular expression "^(\\d)\\d" 
 * TaskA lorum.txt -regex "^(\\d)\\d"   Searches the file lorum.txt for all patterns that match the regular expression "^(\\d)\\d" 
 * TaskA lorum.txt                      Error - search expression provided
 * 
 * *************
 * *** NOTES ***
 * *************
 *
 * o Try to write your code such that is can be reused in other tasks.
 * o Code should be consistently indented and commented
 * o Consider error conditions, such as missing parameters or non-existent files
*/

// I kept getting erros for fileName, searchString and useRegex. I think I am not doing it right. After looking online it's because it's in the if statement
//I rewrote the start a little 
int main(int argc, char* argv[])
{
    // argv is an array of strings, where argv[0] is the path to the program, argv[1] is the first parameter, ...
    // argc is the number of strings in the array argv
    // These are passed to the application as command line arguments
    // Return value should be EXIT_FAILURE if the application exited with any form of error, or EXIT_SUCCESS otherwise

    if (argc == 3) {
        //Welcome message
        cout << "TaskA (c)2024" << endl;

        //BASIC EXAMPLE: Get parameters for the simple case

        //my research keeps saying this part is not right. 
        string fileName = argv[1];
        string searchString = argv[2];
        bool useRegex = false;

        //Confirm
        cout << "TaskA " << fileName << " " << searchString << endl;

        //Done
        return EXIT_SUCCESS;
    }

    //EXAMPLE: Scan command line for -regex switch
    int p = findArg(argc, argv, "-regex");
    if (p) {
        cout << "The search term is a regular expression. See https://www.softwaretestinghelp.com/regex-in-cpp/ for examples of how to do this " << endl;
    }

    //**************************************************************
    //You could continue here :)
    // I think I am making progress little by little
    string fileName = argv[1];
    string searchString = argv[2];
    bool useRegex = false;

    if (findArg(argc, argv, "-regex")) {
        useRegex = true;
    }
    // Let's start! first is the opening of the file. Task 1. 
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error: File not found" << fileName << endl;
        return EXIT_FAILURE;
    }
    //reads file cotents into a string
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string fileContent = buffer.str();
    //displaying part 
    cout << "content of " << fileName << "is:" << endl << fileContent << endl;
    //searching 
    if (useRegex) {
        try {
            regex searchPattern(searchString);
            smatch matches;
            string::const_iterator searchStart(fileContent.cbegin());
            while (regex_search(searchStart, fileContent.cend(), matches, searchPattern)) {
                cout << "match found: " << matches[0] << endl;
                searchStart = matches.suffix().first;
            }
        }
        catch (regex_error& e) {
            cerr << "error: Invaid expression: " << searchString << endl;
            return EXIT_FAILURE;
        }
    }
    else {
        size_t pos = 0;
        while ((pos = fileContent.find(searchString, pos)) != string::npos) {
            cout << "match found at position: " << pos << endl;
            pos += searchString.length();
        }

    }

    // 
    //**************************************************************

    return EXIT_SUCCESS;
}

// Find an argument on the command line and return the location
int findArg(int argc, char* argv[], string pattern)
{
    for (int n = 1; n < argc; n++) {
        string s1(argv[n]);
        if (s1 == pattern) {
            return n;
        }
    }
    return 0;
}
