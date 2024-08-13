#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <qforeach.h>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    QString searchTerm = ui->searchLineEdit->text();
    performSearch(searchTerm);
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
    QFile file(FileName);
    if(!file.exists()){
        ui->resultsTextEdit->append(FileName + "not exist");
        return false;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        ui->resultsTextEdit->append("could not open" + FileName);
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

    QRegularExpression regex("\\s+");

    foreach (const QString &line, lines){
        QStringList words = line.split(regex, Qt::SkipEmptyParts);
        totalWords += words.size();

        foreach (const QString &word, words) {
            if(word.contains(searchTerm,Qt::CaseInsensitive)){
                totalMatches++;
                ui->resultsTextEdit->append("match found: " + word + " in line: " + line);
            }

        }
    }

if (totalWords > 0){
    double matchPercentage = (static_cast<double>(totalMatches)/totalWords) * 100;
    ui->resultsTextEdit->append(QString("total matches %1 out of of %2 words (%3%)")
                                .arg(totalMatches)
                                .arg(totalWords)
                                .arg(matchPercentage,0,'f',2));
} else
{
    ui->resultsTextEdit->append("no match");
}
}

///Section below allows to save
///
///********

void MainWindow:: saveResultsToFile(const QString &fileName)
{
    QFile outFile(fileName);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        ui->resultsTextEdit->append("error to open file");
        return;
}
    QTextStream out(&outFile);
out << ui->resultsTextEdit->toPlainText();
    outFile.close();

ui->resultsTextEdit->append("results save to " + fileName);
}
