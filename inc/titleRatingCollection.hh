#ifndef TITLE_RATING_COLLECTION_HH
#define TITLE_RATING_COLLECTION_HH

#include <cstddef>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm> // contains swap function

#include "titleRating.hh"

constexpr int initialSize = 1000;

/*!
    \brief Class titleRatingCollection representing a collection
    of pointers to object of class titleRating.
*/
class titleRatingCollection{

    titleRating** _titleRatingCollection;
    
    /* Number of records being stored in a collection of title ratings */
    int _recordsNumber = 0;

    /* Total amount of fields allocated for vector _titleRatingCollection */
    int _vectorSize = initialSize;

    /*!
        \brief Method for adding new memory to _titleRatingCollection.
        \retval int _vectorSize - size of vector after reallocating memory
    */
    int reallocate();

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

    public:

    void maxHeapify ( int i );

    void buildMaxHeap ();

    void heapsort();

    titleRatingCollection() {
        _titleRatingCollection = new titleRating*[initialSize];
    }

    ~titleRatingCollection() {
        
        for ( int i = 0; i < _recordsNumber; ++i )
            delete _titleRatingCollection[i];

        delete [] _titleRatingCollection;
    }

    int getRecordsNumber () { return _recordsNumber; }

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

#endif