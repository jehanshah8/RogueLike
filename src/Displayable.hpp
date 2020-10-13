#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

class Displayable {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Displayable();

    // Methods
    void setInvisible();
    void setVisible();
    void setMaxHit(int maxHit);
    void setHpMove(int hpMoves);
    void setHp(int hp);
    void setType(char type);
    void setIntValue(int value);
    void setPosX(int x);
    void setPosY(int y);
    void setWidth(int width);
    void setHeight(int height);

    // Operators

    // Destructor
};

#endif /* DISPLAYABLE_H_ */