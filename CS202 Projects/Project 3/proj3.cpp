//This program takes car rental data from an external file, and manipulates the data from it based on user input. This time, the class function is being implemented
#include<iostream>
#include<fstream>
using namespace std;

  class RentalCar {
    public:
    //RentalCar();
    //RentalCar(char const* make = "Make", char const *model = "Model", int year = 0, float price = 0.0f, bool printFlg = 0);
    char * GetMake();
    char * GetModel();
    int GetYear();
    float GetPrice();
    bool GetAvailability();
    void SetMake(char * make);
    void SetModel(char * model);
    void SetYear(int year);
    void SetPrice(float price);
    void SetAvailability(bool avail);
    void PrintCars();
    float EstimateCost(int days, float price);
    private:
    char * m_make;
    char * m_model;
    int m_year;
    float m_price;
    bool m_available;
  };

  struct RentalAgency{
    char name[15];
    int zipcode;
    RentalCar inventory[5];
 
  };
void readData(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn);
void printData(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn);
void guessCost(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn);
void findExpensive(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn);
void printAvailable(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn);
int stringCompare(char * string1, char * string2);
  
int main()
{

  int command;
  char fileIn[25];
  RentalAgency Agency1, Agency2, Agency3;
  //Displays the commands
  cout << "This program can do various tasks with car rentals" << endl
       << "1 - Read in a text file" << endl
       << "2 - Print out the data for all cars" << endl
       << "3 - Estimate car rental cost" << endl
       << "4 - Find the most expensive car" << endl
       << "5 - Print out all available cars" << endl
       << "6 - Exit the program" << endl;
  for(;;){
  cout << "Please enter a command: ";
  cin >> command;
  //The main control switch
  switch(command){
    case 1:
      cout << "Please enter a file name: ";
      cin >> fileIn;
      readData(Agency1, Agency2, Agency3, fileIn); 
      cout << "Car data has been read" << endl;
    break;
    case 2:
      printData(Agency1, Agency2, Agency3, fileIn);
    break;
    case 3:
      guessCost(Agency1, Agency2, Agency3, fileIn);
    break;
    case 4:
      findExpensive(Agency1, Agency2, Agency3, fileIn);
    break;
    case 5:
      printAvailable(Agency1, Agency2, Agency3, fileIn);
    break;
    case 6:
      return 0;
    default:
      cout << "Please enter a valid command." << endl;
      break;
    }
  }
}
/*

  Function: readData
  Parameters: Three RentalAgency structs, which was previously defined and contain an array of the RentalCar class, a file input name
  Purpose: Reads in the data from file inputted by the user
  Returns: Nothing
  

*/
void readData(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3,char * fileIn)
{
  ifstream inputStream;
  char make[10];
  char model[10];
  int year;
  float price;
  bool flag;
  inputStream.open(fileIn);
  inputStream >> Agency1.name;
  inputStream >> Agency1.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency1.inventory[i].SetMake(make);
  Agency1.inventory[i].SetModel(model);
  Agency1.inventory[i].SetYear(year);
  Agency1.inventory[i].SetPrice(price);
  Agency1.inventory[i].SetAvailability(flag);
  }
    inputStream >> Agency2.name;
  inputStream >> Agency2.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency2.inventory[i].SetMake(make);
  Agency2.inventory[i].SetModel(model);
  Agency2.inventory[i].SetYear(year);
  Agency2.inventory[i].SetPrice(price);
  Agency2.inventory[i].SetAvailability(flag);
  }
  inputStream >> Agency3.name;
  inputStream >> Agency3.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency3.inventory[i].SetMake(make);
  Agency3.inventory[i].SetModel(model);
  Agency3.inventory[i].SetYear(year);
  Agency3.inventory[i].SetPrice(price);
  Agency3.inventory[i].SetAvailability(flag);
  }
  inputStream.close();

}
/*

  Function: printData
  Parameters: Three RentalAgency structs, which was previously defined and contain an array of the RentalCar class, a file input name
  Purpose: Prints out the data from the structs, and outputs it to a file
  Returns: Nothing
  

*/


void printData(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn)
{
  
  ifstream inputStream;
  ofstream outputStream;
  outputStream.open("AllCars.txt");
 
  char make[10];
  char model[10];
  int year;
  float price;
  bool flag;
  inputStream.open(fileIn);
  inputStream >> Agency1.name;
  cout << Agency1.name;
  inputStream >> Agency1.zipcode;
  cout << " " << Agency1.zipcode << endl; 
  outputStream << Agency1.name << " " << Agency1.zipcode << endl;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency1.inventory[i].SetMake(make);
  Agency1.inventory[i].SetModel(model);
  Agency1.inventory[i].SetYear(year);
  Agency1.inventory[i].SetPrice(price);
  Agency1.inventory[i].SetAvailability(flag);
  Agency1.inventory[i].PrintCars();
  outputStream << Agency1.inventory[i].GetYear() << " ";
  outputStream << Agency1.inventory[i].GetMake() << " ";
  outputStream << Agency1.inventory[i].GetModel() << " ";
  outputStream << Agency1.inventory[i].GetPrice() << " ";
  outputStream << Agency1.inventory[i].GetAvailability() << " " << endl;
  }
  inputStream >> Agency2.name;
  cout << Agency2.name;
  inputStream >> Agency2.zipcode;
  cout << " " << Agency2.zipcode << endl;
  outputStream << Agency2.name << " " << Agency2.zipcode << endl;
   for(int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
   Agency2.inventory[i].SetMake(make);
   Agency2.inventory[i].SetModel(model);
   Agency2.inventory[i].SetYear(year);
   Agency2.inventory[i].SetPrice(price);
   Agency2.inventory[i].SetAvailability(flag);
   Agency2.inventory[i].PrintCars();
   outputStream << Agency2.inventory[i].GetYear() << " ";
   outputStream << Agency2.inventory[i].GetMake() << " ";
   outputStream << Agency2.inventory[i].GetModel() << " ";
   outputStream << Agency2.inventory[i].GetPrice() << " ";
   outputStream << Agency2.inventory[i].GetAvailability() << " " << endl;
  }
  inputStream >> Agency3.name;
  cout << Agency3.name;
  inputStream >> Agency3.zipcode;
  cout << " " << Agency3.zipcode << endl;
  outputStream << Agency3.name << " " << Agency3.zipcode << endl;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
   Agency3.inventory[i].SetMake(make);
   Agency3.inventory[i].SetModel(model);
   Agency3.inventory[i].SetYear(year);
   Agency3.inventory[i].SetPrice(price);
   Agency3.inventory[i].SetAvailability(flag);
   Agency3.inventory[i].PrintCars();
   outputStream << Agency3.inventory[i].GetYear() << " ";
   outputStream << Agency3.inventory[i].GetMake() << " ";
   outputStream << Agency3.inventory[i].GetModel() << " ";
   outputStream << Agency3.inventory[i].GetPrice() << " ";
   outputStream << Agency3.inventory[i].GetAvailability() << " " << endl;
  }
  inputStream.close();
  outputStream.close();
}

/*

  Function: guessCost
  Parameters: Three RentalAgency structs, which was previously defined and contain an array of the RentalCar class, a file input name
  Purpose: Estimates the cost of a certain car from the RentalCar class and the RentalAgency struct
  Returns: Nothing
  

*/
void guessCost(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn)
{
  ifstream inputStream;
  char agency[10];
  char make[10];
  char model[10];
  int year;
  int days;
  int car;
  float price;
  bool flag;
  inputStream.open(fileIn);
  inputStream >> Agency1.name;
  inputStream >> Agency1.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency1.inventory[i].SetMake(make);
  Agency1.inventory[i].SetModel(model);
  Agency1.inventory[i].SetYear(year);
  Agency1.inventory[i].SetPrice(price);
  Agency1.inventory[i].SetAvailability(flag);
  }
    inputStream >> Agency2.name;
  inputStream >> Agency2.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency2.inventory[i].SetMake(make);
  Agency2.inventory[i].SetModel(model);
  Agency2.inventory[i].SetYear(year);
  Agency2.inventory[i].SetPrice(price);
  Agency2.inventory[i].SetAvailability(flag);
  }
  inputStream >> Agency3.name;
  inputStream >> Agency3.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency3.inventory[i].SetMake(make);
  Agency3.inventory[i].SetModel(model);
  Agency3.inventory[i].SetYear(year);
  Agency3.inventory[i].SetPrice(price);
  Agency3.inventory[i].SetAvailability(flag);
  }
  cout << "Please enter an agency: ";
  cin >> agency;
  if(stringCompare(agency, Agency1.name) == 0)
  {
    cout << "Please select a car(1-5): ";
    cin >> car;
    cout << "Please enter the number of days: ";
    cin >> days;
    cout << "The estimated cost will be $" << Agency1.inventory[car - 1].EstimateCost(days, Agency1.inventory[car - 1].GetPrice()) << endl;
    return;
  }
  
    if(stringCompare(agency, Agency2.name) == 0)
    {
      cout << "Please select a car(1-5): ";
      cin >> car;
      cout << "Please enter the number of days: ";
      cin >> days;
      cout << "The estimated cost will be $" << Agency2.inventory[car - 1].EstimateCost(days, Agency2.inventory[car - 1].GetPrice()) << endl;
      return;
    }
  if(stringCompare(agency, Agency3.name) == 0)
  {
    cout << "Please select a car(1-5): ";
    cin >> car;
    cout << "Please enter the number of days: ";
    cin >> days;
    cout << "The estimated cost will be $" << Agency3.inventory[car - 1].EstimateCost(days, Agency3.inventory[car - 1].GetPrice()) << endl;
  }
  else{
    cout << "Please enter a valid agency name." << endl;
  }
  inputStream.close();
  
}
/*

  Function: findExpensive
  Parameters: Three RentalAgency structs, which was previously defined and contain an array of the RentalCar class, a file input name
  Purpose: Finds the most expensive price of all the cars, and prints it out
  Returns: Nothing
  

*/
void findExpensive(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3, char * fileIn)
{
  ifstream inputStream;
  char make[10];
  char model[10];
  int year;
  float price;
  float highCost;
  bool flag;
  inputStream.open(fileIn);
  inputStream >> Agency1.name;
  inputStream >> Agency1.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency1.inventory[i].SetMake(make);
  Agency1.inventory[i].SetModel(model);
  Agency1.inventory[i].SetYear(year);
  Agency1.inventory[i].SetPrice(price);
  Agency1.inventory[i].SetAvailability(flag);
  }
    inputStream >> Agency2.name;
  inputStream >> Agency2.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency2.inventory[i].SetMake(make);
  Agency2.inventory[i].SetModel(model);
  Agency2.inventory[i].SetYear(year);
  Agency2.inventory[i].SetPrice(price);
  Agency2.inventory[i].SetAvailability(flag);
  }
  inputStream >> Agency3.name;
  inputStream >> Agency3.zipcode;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency3.inventory[i].SetMake(make);
  Agency3.inventory[i].SetModel(model);
  Agency3.inventory[i].SetYear(year);
  Agency3.inventory[i].SetPrice(price);
  Agency3.inventory[i].SetAvailability(flag);
  }
  
  highCost = Agency1.inventory[0].GetPrice();
  for(int j = 1; j < 5; j++)
  {
     if(Agency1.inventory[j].GetPrice() > highCost)
       highCost = Agency1.inventory[j].GetPrice();
  }
  for(int j = 0; j < 5; j++)
  {
     if(Agency2.inventory[j].GetPrice() > highCost)
       highCost = Agency2.inventory[j].GetPrice();
  }
   for(int j = 0; j < 5; j++)
  {
     if(Agency3.inventory[j].GetPrice() > highCost)
       highCost = Agency3.inventory[j].GetPrice();
  }
  cout << "The most expensive car costs $" << highCost << endl;
  inputStream.close();
}
/*

  Function: printAvailable
  Parameters: Three RentalAgency structs, which was previously defined and contain an array of the RentalCar class, a file input name
  Purpose: Prints out the cars that are available, then outputs them to a file
  Returns: Nothing
  

*/
void printAvailable(RentalAgency Agency1, RentalAgency Agency2, RentalAgency Agency3,char * fileIn)
{
  ifstream inputStream;
  ofstream outputStream;
  outputStream.open("AvailableCars.txt");
  char make[10];
  char model[10];
  int year;
  float price;
  bool flag;
  inputStream.open(fileIn);
  inputStream >> Agency1.name;
  cout << Agency1.name;
  inputStream >> Agency1.zipcode;
  cout << " " << Agency1.zipcode << endl;
  outputStream << Agency1.name << " " << Agency1.zipcode << endl;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
  Agency1.inventory[i].SetMake(make);
  Agency1.inventory[i].SetModel(model);
  Agency1.inventory[i].SetYear(year);
  Agency1.inventory[i].SetPrice(price);
  Agency1.inventory[i].SetAvailability(flag);
  if(Agency1.inventory[i].GetAvailability() == 1){
  Agency1.inventory[i].PrintCars();
  outputStream << Agency1.inventory[i].GetYear() << " ";
  outputStream << Agency1.inventory[i].GetMake() << " ";
  outputStream << Agency1.inventory[i].GetModel() << " ";
  outputStream << Agency1.inventory[i].GetPrice() << " ";
  outputStream << Agency1.inventory[i].GetAvailability() << " " << endl;
  }
  }
  inputStream >> Agency2.name;
  cout << Agency2.name;
  inputStream >> Agency2.zipcode;
  cout << " " << Agency2.zipcode << endl;
  outputStream << Agency2.name << " " << Agency2.zipcode << endl;
   for(int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
   Agency2.inventory[i].SetMake(make);
   Agency2.inventory[i].SetModel(model);
   Agency2.inventory[i].SetYear(year);
   Agency2.inventory[i].SetPrice(price);
   Agency2.inventory[i].SetAvailability(flag);
   if(Agency2.inventory[i].GetAvailability() == 1){
   Agency2.inventory[i].PrintCars();
   outputStream << Agency2.inventory[i].GetYear() << " ";
   outputStream << Agency2.inventory[i].GetMake() << " ";
   outputStream << Agency2.inventory[i].GetModel() << " ";
   outputStream << Agency2.inventory[i].GetPrice() << " ";
   outputStream << Agency2.inventory[i].GetAvailability() << " " << endl;
  }
  }
  inputStream >> Agency3.name;
  cout << Agency3.name;
  inputStream >> Agency3.zipcode;
  cout << " " << Agency3.zipcode << endl;
  outputStream << Agency3.name << " " << Agency3.zipcode << endl;
   for( int i = 0; i < 5; i++){
   inputStream >> year;
   inputStream >> make;
   inputStream >> model;
   inputStream >> price;
   inputStream >> flag;
   Agency3.inventory[i].SetMake(make);
   Agency3.inventory[i].SetModel(model);
   Agency3.inventory[i].SetYear(year);
   Agency3.inventory[i].SetPrice(price);
   Agency3.inventory[i].SetAvailability(flag);
   if(Agency3.inventory[i].GetAvailability() == 1){
   Agency3.inventory[i].PrintCars();
   outputStream << Agency3.inventory[i].GetYear() << " ";
   outputStream << Agency3.inventory[i].GetMake() << " ";
   outputStream << Agency3.inventory[i].GetModel() << " ";
   outputStream << Agency3.inventory[i].GetPrice() << " ";
   outputStream << Agency3.inventory[i].GetAvailability() << " " << endl;
  }
  }
  inputStream.close();
  outputStream.close();
}
/*
RentalCar::RentalCar(char * make, char * model, int year){
  
   SetMake(make);
   SetModel(model);
   SetYear(year);
    

}
*/
/*

  Function: SetMake
  Parameters: a char *, or a string
  Purpose: Changes the member value to the one passed to the parameter
  Returns: Nothing
  

*/
void RentalCar::SetMake(char * make){


  m_make = make;


}
/*

  Function: GetMake
  Parameters: nothing
  Purpose: returns the member variable to be used in other functions
  Returns: the string, or char * corresponding to the member variable
  

*/

char * RentalCar::GetMake()
{

  return m_make;

}
/*

  Function: SetModel
  Parameters: a char *, or a string
  Purpose: Changes the member value to the one passed to the parameter
  Returns: Nothing
  

*/

void RentalCar::SetModel(char * model){


  m_model = model;


}

/*

  Function: GetModel
  Parameters: nothing
  Purpose: returns the member variable to be used in other functions
  Returns: the string, or char * corresponding to the member variable
  

*/
char * RentalCar::GetModel()
{

  return m_model;

}

/*

  Function: SetYear
  Parameters: a integer
  Purpose: Changes the member value to the one passed to the parameter
  Returns: Nothing
  

*/

void RentalCar::SetYear(int year){


  m_year = year;


}

/*

  Function: GetYear
  Parameters: nothing
  Purpose: returns the member variable to be used in other functions
  Returns: an integer corresponding to the member variable
  

*/
int RentalCar::GetYear()
{

  return m_year;

}
 
/*

  Function: SetPrice
  Parameters: a float value
  Purpose: Changes the member value to the one passed to the parameter
  Returns: Nothing
  

*/
void RentalCar::SetPrice(float price){


  m_price = price;


}
/*

  Function: GetPrice
  Parameters: nothing
  Purpose: returns the member variable to be used in other functions
  Returns: an float corresponding to the member variable
  

*/

float RentalCar::GetPrice()
{

  return m_price;

}
 
/*

  Function: SetAvailability
  Parameters: a boolean value
  Purpose: Changes the member value to the one passed to the parameter
  Returns: Nothing
  

*/
void RentalCar::SetAvailability(bool avail){


  m_available = avail;


}

/*

  Function: GetAvailability
  Parameters: nothing
  Purpose: returns the member variable to be used in other functions
  Returns: an boolean value corresponding to the member variable
  

*/
bool RentalCar::GetAvailability()
{

  return m_available;

}
/*

  Function: PrintCars
  Parameters: nothing
  Purpose: Prints out the data of the member variables from the "getter" functions
  Returns: Nothing
  

*/
void RentalCar::PrintCars()
{

  cout << GetYear();
  cout << " " << GetMake();
  cout << " " << GetModel();
  cout << " $" << GetPrice() << " per day Available: ";
  cout << boolalpha << GetAvailability() << endl;  

}

/*

  Function: EstimateCost
  Parameters: the number of days, an int, and a float which is the price
  Purpose: Calculates the total cost based on the parameters given to it
  Returns: Nothing

*/

float RentalCar::EstimateCost(int days, float price)
{
  float totalCost;

  totalCost = days * price;

  return totalCost;

}
 /*

  Function: stringCompare
  Parameters: two char *, or strings
  Purpose: Checks to see if the two strings in the parameters, up to the first 4 digits
  Returns: a 1 if the strings are different, and a 0 if they are the same
  

*/
int stringCompare(char * string1, char * string2)
{
    if(string1[0] != string2[0])
      return 1;
    else
    {
     for(int i = 1; i < 4; i++)
     {
       if(string1[i-1] != string2[i-1] && string1[i] != string2[i])
       {
         return 1;
         break;
       }
     }
    }
  return 0;

}