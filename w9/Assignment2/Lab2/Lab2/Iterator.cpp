//
//  Iterator.cpp
//  Lab2
//
//  Created by GUW06 on 2023-03-14.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student;

class StudentIterator {
public:
    virtual bool hasNext() const = 0;
    virtual Student& next() = 0;
};

class VectorStudentIterator : public StudentIterator {
public:
    VectorStudentIterator(vector<Student>& students) : students_(students), index_(0) {}
    bool hasNext() const override {
        return index_ < students_.size();
    }
    Student& next() override {
        return students_[index_++];
    }
private:
   vector<Student>& students_;
    int index_;
};

class Student {
public:
    Student(const string& name, string id) : name(name), id(id) {}
    const string& getName() const {
        return name;
    }
    const string& getId() const {
        return id;
    }
private:
    string name;
    string id;
};
