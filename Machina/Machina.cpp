#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Родительский класс
class Car {

public:
	Car(const string& _company, const string& _model) : company(_company), model(_model) {}

	virtual ~Car() {
		cout << "Company: " << company << "    " << "Model: " << model << endl;
	}

private:
	const string company;
	const string model;
};

//Классы-дети хд

class Jiguli :public Car {

public:
	Jiguli(const string& model) :Car("Jiguli", model) {}
	~Jiguli() = default;
};

class Tesla : public Car {

public:
	Tesla(const string& model) :Car("Tesla", model) {}
	~Tesla() = default;
};

class Lamb : public Car {

public:
	Lamb(const string& model) : Car("Lamb", model) {}
	~Lamb() = default;
};

class Lada : public Car {

public:
	Lada(const string& model) :Car("Lada", model) {}
	~Lada() = default;
};

class Mazda : public Car {

public:
	Mazda(const string& model) :Car("Mazda", model) {}
	~Mazda() = default;
};

int main() {

	ifstream file("C:\\Users\\Andrew\\Desktop\\Программирование\\Machina\\bebra.txt");

	vector<Car*> Cars;
	string company, model;

	while (file >> company >> model) {
		if (company == "Jiguli") {
			Cars.push_back(new Jiguli(model));
		}
		else if (company == "Tesla") {
			Cars.push_back(new Tesla(model));
		}
		else if (company == "Lamb") {
			Cars.push_back(new Lamb(model));
		}
		else if (company == "Lada") {
			Cars.push_back(new Lada(model));
		}
		else if (company == "Mazda") {
			Cars.push_back(new Mazda(model));
		}
	}

	for (const Car* car : Cars) {
		delete car;
	}
}
