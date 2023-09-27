#include <iostream>
#include <ostream>
#include <ratio>

#include "../inc/titleRating.hh"
#include "../inc/priorityQueue.hh"

int main(int argc, char* argv[])
{
    priorityQueue<titleRating, int> priority;

    priority.read(argv[1]);
    priority.buildMaxHeap();
    
    return 0;
}