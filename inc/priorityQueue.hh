#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include "heap.hh"
#include <iostream>

/*!
    \brief Implementation of priority queue.

    \par Implementation will be based on heap data structure. Template definition
    is included from "heap.hh" header file.

    Public inheritance: derived class would have access to public members
*/
template <typename storedElement, typename key>
class priorityQueue: public heap<storedElement, key>{

    public:

    /*!
        \brief heapMaximum - method returning the max element of priority queue.
    */
    storedElement& heapMaximum () { return (*this)[0]; }

    storedElement* heapExtractMax ();

    int insert( storedElement newElement );

};

template <typename storedElement, typename key>
storedElement* priorityQueue<storedElement,key>::heapExtractMax()
{
    try {
        if ( heap<storedElement,key>::getRecordsNumber() < 1)
            throw false;
    } catch ( bool exception) {
        std::cerr << "Error: Empty heap" << std::endl;
        exit(1);
    }

    /* Get max element */
    storedElement* maxElement = (*this)[0];

    /* If an element was accessed with use of operator, then it was not lvalue */
    this->getElementsCollection()[0] = this->operator[](this->getRecordsNumber()-1);

    this->lessRecordsNumber();
    this->maxHeapify(0);

    return maxElement;
}

#endif