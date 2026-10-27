
#include <iostream>
#include "library.h"

using namespace std;

// 构造函数
Library::Library()
{
}

// 析构函数：释放图书馆管理的所有资源
Library::~Library()
{
    for (size_t i = 0; i < resources.size(); i++)
    {
        delete resources[i];
    }

    resources.clear();
}

// 新增资源
bool Library::addResource(LibraryResource* resource)
{
    if (resource == NULL)
    {
        cout << "添加失败：资源不能为空。" << endl;
        return false;
    }

    // 检查编号是否重复
    if (findResource(resource->getResourceId()) != NULL)
    {
        cout << "添加失败：资源编号已存在。" << endl;
        return false;
    }

    resources.push_back(resource);

    cout << "资源添加成功。" << endl;
    return true;
}

// 根据编号查找资源
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

// 显示指定资源
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

// 显示全部资源
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

// 增加资源数量
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

// 减少资源数量
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

// 删除资源  避免图书馆删除资源后，学生的借阅记录还指向已经释放的对象
bool Library::removeResource(string id) {
    for (int i = 0; i < resources.size(); i++) {
        if (resources[i]->getResourceId() == id) {

            // 检查资源是否还有借出数量
            if (resources[i]->getBorrowedCount() > 0) {
                cout << "删除失败：该资源仍有借出记录。" << endl;
                return false;
            }

            // 没有借出数量，才允许删除
            delete resources[i];
            resources.erase(resources.begin() + i);

            cout << "资源删除成功。" << endl;
            return true;
        }
    }

    cout << "删除失败：没有找到该资源。" << endl;
    return false;
}

// 获取资源总数
int Library::getResourceCount() const
{
    return static_cast<int>(resources.size());
}

