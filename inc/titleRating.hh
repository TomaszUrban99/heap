#ifndef TITLE_RATING_HH
#define TITLE_RATING_HH

#include <istream>
#include <ostream>
#include <string>
#include <iostream>
#include <fstream>

class titleRating {
    
    /* Alphanumeric unique identifier */
    std::string _tconst;

    /* Weighted average of all the individual user ratings */
    float _averageRating;

    /* Number of votes the title has received */
    int _numVotes;

    public:

    titleRating() {}

    ~titleRating() {
    }

    std::string& get_tconst () { return _tconst; }

    float& get_averageRating () { return _averageRating; }

    int& get_numVotes () { return _numVotes; }

};

/*!
    \brief Input operator overloading 
*/
std::istream& operator>>( std::istream& input, titleRating& newRecord );

/*!
    \brief Output operator overloading
*/
std::ostream& operator<<( std::ostream& output, titleRating& recordToWrite );

#endif