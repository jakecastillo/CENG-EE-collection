#include <iostream>
#include <sstream>
#include <cassert>

// The I here stands for "Inteface."
// 
// This class is meant to be an "interface" that people implement
// if they want to support the "print" functionality.
//
// Therefore, all IPrintable classes should be able to have this
// method because classes that inherit from it won't compile
// unless you implement the overload for it on the derived class.
class IPrintable {
public:
    virtual void print(std::ostream& out) const = 0;
};

class Employee : public IPrintable {
protected:
    std::string name;
public:
    Employee(std::string name_) :
        name(name_) {} 

    virtual void print(std::ostream& out) const override {
        out << "Employee: " << this->name << std::endl; 
    }
};

class Executive : public Employee {
protected:
    std::string job_title;
public:
    Executive(std::string name_, std::string job_title_) :
        Employee(name_),
        job_title(job_title_){}

	virtual void print(std::ostream& out) const override{ 
	out << this->job_title <<": "<< this->name << std::endl;
	}

    // Since Executive inherits from Employee,
    // it will call Employee.print().
    //
    // But we want to create our own Executive.print!
    //
    // Do it! Instead of "Employee: NAME", replace "Employee" with
    // the correct job title of the Executive.
};

int main() {
    std::stringstream ss;

    IPrintable* ceo = new Executive("Joe", "Mr. CEO");
    IPrintable* grunt = new Employee("Bill");

    ceo->print(ss);
    grunt->print(ss);

    std::cout << ss.str() << std::endl;

    assert(ss.str() == "Mr. CEO: Joe\nEmployee: Bill\n" &&
           "Your Executive object is still being called with the Employee "
           "member function, which means you did not provide Executive."
           "print() OR you did Executive.print() wrong."
            );

    std::cout << "SUCCESS" << std::endl;
}
