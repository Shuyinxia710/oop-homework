#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    //私有数据成员
    string name;     
    string isbn;    
    string press;    
    double price;    
    int pages;       
    bool inLibrary;  

public:
    Book();
    
    Book(string n, string i, string p, double pr, int pg, bool inLib);

    //修改成员
    void setName(string n);
    void setIsbn(string i);
    void setPress(string p);
    void setPrice(double pr);
    void setPages(int pg);
    void setInLibrary(bool inLib);

    //获取成员
    string getName();
    string getIsbn();
    string getPress();
    double getPrice();
    int getPages();
    bool getInLibrary();
    
    //校验ISBN合法性（简单校验：长度13位数字）
    bool checkIsbnValid();

    //输出图书全部信息
    void showInfo();
};

#endif

