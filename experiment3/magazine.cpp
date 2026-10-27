
#include <iostream>
#include "magazine.h"

using namespace std;

// 构造函数：初始化杂志信息
Magazine::Magazine(string id, string n, string p,
                   string issue, string cycle, int quantity)
    : LibraryResource(id, n, p)
{
    issueNumber = issue;
    publicationCycle = cycle;

    if (quantity < 0)
    {
        quantity = 0;
    }

    totalQuantity = quantity;
    availableQuantity = quantity;
}

// 获取资源类型
string Magazine::getType() const
{
    return "杂志";
}

// 显示杂志信息
void Magazine::showInfo() const
{
    cout << "资源类型：" << getType() << endl;
    cout << "资源编号：" << resourceId << endl;
    cout << "杂志名称：" << name << endl;
    cout << "出版社：" << publisher << endl;
    cout << "期号：" << issueNumber << endl;
    cout << "出版周期：" << publicationCycle << endl;
    cout << "馆藏总数量：" << totalQuantity << endl;
    cout << "当前可借数量：" << availableQuantity << endl;
}

// 借阅杂志
bool Magazine::borrow()
{
    if (availableQuantity <= 0)
    {
        cout << "借阅失败：当前没有可借的杂志。" << endl;
        return false;
    }

    availableQuantity--;
    cout << "借阅成功：" << name << endl;
    return true;
}

// 归还杂志
bool Magazine::returnResource()
{
    if (availableQuantity >= totalQuantity)
    {
        cout << "归还失败：没有需要归还的杂志。" << endl;
        return false;
    }

    availableQuantity++;
    cout << "归还成功：" << name << endl;
    return true;
}
//获取借出数量 
int Magazine::getBorrowedCount() const {
    return totalQuantity - availableQuantity;
}

// 增加馆藏数量
bool Magazine::increaseQuantity(int amount)
{
    if (amount <= 0)
    {
        cout << "增加失败：数量必须大于 0。" << endl;
        return false;
    }

    totalQuantity += amount;
    availableQuantity += amount;

    cout << "杂志馆藏数量增加成功。" << endl;
    return true;
}

// 减少馆藏数量
bool Magazine::decreaseQuantity(int amount)
{
    if (amount <= 0)
    {
        cout << "减少失败：数量必须大于 0。" << endl;
        return false;
    }

    if (amount > availableQuantity)
    {
        cout << "减少失败：可用杂志数量不足。" << endl;
        return false;
    }

    totalQuantity -= amount;
    availableQuantity -= amount;

    cout << "杂志馆藏数量减少成功。" << endl;
    return true;
}

