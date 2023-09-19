#include <iostream>
#include <ostream>

#include "../inc/titleRatingCollection.hh"

int main(int argc, char* argv[])
{
    titleRatingCollection newCollection;

    newCollection.read(argv[1]);


    int a = 15;
    int b = 2;
    
    std::cout << "Tusk: " << a/b << std::endl;

    std::ofstream output(argv[2]);

   output << "Before max Heapify: " << std::endl;
    newCollection.print(output);

    newCollection.heapsort();

    output << "Records number: " << newCollection.getRecordsNumber() << std::endl;
    output << "After max Heapify: " << std::endl;
    newCollection.print(output);
    
    return 0;
}