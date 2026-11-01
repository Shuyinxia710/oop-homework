
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "libraryresource.h"

using namespace std;

class Library
{
private:
    vector<LibraryResource*> resources;  // 保存所有资源的指针

public:
    Library();
    ~Library();

    // 禁止复制图书馆对象，避免重复释放资源
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

    // 新增资源
    bool addResource(LibraryResource* resource);

    // 根据编号查找资源
    LibraryResource* findResource(string id) const;

    // 显示指定资源
    bool showResource(string id) const;

    // 显示全部资源
    void showAllResources() const;

    // 增加资源数量
    bool increaseResourceQuantity(string id, int amount);

    // 减少资源数量
    bool decreaseResourceQuantity(string id, int amount);

    // 删除资源
    bool removeResource(string id);

    // 获取资源总数
    int getResourceCount() const;
};

#endif

