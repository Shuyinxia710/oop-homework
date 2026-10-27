
#include <iostream>
#include "electronicresource.h"

using namespace std;

// 构造函数：初始化电子资源信息
ElectronicResource::ElectronicResource(
    string id, string n, string p,
    string format, string address,
    string authType, int licenses)
    : LibraryResource(id, n, p)
{
    fileFormat = format;
    accessAddress = address;
    authorizationType = authType;

    if (licenses < 0)
    {
        licenses = 0;
    }

    totalLicenses = licenses;
    availableLicenses = licenses;
}

// 获取资源类型
string ElectronicResource::getType() const
{
    return "电子资源";
}

// 显示电子资源信息
void ElectronicResource::showInfo() const
{
    cout << "资源类型：" << getType() << endl;
    cout << "资源编号：" << resourceId << endl;
    cout << "资源名称：" << name << endl;
    cout << "发布机构：" << publisher << endl;
    cout << "文件格式：" << fileFormat << endl;
    cout << "访问地址：" << accessAddress << endl;
    cout << "授权方式：" << authorizationType << endl;
    cout << "总授权数量：" << totalLicenses << endl;
    cout << "当前可用授权数量：" << availableLicenses << endl;
}

// 借用电子资源授权
bool ElectronicResource::borrow()
{
    if (availableLicenses <= 0)
    {
        cout << "访问失败：当前没有可用授权。" << endl;
        return false;
    }

    availableLicenses--;
    cout << "获取访问授权成功：" << name << endl;
    return true;
}

// 归还电子资源授权
bool ElectronicResource::returnResource()
{
    if (availableLicenses >= totalLicenses)
    {
        cout << "归还失败：当前没有被占用的授权。" << endl;
        return false;
    }

    availableLicenses++;
    cout << "释放访问授权成功：" << name << endl;
    return true;
}
//计算已占用的授权数量
int ElectronicResource::getBorrowedCount() const {
    return totalLicenses - availableLicenses;
}

// 增加授权数量
bool ElectronicResource::increaseQuantity(int amount)
{
    if (amount <= 0)
    {
        cout << "增加失败：授权数量必须大于 0。" << endl;
        return false;
    }

    totalLicenses += amount;
    availableLicenses += amount;

    cout << "授权数量增加成功。" << endl;
    return true;
}

// 减少授权数量
bool ElectronicResource::decreaseQuantity(int amount)
{
    if (amount <= 0)
    {
        cout << "减少失败：授权数量必须大于 0。" << endl;
        return false;
    }

    if (amount > availableLicenses)
    {
        cout << "减少失败：可用授权数量不足。" << endl;
        return false;
    }

    totalLicenses -= amount;
    availableLicenses -= amount;

    cout << "授权数量减少成功。" << endl;
    return true;
}

