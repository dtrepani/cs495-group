#include "Vector.h"

Vector::Vector(float anX, float aY, float aZ) { x = anX; y = aY; z = aZ; }

Vector::~Vector(void) {}

// Determine the distance between two entities.
// Only an entity's position should be passed in.
float Vector::distanceTo(Vector* otherEntity) {
	return sqrt( pow((otherEntity->getX()-x), 2) + pow((otherEntity->getY()-y), 2) + pow((otherEntity->getZ()-z), 2) );
}

bool Vector::equalsWithError(Vector* other, float errorThreshold) {
	return ( (abs(x - other->getX()) <= errorThreshold) && (abs(y - other->getY()) <= errorThreshold) && (abs(z - other->getZ()) <= errorThreshold) );
}

// Zeroes out the vector
void Vector::zero() { x = 0; y = 0; z = 0; }

// Various vector math
float Vector::dotProduct(Vector* other) { return (x * other->getX() + y * other->getY() + z * other->getZ()); }

Vector* Vector::add(Vector* other) { return new Vector(x + other->getX(), y + other->getY(), z + other->getZ()); }
Vector* Vector::subtract(Vector* other) { return new Vector(x - other->getX(), y - other->getY(), z - other->getZ()); }
Vector* Vector::scalarMultiply(float scalar) {	return new Vector(scalar*x, scalar*y, scalar*z); }

Vector* Vector::normalize() {
    float magnitude = sqrt(dotProduct(this));
 
    if (magnitude != 0) {
		return new Vector(x/magnitude, y/magnitude, z/magnitude);
    }

	return new Vector(0, 0, 0);
}

Vector* Vector::crossProduct(Vector* other) {
	return new Vector(	  y*other->getZ() - z*other->getY(),
						  z*other->getX() - x*other->getZ(),
						  x*other->getY() - y*other->getX() );
	
}

// Increment the values. Used for fluid movement.
void Vector::incrementX(float anX) { x += anX; }
void Vector::incrementY(float aY) { y += aY; }
void Vector::incrementZ(float aZ) { z += aZ; }

float Vector::getX() { return x; }
float Vector::getY() { return y; }
float Vector::getZ() { return z; }
void Vector::setX(float anX) { x = anX; }
void Vector::setY(float aY) { y = aY; }
void Vector::setZ(float aZ) { z = aZ; }
