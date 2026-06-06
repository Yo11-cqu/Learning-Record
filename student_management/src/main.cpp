#include<Student.h>
#include<StudentManager.h>
#include<iostream>
using namespace std;


void menu()
{
	cout << "\n=====学生管理系统=====" << endl;
	cout << "1. 添加学生" << endl;
	cout << "2. 显示所有学生" << endl;
	cout << "3. 按学号查找" << endl;
	cout << "4. 计算平均分" << endl;
	cout << "5. 退出" << endl;
	cout << "请输入选择：";
}

int main() {
	System stuSys;   
	int choice = 0;

	while (true)
	{
		menu();
if (!(cin >> choice))
{
    cout << "请输入数字！" << endl;
    cin.clear();              
    cin.ignore(10000, '\n'); 
    continue;
}
		switch (choice)
		{
		case 1: {
			int id, age;
			string name;
			int sc[3];
			cout << "输入学号 姓名 年龄 语文 数学 英语：" << endl;
			if (!(cin >> id >> name >> age
          >> sc[0] >> sc[1] >> sc[2]))
		  {
            cout << "输入格式错误，请重新输入！" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
          }
			Student s(id, name, age, sc);
			stuSys.add_student(s);
			cout << "添加成功！" << endl;
			break;
		}
		case 2:
			stuSys.show_student();
			break;
        case 3: {
            int id;
            cout << "输入要查找的学号：";
            if (!(cin >> id))
            {
                cout << "学号必须是数字！" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            continue;
            }
        stuSys.find_student(id);
            break;
        }
		case 4:
			stuSys.average_scores();
			break;
		case 5:
			cout << "退出系统" << endl;
			return 0;
		default:
			cout << "输入错误，请重新选择！" << endl;
			break;
		}
	}
	return 0;
}