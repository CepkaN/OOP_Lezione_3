#include<iostream>
#include<string>
#include<vector>

class Person {            // класс родитель
protected:
	std::string name;
	int age;
public:
	Person(std::string name, int age) {
		this->name = name;             //   обращение к name из protected.
		this->age = age;
	}
	virtual void ShowData() = 0;  // классы наследники должны переписать эту функцию под себя. Создание перегруженной функции.
	/*void ShowData(){
		std::cout << "Name : " << name << '\n';
		std::cout << "Age : " << age << '\n';
	};*/
};

class Student :public Person {    // наследование
	//private:                      //  это не нужно
	//	std::string _name;
	//	int _age;
private:
	std::vector<int>_marks;
public:
	Student(std::string name, int age, std::vector<int>& marks) :Person(name, age) {   // обращение по ссылке быстрее
		_marks = marks;
	}

	void ShowData()override {       // override указывает на то, что мы переписываем функцию у класса родителя.
		std::cout << "name : " << name << '\n';
		std::cout << "age : " << age << '\n';
		std::cout << "marks : ";
		for (const auto& it : _marks)
			std::cout << it << ", ";
		std::cout << "\b\b \n";
	}
};

class Professor :public Person {  // класс наследник
	//private:
	//	std::string _name;
	//	int _age;
private:
	std::string _degree;
public:
	Professor(std::string name, int age, std::string degree) : Person(name, age) {
		_degree = degree;
	}
	void ShowData() {
		std::cout << "Name : " << name << '\n';
		std::cout << "Age : " << age << '\n';
		std::cout << "Degree : " << _degree << '\n';
	}
};

class Worker {
protected:     // private тоже здесь работает.
	std::string _name;
	int _age;
	float _bill;
public:
	Worker(std::string name, int age) :_name(name), _age(age), _bill(0) {}
	//{
	//	_name = name;
	//	_age = age;
	//	_bill = bill;
	//}
	virtual void Work() = 0;   // чистая виртуальная функция

	void Bill(int hoursofWork) {
		_bill = 250.0f * hoursofWork;
		std::cout << "Bill : " << _bill << '\n';
	}
	std::string GetName() {
		return _name;
	}
	int GetAge() {
		return _age;
	}
	float GetBill() {
		return _bill;
	}
};
class Buyer :public Worker {
public:
	Buyer(std::string name, int age) :Worker(name, age) {}

	void Work()override {
		std::cout << GetName() << " - " << GetAge() << " лет : ";
		std::cout << "Покупает что-то.\n";
	}
};
class Builder :public Worker {
public:
	Builder(std::string name, int age) :Worker(name, age) {}

	void Work()override {
		std::cout << GetName() << " - " << GetAge() << " лет : ";
		std::cout << "Строит что-то.\n";
	}
};

class Abonent {
	char* FIO;
	Abonent() {
		FIO = new char[10];
	}
	~Abonent() {
		delete[]FIO;
	}
};

void Foo1(int a) {   // никак не отразится на а, это копия
	a = 1;
}
void Foo2(int* a) {  // обращаемя к оригиналу
	*a = 2;
}
void Foo3(int& a) {
	a = 3;
}
void Foo11(std::vector<int>v) {   // Нельзя для STL

}
void Foo12(std::vector<int>* v) {

}
void Foo13(std::vector<int>& v) {

}
int main() {
	setlocale(LC_ALL, "Russian");

	// НАСЛЕДОВАНИЕ
	// Задание 1.
	/*std::vector<int>marks = { 12,5,6,7,4,11 };
	Student student("Jhon",20,marks);
	Professor professor("Alex",18,"Bakalavr");
	std::cout << "Student : \n";
	student.ShowData();
	std::cout << "\nProfessor : \n";
	professor.ShowData();*/

	// Задание 2.
	Buyer buy("Jhon", 25);
	Builder build("Alex", 32);
	buy.Work();
	buy.Bill(20);
	std::cout << '\n';
	build.Work();
	build.Bill(30);


	// Задачки.
	int a = 10;
	std::cout << "Before foo: " << a << '\n';  //10
	Foo1(a);
	std::cout << "After foo1: " << a << '\n';  //10
	Foo2(&a);
	std::cout << "After foo2: " << a << '\n';  //2
	Foo3(a);
	std::cout << "After foo3: " << a << '\n';   //3 

	std::cout << '\n';



	return 0;
}