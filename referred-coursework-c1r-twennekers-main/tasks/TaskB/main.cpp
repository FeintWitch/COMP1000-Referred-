////// although the main code for gui and additonal stuff is in mainwindow
///// the plan is to use this call mainwindow code for command line just in case
///// I am wrong

#include <QApplication>
#include <QCommandLineParser>
#include "mainwindow.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
        MainWindow w;
        w.show();

        QCommandLineParser parser;
        parser.setApplicationDescription("qt app with CLI commands");
        parser.addHelpOption();

        //comand line

        QCommandLineOption runAddRecordOption("runAddRecord");
        QCommandLineOption runUpdateRecordOption("runUpdateRecord");
        QCommandLineOption runQueryDBOption("runQueryDB");
        QCommandLineOption showAllOption("showAll");

        // options
        parser

}
