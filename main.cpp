//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Input_Validation_Extended.h"
using namespace std; 

class MenuItem
{
  private:
    string name;
    double itemCost; 
    string desc; 
    char addLetter; 
    char removeLetter;
    int count; 
    int defaultIndex;
  public:
    MenuItem() {}
    MenuItem(int defInd)
    {
      vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7"}; 
      vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
      vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

      name = defaultMenuNames[defInd];
      addLetter = defaultAddLetters[defInd];
      removeLetter = defaultRemoveLetters[defInd];

      itemCost = (3.00 + defInd);
      count = 0;
      desc = "delicious";
    }
    void setName(string nm) {name = nm;}
    void setItemCost(double cost) {itemCost = cost;}
    void setDesc(string dsc) {desc = dsc;}
    void setAddLetter(char letter) {addLetter = letter;}
    void setRemoveLetter(char letter) {removeLetter = letter;}
    void setCount(int c) {count = c;}

    string getName() const {return name;}
    double getItemCost() const {return itemCost;}
    string getDesc() const {return desc;}
    char getAddLetter() const {return addLetter;}
    char getRemoveLetter() const {return removeLetter;}
    int getCount() const {return count;}
};

//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1(0); 
  MenuItem Item2(1);
  MenuItem Item3(2); 
  MenuItem Item4(3);
  MenuItem Item5(4);
  MenuItem Item6(5);
  MenuItem Item7(6);    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7
}

void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].getAddLetter() << ")" << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getItemCost() << setw(5) << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() 
    <<endl; 
  }

}

void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 
  int tempCount = 0;
  double tip = 0.0;

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      tempCount = m[i].getCount();

      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 

        m[i].setCount(tempCount + 1); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].setCount(tempCount - 1); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
  cout << "\nPlease enter tip (20% or more is recommended): ";
  tip = validateDouble(tip);
  while(tip < 0.0)
  {
    tip = validateDouble(tip);
  } 
  subtotal += tip;
  //handle reciept generation here
}

int main() 
{
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 
  
  return 0; 
}