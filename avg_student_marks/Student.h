#include <iostream>

using namespace std;

class Student {

    private:
        string _name;
        float _grade;

    public:
        Student();
        Student(string name, float grade);
        string getName();
        float getGrade();
};
