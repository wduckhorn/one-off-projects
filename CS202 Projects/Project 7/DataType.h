#ifndef DATATYPE_H
#define DATATYPE_H
//Header file for the DataType class
#include <ostream>

class DataType{

  public:
    DataType();
    DataType(int intVal, double doubleVal);

    bool operator==(const DataType& other_dataType) const;
    DataType& operator= (const DataType& other_dataType);
    int GetIntVal();
    double GetDoubleVal();
friend std::ostream& operator<<(std::ostream& os, const DataType& dataType);

  private:
	int m_intVal;
	double m_doubleVal;
};

#endif