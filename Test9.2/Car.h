#ifndef CAR_H
#define CAR_H

#include "Automobile.h"

class Car : public Automobile {
public:
	Car(std::string id, std::string type);
	int pay() const;
private:
	std::string type;
	void pay(Park* park) override;
};

#endif //CAR_H
