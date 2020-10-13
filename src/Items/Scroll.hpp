#ifndef SCROLL_H_
#define SCROLL_H_

#include "Item.hpp"

class Scroll : public Item {
    private:
    // Fields

    // Methods

    public:
    // Constructors
    Scroll(std::string name);

    // Methods
    void setID(int room, int serial);
    
    // Operators

    // Destructor
};

#endif /* SCROLL_H_ */
