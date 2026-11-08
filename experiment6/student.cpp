#include <iostream>
#include "student.h"
#include "library.h"
#include "libraryresource.h"

using namespace std;

Student::Student(string id, string n)
{
    studentId = id;
    name = n;
}

string Student::getStudentId() const
{
    return studentId;
}

string Student::getName() const
{
    return name;
}

bool Student::borrowResource(Library& library, string resourceId)
{
    LibraryResource* resource = library.findResource(resourceId);

    if (resource == NULL)
    {
        cout << "借阅失败：没有找到该资源。" << endl;
        return false;
    }

    for (size_t i = 0; i < borrowedResources.size(); i++)
    {
        if (borrowedResources[i]->getResourceId() == resourceId)
        {
            cout << "借阅失败：该学生已经借阅过此资源。" << endl;
            return false;
        }
    }

    if (!resource->borrow())
    {
        return false;
    }

    borrowedResources.push_back(resource);

    cout << name << "（" << studentId << "）借阅成功！" << endl;
    return true;
}

bool Student::returnResource(string resourceId)
{
    for (vector<LibraryResource*>::iterator it = borrowedResources.begin();
         it != borrowedResources.end(); ++it)
    {
        if ((*it)->getResourceId() == resourceId)
        {
            if (!(*it)->returnResource())
            {
                return false;
            }

            borrowedResources.erase(it);

            cout << name << "（" << studentId << "）归还成功！" << endl;
            return true;
        }
    }

    cout << "归还失败：该学生没有借阅此资源。" << endl;
    return false;
}

int Student::getBorrowedResourceCount() const
{
    return static_cast<int>(borrowedResources.size());
}

void Student::showBorrowedResources() const
{
    if (borrowedResources.empty())
    {
        cout << name << "当前没有借阅资源。" << endl;
        return;
    }

    cout << "\n学生姓名：" << name << endl;
    cout << "学号：" << studentId << endl;
    cout << "当前借阅记录：" << endl;

    for (size_t i = 0; i < borrowedResources.size(); i++)
    {
        cout << "资源编号：" << borrowedResources[i]->getResourceId()
             << "，资源名称：" << borrowedResources[i]->getName()
             << "，资源类型：" << borrowedResources[i]->getType()
             << endl;
    }
}

void Student::saveToFile(ofstream& out) const
{
    out << studentId << endl;
    out << name << endl;
    out << borrowedResources.size() << endl;

    for (size_t i = 0; i < borrowedResources.size(); i++)
    {
        out << borrowedResources[i]->getResourceId() << endl;
    }
}

void Student::loadBorrowedResource(LibraryResource* resource)
{
    if (resource != NULL)
    {
        borrowedResources.push_back(resource);
    }
}
