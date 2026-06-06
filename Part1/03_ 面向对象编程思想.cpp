#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class Book{
public:
    string name;
    string author;
    int pages;
    Book(string my_name,string my_author,int my_pages):name(my_name),author(my_author),pages(my_pages){}
    void show_details(){
        cout<<"书名: "<<name<<",作者："<<author<<",页数："<<pages<<"页"<<endl;
    }
    bool is_thick(){
        return pages>=500;
    }

};
void if_thick(Book bk){
    if(bk.is_thick()){
        cout<<bk.name<<"是一本厚书"<<endl;
    }
    else{
        cout<<bk.name<<"不是一本厚书"<<endl;
    }
}
int main(){
    Book Python("Python编程","张三",300);
    Book Cpp("C++实战","李四",600);
    Python.show_details();
    Cpp.show_details();
    if_thick(Python);
    if_thick(Cpp);
    return 0;
}