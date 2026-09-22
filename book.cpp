#include "book.h"
#include <cctype>

//默认构造
Book::Book()
{
    name = "未知图书";
    isbn = "0000000000000";
    press = "未知出版社";
    price = 0;
    pages = 0;
    inLibrary = true;
}

//重载构造
Book::Book(string n, string i, string p, double pr, int pg, bool inLib)
{
    name = n;
    isbn = i;
    press = p;
    price = pr;
    pages = pg;
    inLibrary = inLib;
}

void Book::setName(string n) { name = n; }
void Book::setIsbn(string i) { isbn = i; }
void Book::setPress(string p) { press = p; }
void Book::setPrice(double pr) { price = pr; }
void Book::setPages(int pg) { pages = pg; }
void Book::setInLibrary(bool inLib) { inLibrary = inLib; }

string Book::getName() { return name; }
string Book::getIsbn() { return isbn; }
string Book::getPress() { return press; }
double Book::getPrice() { return price; }
int Book::getPages() { return pages; }
bool Book::getInLibrary() { return inLibrary; }

//校验ISBN：必须13位全部数字
bool Book::checkIsbnValid()
{
    if(isbn.size() != 13)
        return false;
    for(int i = 0; i < isbn.size(); i++)
    {
        if(!isdigit(isbn[i]))
            return false;
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
    if(inLibrary)
        cout << "状态：在馆，可以借阅" << endl;
    else
        cout << "状态：已借出" << endl;
    if(checkIsbnValid())
        cout << "ISBN：合法" << endl;
    else
        cout << "ISBN：不合法" << endl;
    cout << endl;
}

