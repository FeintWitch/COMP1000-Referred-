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

    //the buttons
    connect(ui->openFileButton, &QPushButton::clicked, this, &MainWindow::on_openFileButton_clicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
    connect(ui->saveResultsButton, &QPushButton::clicked, this, &MainWindow::on_saveResultsButton_clicked);
    //the buttons for task a
    connect(ui->runAddRecordButton, &QPushButton::clicked, this, &MainWindow::on_runAddRecordButton_clicked);
    connect(ui->runUpdateRecordButton, &QPushButton::clicked, this, &MainWindow::on_runUpdateRecordButton_clicked);
    connect(ui->runQueryDBButton, &QPushButton::clicked, this, &MainWindow::on_runQueryDBButton_clicked);
    connect(ui->runQueryDBShowAllButton,& QPushButton::clicked, this, &MainWindow::on_runQueryDBShowAllButton_clicked);
    connect(ui->runQueryDBSid12345Button, &QPushButton::clicked, this, &MainWindow::on_runQueryDBSid12345Button_clicked);
    connect(ui->runQueryDBSid12346Button, &QPushButton::clicked, this, &MainWindow::on_runQueryDBSid12346Button_clicked);
    connect(ui->runQueryDBSidAbc12Button, &QPushButton::clicked, this, &MainWindow::on_runQueryDBSidAbc12Button_clicked);

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

//This section Below is make a database for computing.txt
//*************
void MainWindow::generateDatabase(const QString &filename){
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << "SID, name, enrollments, phone, grade\n";
        out << "12345, Jo Kingly Blunt, COMP101 COMP102 COMP105 COMP110 COMP150, 44-1243-567890, 54 67.5 33.1 78.3 47.1\n";
        out << "14351, Bee Hyve, COMP101 COMP102 COMP105 COMP110 COMP155 COMP165, NUL, 84.3 54.7 91.4 80.4 40.5 67.5\n";
        out << "15309, Gee Rafferty, ELEC101 ELEC133 COMP101 PROJ101 GIT101, NUL, 95 37.5 55 65.5 0\n";
        file.close();
    }else {
        qDebug() << "unable to create a database.";
    }
}
void MainWindow::showAllRecord(const QString &filename){
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while (!in.atEnd()){
            QString line = in.readLine();
            qDebug() << line;
        }
        file.close();
    }else {
        qDebug() << "unable to open database";
    }
}


//*************

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
/////***************************************************
////This section now is for the tasks for report

void MainWindow::on_runAddRecordButton_clicked(){
    runExecutable("addrecord.exe",{});
}
void MainWindow::on_runUpdateRecordButton_clicked(){
    runExecutable("updaterecord.exe",{});
}
void MainWindow::on_runQueryDBButton_clicked(){
    generateDatabase("computing.txt");
    //above generates the database and below shows all
    showAllRecord("computing.txt");

    //the next part checks
    if(QFile::exists("computing.txt")){
        QMessageBox::information(this, "Computing.txt database has been generated");
    }else {
        QMessageBox::warning(this, "failure");
    }
}
void MainWindow::on_runQueryDBShowAllButton_clicked(){
    runExecutable("Querydb.exe",{"-db", "computing.txt", "-showAll"});
}
///
void MainWindow::on_runQueryDBSid12345Button_clicked(){
    runExecutable("querydb.exe",{"-db", "computing,txt", "-sid", "12345"});
}
void MainWindow::on_runQueryDBSid12346Button_clicked(){
    runExecutable("querydb.exe",{"-db", "computing.txt","-sid", "12346"});
    runExecutable("querydb.exe",{"-db", "computing.txt","-sid", "12346", "-n"});
    runExecutable("querydb.exe",{"-db", "computing.txt","-sid", "12346", "-g"});
    runExecutable("querydb.exe",{"-db", "computing.txt","-sid", "12346", "-p"});
}

void MainWindow::on_runQueryDBSidAbc12Button_clicked(){
    runExecutable("querydb.exe",{"-db", "computing.txt", "-sid", "abc12"});
}
void MainWindow::runExecutable(const QString &program, const QStringList &arguments)
{
    QProcess *process = new QProcess(this);
    process->start(program, arguments);

    if (process->waitForFinished()){
        QString output = process->readAllStandardOutput();
        ui->resultsTextEdit->append("comand output: " + output);
    }else {
        ui->resultsTextEdit->append("command failed to process");
    }
}
