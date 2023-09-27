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
    

    priority.print(std::cout);

    priority.heapIncreaseKey(7, 8);

    std::cout << "After increasing key: " << std::endl;
    priority.print(std::cout);

    return 0;
}