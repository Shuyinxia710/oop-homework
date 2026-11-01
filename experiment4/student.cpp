
#include <iostream>
#include "student.h"

using namespace std;

// 构造函数：初始化学生信息
Student::Student(string id, string n)
{
    studentId = id;
    name = n;
}

// 获取学号
string Student::getStudentId() const
{
    return studentId;
}

// 获取姓名
string Student::getName() const
{
    return name;
}

// 借阅资源
bool Student::borrowResource(Library& library, string resourceId)
{
    // 查找资源
    LibraryResource* resource = library.findResource(resourceId);

    if (resource == NULL)
    {
        cout << "借阅失败：没有找到该资源。" << endl;
        return false;
    }

    // 检查是否已经借过这项资源
    for (size_t i = 0; i < borrowedResources.size(); i++)
    {
        if (borrowedResources[i]->getResourceId() == resourceId)
        {
            cout << "借阅失败：你已经借过该资源。" << endl;
            return false;
        }
    }

    // 尝试借阅资源
    if (!resource->borrow())
    {
        return false;
    }

    // 借阅成功后，保存资源指针
    borrowedResources.push_back(resource);

    cout << name << "（" << studentId << "）借阅成功。" << endl;
    return true;
}

// 归还资源
bool Student::returnResource(string resourceId)
{
    for (size_t i = 0; i < borrowedResources.size(); i++)
    {
        if (borrowedResources[i]->getResourceId() == resourceId)
        {
            // 归还资源，释放对应数量或授权
            if (!borrowedResources[i]->returnResource())
            {
                return false;
            }

            // 从借阅记录中移除
            borrowedResources.erase(borrowedResources.begin() + i);

            cout << name << "（" << studentId << "）归还成功。" << endl;
            return true;
        }
    }

    cout << "归还失败：你的借阅记录中没有该资源。" << endl;
    return false;
}

// 显示当前借阅记录
void Student::showBorrowedResources() const
{
    if (borrowedResources.empty())
    {
        cout << name << " 当前没有借阅资源。" << endl;
        return;
    }

    cout << "\n学生：" << name << endl;
    cout << "学号：" << studentId << endl;
    cout << "当前借阅记录：" << endl;

    for (size_t i = 0; i < borrowedResources.size(); i++)
    {
        cout << "资源编号："
             << borrowedResources[i]->getResourceId()
             << "，资源名称："
             << borrowedResources[i]->getName()
             << "，资源类型："
             << borrowedResources[i]->getType()
             << endl;
    }
}

