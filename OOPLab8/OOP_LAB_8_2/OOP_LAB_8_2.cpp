#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    // Gatterer for age
    int getAge()
    {
        return age;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Car
{
private:
    string model;
    int yearsOld; // Age of the car

public:
    Car(string model, int yearsOld)
    {
        this->model = model;
        this->yearsOld = yearsOld;
    }

    // Gatterer for age (vehicle age)
    int getAge()
    {
        return yearsOld;
    }

    void display()
    {
        cout << "Model: " << model << ", Years Old: " << yearsOld << endl;
    }
};

template <typename T>
class AverageCalculator
{
public:
    static double computeAverageAge(vector<T>& list)
    {
        if (list.empty())
            return 0.0;

        int totalAge = 0;

        for (T& item : list)
            totalAge += item.getAge();

        return (double)totalAge / list.size();
    }
};

int main()
{
    // List of Persons
    vector<Person> persons = {
        Person("Elena", 30),
        Person("Tudor", 25),
        Person("Carlito", 35) };

    // List of Cars
    vector<Car> cars = {
        Car("Toyota", 5),
        Car("Tesla", 3),
        Car("Dacia", 10) };

    // Compute and display average age for persons
    cout << "Persons in the list:" << endl;

    for (Person& person : persons)
        person.display();

    double avgPersonAge = AverageCalculator<Person>::computeAverageAge(persons);
    cout << "Average Age of Persons: " << avgPersonAge << endl;

    // Compute and display average age for cars
    cout << "\nCars in the list:" << endl;
    for (Car& car : cars)
        car.display();

    double avgCarAge = AverageCalculator<Car>::computeAverageAge(cars);
    cout << "Average Age of Cars: " << avgCarAge << endl;

    return 0;
}
