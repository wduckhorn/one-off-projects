#ifndef NODELIST_H
#define NODELIST_H

#include "DataType.h"
//Header File for the NodeList and Node class
class Node{
  public:
    Node(){
		m_next = NULL;
		//m_data = m_data(0,0.0);			//unnecessary, DataType has default ctor that 0-initializes
	}
	Node(const DataType& data, Node* next = NULL){
		m_next = next;
		m_data = data;					//uses DataType's assignment operator=
	}
	void setData(const DataType& data){
          m_data = data;

        }
	void setNext(Node * next){
          m_next = next;

        }
    	DataType& getData(){					//gets non-const reference, can be used to modify value of underlying data
        	//return const_cast<DataType&>(static_cast<const Node&>(*this).getData());  //an alternative implementation, for reference
		return m_data;
    	}
    	const DataType& getData() const{ 			//gets const reference, can be used to access value of underlying data
        	return m_data;
    	}
	Node* GetNext(){
	return m_next;
	}
  friend class NodeList;					//allows accessing of link(s) and data from NodeList (link remains otherwise inaccessible outside of Node)

  private:
    Node* m_next; 						//the link to next node
    DataType m_data;						//the actual data
};

class NodeList{
  public:
    NodeList();							//(1)
    NodeList(int size, const DataType& value);			//(2)
    NodeList(const NodeList& other);				//(3)
    ~NodeList();						//(4)

    NodeList& operator= (const NodeList& other_nodeList);	//(5)
    friend std::ostream& operator<<(std::ostream& os,		//(6)
				    const NodeList& nodeList); 

    DataType first();						//(7a)
    const DataType* first() const;			      	//(7b)
	
    DataType last();					       	//(8a)
    const DataType* last() const;			    	//(8b)
	
    DataType find(const DataType& target);
    const DataType* find(const DataType& target,		//(9b)
			 const Node* previous,
			 const Node* const start = NULL) const;	
	
    DataType insertAfter(const DataType& target,               	//(10)
                      const DataType& value);	    
    DataType insertBefore(const DataType& target,              	//(11)
                       const DataType& value);
    
    DataType removeForward(const DataType& target);   
    DataType removeBackward(const DataType& target);   
	
    DataType& operator[] (int position);			//(14a)
    const DataType& operator[] (int position) const;		//(14b)
    
    int size() const;						//(15)
    bool empty() const;						//(16)
    void clear();						//(17)	

  private:

    Node *m_head;
    int m_size;
};

#endif