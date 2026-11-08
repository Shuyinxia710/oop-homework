#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Library;
class LibraryResource;

class Student
{
private:
    string studentId;
    string name;
    vector<LibraryResource*> borrowedResources;

public:
    Student(string id, string n);

    string getStudentId() const;
    string getName() const;

    bool borrowResource(Library& library, string resourceId);
    bool returnResource(string resourceId);

    int getBorrowedResourceCount() const;
    void showBorrowedResources() const;

    void saveToFile(ofstream& out) const;
    void loadBorrowedResource(LibraryResource* resource);
};

#endif
