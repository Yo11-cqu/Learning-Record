#include "Student.h"

Student::Student(int my_ID, std::string my_name, int my_age, int my_scores[3])
	:ID(my_ID), name(my_name), age(my_age)
{
	for (int n = 0; n < 3; n++) {
		scores[n] = my_scores[n];
	}
}
