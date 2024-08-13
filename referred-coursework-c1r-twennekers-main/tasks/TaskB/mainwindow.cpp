//#include "mainwindow.h"
//#include "./ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent)
  //  : QMainWindow(parent)
   // , ui(new Ui::MainWindow)
//{
  //  ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
  ///  delete ui;
//}
//oopps
//************
//This section is from task a. Going to rework this code for task b!
///*********

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
using namespace std;

///****************
/// task 6 is class liberalies
/// ****************
class fileSearcher;
class CSVLogger;

//See bottom of main
int findArg(int argc, char* argv[], const string& pattern);

//FileSearcher handles file reading and searching
class FileSearcher {
public:
    FileSearcher(const QString& fileName, const QString& searchTerm) : fileName(fileName), searchTerm(searchTerm), totalWords(0), totalMatches(0){}


    bool readFile(){
        QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text )){
            qDebug() << "couldn't open file" << fileName;
        }
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        lines.append(line);
        QStringList words = line.split(QRegularExpression("\\w+"), QT::SkipEmptyParts);
        totalWords += words.size();
        for (const QString& word : words);
        if(word.contains(searchTerm, QT::CaseInsensitive)){
            totalMatches++
                matchingLines.append(line);
        }
    }
    file.close();
    return true;
}
void displayResults() const{
    qDebug()<< "Search results for term: " << searchTerm;
    for (const QString& line : matchingLines){
        qDebug()<< line;
}

  double MatchPercentage() =
        (totalWords > 0) ? (static_cast<double>(totalMatches) / totalWords) * 100 : 0;
        qDebug() << "total matches: " << totalMatches;
        qDebug()<< "total words: " << totalWords;
        qDebug() << "total percentage:  " << MatchPercentage << "%";
}

void saveResults(const QString& outputFileName) const {
    QFile outFile(outputFileName);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&outFile);
        out << "search results for: " << searchTerm <<"\n";
        for (const QString& line : matchingLines){
            out<< line<< "\n";
        }
        double matchPercentage = (totalWords > 0)? (static_cast<double>(totalMatches)/totalWords)*100:0;

        out << "Total matches: " << totalMatches << "\n";
        out << "Total words: " << totalWords << "\n";
        out << "match percentage: " << matchPercentage << "%\n";
        outFile.close();
        qDebug() << "results saved to" << outputFileName;
    }else {
        qDebug() << "file could not open" << outputFileName << "for writing";
    }
}

private:
    QString fileName;
    QString searchString;
    QStringList lines;
    QStringList matchingLines;
    int totalWords;
    int totalMatches;

    };

    int main(int argc, char *argv[]){
        QCoreApplication a(argc, argv);
    }

    vector<string> split(const string& str) {
        stringstream ss(str);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

    void searchLine(const string& line, int lineNumber) {
        vector<string> words = split(line);
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i].find(searchString)!= string::npos) {
                cout << "match found: " << words[i] << " (line: " << lineNumber << "words: " << i + 1 << ")" << endl;
                ++totalMatches;
            }
        }
    }


    void searchLineWithRegex(const string& line, int lineNumber) {
        regex searchPattern(searchString);
        smatch matches;
        string::const_iterator searchStart(line.cbegin());

        //STARTED PUTTING BELOW CODE HERE BECAUSE IT HELPS WITH MY EYES AND SEE WHAT I AM ACTUALLY DOING
        //AND MAKING SURE IT ORANGISED AND EASY TO READ

        while (regex_search(searchStart, line.cend(), matches, searchPattern)) {
            size_t wordPos = line.find(matches[0]);
            vector <string> words = split(line);
            int wordNumber = static_cast<int>(count_if(words.begin(), words.end(), [wordPos, &line](const string& word) {
                                 return line.find(word) < wordPos;
                             })) + 1;

            cout << "match found: " << matches[0]
                 << "(line: " << lineNumber << ", word: " << wordNumber << ")" << endl;
            ++totalMatches;
            searchStart = matches.suffix().first;
        }
    }
};
    ///next class for a6 is csvlogger. This was done in a5, was at the bottom of the code. but I moved it here to make it easier to read

class CSVLogger {
public:
    void appendToCSV(const string& fileName, const string& searchString, double frequency) {
        ofstream outFile("results.csv", ios::app);
        if (outFile.is_open()) {
            outFile << fileName << "," << searchString << "," << frequency << "%" << endl;
            outFile.close();
        }
        else {
            cerr << "error, unable to open for writing" << endl;
        }
    }
};


//// next we are moving to the section which will be reworked



//I rewrote the start a little
int main(int argc, char* argv[])
{
    // argv is an array of strings, where argv[0] is the path to the program, argv[1] is the first parameter, ...
    // argc is the number of strings in the array argv
    // These are passed to the application as command line arguments
    // Return value should be EXIT_FAILURE if the application exited with any form of error, or EXIT_SUCCESS otherwise

    if (argc < 3) {
        //Welcome message
        cerr << "usage: task a <filename> <search term> [-regex]" << endl;
        return EXIT_FAILURE;
    }
    //   cout << "TaskA (c)2024" << endl;

    //BASIC EXAMPLE: Get parameters for the simple case

    //my research keeps saying this part is not right. but updated
    string fileName = argv[1];
    string searchString = argv[2];
    bool useRegex = (findArg(argc, argv, "-regex")!=0);

    FileSearcher fileSearcher(fileName, searchString, useRegex);
    fileSearcher.searchFile();

    double matchPercentage = fileSearcher.getMatchPercentage();
    cout << "total matches: " << fileSearcher.getTotalMatches() << "out of" << matchPercentage << "words (" << matchPercentage << "%" << endl;

    CSVLogger logger;
    logger.appendToCSV(fileName, searchString, matchPercentage);

    return EXIT_SUCCESS;
}

// Find an argument on the command line and return the location
int findArg(int argc, char* argv[],const string& pattern)
{
    for (int n = 1; n < argc; n++) {
        string s1(argv[n]);
        if (s1 == pattern) {
            return n;
        }
    }
    return 0;
}



// FOR REGEX
//  if (findArg(argc, argv, "-regex")) {
//      useRegex = true;
//  }
//above checs

//Confirm
//     cout << "TaskA " << fileName << " " << searchString << endl;

//Done
//      return EXIT_SUCCESS;
//  }

//EXAMPLE: Scan command line for -regex switch
//  int p = findArg(argc, argv, "-regex");
//  if (p) {
//     cout << "The search term is a regular expression. See https://www.softwaretestinghelp.com/regex-in-cpp/ for examples of how to do this " << endl;
// }

//**************************************************************
//You could continue here :)








//****************

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
