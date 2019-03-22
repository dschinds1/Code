#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<string>
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 void setactivities(std::string firststring, std::string secondstring);

private slots:


    void on_ExecuteTask_clicked();

    void on_Createrobot_clicked();

    void on_Myrobots_currentIndexChanged(int index);

    void on_UpgradeRobot_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
