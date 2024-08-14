#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ///**********
    ///For mainwindow.CPP
private slots:
    void on_openFileButton_clicked();
    void on_searchButton_clicked();
    void on_saveResultsButton_clicked();
    /// **********
    /// Below is for additonal buttons
    ///
    void on_runAddRecordButton_clicked();
    void on_runUpdateRecordButton_clicked();
    void on_runQueryDBShowAllButton_clicked();
    void on_runQueryDBButton_clicked();
    void on_runQueryDBSid12345Button_clicked();
    void on_runQueryDBSid12346Button_clicked();
    void on_runQueryDBSidAbc12Button_clicked();

private:
    Ui::MainWindow *ui;
    QString fileContent;

    void runExecutable(const QString &program, const QStringList &arguments);
    bool openAndReadFile(const QString &fileName);
    void performSearch(const QString &searchTerm);
    void saveResultsToFile(const QString &fileName);
    void generateDatabase(const QString &fileName);
    void showAllRecord(const QString &fileName);
};
#endif // MAINWINDOW_H
