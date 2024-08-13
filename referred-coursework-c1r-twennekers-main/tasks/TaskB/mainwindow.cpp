#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileButton_clicked()
{
    QString fileName = "computing.txt";
    if (openAndReadFile(fileName)){
        ui->resultsTextEdit->append("file loaded successfully");
    } else {
        ui->resultsTextEdit->append("error");
    }
}

void MainWindow::on_saveResultsButton_clicked()
{
    saveResultsToFile("results.csv");
}

///This will allow to open, read and store text
///
///********
bool MainWindow::openAndReadFile(const QString &FileName)
{
    QFile file(fileName);
    if(!file.exists()){
        ui->resultsTextEdit->append(fileName + "not exist");
        return false;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        ui->resultsTextEdit->append("could not open" + fileName);
        return false;
    }

    QTextStream in(&file);
    fileContent = in.readAll();
    file.close();
    return true;
}

///Section below allows to perform a search in the stored file content
///
///********
void MainWindow::performSearch(const QString &searchTerm)
{
    if (fileContent.isEmpty()){
        ui->resultsTextEdit->append("no file to search");
            return;
    }
    QStringList lines = fileContent.split('\n');
    int totalMatches= 0 ;
    int totalWords= 0;

    foreach (const QString &line, lines){
        QStringList words = line.split(QRegExp("\s+"), Qt::SkipEmptyParts);
        totalWords += words.size();

        foreach (const, QString &words, words) {
            if(word.contains(searchTerm,Qt::CaseInsensitive)){
                totalMatches++;
                ui->resultsTextEdit->append("match found: " + word + " in line: " + line);
            }


        }
    }
}
