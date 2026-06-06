#include "StudentManager.h"
#include <iostream>
#include <cstdio>


void System::add_student(Student s){
    v.push_back(s);
}

void System::show_student(){
	for (int n = 0; n < v.size(); n++) {
		printf("%d,%s,%d,语文成绩是%d,数学成绩是%d,英语成绩是%d\n",
			v[n].ID, v[n].name.c_str(), v[n].age,
			v[n].scores[0], v[n].scores[1], v[n].scores[2]);
	}
}

void System::find_student(int num){
    for (int n = 0; n < v.size(); n++) {
	    if (v[n].ID == num) {
		    printf("%d,%s,%d,语文成绩是%d,数学成绩是%d,英语成绩是%d\n",
			    v[n].ID, v[n].name.c_str(), v[n].age,
			    v[n].scores[0], v[n].scores[1], v[n].scores[2]);
		    return;
	    }
    }
    std::cout << "查无此人" << std::endl;
}

void System::average_scores(){
    if (v.size() == 0) {
	std::cout << "暂无学生数据" << std::endl;
	return;
    }  
    for (int n = 0; n < v.size(); n++) {
        int all = 0;
	    all += (v[n].scores[0] + v[n].scores[1] + v[n].scores[2]);
        double avg = all / 3.0;
        std::cout <<v[n].name<< "的科目平均分：" << avg << std::endl;
    }
}