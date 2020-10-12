#ifndef PASSAGE_H_
#define PASSAGE_H_

#include "Structure.hpp"

class Passage : public Structure {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Passage();

    // Methods
    void setName(std::string name);
    void setID(int room1, int room2);
    
    // Operators

    // Destructor
};

#endif /* PASSAGE_H_ */