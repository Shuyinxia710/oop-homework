#include "student.h"
#include <iostream>

using namespace std;

Student::Student()
{
    name = "未知学生";
    studentId = "000000";
}

Student::Student(string n, string id)
{
    name = n;
    studentId = id;
}

void Student::setName(string n)
{
    name = n;
}

void Student::setStudentId(string id)
{
    studentId = id;
}

string Student::getName()
{
    return name;
}

string Student::getStudentId()
{
    return studentId;
}

// 学生借阅图书
bool Student::borrowBook(Book &book)
{
    cout << "学生 " << name
         << "（学号：" << studentId << "）"
         << " 正在借阅《" << book.getName() << "》" << endl;

    if (!book.canBorrow())
    {
        cout << "借阅失败：该图书暂无可借库存。"
             << endl;
        return false;
    }

    // 借出一本图书，更新原图书对象的库存
    if (book.borrowOne())
    {
        // 借阅成功后保存借阅记录
        borrowRecords.push_back(book.getName());

        cout << "借阅成功！" << endl;
        cout << "剩余可借数量："
             << book.getAvailableCount() << endl;

        return true;
    }

    cout << "借阅失败。" << endl;
    return false;
}

// 显示学生的借阅记录
void Student::showBorrowRecords()
{
    cout << endl;
    cout << "========== 学生借阅记录 ==========" << endl;
    cout << "学生姓名：" << name << endl;
    cout << "学生学号：" << studentId << endl;

    if (borrowRecords.empty())
    {
        cout << "当前没有借阅记录。" << endl;
        return;
    }

    for (int i = 0; i < borrowRecords.size(); i++)
    {
        cout << i + 1 << ". "
             << borrowRecords[i] << endl;
    }
}

int Student::getBorrowCount()
{
    return static_cast<int>(borrowRecords.size());
}
