#ifndef GRID_CHAR_H_
#define GRID_CHAR_H_

class GridChar
{
private:
	// Fields
	char displayCode;

	// Methods
public:
	// Constructors
	GridChar(char displayCode);

	// Methods
	virtual const char getDisplayCode() const;
	virtual void setDisplayCode(char displayCode);

	// Operators

	// Destructor
};
#endif /* GRID_CHAR_H_ */
