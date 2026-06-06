#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student{
public:
    int ID;
    std::string name;
    int age;
    int scores[3];
    Student(int my_ID,std::string my_name,int my_age,int my_scores[3]);
};

#endif