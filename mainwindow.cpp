#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Aeronautical.h"
#include "Arachnid.h"
#include "Bipedal.h"
#include "Quadrupedal.h"
#include "Radial.h"
#include "Robot.h"
#include "Unipedal.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <queue>
using namespace std;
static std::map<string, string> mymap;
static std::map<string, Aeronautical> aeromap;
static std::map<string, Arachnid> arachmap;
static std::map<string, Bipedal> bipedmap;
static std::map<string, Quadrupedal> quadmap;
static std::map<string, Radial> radmap;
static std::map<string, Unipedal> unimap;
static std::vector<pair<int,string>> sortedorder; //Technically using trees or maps would be more efficent to hold the leaderboard, but with small amounts of robots in this game this works fine


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox msgBox;
    msgBox.setText("Welcome to Bot-O-Mat, an application that helps you purchase robots and complete tasks with them");
    msgBox.exec();
    msgBox.setText("We have many different types of robots that complete different tasks");
    msgBox.exec();
    msgBox.setText("Robots can be upgraded to complete tasks faster");
    msgBox.exec();
    msgBox.setText("The harder the tasks a robot has the greater its upgrade factor, upgrades can be done every factor of 2 tasks");
    msgBox.exec();
    msgBox.setText("Enjoy!");
    msgBox.exec();

}

MainWindow::~MainWindow()
{
    delete ui;
}
int indexofval(vector<pair<int,string>> findval, string findstring, int intval) { // a linear search function used to make the leaderboard
    for (int i = 0; i < findval.size(); ++i) {
        if (findval[i].first == intval && findval[i].second == findstring) {
            return i;
        }

    }
    return -1; // returning negative 1 means a certain robot is not in the vector yet, it need sto be inserted
}
bool cmpsort(const pair<int, string> &p1, const pair<int, string> v) //comparator to sort vector of pairs, basically sorts by ints then by strings
    {
        if (p1.first < v.first)
            return true;
        else if (p1.first > v.first)
            return false;
        else if (p1.second < v.second)
            return true;
        else if (p1.second > v.second)
            return false;
        return false;

    }


void MainWindow::setactivities(string firststring, string secondstring){ // called to create qstrings and update the activities robots can do
     QString myfirststring = QString::fromStdString(firststring); // this is what helps with updating the robots tasks everytime a user switches robots
      ui->Myrobotsactions->addItem(myfirststring);
      if(secondstring != ""){
          QString mysecondstring = QString::fromStdString(secondstring);
          ui->Myrobotsactions->addItem(mysecondstring);
      }
}


void MainWindow::on_Createrobot_clicked() // when the create robot button is pressed, basically create robot object and put it in the correct map,
//set the name
{
    QString robotname = ui->lineEdit->text(); //get the inserted text
    QString robottype = ui->Picktypeofrobot->currentText(); // get the type of robot selected

    string typeofrobotstd = robottype.toStdString(); // convert both to std string
    string nameofrobotstd = robotname.toStdString();
    if(mymap.find(nameofrobotstd) != mymap.end()){ // make sure robot of the same name doesnt already exist
        QMessageBox msgBox;
        msgBox.setText("Sorry two robots can not have the same name");
        msgBox.exec();
        return;
    }
    mymap[nameofrobotstd] = typeofrobotstd; // create a map just to keep robot names and type connected
            if(typeofrobotstd == "Unipedal"){ //create a unipedal robot and set name
            Unipedal U1;
            U1.setname(nameofrobotstd);
            unimap[nameofrobotstd] = U1;

}
            else if(typeofrobotstd == "Bipedal"){ //create bipedal robot and set name
                Bipedal B1;
                B1.setname(nameofrobotstd);
                bipedmap[nameofrobotstd] = B1;


            }
            else if(typeofrobotstd == "Aeronautical"){ // create an aeornautical robot and set name
                 Aeronautical A1;
                 A1.setname(nameofrobotstd);
                 aeromap[nameofrobotstd] = A1;

            }
            else if(typeofrobotstd == "Arachnid"){ // create an arachnid robot and set name
                Arachnid A1;
                A1.setname(nameofrobotstd);
                arachmap[nameofrobotstd] = A1;

            }
            else if(typeofrobotstd == "Radial"){ //create radial robot and set name
                Radial R1;
                R1.setname((nameofrobotstd));
                radmap[nameofrobotstd] = R1;

            }
            else if(typeofrobotstd == "Quadrupedal"){ // create quad robot and set name
                Quadrupedal Q1;
                Q1.setname(nameofrobotstd);
                quadmap[nameofrobotstd] = Q1;

            }


    //QMessageBox::information(this,"title",robottype);
    ui->Myrobots->addItem(robotname); // add robots name to the robot list
}

void MainWindow::on_Myrobots_currentIndexChanged(int index)//when selected robot changes we need to update the tasks the bot can do
{
    ui->Myrobotsactions->clear(); //clear the currently listed tasks
   string name = ui->Myrobots->currentText().toStdString(); //get the name that was selected
   string typeofrobot = mymap[name]; //find the type of robot
   if(typeofrobot == "Unipedal"){ //if unipedal get description and put them into the activities field
      Unipedal U1 = unimap[name];
        string firststring = U1.getdishdescription() + " eta: " + to_string(U1.getdishtime());
         string secondstring = U1.getsweepdescription() + " eta: " + to_string(U1.getsweeptime());
          setactivities(firststring,secondstring); //helper function to set field, since this is called so much
}
   else if(typeofrobot == "Bipedal"){ //if bipedal get description and put them into the activities field
         Bipedal B1 = bipedmap[name];
          string firststring = B1.getlaundrydescription() + " eta: " + to_string(B1.getlaundrytime());
           string secondstring = B1.getrecyclingdescription() + " eta: " + to_string(B1.getrecyclingtime());
            setactivities(firststring,secondstring);



   }
   else if(typeofrobot == "Aeronautical"){ //if aeronautical get description and put them into the activities field

            Aeronautical A1 = aeromap[name];
            string firststring = A1.getcardescription() + " eta: " + to_string(A1.getcartime());
            string secondstring = "";
            setactivities(firststring,secondstring);


   }
   else if(typeofrobot == "Arachnid"){ //if arachnid get description and put them into the activities field
       Arachnid A1 = arachmap[name];
           string firststring = A1.getbakedescription() + " eta: " + to_string(A1.getbaketime());
           string secondstring = "";
            setactivities(firststring,secondstring);


   }
   else if(typeofrobot == "Radial"){ //if radial get description and put them into the activities field
       Radial R1 = radmap[name];
           string firststring = R1.getbathdescription() + " eta: " + to_string(R1.getbathtime());
           string secondstring = R1.getrakedescription() + " eta: " + to_string(R1.getraketime());
            setactivities(firststring,secondstring);


   }
   else if(typeofrobot == "Quadrupedal"){ //if quadrupedal get description and put them into the activities field
       Quadrupedal Q1 = quadmap[name];
           string firststring = Q1.getsandwichdescription() + " eta: " + to_string(Q1.getsandwichtime());
           string secondstring = Q1.getmowlawndescription() + " eta: " + to_string(Q1.getlawntime());
            setactivities(firststring,secondstring);


}
}

void MainWindow::on_UpgradeRobot_clicked() // when upgrade robot is clicked we need to see if the robot has enough tasks to be upgraded, if it does
//we can upgrade
{
    string name = ui->Myrobots->currentText().toStdString(); //get name
    string typeofrobot = mymap[name]; //find robot type
    if(typeofrobot == ""){
    QMessageBox mybox; //make sure a robot has been created when this button is presed
    mybox.setText("Please create a robot");
    mybox.exec();
    return;
    }
    //the function to level up a robot is quadratic
   bool hit = false;
    if(typeofrobot == "Unipedal"){ //if unipedal see if robot has completed tasks in relation to its level squared + 1
       Unipedal *U1 = &unimap[name];
       if(U1->gettaskcompleted() > pow(U1->getrobotlevel(),2) + 1){
           U1->increaselevel();
           hit = true;
       }
 }
    else if(typeofrobot == "Bipedal"){
     Bipedal *B1 = &bipedmap[name]; //if unipedal see if robot has completed tasks in relation to its level squared + 1
     if(B1->gettaskcompleted() > pow(B1->getrobotlevel(),2) + 1){
         B1->increaselevel();
         hit = true;
     }
    }
    else if(typeofrobot == "Aeronautical"){
      Aeronautical *A1 = &aeromap[name]; //if unipedal see if robot has completed tasks in relation to its level squared + 1
      if(A1->gettaskcompleted() > pow(A1->getrobotlevel(),2) + 1){
          A1->increaselevel();
          hit = true;
      }

    }
    else if(typeofrobot == "Arachnid"){
     Arachnid *A1 = &arachmap[name]; //if unipedal see if robot has completed tasks in relation to its level squared + 1
     if(A1->gettaskcompleted() > pow(A1->getrobotlevel(),2) + 1){
         A1->increaselevel();
         hit = true;
     }
    }
    else if(typeofrobot == "Radial"){
        Radial *R1 = &radmap[name]; //if unipedal see if robot has completed tasks in relation to its level squared + 1
        if(R1->gettaskcompleted() > pow(R1->getrobotlevel(),2) + 1){
            R1->increaselevel();
            hit = true;
        }
    }
    else if(typeofrobot == "Quadrupedal"){
      Quadrupedal *Q1 = &quadmap[name]; //if unipedal see if robot has completed tasks in relation to its level squared + 1
      if(Q1->gettaskcompleted() > pow(Q1->getrobotlevel(),2) + 1){
          Q1->increaselevel();
          hit = true;
      }
 }
    if(hit == false) {
        QMessageBox msgBox; // robot needs more tasks to get upgraded
        msgBox.setText("Sorry you have not completed enough tasks to upgrade this robot");
        msgBox.exec();
        return;
    }
    else {
    QMessageBox msgBox; // the robot was sucesfully upgraded
    msgBox.setText("Robot upgraded");
    msgBox.exec();
    }
    on_Myrobots_currentIndexChanged(0); // call to update display based on decreasing time
}
void MainWindow::on_ExecuteTask_clicked() // the execute task function that sees if enough time has passed to execute a task, uses class function
// and sees if they return true or false
{

    string name = ui->Myrobots->currentText().toStdString(); //gets robot name
    string typeofrobot = mymap[name]; //gets robot types
    string str; //used for printing and testing
   QString qstr;
    int index = ui->Myrobotsactions->currentIndex(); // The index allows you to see what task a robot is on, since we know what task is at what index
    QMessageBox mybox;

    if(typeofrobot == ""){
    mybox.setText("Please create a robot"); // need a robot to execute tasks with
    mybox.exec();
    return;
    }

   bool hit = false; // see if a task was run at all
    if(typeofrobot == "Unipedal"){ // tasks unipedal does
       Unipedal *U1 = &unimap[name];
       if(index == 0){
           if(U1->dishes()){  //if this returns true the robot is running the task
               str = "Robot " + name + " is doing the dishes "; // we say the robot is doing the task
              qstr = QString::fromStdString(str);
               mybox.setText(qstr);
               mybox.exec();
               hit = true; // hit becomes true


               int indexval = indexofval(sortedorder,name,U1->gettaskcompleted()); //find where robot is in the array
              // auto it = std::lower_bound(sortedorder.begin(),sortedorder.end(),make_pair(U1->gettaskcompleted(),name),cmp); // binary search sorted array, would have been a bit faster
               //but unfortunitely this part above was hard to get functioning properly on pairs, even with my own comparators, will have to look into it more
               // luckily there would normally be only a few robots so this will not be terrible in runtime
               if(indexval != -1){ // this robot exists on the leaderboard
                sortedorder[indexval].first++; // increase tasks completed

               }
               else {
                   sortedorder.push_back(make_pair(U1->gettaskcompleted() + 1,name)); // add robot with its proper task count to the vector

               }
               U1->increasetask(); // increase the tasks in the class
           }

       }

       else if(U1->sweep()){ // same thing we did above but for sweep
           str = "Robot " + name + " is sweeping ";
          qstr = QString::fromStdString(str);
           mybox.setText(qstr);
           mybox.exec();
           hit = true;
         int indexval = indexofval(sortedorder,name,U1->gettaskcompleted()); // linear search since this is small
           if(indexval != -1){
             sortedorder[indexval].first++;
           }
           else {
               sortedorder.push_back(make_pair(U1->gettaskcompleted() + 1,name));
           }
           U1->increasetask();
       }
 }
    else if(typeofrobot == "Bipedal"){ // for bipedal, see if task can run then either add or update on leaderboard
     Bipedal *B1 = &bipedmap[name];
     if(index == 0){
     if(B1->laundry()){
         str = "Robot " + name + " is doing the laundry ";
        qstr = QString::fromStdString(str);
         mybox.setText(qstr);
         mybox.exec();
         hit = true;
        int indexval = indexofval(sortedorder,name,B1->gettaskcompleted()); // binary search sorted array
         if(indexval != -1){
          sortedorder[indexval].first++;
         }
         else {
             sortedorder.push_back(make_pair(B1->gettaskcompleted() + 1,name));
         }
         B1->increasetask();
     }


}
 else if(B1->recycling()){
     str = "Robot " + name + " is recycling ";
    qstr = QString::fromStdString(str);
     mybox.setText(qstr);
     mybox.exec();
     hit = true;
     int indexval = indexofval(sortedorder,name,B1->gettaskcompleted());  // binary search sorted array
     if(indexval != -1){
      sortedorder[indexval].first++;
     }
     else {
         sortedorder.push_back(make_pair(B1->gettaskcompleted() + 1,name));
     }
     B1->increasetask();
 }
    }
    else if(typeofrobot == "Aeronautical"){ // for aeronautical, see if task can run then either add or update on leaderboard
      Aeronautical *A1 = &aeromap[name];
      if(A1->washcar()){
          str = "Robot " + name + " is washing the car ";
         qstr = QString::fromStdString(str);
          mybox.setText(qstr);
          mybox.exec();
          hit = true;
          int indexval = indexofval(sortedorder,name,A1->gettaskcompleted());  // binary search sorted array
          if(indexval != -1){
           sortedorder[indexval].first++;
          }
          else {
              sortedorder.push_back(make_pair(A1->gettaskcompleted() + 1,name));
          }
          A1->increasetask();
      }




    }
    else if(typeofrobot == "Arachnid"){ // for arachnid, see if task can run then either add or update on leaderboard
     Arachnid *A1 = &arachmap[name];
     if(A1->bake()){
         str = "Robot " + name + " is baking ";
        qstr = QString::fromStdString(str);
         mybox.setText(qstr);
         mybox.exec();
         hit = true;
         int indexval = indexofval(sortedorder,name,A1->gettaskcompleted());  // binary search sorted array
         if(indexval != -1){
          sortedorder[indexval].first++;
         }
         else {
             sortedorder.push_back(make_pair(A1->gettaskcompleted() + 1,name));
         }
         A1->increasetask();
     }
    }
    else if(typeofrobot == "Radial"){ // for radial, see if task can run then either add or update on leaderboard
        Radial *R1 = &radmap[name];
        if(index == 0){
            if(R1->bath()){
                str = "Robot " + name + " is giving the dog a bath ";
               qstr = QString::fromStdString(str);
                mybox.setText(qstr);
                mybox.exec();
                hit = true;
               int indexval = indexofval(sortedorder,name,R1->gettaskcompleted());
                if(indexval != -1){
                 sortedorder[indexval].first++;
                }
                else {
                    sortedorder.push_back(make_pair(R1->gettaskcompleted() + 1,name));
                }
                R1->increasetask();
            }
        }
        else if(R1->rake()) {
            str = "Robot " + name + " is raking the leaves";
           qstr = QString::fromStdString(str);
            mybox.setText(qstr);
            mybox.exec();
            hit = true;
            int indexval = indexofval(sortedorder,name,R1->gettaskcompleted()); // binary search sorted array
            if(indexval != -1){
             sortedorder[indexval].first++;
            }
            else {
                sortedorder.push_back(make_pair(R1->gettaskcompleted() + 1,name));
            }
            R1->increasetask();
        }
    }
    else if(typeofrobot == "Quadrupedal"){ // for quadrupedal, see if task can run then either add or update on leaderboard
      Quadrupedal *Q1 = &quadmap[name];
      if(index == 0){
          if(Q1->sandwich()){
              str = "Robot " + name + " is making a samich ";
             qstr = QString::fromStdString(str);
              mybox.setText(qstr);
              mybox.exec();
              hit = true;
              int indexval = indexofval(sortedorder,name,Q1->gettaskcompleted());
              if(indexval != -1){
               sortedorder[indexval].first++;
              }
              else {
                  sortedorder.push_back(make_pair(Q1->gettaskcompleted() + 1,name));
              }
              Q1->increasetask();
          }
      }
      else if(Q1->mowlawn()) {
          str = "Robot " + name + " is mowing the lawn";
         qstr = QString::fromStdString(str);
          mybox.setText(qstr);
          mybox.exec();
          hit = true;
          int indexval = indexofval(sortedorder,name,Q1->gettaskcompleted()); // binary search sorted array
          if(indexval != -1){
           sortedorder[indexval].first++;
          }
          else {
              sortedorder.push_back(make_pair(Q1->gettaskcompleted() + 1,name));
          }
          Q1->increasetask();
      }
 }
    if(hit == false) {
        QMessageBox msgBox;
        msgBox.setText("Sorry a task is still in progress");
        msgBox.exec();
        return;
    }
    sort(sortedorder.begin(),sortedorder.end(),cmpsort); //sort n log n // sort array each time for leaderboard
    ui->Leaderboard->clear(); // clear the leaderboard from before
    for(int i = sortedorder.size() - 1; i >=0; --i){
        string str = "Name: " +sortedorder[i].second + " Score: " + to_string(sortedorder[i].first);
        QString qstr = QString::fromStdString(str);
        ui->Leaderboard->addItem(qstr);
    }

}

