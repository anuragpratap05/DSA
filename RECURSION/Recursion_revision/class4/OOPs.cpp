#include <bits/stdc++.h>
using namespace std;

class AbstractEmployee
{

    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{
protected:
    string name;

private:
    string company;
    int age;

public:
    Employee(string name, string company, int age)
    {
        this->name = name;
        this->company = company;
        this->age = age;
    }
    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }
    void Display()
    {
        cout << "Name->" << this->name << endl
             << "Company->" << this->company << endl
             << "Age->" << this->age << endl;
    }
    void AskForPromotion()
    {
        if (this->age > 30)
        {
            cout << this->name << " got promoted!!" << endl;
        }
        else
        {
            cout << this->name << " sorry not promoted" << endl;
        }
    }
    virtual void doWork()
    {
        cout << this->name << " is driving truck, and unloading baggages" << endl;
    }
};

class Developer : public Employee
{
public:
    string favLang;
    Developer(string name, string company, int age, string favLang)
        : Employee(name, company, age)
    {
        this->favLang = favLang;
    }
    void Display()
    {
        cout << "name->" << this->name << endl
             << "favLang->" << favLang << endl;
    }
    void doWork()
    {
        cout << this->name << " is writing code in " << this->favLang << endl;
    }
};

class Teacher : public Employee
{
public:
    string subject;
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        this->subject = subject;
    }

    void PrepareLesson()
    {
        cout << this->name << " is preparing lesson for " << this->subject << endl;
    }
    void doWork()
    {
        cout << this->name << " is teaching students " << this->subject << endl;
    }
};

int main()
{

    Developer d = Developer("Manmohan", "Sapient", 32, "C++");
    Teacher t = Teacher("Suman", "Awadh Collegiate", 55, "Sanskrit ");

    Employee *e1 = &d;
    Employee *e2 = &t;
    e1->doWork();
    e2->doWork();

    return 0;
}