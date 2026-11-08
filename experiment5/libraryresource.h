
#ifndef LIBRARYRESOURCE_H
#define LIBRARYRESOURCE_H

#include <string>
using namespace std;

class LibraryResource
{
protected:
    string resourceId;    // 资源编号
    string name;          // 资源名称
    string publisher;     // 出版社或发布机构

public:
    LibraryResource(string id, string n, string p);

    virtual ~LibraryResource();

    string getResourceId() const;
    string getName() const;
    string getPublisher() const;

    virtual string getType() const = 0;

    virtual void showInfo() const = 0;

    virtual bool borrow() = 0;
    virtual bool returnResource() = 0;
    //让不同类型的资源可以分别实现自己的计算方式。
    virtual int getBorrowedCount() const = 0;

    virtual bool increaseQuantity(int amount) = 0;
    virtual bool decreaseQuantity(int amount) = 0;
};

#endif

