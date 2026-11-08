
#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "libraryresource.h"

class PrintedBook : public LibraryResource
{
private:
    string isbn;              // ISBN编号
    string author;            // 作者
    int totalQuantity;        // 馆藏总数量
    int availableQuantity;    // 当前可借数量

public:
    PrintedBook(string id, string n, string p,
                string isbn, string author, int quantity);

    string getType() const override;
    void showInfo() const override;

    bool borrow() override;
    bool returnResource() override;
    //重写父类 LibraryResource 中声明的虚函数
    int getBorrowedCount() const override;

    bool increaseQuantity(int amount) override;
    bool decreaseQuantity(int amount) override;
};

#endif

