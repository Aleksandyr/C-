#include <iostream>
#include <fstream>
#include <string.h>
#include "Student.h"
#include <map>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

Student get_value_from_list(list<Student> _list, int _i){
    list<Student>::iterator it = _list.begin();
    for(int i = 0; i < _i; i++){
        ++it;
    }

    return *it;
}

vector<string> get_all_keys_dictionary(map< string, list<Student> > dictionary){
    vector<string> keys;
    map< string, list<Student> >::iterator it;

    for(it = dictionary.begin(); it != dictionary.end(); ++it) {
       keys.push_back(it->first);
    }

    return keys;
}

float get_avg_by_group(map< string, list<Student> > dictionary, string group){

    float sum;
    for(int i = 0; i < dictionary[group].size(); i++){
        Student currStudent = get_value_from_list(dictionary[group], i);
        sum += currStudent.getGrade();
    }

    float averageByGroups = sum / dictionary[group].size();

    return averageByGroups;
}

float get_avg_all_students(map< string, list<Student> > dictionary){
    float sum = 0;
    float studentsCount = 0;

    vector<string> keys = get_all_keys_dictionary(dictionary);
    for(int i = 0; i < keys.size(); i ++){

        string key = keys[i];
        for(int j = 0; j < dictionary[key].size(); j++){
            Student currStudent = get_value_from_list(dictionary[key], j);
            sum += currStudent.getGrade();
            studentsCount++;
        }
    }

    float averageAllStudents = sum / studentsCount;

    return averageAllStudents;
}

int main() {

      size_t pos = 0;
      string line;
      string determin = ": ";
      string key;
      string value;
      map< string, list<Student> > studentsByGroups;

      ifstream myfile ("students.txt");
      if (myfile.is_open()) {

            string name;
            string group;
            string grade;
            while (! myfile.eof()){

                getline (myfile, line);

                key = key.empty();
                value = value.empty();

                while ((pos = line.find(determin)) != string::npos) {
                    key = line.substr(0, pos);
                    value = line.erase(0, pos + determin.length());
                }

                if(key == "name"){
                    name = value;
                }
                if(key == "grade"){
                    grade = value;
                }
                if(key == "group"){
                    group = value;
                }

                if(!name.empty() && !grade.empty()){

                    float gradeToFloat = (float)atof(value.c_str());
                    Student &student = *new Student(name, gradeToFloat);

                    if(!group.empty()){

                        studentsByGroups[group].push_back(student);
                        group = "";
                    }

                    name = "";
                    grade = "";
                }

                cout << endl;

            }

      } else {
          cout << "Unable to open file";
      }

      myfile.close();

      float avgGradeAllStudnets = get_avg_all_students(studentsByGroups);
      float avgGradePerGroup = get_avg_by_group(studentsByGroups, "english");

      printf("Average by group: %.2f\n", avgGradePerGroup);
      printf("All average grades: %.2f\n", avgGradeAllStudnets);

      return 0;
}
