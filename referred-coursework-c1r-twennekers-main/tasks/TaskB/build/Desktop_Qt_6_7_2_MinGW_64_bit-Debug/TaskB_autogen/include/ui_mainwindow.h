/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QPushButton *searchButton;
    QPushButton *openFileButton;
    QPushButton *saveResultsButton;
    QPushButton *pushButton_3;
    QLineEdit *searchLineEdit;
    QPushButton *runAddRecordButton;
    QPushButton *runUpdateRecordButton;
    QPushButton *runQueryDBButton;
    QPushButton *runQueryDBShowAllButton;
    QPushButton *runQueryDBSid12345Button;
    QPushButton *runQueryDBSid12346Button;
    QPushButton *runQueryDBSidAbc12Button;
    QTextEdit *outputTextEdit;
    QTextBrowser *resultsTextEdit;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout);

        openFileButton = new QPushButton(centralwidget);
        openFileButton->setObjectName("openFileButton");

        verticalLayout->addWidget(openFileButton);

        saveResultsButton = new QPushButton(centralwidget);
        saveResultsButton->setObjectName("saveResultsButton");

        verticalLayout->addWidget(saveResultsButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");

        verticalLayout->addWidget(searchLineEdit);

        runAddRecordButton = new QPushButton(centralwidget);
        runAddRecordButton->setObjectName("runAddRecordButton");

        verticalLayout->addWidget(runAddRecordButton);

        runUpdateRecordButton = new QPushButton(centralwidget);
        runUpdateRecordButton->setObjectName("runUpdateRecordButton");

        verticalLayout->addWidget(runUpdateRecordButton);

        runQueryDBButton = new QPushButton(centralwidget);
        runQueryDBButton->setObjectName("runQueryDBButton");

        verticalLayout->addWidget(runQueryDBButton);

        runQueryDBShowAllButton = new QPushButton(centralwidget);
        runQueryDBShowAllButton->setObjectName("runQueryDBShowAllButton");

        verticalLayout->addWidget(runQueryDBShowAllButton);

        runQueryDBSid12345Button = new QPushButton(centralwidget);
        runQueryDBSid12345Button->setObjectName("runQueryDBSid12345Button");

        verticalLayout->addWidget(runQueryDBSid12345Button);

        runQueryDBSid12346Button = new QPushButton(centralwidget);
        runQueryDBSid12346Button->setObjectName("runQueryDBSid12346Button");

        verticalLayout->addWidget(runQueryDBSid12346Button);

        runQueryDBSidAbc12Button = new QPushButton(centralwidget);
        runQueryDBSidAbc12Button->setObjectName("runQueryDBSidAbc12Button");

        verticalLayout->addWidget(runQueryDBSidAbc12Button);

        outputTextEdit = new QTextEdit(centralwidget);
        outputTextEdit->setObjectName("outputTextEdit");

        verticalLayout->addWidget(outputTextEdit);

        resultsTextEdit = new QTextBrowser(centralwidget);
        resultsTextEdit->setObjectName("resultsTextEdit");

        verticalLayout->addWidget(resultsTextEdit);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Search Term", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Regex", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "open file", nullptr));
        saveResultsButton->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        searchLineEdit->setText(QCoreApplication::translate("MainWindow", "searchLineEdit", nullptr));
        runAddRecordButton->setText(QCoreApplication::translate("MainWindow", "runAddRecordButton", nullptr));
        runUpdateRecordButton->setText(QCoreApplication::translate("MainWindow", "runUpdateRecord", nullptr));
        runQueryDBButton->setText(QCoreApplication::translate("MainWindow", "runQueryDB", nullptr));
        runQueryDBShowAllButton->setText(QCoreApplication::translate("MainWindow", "runQueryDBShowAll", nullptr));
        runQueryDBSid12345Button->setText(QCoreApplication::translate("MainWindow", "runQueryDBSid12345Button", nullptr));
        runQueryDBSid12346Button->setText(QCoreApplication::translate("MainWindow", "runQueryDBSid12346Button", nullptr));
        runQueryDBSidAbc12Button->setText(QCoreApplication::translate("MainWindow", "runQueryDBSidAbc12Button", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
