#include <iostream>
#include "library.h"

using namespace std;

Library::Library()
{
}

Library::~Library()
{
    for (size_t i = 0; i < resources.size(); i++)
    {
        delete resources[i];
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
    for (size_t i = 0; i < resources.size(); i++)
    {
        if (resources[i]->getResourceId() == id)
        {
            return resources[i];
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

    for (size_t i = 0; i < resources.size(); i++)
    {
        cout << "\n--------------------" << endl;
        resources[i]->showInfo();
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
    for (size_t i = 0; i < resources.size(); i++)
    {
        if (resources[i]->getResourceId() == id)
        {
            if (resources[i]->getBorrowedCount() > 0)
            {
                cout << "删除失败：该资源仍有借阅记录。" << endl;
                return false;
            }

            delete resources[i];
            resources.erase(resources.begin() + i);

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
