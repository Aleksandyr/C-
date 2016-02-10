#include "Student.h"

Student::Student(){
}

Student::Student(string name, float grade){
    _name = name;
    _grade = grade;
}

string Student::getName(){
    return _name;
}

float Student::getGrade(){
    return _grade;
}
