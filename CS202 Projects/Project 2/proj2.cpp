//This program takes car rental data from an external file, and manipulates the data from it based on user input
#include<iostream>
#include<fstream>
using namespace std;

  struct RentalCar {
    char make[10];
    char model[10];
    int year;
    float price;
    bool available;
  };

void readData(RentalCar carList[]);
void printData(RentalCar carList[]);
float estimateCost(RentalCar carList[]);
void mostExpensive(RentalCar carList[]);
void printAvailableCars(RentalCar carlist[]);

int main()
{

  int command;
  float dayCost;
  RentalCar carList[10];
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
    readData(carList); 
    cout << "Car data has been read" << endl;
    break;
    case 2:
    printData(carList);
    break;
    case 3:
    dayCost = estimateCost(carList);
    cout << "The estimated cost is $" << dayCost << endl;
    break;
    case 4:
    mostExpensive(carList);
    break;
    case 5:
    printAvailableCars(carList);
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
  Parameters: An array of struct RentalCar, which was previously defined
  Purpose: Reads in the data from file inputted by the user
  Returns: Nothing
  
*/

void readData(RentalCar carList[])
{
  ifstream inputStream;
  char fileIn[20];
  cout << "Enter a file for input: ";
  cin >> fileIn;
  inputStream.open(fileIn);
    for(int i = 0; i < 10; i++){
     inputStream >> carList[i].year;
     inputStream >> carList[i].make;
     inputStream >> carList[i].model;
     inputStream >> carList[i].price;
     inputStream >> carList[i].available;
    } 
     inputStream.close();
}
/*

  Function: printData
  Parameters: An array of struct RentalCar, which was previously defined
  Purpose: Prints out the data onto the terminal, along with writing it to a file named AllCars.txt
  Returns: Nothing

*/
void printData(RentalCar carList[])
{
  ofstream outputStream;
  outputStream.open("AllCars.txt");
    for(int i = 0; i < 10; i++){
      cout << carList[i].year << " " << carList[i].make
      << " " << carList[i].model << " " << "$" << carList[i].price 
      << " per day Available: " << boolalpha << carList[i].available << endl;
    }
  for(int j = 0; j < 10; j++){
    outputStream << carList[j].year << " " << carList[j].make << " " << carList[j].model << " " << carList[j].price << " " << carList[j].available << endl;
  }
  outputStream.close();
}

/*

  Function: estimateCost
  Parameters: An array of struct RentalCar, which was previously defined
  Purpose: Asks the user for a car number, along with the number of days. It then calculates the cost of the vehicle based on the inputs
  Returns: The cost, a float value

*/
float estimateCost(RentalCar carList[])
{
  int days, car;
  float cost;
  cout << "Please select a car: ";
  cin >> car;
  cout << "Enter the numbers of days to rent this car: ";
  cin >> days;

  cost = days * carList[car - 1].price;

  return cost;

}
/*

  Function: mostExpensive
  Parameters: An array of struct RentalCar, which was previously defined
  Purpose: Goes through every individual price of the list of cars, finds the most expensive, then prints out the name of the car along with the price of it
  Returns: Nothing

*/
void mostExpensive(RentalCar carList[])
{

  float highCost;

  highCost = carList[0].price;

  for(int i = 1; i < 10; i++){
    if(carList[i].price > highCost)
      carList[i].price = highCost;
  }
 
  for(int i = 0; i < 10; i++){
    if(carList[i].price == highCost)
    cout << "The most expensive car is the " << carList[i].year << " " << carList[i].make << " " << carList[i].model 
         << " at $" << carList[i].price << " per day" << endl;
  }
/*

  Function: printAvailableCars
  Parameters: An array of struct RentalCar, which was previously defined
  Purpose: Goes through the individual availability of each car, and prints along with outputs to a file every available car
  Returns: Nothing

*/
}
void printAvailableCars(RentalCar carList[])
{
  ofstream outputStream;
  outputStream.open("AvailableCars.txt");
  cout << "These are the available cars: " << endl;
  for(int i = 0; i < 10; i++){
    if( carList[i].available == 1){
      cout << carList[i].year << " " << carList[i].make
      << " " << carList[i].model << " " << "$" << carList[i].price 
      << " per day" << endl;
      outputStream << carList[i].year << " " << carList[i].make << " " << carList[i].model << " " << carList[i].price << " " << carList[i].available << endl;
    }
  }

  outputStream.close();

}