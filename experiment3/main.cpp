
#include <iostream>
#include "library.h"
#include "printedbook.h"
#include "magazine.h"
#include "electronicresource.h"
#include "student.h"

using namespace std;

int main()
{
    // 创建图书馆
    Library library;

    // 创建三种资源，并添加到图书馆
    library.addResource(new PrintedBook(
        "B001", "C++程序设计", "高等教育出版社",
        "9787040000001", "张三", 5
    ));

    library.addResource(new Magazine(
        "M001", "计算机世界", "计算机世界出版社",
        "2026年第10期", "月刊", 3
    ));

    library.addResource(new ElectronicResource(
        "E001", "C++电子教程", "学校图书馆",
        "PDF", "https://example.com/cpp.pdf",
        "并发授权", 10
    ));

    cout << "\n========== 一、显示全部资源 ==========" << endl;
    library.showAllResources();

    // 创建学生
    Student student1("2026001", "小明");
	
    cout << "\n========== 二、学生借阅资源 ==========" << endl;
    student1.borrowResource(library, "B001");
    student1.borrowResource(library, "M001");
    library.removeResource("M001");
    student1.returnResource("M001");
	library.removeResource("M001");
    student1.borrowResource(library, "E001");

    cout << "\n========== 三、显示借阅记录 ==========" << endl;
    student1.showBorrowedResources();

    cout << "\n========== 四、查看借阅后的资源信息 ==========" << endl;
    library.showResource("B001");
    library.showResource("M001");
    library.showResource("E001");

    cout << "\n========== 五、归还纸质图书 ==========" << endl;
    student1.returnResource("B001");

    cout << "\n========== 六、增加图书馆藏 ==========" << endl;
    library.increaseResourceQuantity("B001", 2);

    cout << "\n========== 七、减少杂志馆藏 ==========" << endl;
    library.decreaseResourceQuantity("M001", 1);

    cout << "\n========== 八、再次显示全部资源 ==========" << endl;
    library.showAllResources();

    cout << "\n========== 九、查询不存在的资源 ==========" << endl;
    library.showResource("X999");

    cout << "\n========== 十、显示最终借阅记录 ==========" << endl;
    student1.showBorrowedResources();

    cout << "\n========== 实验测试结束 ==========" << endl;

    return 0;
}

