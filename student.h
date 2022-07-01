#include <string>
#include "price.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

const int MAX = 6;

class Student
{
 private:
  string first_name;
  string last_name;
  char gender;
  int num_class;
  int arr_class[MAX];
  int stuID;
  Price balance;

 public:
  Student();
  Student(string fn, string ln, char gen, int id);
  int addCourse(int crn);
  void viewAllCourses(const Student& s) const;
  bool dropCourse(int& crn);
  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getNumClasses() const;
  int getstuID() const;
  int getClassOf(int i) const;
  Price getBalance() const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};

#endif
