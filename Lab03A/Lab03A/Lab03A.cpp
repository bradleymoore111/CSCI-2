#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name;
	string address;
	int age;
	int phoneNumber;
public:
	Person::Person(string a, string b, int c, int d) {
		name = a;
		address = b;
		age = c;
		phoneNumber = d;
	}
	Person::Person() {
		name = "";
		address = "";
		age = 0;
		phoneNumber = 0;
	}

	void Person::setName(string s) {
		name = s;
	}
	void Person::setAddress(string s) {
		address = s;
	}
	void Person::setAge(int n) {
		age = n;
	}
	void Person::setPhoneNumber(int n) {
		phoneNumber = n;
	}

	string Person::getName() const {
		return name;
	}
	string Person::getAddress() const {
		return address;
	}
	int Person::getAge() const {
		return age;
	}
	int Person::getPhoneNumber() const {
		return phoneNumber;
	}
};

int main() {
	// Person one, two, thr;

	Person one(); // Default person
	//one.setName("I won't");
	Person two("Bradley G.", "757 Lomita St.", 18, 858);
	Person thr();
	thr.setName("Ay Jay the Jet Plane");
	thr.setAddress("Space");
	thr.setAge(12);
	thr.setPhoneNumber(1210);

	cout << "We have three people:" << endl;
	cout << "\t" << one.getName() << ", who lives at " << one.getAddress() << ", is " << one.getAge() << " years old, and can be contacted at " << one.getPhoneNumber() << endl;
	cout << "\t" << two.getName() << ", who lives at " << two.getAddress() << ", is " << two.getAge() << " years old, and can be contacted at " << two.getPhoneNumber() << endl;
	cout << "\t" << thr.getName() << ", who lives at " << thr.getAddress() << ", is " << thr.getAge() << " years old, and can be contacted at " << thr.getPhoneNumber() << endl;
	return 0;
}