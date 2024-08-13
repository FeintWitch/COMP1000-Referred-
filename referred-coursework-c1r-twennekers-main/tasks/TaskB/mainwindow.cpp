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

}

