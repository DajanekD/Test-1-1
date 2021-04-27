//Dajanek Davis: Football Scoreboard
//Object Oriented Programming in C++
//Updates 4-23-2021 
 

#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    int shotsOnGoal; 
    string coachName; 
    string city;
    

  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "DefaultTeamName"; 
        shotsOnGoal = 0; 
        coachName = "DefaultCoachName"; 
        city = "DefaultCityName";
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setShotsOnGoal(int sog) { shotsOnGoal = sog; }
      void setCoachName(string sCN) { coachName = sCN; }
      void set_homeCity(string c){ city = c; }
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      int getShotsOnGoal() const { return shotsOnGoal; }
      string getCoachName() const { return coachName; }
      string getCity() const { return city; }

};

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color 
      cout << color << "Football Scoreboard" << reset;
      cout << "       10:37" << endl;
      cout << home.getCity() << "\t\t" << visitor.getCity() << endl; 
      cout << home.getName() << "\t\t" << visitor.getName() << endl; 
      cout << "\t" << score << home.getScore() << reset << "\t\t\t\t\t\t" << visitor.getScore() << endl; 
      cout << score << home.getCoachName() << reset << "\t\t" << visitor.getCoachName() << endl; 
      cout << "                 QTR: 4 " << endl;
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  string newCityName = "";
  int homeTeamQuestion = 0; 
  int newScore = 0; 
  

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home Status" << endl; 
      cout << "D = Update Home Coach Name" << endl;
      cout << "E = Update Visting Team Coach Name" << endl; 
      cout << "F = Update Visting Team Name" << endl;
      cout << "G = Update Visitor Team Score" << endl;
      cout << "H = Update Home Team City" << endl;
      cout << "I = Update Vistor Team City" << endl;
      cout << "J = Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
       else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Home Coach Module****" << endl; 
          cout << "\nPlease enter the home coach Name: "; 
          cin >> newCoachName; 
          tOne.setCoachName(newCoachName); 
      }
      else if(userChoice == "E" || userChoice == "e")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor coach Name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
      else if(userChoice == "F" || userChoice == "f")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor team Name: "; 
          cin >> newName; 
          tTwo.setName(newName); 
      }
      else if(userChoice == "G" || userChoice == "g")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the new score for visitor team: "; 
          cin >> newScore; 
          tTwo.setScore(newScore);  
      }
      else if(userChoice == "H" || userChoice == "h")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the city for the home team: "; 
          cin >> newCityName; 
          tOne.set_homeCity(newCityName);  
      }
      else if(userChoice == "I" || userChoice == "i")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the city for the visitor team: "; 
          cin >> newCityName; 
          tTwo.set_homeCity(newCityName);  
      }
      else if(userChoice == "J" || userChoice == "j")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
  
  }while(userChoice != "J" && userChoice != "j");


  return 0; 
}