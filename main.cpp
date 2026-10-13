#include "book.h"
#include "student.h"

int main()
{
    // 一、创建图书对象
    cout << "========== 一、图书初始化 ==========" << endl;

    Book b1("C++面向对象", "9787111640547",
            "机械工业出版社", 59.0, 380, true);
    b1.setAvailableCount(2);

    Book b2("数据结构", "9787115579861",
            "人民邮电出版社", 69.5, 420, true);
    b2.setAvailableCount(0);

    b1.showInfo();
    b2.showInfo();

    // 二、创建学生对象
    cout << "========== 二、学生初始化 ==========" << endl;

    Student s1("张三", "2026001");

    cout << "学生姓名：" << s1.getName() << endl;
    cout << "学生学号：" << s1.getStudentId() << endl;

    // 三、测试借书成功
    cout << endl;
    cout << "========== 三、测试借书成功 ==========" << endl;

    s1.borrowBook(b1);

    // 四、再次借阅同一本书
    cout << endl;
    cout << "========== 四、测试第二次借书 ==========" << endl;

    s1.borrowBook(b1);

    // 五、测试无库存时借书
    cout << endl;
    cout << "========== 五、测试无库存借书 ==========" << endl;

    s1.borrowBook(b2);

    // 六、查看最终图书库存
    cout << endl;
    cout << "========== 六、最终图书状态 ==========" << endl;

    b1.showInfo();
    b2.showInfo();

    // 七、查看学生借阅记录
    cout << "========== 七、学生借阅记录 ==========" << endl;

    s1.showBorrowRecords();

    cout << "成功借阅数量："
         << s1.getBorrowCount() << endl;

    return 0;
}
