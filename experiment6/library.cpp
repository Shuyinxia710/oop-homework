#include <iostream>
#include <fstream>
#include <sstream>
#include "library.h"
#include "printedbook.h"
#include "magazine.h"
#include "electronicresource.h"

using namespace std;

bool readInteger(ifstream& in, int& value)
{
    string line;
    getline(in, line);

    stringstream stream(line);
    return static_cast<bool>(stream >> value);
}

Library::Library()
{
}

Library::~Library()
{
    clearData();
}

void Library::clearData()
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
        cout << "\n学号：" << it->getStudentId() << endl;
        cout << "姓名：" << it->getName() << endl;
        cout << "已借资源数量：" << it->getBorrowedResourceCount() << endl;
    }
}

int Library::getStudentCount() const
{
    return static_cast<int>(students.size());
}

bool Library::saveData(string fileName) const
{
    ofstream out(fileName.c_str());

    if (!out)
    {
        cout << "保存失败：无法打开数据文件。" << endl;
        return false;
    }

    out << "LIBRARY_DATA_V1" << endl;
    out << resources.size() << endl;

    for (vector<LibraryResource*>::const_iterator it = resources.begin();
         it != resources.end(); ++it)
    {
        PrintedBook* book = dynamic_cast<PrintedBook*>(*it);
        Magazine* magazine = dynamic_cast<Magazine*>(*it);
        ElectronicResource* electronic = dynamic_cast<ElectronicResource*>(*it);

        if (book != NULL)
        {
            out << "BOOK" << endl;
            out << book->getResourceId() << endl;
            out << book->getName() << endl;
            out << book->getPublisher() << endl;
            out << book->getIsbn() << endl;
            out << book->getAuthor() << endl;
            out << book->getTotalQuantity() << endl;
        }
        else if (magazine != NULL)
        {
            out << "MAGAZINE" << endl;
            out << magazine->getResourceId() << endl;
            out << magazine->getName() << endl;
            out << magazine->getPublisher() << endl;
            out << magazine->getIssueNumber() << endl;
            out << magazine->getPublicationCycle() << endl;
            out << magazine->getTotalQuantity() << endl;
        }
        else if (electronic != NULL)
        {
            out << "ELECTRONIC" << endl;
            out << electronic->getResourceId() << endl;
            out << electronic->getName() << endl;
            out << electronic->getPublisher() << endl;
            out << electronic->getFileFormat() << endl;
            out << electronic->getAccessAddress() << endl;
            out << electronic->getAuthorizationType() << endl;
            out << electronic->getTotalQuantity() << endl;
        }
    }

    out << students.size() << endl;

    for (vector<Student>::const_iterator it = students.begin();
         it != students.end(); ++it)
    {
        it->saveToFile(out);
    }

    out.close();

    cout << "数据保存成功！" << endl;
    return true;
}

bool Library::loadData(string fileName)
{
    ifstream in(fileName.c_str());

    if (!in)
    {
        return false;
    }

    string header;
    getline(in, header);

    if (header != "LIBRARY_DATA_V1")
    {
        cout << "读取失败：数据文件格式错误。" << endl;
        in.close();
        return false;
    }

    int resourceCount;

    if (!readInteger(in, resourceCount))
    {
        cout << "读取失败：资源数据错误。" << endl;
        in.close();
        return false;
    }

    clearData();

    for (int i = 0; i < resourceCount; i++)
    {
        string type;
        string id;
        string name;
        string publisher;
        string firstInfo;
        string secondInfo;
        string thirdInfo;
        int quantity;

        getline(in, type);
        getline(in, id);
        getline(in, name);
        getline(in, publisher);

        if (type == "BOOK")
        {
            getline(in, firstInfo);
            getline(in, secondInfo);
            readInteger(in, quantity);

            resources.push_back(new PrintedBook(
                id, name, publisher, firstInfo, secondInfo, quantity
            ));
        }
        else if (type == "MAGAZINE")
        {
            getline(in, firstInfo);
            getline(in, secondInfo);
            readInteger(in, quantity);

            resources.push_back(new Magazine(
                id, name, publisher, firstInfo, secondInfo, quantity
            ));
        }
        else if (type == "ELECTRONIC")
        {
            getline(in, firstInfo);
            getline(in, secondInfo);
            getline(in, thirdInfo);
            readInteger(in, quantity);

            resources.push_back(new ElectronicResource(
                id, name, publisher,
                firstInfo, secondInfo, thirdInfo, quantity
            ));
        }
    }

    int studentCount;

    if (!readInteger(in, studentCount))
    {
        cout << "读取失败：学生数据错误。" << endl;
        in.close();
        return false;
    }

    for (int i = 0; i < studentCount; i++)
    {
        string studentId;
        string studentName;
        int borrowedCount;

        getline(in, studentId);
        getline(in, studentName);
        readInteger(in, borrowedCount);

        addStudent(studentId, studentName);
        Student* student = findStudent(studentId);

        for (int j = 0; j < borrowedCount; j++)
        {
            string resourceId;
            getline(in, resourceId);

            LibraryResource* resource = findResource(resourceId);

            if (student != NULL && resource != NULL && resource->borrow())
            {
                student->loadBorrowedResource(resource);
            }
        }
    }

    in.close();

    cout << "数据读取成功！" << endl;
    return true;
}
