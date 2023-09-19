#include "../inc/titleRating.hh"
#include <ostream>

std::istream& operator>>( std::istream& input, titleRating& newRecord )
{
    input >> newRecord.get_tconst();
    
    if (input.fail())
        return input;

    input >> newRecord.get_averageRating();

    if (input.fail())
        return input;

    input >> newRecord.get_numVotes();

    if (input.fail())
        return input;

    return input;
}

std::ostream& operator<<( std::ostream& output, titleRating& recordToWrite )
{
    output  << recordToWrite.get_tconst() << " " 
            << recordToWrite.get_averageRating() << " " 
            << recordToWrite.get_numVotes();

    return output;
}