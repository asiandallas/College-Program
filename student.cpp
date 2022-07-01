#include "student.h"
#include "array.h"
#include "price.h"

// default constructor
Student::Student()
{
  first_name = "unknown";
  last_name = "unknown";
  gender = 'x';
  stuID = -1;
}

// constructor that takes a first & last name, and gender
Student::Student(string fn, string ln, char gen, int id)
{
  first_name = fn;
  last_name = ln;
  gender = gen;
  num_class = 0;
  arr_class[MAX];
  stuID = id;
}

// adds class
int Student::addCourse(int crn)
{
  int notfound; // stores index, -1 otherwise
  notfound = find(arr_class, num_class, crn);

  if(notfound == -1) // key not found, no duplicate
    {
      if(num_class < MAX) // checks if space in array
	{
	  arr_class[num_class++] = crn;
	  return 1;
	}
      else // array is full
	{
	  return -1;
	}
    }
  else // index was found
    {
      return 0;
    }
}

// displays all of courses
void Student::viewAllCourses(const Student& s) const
{
  print(arr_class, num_class);
}

// removes a class
// returns true if found key to remove, otherwise false
bool Student::dropCourse(int& crn)
{
  bool remove_found;
  remove_found = remove(arr_class, num_class, crn);
  if(remove_found)
    {
      num_class--;
      return true;
    }
  else
    {
      return false;
    }
}

string Student::getFirstName() const
{
  return first_name;
}

string Student::getLastName() const
{
  return last_name;
}

char Student::getGender() const
{
  return gender;
}

int Student::getNumClasses() const
{
  return num_class;
}

int Student::getstuID() const
{
  return stuID;
}

int Student::getClassOf(int i) const
{
  return arr_class[i];
}

Price Student::getBalance() const
{
  return balance;
}

void Student::addFee(int d, int c)
{
  Price p(d, c);
  balance = p+balance;
}

void Student::reduceFee(int d, int c)
{
  Price p(d, c);
  balance = balance-p;
}

