#include "../inc/titleRatingCollection.hh"
#include <fstream>

void titleRatingCollection::buildMaxHeap ()
{
    for ( int i = _vectorSize/2; i >= 0; --i ){
        maxHeapify(i);
    }
}

void titleRatingCollection::maxHeapify ( int i )
{
    int leftNode = left(i);
    int rightNode = right(i);
    int largest = i;

    if (    leftNode < _recordsNumber && 
            _titleRatingCollection[leftNode]->get_averageRating() > _titleRatingCollection[i]->get_averageRating() ){
                largest = leftNode;        
        }
    
    if ( rightNode < _recordsNumber &&
            _titleRatingCollection[rightNode]->get_averageRating() > _titleRatingCollection[largest]->get_averageRating()){
                largest = rightNode;
        }
    
    if ( largest != i ){
        std::swap(_titleRatingCollection[i], _titleRatingCollection[largest]);
        maxHeapify(largest);
    }
}

void titleRatingCollection::heapsort()
{
    int tmpRecordsNumber = _recordsNumber;

    buildMaxHeap();
    
    for ( int i = tmpRecordsNumber; i > 0; --i ){

        std::swap(_titleRatingCollection[0],_titleRatingCollection[i-1]);
        _recordsNumber--;
        maxHeapify(0);
    }

    _recordsNumber = tmpRecordsNumber;
}

int titleRatingCollection::reallocate()
{
    /* Allocate new memory */
    titleRating** tmpPointer = new titleRating*[_vectorSize + initialSize];
    titleRating** pointer;

    for ( int i = 0; i < _vectorSize; ++i ){
        tmpPointer[i] = _titleRatingCollection[i];
    }

    _vectorSize = _vectorSize + initialSize;

    pointer = _titleRatingCollection;
    _titleRatingCollection = tmpPointer;

    delete [] pointer;
    
    return _vectorSize;
}

int titleRatingCollection::read(char *filename)
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

        _titleRatingCollection[_recordsNumber] = new titleRating (); 
        input >> *_titleRatingCollection[_recordsNumber];

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

void titleRatingCollection::print(std::ostream& outputStream)
{
    for ( int i = 0; i < _recordsNumber; ++i){
        outputStream << *_titleRatingCollection[i] << std::endl;
    }
}
