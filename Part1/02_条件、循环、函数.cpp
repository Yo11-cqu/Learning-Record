#include<iostream>
#include<cstdio>
using namespace std;
bool check(int score){
    return score >= 60;
}
int count_passed(int student_scores[3]){
    int times=0;
    for(int i =0;i<3;i++){
        if (check(student_scores[i])){
            times+=1;
            printf("第%d名：%d分，及格\n",i+1,student_scores[i]);
        }
        else{
            printf("第%d名：%d分，不及格\n",i+1,student_scores[i]);
        }
    }
    return times;
}
int main(){
    int student_scores[3];
    for(int i=0;i<3;i++){
        cout<<"请输入学生的分数"<<endl;
        int score;
        while(1){
            if(!(cin>>score)){
                 cout<<"请输入数字"<<endl;
                 cin.clear();              
                 cin.ignore(10000, '\n'); 
                 continue;
            }
            if(score<=100&&score>=0){
            student_scores[i]=score;
            cout<<"输入成功"<<endl;
            break;
            }
            else{
                cout<<"输入数值不合理，请输入正确的分数"<<endl;
            }
        }
    }
    int times = count_passed(student_scores);
    printf("3名学生中，及格人数为：%d人",times);
    return 0;
}