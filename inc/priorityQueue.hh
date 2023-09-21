#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include "heap.hh"

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

    storedElement& heapExtractMax ();

    int insert( storedElement newElement );

};

template <typename storedElement, typename key>
storedElement& priorityQueue<storedElement,key>::heapExtractMax()
{
}

#endif