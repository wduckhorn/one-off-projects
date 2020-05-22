//This program prints out user data based on a file input, and manipulates that data with the use of multiple classes
#include<iostream>
#include<fstream>
using namespace std;

class CarSensor{

  public:
  CarSensor();
  CarSensor(char * type, float extracost);
  CarSensor(const CarSensor &sensor);
  void SetType(char * type);
  char * GetType();
  void SetExtraCost(char * type);
  float GetExtraCost();
  void ResetGPSCount();
  int GetGPSCount();
  void ResetCameraCount();
  int GetCameraCount();
  void ResetLidarCount();
  int GetLidarCount();
  void ResetRadarCount();
  int GetRadarCount();
  void SetTypeCount(char * type);
  const CarSensor operator ==(const CarSensor &sensor) const;
  private:
  char * m_type;
  float m_extracost;
  static int gps_cnt;
  static int camera_cnt;
  static int lidar_cnt;
  static int radar_cnt;
};


class RentalCar{

  public:
  RentalCar();
  RentalCar(char * make, char * model, int year, float tank, float price, bool avail);
  RentalCar(const RentalCar &car);
  char * GetMake();
  char * GetModel();
  int GetYear();
  float GetTank();
  CarSensor GetSensor();
  float GetBasePrice();
  float GetFinalPrice();
  bool GetAvailability();
  char * GetOwner();
  void SetMake(char * make);
  void SetModel(char * model);
  void SetYear(int year);
  void SetTank(float tank);
  void SetBasePrice(float price);
  void SetAvailability(bool avail);
  void SetOwner(char * owner);
  void UpdatePrice(float base, float sensorcost);
  void Print();
  float EstimateCost(int days, float price);
  const RentalCar operator +(const RentalCar &car) const;
  CarSensor m_sensor[3];
  private:
  char * m_make;
  char * m_model;
  int m_year;
  float m_tank;
  float m_baseprice;
  float m_finalprice;
  bool m_available;
  char * m_owner;
};


class RentalAgency{

  public:
  RentalAgency();
  void SetName(char * name);
  char * GetName();
  void SetZipcode(int zipcode);
  int GetZipcode();
  RentalCar& operator[](const int size){
    return m_inventory[size];
  }
  void ReadAllData(char * fileIn);
  void PrintAllData(char * fileIn);
  void PrintCount(char * fileIn);
  void PrintAvailableCars(char * fileIn);
  void AddLesee(char * fileIn, char * newName, float finalcost);
  private:
  char * m_name;
  int m_zipcode;
  RentalCar m_inventory[5];
};

int stringCompare(char * string);

int CarSensor::gps_cnt = 0;
int CarSensor::camera_cnt = 0;
int CarSensor::lidar_cnt = 0;
int CarSensor::radar_cnt = 0;

int main()
{

  RentalAgency Agency;
  int command;
  char fileIn[20];
  cout << "This program can do various tasks with car rentals" << endl
       << "1 - Read in a text file" << endl
       << "2 - Print out the data for all cars" << endl
       << "3 - Print out the count of all sensors" << endl
       << "4 - Print most available expensive car" << endl
       << "5 - Exit the program" << endl;
  for(;;){
  cout << "Please enter a command: ";
  cin >> command;
  //The main control switch
  switch(command){
    case 1:
    cout << "Please enter a filename: ";
    cin >> fileIn;
    Agency.ReadAllData(fileIn);
    cout << "The file has been read" << endl;
    break;
    case 2:
    Agency.PrintAllData(fileIn);
    break;
    case 3:
    Agency.PrintCount(fileIn);
    break;
    case 4:
    Agency.PrintAvailableCars(fileIn);
    break;
    case 5:
      return 0;
    default:
      cout << "Please enter a valid command." << endl;
      break;
    }
  }
}



RentalAgency::RentalAgency(){

}
RentalCar::RentalCar(){

}
CarSensor::CarSensor(){

}
/*

  Function: ReadAllData
  Parameters: a string, which is the file name
  Purpose: Reads in the data from file inputted by the user
  Returns: Nothing
  
*/
void RentalAgency::ReadAllData(char * fileIn){
  
  ifstream inputStream;
  char name[15];
  int zipcode;
  int year;
  char make[15];
  float tank;
  float baseprice;
  char type[15];
  char sensortype[8];
  char sensortype2[8];
  char sensortype3[8];
  bool avail;
  int test;
  char owner[10];
  inputStream.open(fileIn);

  inputStream >> name;
  SetName(name);

  inputStream >> zipcode;
  SetZipcode(zipcode);
  
  
  for(int i = 0; i < 5; i++){
  inputStream >> year;
  m_inventory[i].SetYear(year);

  inputStream >> make;
  m_inventory[i].SetMake(make);
  
  inputStream >> make;
  m_inventory[i].SetModel(make);
  
  inputStream >> tank;
  m_inventory[i].SetTank(tank);
  
  inputStream >> baseprice;
  m_inventory[i].SetBasePrice(baseprice);

  inputStream >> sensortype;
  m_inventory[i].m_sensor[0].SetType(sensortype);
  test = stringCompare(sensortype);
  if(test == 0){
  inputStream >> sensortype2;
  m_inventory[i].m_sensor[1].SetType(sensortype2);
    if(stringCompare(sensortype2) == 0){
    inputStream >> sensortype3;
    m_inventory[i].m_sensor[2].SetType(sensortype3);
  }
  }
    
  inputStream >> avail;
  m_inventory[i].SetAvailability(avail);
  
  if(m_inventory[i].GetAvailability() == 0){
  inputStream >> owner;
  m_inventory[i].SetOwner(owner);
  }
  }
  inputStream.close();
}
/*

  Function: PrintAllData
  Parameters: a string, which is the file name
  Purpose: Prints out the data from file inputted by the user, then outputs it to a file named AllCars.txt
  Returns: Nothing
  
*/
void RentalAgency::PrintAllData(char * fileIn){

  ifstream inputStream;
  ofstream outputStream;
  char name[15];
  int zipcode;
  int year;
  char make[15];
  char model[15];
  float tank;
  float baseprice;
  char type[15];
  char sensortype[8];
  char sensortype2[8];
  char sensortype3[8];
  bool avail;
  int test;
  char owner[10];
  float highcost[5] = {0, 0, 0, 0, 0};
  inputStream.open(fileIn);
  outputStream.open("AllCars.txt");
  inputStream >> name;
  SetName(name);
  cout << GetName() << " ";
  inputStream >> zipcode;
  SetZipcode(zipcode);
  cout << GetZipcode() << endl;
  outputStream << GetName() << " " << GetZipcode() << endl;
  
  for(int i = 0; i < 5; i++){
  inputStream >> year;
  m_inventory[i].SetYear(year);
  outputStream << m_inventory[i].GetYear() << " ";

  inputStream >> make;
  m_inventory[i].SetMake(make);
  outputStream << m_inventory[i].GetMake() << " ";

  inputStream >> model;
  m_inventory[i].SetModel(model);
  outputStream << m_inventory[i].GetModel() << " ";  
  
  inputStream >> tank;
  m_inventory[i].SetTank(tank);
  outputStream << m_inventory[i].GetTank() << " ";

  inputStream >> baseprice;
  m_inventory[i].SetBasePrice(baseprice);
  outputStream << m_inventory[i].GetBasePrice() << " ";

  inputStream >> sensortype;
  m_inventory[i].m_sensor[0].SetType(sensortype);
  outputStream << m_inventory[i].m_sensor[0].GetType() << " ";
  m_inventory[i].m_sensor[0].SetExtraCost(sensortype);
  highcost[i] += m_inventory[i].m_sensor[0].GetExtraCost();
  test = stringCompare(sensortype);
  if(test == 0){
  inputStream >> sensortype2;
  m_inventory[i].m_sensor[1].SetType(sensortype2);
  outputStream << m_inventory[i].m_sensor[1].GetType() << " ";
  m_inventory[i].m_sensor[1].SetExtraCost(sensortype2);
  highcost[i] += m_inventory[i].m_sensor[1].GetExtraCost();
    if(stringCompare(sensortype2) == 0){
    inputStream >> sensortype3;
    m_inventory[i].m_sensor[2].SetType(sensortype3);
    outputStream << m_inventory[i].m_sensor[2].GetType() << " ";
    m_inventory[i].m_sensor[2].SetExtraCost(sensortype3);
    highcost[i] += m_inventory[i].m_sensor[2].GetExtraCost();
  }
  }
  m_inventory[i].UpdatePrice(baseprice, highcost[i]);
  inputStream >> avail;
  m_inventory[i].SetAvailability(avail);
  outputStream << m_inventory[i].GetAvailability() << " ";

  if(m_inventory[i].GetAvailability() == 0){
  inputStream >> owner;
  m_inventory[i].SetOwner(owner);
  outputStream << m_inventory[i].GetOwner() << " ";
  }
  outputStream << endl;
  m_inventory[i].Print();
  }
  
  inputStream.close();
  outputStream.close();
}
/*

  Function: PrintCount
  Parameters: a string, which is the file name
  Purpose: Counts the amount of sensors in a user inputted file, prints them out, then resets the counter
  Returns: Nothing
  
*/
void RentalAgency::PrintCount(char * fileIn){

  ifstream inputStream;
  char name[15];
  int zipcode;
  int year;
  char make[15];
  char model[15];
  float tank;
  float baseprice;
  char type[15];
  char sensortype[8];
  char sensortype2[8];
  char sensortype3[8];
  bool avail;
  int test;
  char owner[10];
  inputStream.open(fileIn);
  inputStream >> name;
  SetName(name);

  inputStream >> zipcode;
  SetZipcode(zipcode);

  for(int i = 0; i < 5; i++){
  inputStream >> year;
  m_inventory[i].SetYear(year);

  inputStream >> make;
  m_inventory[i].SetMake(make);
  
  inputStream >> model;
  m_inventory[i].SetModel(model);
  
  inputStream >> tank;
  m_inventory[i].SetTank(tank);
  
  inputStream >> baseprice;
  m_inventory[i].SetBasePrice(baseprice);

  inputStream >> sensortype;
  m_inventory[i].m_sensor[0].SetType(sensortype);
  m_inventory[i].m_sensor[0].SetTypeCount(sensortype);
  test = stringCompare(sensortype);
  if(test == 0){
  inputStream >> sensortype2;
  m_inventory[i].m_sensor[1].SetType(sensortype2);
  m_inventory[i].m_sensor[1].SetTypeCount(sensortype2);
    if(stringCompare(sensortype2) == 0){
    inputStream >> sensortype3;
    m_inventory[i].m_sensor[2].SetType(sensortype3);
    m_inventory[i].m_sensor[1].SetTypeCount(sensortype3);
  }
  }
  inputStream >> avail;
  m_inventory[i].SetAvailability(avail);
  
  if(m_inventory[i].GetAvailability() == 0){
  inputStream >> owner;
  m_inventory[i].SetOwner(owner);
  }
  }
  inputStream.close();
  
  cout << "GPS: " << m_inventory[0].m_sensor[0].GetGPSCount() << endl;
  cout << "Camera: " << m_inventory[0].m_sensor[0].GetCameraCount() << endl;
  cout << "Lidar: " << m_inventory[0].m_sensor[0].GetLidarCount() << endl;
  cout << "Radar: " << m_inventory[0].m_sensor[0].GetRadarCount() << endl;

  m_inventory[0].m_sensor[0].ResetGPSCount();
  m_inventory[0].m_sensor[0].ResetCameraCount();
  m_inventory[0].m_sensor[0].ResetLidarCount();
  m_inventory[0].m_sensor[0].ResetRadarCount();
}
/*

  Function: PrintAvailableCars
  Parameters: a string, which is the file name
  Purpose: Finds only the available cars, adds on the price of the sensors to the base price,prints out the highest price, then asks the user if they would like to rent this car
  Returns: Nothing
  
*/
void RentalAgency::PrintAvailableCars(char * fileIn){

  ifstream inputStream;
  char name[15];
  int zipcode;
  int year;
  char make[15];
  float tank;
  float baseprice;
  char type[15];
  char sensortype[8];
  char sensortype2[8];
  char sensortype3[8];
  bool avail;
  int test;
  float highcost[5] = {0, 0, 0, 0, 0};
  float totalcost;
  float mostcost;
  char owner[10];
  char newOwner[20];
  char takeCar;
  inputStream.open(fileIn);

  inputStream >> name;
  SetName(name);

  inputStream >> zipcode;
  SetZipcode(zipcode);
  
  
  for(int i = 0; i < 5; i++){
  inputStream >> year;
  m_inventory[i].SetYear(year);

  inputStream >> make;
  m_inventory[i].SetMake(make);
  
  inputStream >> make;
  m_inventory[i].SetModel(make);
  
  inputStream >> tank;
  m_inventory[i].SetTank(tank);
  
  inputStream >> baseprice;
  m_inventory[i].SetBasePrice(baseprice);

  inputStream >> sensortype;
  m_inventory[i].m_sensor[0].SetType(sensortype);
  m_inventory[i].m_sensor[0].SetExtraCost(sensortype);
  highcost[i] += m_inventory[i].m_sensor[0].GetExtraCost();
  test = stringCompare(sensortype);
  if(test == 0){
  inputStream >> sensortype2;
  m_inventory[i].m_sensor[1].SetType(sensortype2);
  m_inventory[i].m_sensor[1].SetExtraCost(sensortype2);
  highcost[i] += m_inventory[i].m_sensor[1].GetExtraCost();
    if(stringCompare(sensortype2) == 0){
    inputStream >> sensortype3;
    m_inventory[i].m_sensor[2].SetType(sensortype3);
    m_inventory[i].m_sensor[2].SetExtraCost(sensortype3);
    highcost[i] += m_inventory[i].m_sensor[2].GetExtraCost();
  }
  }
  inputStream >> avail;
  m_inventory[i].SetAvailability(avail);
  if(m_inventory[i].GetAvailability() == 1){
    m_inventory[i].UpdatePrice(baseprice, highcost[i]);
    if(m_inventory[i].GetFinalPrice() > mostcost){
      mostcost = m_inventory[i].GetFinalPrice();
    }

  }
  if(m_inventory[i].GetAvailability() == 0){
  inputStream >> owner;
  m_inventory[i].SetOwner(owner);
  }
  }
  if(mostcost == 0){
    cout << "No cars available." << endl;
    return;
  }
  cout << "The most expensive available car costs $" << mostcost << ". Would you like to rent it? (Y or N): ";
  cin >> takeCar;
  if(takeCar == 'Y' || takeCar == 'y'){
     cout << "Please enter a name: ";
     cin >> newOwner;
     AddLesee(fileIn, newOwner, mostcost);
     cout << "The new list is created" << endl; 
  }
  if(takeCar == 'N' || takeCar == 'n'){
    cout << "The car was not taken" << endl;
  }
  inputStream.close();


}
/*

  Function: AddLesee
  Parameters: a string, which is the file name, another string which is the new owner name, and a float which is the highest cost
  Purpose: Updates the list to include the new owner for the available car, prints out the list to the screen, and creates a new file 
  Returns: Nothing
  
*/
void RentalAgency::AddLesee(char * fileIn, char * newName, float finalcost){
  ifstream inputStream;
  ofstream outputStream;
  char name[15];
  int zipcode;
  int year;
  char make[15];
  char model[15];
  float tank;
  float baseprice;
  char type[15];
  char sensortype[8];
  char sensortype2[8];
  char sensortype3[8];
  bool avail;
  int test;
  char fileOut[20];
  float highcost[5] = {0, 0, 0, 0, 0};
  float totalcost;
  float mostcost;
  char owner[10];
  char newOwner[20];
  char takeCar;
  inputStream.open(fileIn);
  cout << "Please enter a filename for output: ";
  cin >> fileOut;
  outputStream.open(fileOut);
  inputStream >> name;
  SetName(name);
  cout << GetName() << " ";

  inputStream >> zipcode;
  SetZipcode(zipcode);
  cout << GetZipcode() << endl;
 
  outputStream << GetName() << " " << GetZipcode() << endl;

  for(int i = 0; i < 5; i++){
  inputStream >> year;
  m_inventory[i].SetYear(year);
  outputStream << m_inventory[i].GetYear() << " ";

  inputStream >> make;
  m_inventory[i].SetMake(make);
  outputStream << m_inventory[i].GetMake() << " ";
 
  inputStream >> model;
  m_inventory[i].SetModel(model);
  outputStream << m_inventory[i].GetModel() << " ";

  inputStream >> tank;
  m_inventory[i].SetTank(tank);
  outputStream << m_inventory[i].GetTank() << " ";

  inputStream >> baseprice;
  m_inventory[i].SetBasePrice(baseprice);
  outputStream << m_inventory[i].GetBasePrice() << " ";

  inputStream >> sensortype;
  m_inventory[i].m_sensor[0].SetType(sensortype);
  outputStream << m_inventory[i].m_sensor[0].GetType() << " ";
  m_inventory[i].m_sensor[0].SetExtraCost(sensortype);
  highcost[i] += m_inventory[i].m_sensor[0].GetExtraCost();
  test = stringCompare(sensortype);
  if(test == 0){
  inputStream >> sensortype2;
  m_inventory[i].m_sensor[1].SetType(sensortype2);
  outputStream << m_inventory[i].m_sensor[1].GetType() << " ";
  m_inventory[i].m_sensor[1].SetExtraCost(sensortype2);
  highcost[i] += m_inventory[i].m_sensor[1].GetExtraCost();
    if(stringCompare(sensortype2) == 0){
    inputStream >> sensortype3;
    m_inventory[i].m_sensor[2].SetType(sensortype3);
    outputStream << m_inventory[i].m_sensor[2].GetType() << " ";
    m_inventory[i].m_sensor[2].SetExtraCost(sensortype3);
    highcost[i] += m_inventory[i].m_sensor[2].GetExtraCost();
  }
  }
  inputStream >> avail;
  m_inventory[i].SetAvailability(avail);
  if(m_inventory[i].GetAvailability() == 0){
  inputStream >> owner;
  m_inventory[i].SetOwner(owner);
  }
  if(m_inventory[i].GetAvailability() == 1){
    m_inventory[i].UpdatePrice(baseprice, highcost[i]); 
    if(finalcost == m_inventory[i].GetFinalPrice()){
     m_inventory[i].SetAvailability(0);
     m_inventory[i].SetOwner(newName);
    }
    }
  outputStream << m_inventory[i].GetAvailability() << " ";
  if(m_inventory[i].GetAvailability() == 0){
  outputStream << m_inventory[i].GetOwner() << " ";
  }
  m_inventory[i].Print();
  outputStream << endl;
  }
  
  outputStream.close();
}
/*

  Function: SetName
  Parameters: a string, which is the name of the agency
  Purpose: Sets the value of m_name
  Returns: Nothing
  
*/
void RentalAgency::SetName(char * name){

  m_name = name;

}
/*

  Function: GetName
  Parameters: Nothing
  Purpose: Returns the value of m_name
  Returns: a string, m_name
  
*/
char * RentalAgency::GetName(){

  return m_name;
}
/*

  Function: SetZipcode
  Parameters: a int, which is the zipcode
  Purpose: Sets the value of m_zipcode
  Returns: Nothing
  
*/
void RentalAgency::SetZipcode(int zipcode){

  m_zipcode = zipcode;

}
/*

  Function: GetZipcode
  Parameters: Nothing
  Purpose: Returns the value of m_zipcode
  Returns: a int, m_zipcode
  
*/
int RentalAgency::GetZipcode(){

  return m_zipcode;
}
/*

  Function: SetYear
  Parameters: a int, which is the year
  Purpose: Sets the value of m_year
  Returns: Nothing
  
*/
void RentalCar::SetYear(int year){


  m_year = year;

}
/*

  Function: GetYear
  Parameters: Nothing
  Purpose: Returns the value of m_year
  Returns: a int, m_year
  
*/
int RentalCar::GetYear(){

  return m_year;

}
/*

  Function: SetMake
  Parameters: a string, which is the name of the make
  Purpose: Sets the value of m_make
  Returns: Nothing
  
*/
void RentalCar::SetMake(char * make){


  m_make = make;

}
/*

  Function: GetMake
  Parameters: Nothing
  Purpose: Returns the value of m_make
  Returns: a string, m_make
  
*/
char * RentalCar::GetMake(){

  return m_make;

}
/*

  Function: SetModel
  Parameters: a string, which is the name of the model
  Purpose: Sets the value of m_model
  Returns: Nothing
  
*/
void RentalCar::SetModel(char * model){

  m_model = model;

}
/*

  Function: GetModel
  Parameters: Nothing
  Purpose: Returns the value of m_model
  Returns: a string, m_model
  
*/
char * RentalCar::GetModel(){

  return m_model;

}
/*

  Function: SetTank
  Parameters: a float, which is the size of the gas tank
  Purpose: Sets the value of m_tank
  Returns: Nothing
  
*/
void RentalCar::SetTank(float tank){

  m_tank = tank;

}
/*

  Function: GetTank
  Parameters: Nothing
  Purpose: Returns the value of m_tank
  Returns: a float, which is the size of the gas tank
  
*/
float RentalCar::GetTank(){

  return m_tank;

}
/*

  Function: SetBasePrice
  Parameters: a float, which is the base price
  Purpose: Sets the value of m_baseprice
  Returns: Nothing
  
*/
void RentalCar::SetBasePrice(float baseprice){

  m_baseprice = baseprice;

}
/*

  Function: GetBasePrice
  Parameters: Nothing
  Purpose: Returns the value of m_baseprice
  Returns: a float, which is the base price
  
*/
float RentalCar::GetBasePrice(){

  return m_baseprice;

}
/*

  Function: SetType
  Parameters: a string, which is the type of sensor
  Purpose: Sets the value of m_type
  Returns: Nothing
  
*/
void CarSensor::SetType(char * type){
  
  m_type = type;

}
/*

  Function: GetType
  Parameters: Nothing
  Purpose: Returns the value of m_type
  Returns:  a string, which is the type of sensor
  
*/
char * CarSensor::GetType(){

  return m_type;

}
/*

  Function: SetAvailability
  Parameters: a bool value, which is the availability of the car
  Purpose: Sets the value of m_available
  Returns: Nothing
  
*/
void RentalCar::SetAvailability(bool avail){

  m_available = avail;

}
/*

  Function: GetAvailability
  Parameters: Nothing
  Purpose: Returns the value of m_available
  Returns:  a bool value, which is the availability of the car
  
*/
bool RentalCar::GetAvailability(){

  return m_available;

}
/*

  Function: SetOwner
  Parameters: a string, which is the name of the Owner
  Purpose: Sets the value of m_owner
  Returns: Nothing

*/
void RentalCar::SetOwner(char * owner){

  m_owner = owner;

}
/*

  Function: GetOwner
  Parameters: Nothing
  Purpose: Returns the value of m_owner
  Returns: a string, m_owner
  
*/
char * RentalCar::GetOwner(){

  return m_owner;

}
/*

  Function: SetTypeCount
  Parameters: a string, which is the type of sensor
  Purpose: Updates the count based on the type of sensor, and increments the correct variable
  Returns: Nothing
  
*/
void CarSensor::SetTypeCount(char * type){

  if(type[0] == '{'){
     if(type[1] == 'g')
       gps_cnt++;
     if(type[1] == 'c')
       camera_cnt++;
     if(type[1] == 'l')
       lidar_cnt++;
     if(type[1] == 'r')
       radar_cnt++;
  }
  else{
     if(type[0] == 'g')
       gps_cnt++;
     if(type[0] == 'c')
       camera_cnt++;
     if(type[0] == 'l')
       lidar_cnt++;
     if(type[0] == 'r')
       radar_cnt++;
   }

}
/*

  Function: GetGPSCount
  Parameters: Nothing
  Purpose: Returns the value of gps_cnt
  Returns: an int, gps_cnt
  
*/
int CarSensor::GetGPSCount(){
   return gps_cnt;
}
/*

  Function: GetCameraCount
  Parameters: Nothing
  Purpose: Returns the value of camera_cnt
  Returns: an int, camera_cnt
  
*/
int CarSensor::GetCameraCount(){
   return camera_cnt;
}
/*

  Function: GetLidarCount
  Parameters: Nothing
  Purpose: Returns the value of lidar_cnt
  Returns: an int, lidar_cnt
  
*/
int CarSensor::GetLidarCount(){
   return lidar_cnt;
}
/*

  Function: GetRadarCount
  Parameters: Nothing
  Purpose: Returns the value of radar_cnt
  Returns: an int, radar_cnt
  
*/
int CarSensor::GetRadarCount(){
   return radar_cnt;
}
/*

  Function: ResetGPSCount
  Parameters: Nothing
  Purpose: Resets the value of gps_cnt
  Returns: Nothing
  
*/
void CarSensor::ResetGPSCount(){
  gps_cnt = 0;
}
/*

  Function: ResetCameraCount
  Parameters: Nothing
  Purpose: Resets the value of camera_cnt
  Returns: Nothing
  
*/
void CarSensor::ResetCameraCount(){
  camera_cnt = 0;
}
/*

  Function: ResetLidarCount
  Parameters: Nothing
  Purpose: Resets the value of lidar_cnt
  Returns: Nothing
  
*/
void CarSensor::ResetLidarCount(){
  lidar_cnt = 0;
}
/*

  Function: ResetRadarCount
  Parameters: Nothing
  Purpose: Resets the value of radar_cnt
  Returns: Nothing
  
*/
void CarSensor::ResetRadarCount(){
  radar_cnt = 0;
}
/*

  Function: SetExtraCost
  Parameters: a string, the type of sensor
  Purpose: Sets the value of m_extracost based on the sensor
  Returns: Nothing
  
*/
void CarSensor::SetExtraCost(char * type){

  if(type[0] == '{'){
     if(type[1] == 'g')
       m_extracost = 5;
     if(type[1] == 'c')
       m_extracost = 10;
     if(type[1] == 'l')
       m_extracost = 15;
     if(type[1] == 'r')
       m_extracost = 20;
  }
  else{
     if(type[0] == 'g')
       m_extracost = 5;
     if(type[0] == 'c')
       m_extracost = 10;
     if(type[0] == 'l')
       m_extracost = 15;
     if(type[0] == 'r')
       m_extracost = 20;
  }

}
/*

  Function: GetExtraCost
  Parameters: Nothing
  Purpose: Returns the value of m_extracost
  Returns: a float, the value of m_extracost 
  
*/
float CarSensor::GetExtraCost(){
    return m_extracost;
}
/*

  Function: UpdatePrice
  Parameters: two floats, the base price and the price of the sensors
  Purpose: Calculates and returns the value of m_finalprice
  Returns: a float,the value of m_finalprice
  
*/
void RentalCar::UpdatePrice(float base, float sensorcost){
 
  m_finalprice = base + sensorcost;
    

}
/*

  Function: GetFinalPrice
  Parameters: Nothing
  Purpose: Returns the value of m_finalprice
  Returns: a float, the value of m_finalprice 
  
*/
float RentalCar::GetFinalPrice(){
 
   return m_finalprice;
    
}

/*

  Function: Print
  Parameters: Nothing
  Purpose:Prints the values of the info from the user inputted file
  Returns: Nothing
  
*/
void RentalCar::Print()
{
  int test;
  cout << GetYear() << " ";
  cout << GetMake() << " ";
  cout << GetModel() << " ";
  cout << GetTank() << " Gallons $";
  cout << GetBasePrice() << " per day Sensors: ";
  cout << m_sensor[0].GetType() << " ";
  test = stringCompare(m_sensor[0].GetType());
  if(test == 0){
  cout << m_sensor[1].GetType() << " ";
    if(stringCompare(m_sensor[1].GetType()) == 0){
    cout << m_sensor[2].GetType() << " ";
  }
  }
  cout << "(Total price including sensors: $" << GetFinalPrice() << ") ";
  cout << "Available: ";
  cout << boolalpha << GetAvailability() << " ";
  if(GetAvailability() == 0){
  cout << "Owner: ";
  cout << GetOwner() << " ";
  }
  
  cout << endl;

}
/*

  Function: stringCompare
  Parameters: a string
  Purpose: Checks if the string ends with a '}', and outputs a value based on that
  Returns: an int based on if the test passed or not
  
*/
int stringCompare(char * string)
{
   for(int i = 0; i < 8; i++){
    if(string[i] == '}'){
     return 1;
    }
   }
   return 0;
}