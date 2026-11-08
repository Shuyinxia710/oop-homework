#include <iostream>
#include "library.h"

using namespace std;

Library::Library()
{
}

Library::~Library()
{
    students.clear();

    for (vector<LibraryResource*>::iterator it = resources.begin();
         it != resources.end(); ++it)
    {
        delete *it;
    }

    resources.clear();
}

bool Library::addResource(LibraryResource* resource)
{
    if (resource == NULL)
    {
        cout << "添加失败：资源不能为空。" << endl;
        return false;
    }

    if (findResource(resource->getResourceId()) != NULL)
    {
        cout << "添加失败：资源编号已存在。" << endl;
        delete resource;
        return false;
    }

    resources.push_back(resource);
    cout << "资源添加成功！" << endl;
    return true;
}

LibraryResource* Library::findResource(string id) const
{
    for (vector<LibraryResource*>::const_iterator it = resources.begin();
         it != resources.end(); ++it)
    {
        if ((*it)->getResourceId() == id)
        {
            return *it;
        }
    }

    return NULL;
}

bool Library::showResource(string id) const
{
    LibraryResource* resource = findResource(id);

    if (resource == NULL)
    {
        cout << "查询失败：没有找到该资源。" << endl;
        return false;
    }

    resource->showInfo();
    return true;
}

void Library::showAllResources() const
{
    if (resources.empty())
    {
        cout << "当前没有资源。" << endl;
        return;
    }

    cout << "\n当前共有 " << resources.size() << " 个资源：" << endl;

    for (vector<LibraryResource*>::const_iterator it = resources.begin();
         it != resources.end(); ++it)
    {
        cout << "\n--------------------" << endl;
        (*it)->showInfo();
    }
}

bool Library::increaseResourceQuantity(string id, int amount)
{
    LibraryResource* resource = findResource(id);

    if (resource == NULL)
    {
        cout << "增加失败：没有找到该资源。" << endl;
        return false;
    }

    return resource->increaseQuantity(amount);
}

bool Library::decreaseResourceQuantity(string id, int amount)
{
    LibraryResource* resource = findResource(id);

    if (resource == NULL)
    {
        cout << "减少失败：没有找到该资源。" << endl;
        return false;
    }

    return resource->decreaseQuantity(amount);
}

bool Library::removeResource(string id)
{
    for (vector<LibraryResource*>::iterator it = resources.begin();
         it != resources.end(); ++it)
    {
        if ((*it)->getResourceId() == id)
        {
            if ((*it)->getBorrowedCount() > 0)
            {
                cout << "删除失败：该资源仍有借阅记录。" << endl;
                return false;
            }

            delete *it;
            resources.erase(it);

            cout << "资源删除成功！" << endl;
            return true;
        }
    }

    cout << "删除失败：没有找到该资源。" << endl;
    return false;
}

int Library::getResourceCount() const
{
    return static_cast<int>(resources.size());
}

bool Library::addStudent(string id, string name)
{
    if (id.empty() || name.empty())
    {
        cout << "添加失败：学号和姓名不能为空。" << endl;
        return false;
    }

    if (findStudent(id) != NULL)
    {
        cout << "添加失败：该学号已经存在。" << endl;
        return false;
    }

    students.emplace_back(id, name);

    cout << "学生添加成功！" << endl;
    return true;
}

Student* Library::findStudent(string id)
{
    for (vector<Student>::iterator it = students.begin();
         it != students.end(); ++it)
    {
        if (it->getStudentId() == id)
        {
            return &(*it);
        }
    }

    return NULL;
}

bool Library::removeStudent(string id)
{
    for (vector<Student>::iterator it = students.begin();
         it != students.end(); ++it)
    {
        if (it->getStudentId() == id)
        {
            if (it->getBorrowedResourceCount() > 0)
            {
                cout << "删除失败：该学生还有未归还资源。" << endl;
                return false;
            }

            students.erase(it);

            cout << "学生删除成功！" << endl;
            return true;
        }
    }

    cout << "删除失败：没有找到该学生。" << endl;
    return false;
}

void Library::showAllStudents() const
{
    if (students.empty())
    {
        cout << "当前没有学生信息。" << endl;
        return;
    }

    cout << "\n当前共有 " << students.size() << " 名学生：" << endl;

    for (vector<Student>::const_iterator it = students.begin();
         it != students.end(); ++it)
    {
        cout << "\n--------------------" << endl;
        cout << "学号：" << it->getStudentId() << endl;
        cout << "姓名：" << it->getName() << endl;
        cout << "已借资源数量：" << it->getBorrowedResourceCount() << endl;
    }
}

int Library::getStudentCount() const
{
    return static_cast<int>(students.size());
}
