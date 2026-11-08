#include <iostream>
#include <string>
#include <limits>
#include "library.h"
#include "printedbook.h"
#include "magazine.h"
#include "electronicresource.h"
using namespace std;
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int readInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            clearInput();
            return value;
        }
        cout << "输入错误，请输入整数！" << endl;
        clearInput();
    }
}
int readPositiveInt(const string& prompt)
{
    int value;
    do
    {
        value = readInt(prompt);
        if (value <= 0)
        {
            cout << "请输入大于 0 的整数！" << endl;
        }
    } while (value <= 0);
    return value;
}
string readString(const string& prompt)
{
    string value;
    cout << prompt;
    getline(cin >> ws, value);
    return value;
}
void showMenu()
{
    cout << "\n====================================" << endl;
    cout << "     图书馆借阅管理系统（实验五）" << endl;
    cout << "====================================" << endl;
    cout << "1. 增加新的图书或资源" << endl;
    cout << "2. 增加已有资源数量" << endl;
    cout << "3. 显示某一资源情况" << endl;
    cout << "4. 显示所有资源情况" << endl;
    cout << "5. 减少已有资源数量" << endl;
    cout << "6. 删除某一资源" << endl;
    cout << "7. 添加学生" << endl;
    cout << "8. 删除学生" << endl;
    cout << "9. 学生借阅资源" << endl;
    cout << "10. 学生归还资源" << endl;
    cout << "11. 显示某学生借阅记录" << endl;
    cout << "12. 显示所有学生" << endl;
    //=========新增菜单选项=========
    cout << "13. 保存当前数据" << endl;
    cout << "14. 重新读取保存的数据" << endl;
    //============================
    cout << "0. 退出系统" << endl;
    cout << "====================================" << endl;
}
LibraryResource* createResource()
{
    int type;
    do
    {
        cout << "\n请选择资源类型：" << endl;
        cout << "1. 纸质图书" << endl;
        cout << "2. 杂志" << endl;
        cout << "3. 电子资源" << endl;
        type = readInt("请输入选项：");
        if (type < 1 || type > 3)
        {
            cout << "资源类型不存在，请重新选择！" << endl;
        }
    } while (type < 1 || type > 3);
    string id = readString("请输入资源编号：");
    string name = readString("请输入资源名称：");
    string publisher = readString("请输入出版社或发布单位：");
    int quantity = readPositiveInt("请输入初始数量：");
    if (type == 1)
    {
        string isbn = readString("请输入 ISBN：");
        string author = readString("请输入作者：");
        return new PrintedBook(id, name, publisher, isbn, author, quantity);
    }
    if (type == 2)
    {
        string issueNumber = readString("请输入期号：");
        string publicationCycle = readString("请输入出版周期：");
        return new Magazine(
            id, name, publisher,
            issueNumber, publicationCycle, quantity
        );
    }
    string fileFormat = readString("请输入文件格式：");
    string accessAddress = readString("请输入访问地址：");
    string authorizationType = readString("请输入授权方式：");
    return new ElectronicResource(
        id, name, publisher,
        fileFormat, accessAddress,
        authorizationType, quantity
    );
}
int main()
{
    Library library;
    //=========新增：启动自动加载数据=========
    library.loadData("library_data.txt");
    //=======================================
    int choice;
    cout << "========== 欢迎使用图书馆借阅管理系统 ==========" << endl;
    do
    {
        showMenu();
        choice = readInt("请选择功能：");
        string resourceId;
        string studentId;
        int amount;
        switch (choice)
        {
        case 1:
        {
            LibraryResource* resource = createResource();
            library.addResource(resource);
            break;
        }
        case 2:
            resourceId = readString("请输入资源编号：");
            amount = readPositiveInt("请输入增加数量：");
            library.increaseResourceQuantity(resourceId, amount);
            break;
        case 3:
            resourceId = readString("请输入资源编号：");
            library.showResource(resourceId);
            break;
        case 4:
            library.showAllResources();
            break;
        case 5:
            resourceId = readString("请输入资源编号：");
            amount = readPositiveInt("请输入减少数量：");
            library.decreaseResourceQuantity(resourceId, amount);
            break;
        case 6:
            resourceId = readString("请输入要删除的资源编号：");
            library.removeResource(resourceId);
            break;
        case 7:
        {
            studentId = readString("请输入学生学号：");
            string studentName = readString("请输入学生姓名：");
            library.addStudent(studentId, studentName);
            break;
        }
        case 8:
            studentId = readString("请输入要删除的学生学号：");
            library.removeStudent(studentId);
            break;
        case 9:
        {
            studentId = readString("请输入学生学号：");
            Student* student = library.findStudent(studentId);
            if (student == NULL)
            {
                cout << "借阅失败：没有找到该学生。" << endl;
                break;
            }
            resourceId = readString("请输入要借阅的资源编号：");
            student->borrowResource(library, resourceId);
            break;
        }
        case 10:
        {
            studentId = readString("请输入学生学号：");
            Student* student = library.findStudent(studentId);
            if (student == NULL)
            {
                cout << "归还失败：没有找到该学生。" << endl;
                break;
            }
            resourceId = readString("请输入要归还的资源编号：");
            student->returnResource(resourceId);
            break;
        }
        case 11:
        {
            studentId = readString("请输入学生学号：");
            Student* student = library.findStudent(studentId);
            if (student == NULL)
            {
                cout << "查询失败：没有找到该学生。" << endl;
                break;
            }
            student->showBorrowedResources();
            break;
        }
        case 12:
            library.showAllStudents();
            break;
        //=========新增case13、case14=========
        case 13:
            library.saveData("library_data.txt");
            break;
        case 14:
            library.loadData("library_data.txt");
            break;
        //====================================
        case 0:
            //=========修改原来的case0，退出自动保存=========
            library.saveData("library_data.txt");
            cout << "数据已保存，感谢使用，再见！" << endl;
            break;
        default:
            cout << "选项不存在，请重新输入！" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}

