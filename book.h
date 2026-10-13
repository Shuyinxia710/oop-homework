#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    // 图书的基本信息
    string name;
    string isbn;
    string press;
    double price;
    int pages;
    
    bool inLibrary;

    // 图书可借数量
    int availableCount;

public:
    
    Book();

    Book(string n, string i, string p,
         double pr, int pg, bool inLib);

    void setName(string n);
    void setIsbn(string i);
    void setPress(string p);
    void setPrice(double pr);
    void setPages(int pg);
    void setInLibrary(bool inLib);

    //设置可借数量
    void setAvailableCount(int count);

    // 获取成员
    string getName();
    string getIsbn();
    string getPress();
    double getPrice();
    int getPages();
    bool getInLibrary();

    // 获取可借数量
    int getAvailableCount();

    // 判断是否可以借阅
    bool canBorrow();

    // 借出一本图书
    bool borrowOne();

    // 校验 ISBN 合法性
    bool checkIsbnValid();

    // 输出图书全部信息
    void showInfo();
};

#endif

