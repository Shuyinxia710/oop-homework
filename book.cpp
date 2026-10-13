#include "book.h"
#include <cctype>

Book::Book()
{
    name = "未知图书";
    isbn = "0000000000000";
    press = "未知出版社";
    price = 0;
    pages = 0;
    inLibrary = true;
    availableCount = 1;
}

Book::Book(string n, string i, string p,
           double pr, int pg, bool inLib)
{
    name = n;
    isbn = i;
    press = p;
    price = pr;
    pages = pg;
    inLibrary = inLib;

    // 根据原来的在馆状态初始化可借数量
    availableCount = inLib ? 1 : 0;
}

void Book::setName(string n)
{
    name = n;
}

void Book::setIsbn(string i)
{
    isbn = i;
}

void Book::setPress(string p)
{
    press = p;
}

void Book::setPrice(double pr)
{
    price = pr;
}

void Book::setPages(int pg)
{
    pages = pg;
}

void Book::setInLibrary(bool inLib)
{
    inLibrary = inLib;

    // 保持原有状态与可借数量一致
    availableCount = inLib ? 1 : 0;
}

void Book::setAvailableCount(int count)
{
    if (count >= 0)
    {
        availableCount = count;
        inLibrary = (availableCount > 0);
    }
}

string Book::getName()
{
    return name;
}

string Book::getIsbn()
{
    return isbn;
}

string Book::getPress()
{
    return press;
}

double Book::getPrice()
{
    return price;
}

int Book::getPages()
{
    return pages;
}

bool Book::getInLibrary()
{
    return inLibrary;
}

int Book::getAvailableCount()
{
    return availableCount;
}

bool Book::canBorrow()
{
    return availableCount > 0;
}

// 借出一本图书
bool Book::borrowOne()
{
    if (!canBorrow())
    {
        return false;
    }

    availableCount--;

    // 更新图书在馆状态
    inLibrary = (availableCount > 0);

    return true;
}

// 校验 ISBN：必须是13位数字
bool Book::checkIsbnValid()
{
    if (isbn.size() != 13)
    {
        return false;
    }

    for (int i = 0; i < isbn.size(); i++)
    {
        if (!isdigit(static_cast<unsigned char>(isbn[i])))
        {
            return false;
        }
    }

    return true;
}

void Book::showInfo()
{
    cout << "====图书信息====" << endl;
    cout << "书名：" << name << endl;
    cout << "ISBN：" << isbn << endl;
    cout << "出版社：" << press << endl;
    cout << "价格：" << price << "元" << endl;
    cout << "页数：" << pages << endl;

    cout << "可借数量：" << availableCount << endl;

    if (canBorrow())
    {
        cout << "状态：可以借阅" << endl;
    }
    else
    {
        cout << "状态：暂无可借图书" << endl;
    }

    if (checkIsbnValid())
    {
        cout << "ISBN：合法" << endl;
    }
    else
    {
        cout << "ISBN：不合法" << endl;
    }

    cout << endl;
}

