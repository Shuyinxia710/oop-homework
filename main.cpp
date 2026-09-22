#include "book.h"

int main()
{
    //调用重载构造
    Book b1("C++面向对象", "9787111640547", "机械工业出版社", 59.0, 380, true);
    b1.showInfo();

    //默认构造对象
    Book b2;
    b2.setName("数据结构");
    b2.setIsbn("9787115579861");
    b2.setPress("人民邮电出版社");
    b2.setPrice(69.5);
    b2.setPages(420);
    b2.setInLibrary(false);
    b2.showInfo();

    //测试非法ISBN
    Book b3("测试书籍", "1234abc", "测试出版社", 20, 100, true);
    b3.showInfo();

    return 0;
}

