#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H

#include "Student.h"
#include <vector>

class System{
    public:
    std::vector<Student>v;
    void add_student(Student s);
    void show_student();
    void find_student(int num);
    void average_scores();
};

#endif