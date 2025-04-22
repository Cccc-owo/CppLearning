#ifndef CAR_H
#define CAR_H

#include "Automobile.h"

class Car : public Automobile {
public:
	Car(string id, string type);
	int pay() const override;
private:
	string type;
};

#endif //CAR_H
