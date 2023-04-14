#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Type
{
	HUD, TECH
};

//Класс книги
class Book {
public:

	Book (const string& _avtor, const string& _nazvanie, Type _type) : avtor(_avtor), nazvanie(_nazvanie), type(_type) {
	}

    //Метод забора типа книги
	Type getType() const{
		return type;
	}

    //Деструктор
	~Book() {
	}

private:
	const string avtor;
	const string nazvanie;
	const Type type;
};

//Класс библиотеки
class Library {
public:

    //Добавление и чек книг
    void addBook(const string& _avtor, const string& _nazvanie, Type _type) {
        if ((_avtor == "") || (_nazvanie == "")) {
            cout << "Книга не найдена" << endl;
        }
        else {
            Libary.push_back(new Book(_avtor, _nazvanie, _type));
        }

    }

    //Первый метод через case
    void ReturningTypel() {
        int hud = 0;
        int tech = 0;
        for (const Book* book : Libary) {
            switch (book->getType()) {
            case Type::HUD:
                ++hud;
                break;
            case Type::TECH:
                ++tech;
            }
        }
        cout << hud << " " << tech << endl;
    }

    //Второй через цикл
    void ReturningType2() {
        int hud = 0;
        int tech = 0;
        for (const Book* book : Libary) {
            if (book->getType() == Type::HUD) {
                hud++;
            }
            else
            {
                tech++;
            }
        }
        cout << hud << " " << tech << endl;
    }

    //Деструктор
    ~Library() {
        for (int i = 0; i < size(Libary); ++i) {
            delete Libary[i];
        }
    }

private:
    vector<Book*> Libary;
};


int main() {
	setlocale(LC_ALL, "ru");

    Library LBook;
    LBook.addBook("Gogol", "Myortvie Dushi", Type::HUD);
    LBook.addBook("Trahtenberg", "Luchshie anekdoti", Type::HUD);
    LBook.addBook("Vefield", "OOP", Type::TECH);
    //LBook.addBook("", "", Type::TECH);

	//std::vector <Book> Libary;

	//Libary.push_back(Knigal);
	//Libary.push_back(Kniga2);
	//Libary.push_back(Kniga3);
	//Libary.push_back(Kniga4);

	LBook.ReturningTypel();

	cout << endl;

	LBook.ReturningType2();

	return 0;
}