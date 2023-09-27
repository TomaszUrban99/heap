#ifndef HEAP_HH
#define HEAP_HH

#include <iostream>
#include <algorithm>
#include <fstream>

constexpr int initialSize = 1000;

/*!
    \brief Class templete of heap data structure
    
    \param storedElement - element type stored in data structure
*/
template<typename storedElement, typename key>
class heap{

    storedElement** _elementsCollection;
    
    /* Number of records being stored in a collection of title ratings */
    int _recordsNumber = 0;

    /* Total amount of fields allocated for vector _titleRatingCollection */
    int _vectorSize = initialSize;
    
    /*!
        \brief Method for adding new memory to _titleRatingCollection.
        \retval int _vectorSize - size of vector after reallocating memory
    */
    int reallocate();



    public:
    
    /*!
        \brief Method returning parent's index of node with index i.
    */
    int parent ( int i ){
        return i/2;
    }

    /*!
        \brief Method returning left son's index of node with index i.
    */
    int left ( int i ){
        return 2 * i + 1;
    }

    /*!
        \brief Method returning right son's index of node with index i.
    */
    int right ( int i ){
        return 2 * i + 2;
    }     
    
    heap<storedElement, key>() {
        _elementsCollection = new storedElement*[initialSize];
    }

    virtual ~heap<storedElement, key>() {
        
        for ( int i = 0; i < _recordsNumber; ++i )
            delete _elementsCollection[i];

        delete [] _elementsCollection;
    }

    /* Interface elements */
    storedElement* operator[](int index) { return _elementsCollection[index];}

    storedElement** getElementsCollection () { return _elementsCollection; }

    int getRecordsNumber () const { return _recordsNumber; }
 
    int& getRecordsNumber () { return _recordsNumber; }

    int getVectorSize () const { return _vectorSize; }

    int& getVectorSize () { return _vectorSize; }

    /* Substract one from numbers of records */
    void lessRecordsNumber () {
        _recordsNumber = _recordsNumber - 1;
     }

    void maxHeapify ( int i );

    void buildMaxHeap ();

    void heapsort();

    /*!
        \brief Method for reading data from input file
        \par std::string &filename reference to name input file
        \retval int number of records being read
    */
    int read(char *filename );

    /*!
        \brief Method to print data stored in titleRatingCollection
        \par std::ostream &outputStream- reference to output stream
    */
    void print(std::ostream &outputStream);

};


/* Method for reallocating memory */
template <typename storedElement, typename key>
int heap<storedElement,key>::reallocate()
{
    /* Allocate new memory */
    storedElement** tmpPointer = new storedElement*[_vectorSize + initialSize];
    storedElement** pointer;

    for ( int i = 0; i < _vectorSize; ++i ){
        tmpPointer[i] = _elementsCollection[i];
    }

    _vectorSize = _vectorSize + initialSize;

    pointer = _elementsCollection;
    _elementsCollection = tmpPointer;

    delete [] pointer;

    return _vectorSize;
}

/* */
template <typename storedElement, typename key>
void heap<storedElement,key>::maxHeapify(int i)
{
    key leftValue = left(i);
    key rightValue = right(i);

    int largest = i;

    if ( leftValue < _recordsNumber && 
    _elementsCollection[leftValue]->getKey() > _elementsCollection[largest]->getKey()){
        largest = leftValue;
    }

    if ( rightValue < _recordsNumber && 
    _elementsCollection[rightValue]->getKey() > _elementsCollection[largest]->getKey()){
        largest = rightValue;
    }

    if ( largest != i ){
        std::swap(_elementsCollection[largest], _elementsCollection[i]);
        maxHeapify(largest);
    }
}

/* Build maxHeap method */
template <typename storedElement, typename key>
void heap<storedElement, key>::buildMaxHeap()
{
    for ( int i = _vectorSize/2; i >= 0; --i ){
        maxHeapify(i);
    }
}

/* Read data from file */
template <typename storedElement, typename key>
int heap<storedElement, key>::read(char *filename)
{
    /* Create input handle to the file with given filename */
    std::ifstream input ( filename );
    
    if (input.fail()){
        std::cerr << "Failed to open the file";
        return -1;
    }
    
    /* Omit headers */
    char readCharacter = 'o';
        while ( readCharacter != '\n'){
           input.get(readCharacter);
        }

    /* Read data */
    while (!input.eof())
    { 
        /* Check if there is enough space to store records */
        if ( _recordsNumber >=_vectorSize ){
            reallocate();     
        }

        _elementsCollection[_recordsNumber] = new storedElement (); 
        input >> *_elementsCollection[_recordsNumber];

        if (input.fail() && !input.eof()){
            std::cerr << "Failed to read data" << std::endl;
            return -1;
        }
        else {
          _recordsNumber++;  
        }  
    }

    return _recordsNumber;
}

template<typename StoredElement, typename key>
void heap<StoredElement, key>::print(std::ostream& outputStream)
{
    for ( int i = 0; i < _recordsNumber; ++i ){
        outputStream << *(_elementsCollection[i]) << std::endl;
    }
}

#endif