
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "library.h"

using namespace std;

class Student
{
private:
    string studentId;                  // 学号
    string name;                       // 姓名
    vector<LibraryResource*> borrowedResources;  // 已借资源

public:
    Student(string id, string n);

    string getStudentId() const;
    string getName() const;

    // 借阅资源
    bool borrowResource(Library& library, string resourceId);

    // 归还资源
    bool returnResource(string resourceId);

    // 显示借阅记录
    void showBorrowedResources() const;
};

#endif

