
#include <iostream>
#include "printedbook.h"

using namespace std;

// 构造函数：初始化纸质图书的信息
PrintedBook::PrintedBook(string id, string n, string p,
                         string isbn, string author, int quantity)
    : LibraryResource(id, n, p)
{
    this->isbn = isbn;
    this->author = author;
    
    if (quantity < 0)
    {
        quantity = 0;
    }

    totalQuantity = quantity;
    availableQuantity = quantity;
}

// 获取资源类型
string PrintedBook::getType() const
{
    return "纸质图书";
}

// 显示图书信息
void PrintedBook::showInfo() const
{
    cout << "资源类型：" << getType() << endl;
    cout << "资源编号：" << resourceId << endl;
    cout << "书名：" << name << endl;
    cout << "出版社：" << publisher << endl;
    cout << "ISBN：" << isbn << endl;
    cout << "作者：" << author << endl;
    cout << "馆藏总数量：" << totalQuantity << endl;
    cout << "当前可借数量：" << availableQuantity << endl;
}

// 借阅图书
bool PrintedBook::borrow()
{
    if (availableQuantity <= 0)
    {
        cout << "借阅失败：当前没有可借的图书。" << endl;
        return false;
    }

    availableQuantity--;
    cout << "借阅成功：" << name << endl;
    return true;
}

// 归还图书
bool PrintedBook::returnResource()
{
    if (availableQuantity >= totalQuantity)
    {
        cout << "归还失败：没有需要归还的图书。" << endl;
        return false;
    }

    availableQuantity++;
    cout << "归还成功：" << name << endl;
    return true;
}
//返回已借出数量 
int PrintedBook::getBorrowedCount() const {
    return totalQuantity - availableQuantity;
}
// 增加馆藏数量
bool PrintedBook::increaseQuantity(int amount)
{
    if (amount <= 0)
    {
        cout << "增加失败：数量必须大于 0。" << endl;
        return false;
    }

    totalQuantity += amount;
    availableQuantity += amount;

    cout << "馆藏数量增加成功。" << endl;
    return true;
}

// 减少馆藏数量
bool PrintedBook::decreaseQuantity(int amount)
{
    if (amount <= 0)
    {
        cout << "减少失败：数量必须大于 0。" << endl;
        return false;
    }

    // 不能减少已经借出去的图书
    if (amount > availableQuantity)
    {
        cout << "减少失败：可用馆藏数量不足。" << endl;
        return false;
    }

    totalQuantity -= amount;
    availableQuantity -= amount;

    cout << "馆藏数量减少成功。" << endl;
    return true;
}

