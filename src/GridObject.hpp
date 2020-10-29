#ifndef GRID_OBJECT_H_
#define GRID_OBJECT_H_

class GridObject
{
private:
	// Fields
	char displayCode;

	// Methods
public:
	// Constructors
	GridObject(char displayCode);

	// Methods
	virtual const char getDisplayCode() const;
	virtual void setDisplayCode(char displayCode);

	// Operators

	// Destructor
};
#endif /* GRID_OBJECT_H_ */
