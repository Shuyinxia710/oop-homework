
#ifndef ELECTRONICRESOURCE_H
#define ELECTRONICRESOURCE_H

#include "libraryresource.h"

class ElectronicResource : public LibraryResource
{
private:
    string fileFormat;          // 文件格式，例如 PDF、EPUB
    string accessAddress;       // 电子资源访问地址
    string authorizationType;   // 授权方式
    int totalLicenses;          // 总授权数量
    int availableLicenses;      // 当前可用授权数量

public:
    ElectronicResource(string id, string n, string p,
                       string format, string address,
                       string authType, int licenses);

    string getType() const override;
    void showInfo() const override;

    bool borrow() override;
    bool returnResource() override;
    //统计正在使用的授权数量
    int getBorrowedCount() const override;
    bool increaseQuantity(int amount) override;
    bool decreaseQuantity(int amount) override;
};

#endif

