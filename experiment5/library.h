#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "libraryresource.h"
#include "student.h"

using namespace std;

class Library
{
private:
    vector<LibraryResource*> resources;
    vector<Student> students;

public:
    Library();
    ~Library();

    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

    bool addResource(LibraryResource* resource);
    LibraryResource* findResource(string id) const;
    bool showResource(string id) const;
    void showAllResources() const;
    bool increaseResourceQuantity(string id, int amount);
    bool decreaseResourceQuantity(string id, int amount);
    bool removeResource(string id);
    int getResourceCount() const;

    bool addStudent(string id, string name);
    Student* findStudent(string id);
    bool removeStudent(string id);
    void showAllStudents() const;
    int getStudentCount() const;
};

#endif
