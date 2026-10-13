#ifndef STUDENT_H
#define STUDENT_H

#include "book.h"
#include <vector>
#include <string>

using namespace std;

class Student
{
private:
    // 学生基本信息
    string name;
    string studentId;

    // 借阅记录列表：保存该学生借过的图书名称
    vector<string> borrowRecords;

public:
    // 构造函数
    Student();
    Student(string n, string id);

    // 设置学生信息
    void setName(string n);
    void setStudentId(string id);

    // 获取学生信息
    string getName();
    string getStudentId();

    // 借阅图书
    bool borrowBook(Book &book);

    // 显示借阅记录
    void showBorrowRecords();

    // 获取借阅数量
    int getBorrowCount();
};

#endif
