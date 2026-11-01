
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "libraryresource.h"

class Magazine : public LibraryResource
{
private:
    string issueNumber;        // 期号
    string publicationCycle;   // 出版周期
    int totalQuantity;         // 馆藏总数量
    int availableQuantity;     // 当前可借数量

public:
    Magazine(string id, string n, string p,
             string issue, string cycle, int quantity);

    string getType() const override;
    void showInfo() const override;

    bool borrow() override;
    bool returnResource() override;
    int getBorrowedCount() const override;
    bool increaseQuantity(int amount) override;
    bool decreaseQuantity(int amount) override;
};

#endif

