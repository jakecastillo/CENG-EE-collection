#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Here is a C++-version of an enumerated type.
enum class EmployeeType : int {
    EMPLOYEE = 0,
    TEMP_EMPLOYEE = 1,
    CONTRACTOR = 2
};

class Employee { std::string name;

public:
    Employee(std::string name_) :
        name(name_) {}

    // The destructor is virtual so that when we call
    // delete for each element in the vector in main(),
    // it will call the correct destructor on the underlying
    // object's class instead of ~Employee() every time.
    virtual ~Employee() {} 

    std::string get_name() const { return this->name; }

    virtual EmployeeType get_type() const {
        return EmployeeType::EMPLOYEE;
    };
};

class TempEmployee : public Employee {
public:
    TempEmployee(std::string name_) :
        Employee(name_) {} 

    virtual ~TempEmployee() {}

    virtual EmployeeType get_type() const {
        return EmployeeType::TEMP_EMPLOYEE;
    }
};

class Contractor : public Employee {
public:
    Contractor(std::string name_) :
        Employee(name_) {}

    virtual ~Contractor() {}

    virtual EmployeeType get_type() const {
        return EmployeeType::CONTRACTOR;
    }
};

int main() {
    std::vector<Employee*> employees;
   
    employees.emplace_back(new Employee("Jane Austen"));
    employees.emplace_back(new Contractor("Andrew Schong"));
    employees.emplace_back(new TempEmployee("John Doe"));

    for (int i = 0; i < 3; ++i) {
        std::cout << static_cast<int>(employees[i]->get_type())
                  << std::endl;
    }

    assert(employees[0]->get_type() == EmployeeType::EMPLOYEE &&
           "This is surprising -- "
           "your get_type() on Employee is not working?");
    assert(employees[1]->get_type() == EmployeeType::CONTRACTOR &&
           "With a virtual function, you should not be still calling "
           "Employee.get_type() when the underlying type is Contractor.");
    assert(employees[2]->get_type() == EmployeeType::TEMP_EMPLOYEE &&
           "You should be calling TempEmployee.get_type() polymorphically, "
           "by applying the virtual keyword to the member functions.");

    for (int i = 0; i < employees.size(); ++i) {
        delete employees[i];
    }

    std::cout << "SUCCESS" << std::endl;
}
