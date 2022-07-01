/*****************************************************************************                                                                                                           
Kyrstn Hall                                                                                                                                                                              
10/27/2021                                                                                                                                                                               
CS 211                                                                                                                                                                                   
Homework - college.cpp                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
*****************************************************************************/

#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "student.h"
#include "array.h"
#include <fstream>

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

void addStu(Student arr[], int& num, int& ID);
void showStuInfo(Student& s);
void allStuInfo(Student arr[], int& num);
bool  operator==(const Student& s, int id);
void removeStu(Student arr[], int& count);
void addStuFromFile(Student arr[],int&num, int& ID);
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student& s);
int showMenu();
int showAdmMenu();
int showStuMenu();

int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating

  Student stud_arr[SIZE];

  /******************* PHASE 1********************************/
  /*
  cout << "-------- adding the first student --------" << endl;
  addStu(stud_arr, count, curID);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(stud_arr[0]);  //pass the first student 
  cout << "-------- adding student 2, 3, and 4 --------" << endl;
  addStu(stud_arr, count, curID);
  addStu(stud_arr, count, curID);
  addStu(stud_arr, count, curID);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(stud_arr, count);
  cout << "-------- removing stu 2 --------" << endl;
  removeStu(stud_arr, count); //remove the second stu
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(stud_arr, count);
  cout << "-------- removing the last student --------" << endl;
  removeStu(stud_arr, count); //remove the last stu
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(stud_arr, count);
  
  cout << "-------- adding from file --------" << endl;
  addStuFromFile(stud_arr, count, curID);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(stud_arr, count);
  */
  
  /******************* PHASE 2********************************/
  /*
  cout << "-------- adding the first student --------" << endl;
  addStu(stud_arr, count, curID);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(stud_arr[0]);
  cout << "-------- addiing 111 to a student --------" << endl;
  addCourse(stud_arr[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(stud_arr[0]);
  cout << "-------- addiing 222 to a student --------" << endl;
  addCourse(stud_arr[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(stud_arr[0]);
  cout << "-------- addiing 222 again to a student ==> error --------" << endl;
  addCourse(stud_arr[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(stud_arr[0]);
  cout << "-------- removing 222 --------" << endl;
  dropCourse(stud_arr[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(stud_arr[0]);
  cout << "-------- removing 333 ==> error --------" << endl;
  dropCourse(stud_arr[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(stud_arr[0]);

  
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 20 0. If you did, enter 20" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(stud_arr[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(stud_arr[0]);
  
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 10 14. If you did, enter 10.14" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(stud_arr[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(stud_arr[0]);
  cout << "########################################################################################" << endl;
  cout << "Did you work on the bonus feature where you reject an over payment? Enter Y or N:";
  char ans;
  cin >> ans;
  if(ans == 'Y' || ans == 'y')
    {
      cout << "-------- For bonus, making an overpayment ==> show error and won't be processed --------" << endl;
      makePayment(stud_arr[0]);
      cout << "-------- showing the info --------" << endl;
      showStuInfo(stud_arr[0]);
    }
  else
    cout << "You didn't work on the bonus feather for overpayment" << endl;
  */

  /******************* PHASE 3********************************/
  int choice; // store user's choice 
  do
    {
      choice = showMenu();
    
      if(choice == 1) // admissions office
	{
	  int pass; // user input's password attempt
	  cout << "Enter the password: ";
	  cin >> pass;
	  if(pass == PASSWORD) // correct password
	    {
	      int adm_choice;
	      do // show adm menu until user enters 6
		{
		  adm_choice = showAdmMenu();
		  cout << endl;
		  switch(adm_choice)
		    {
		    case 1: // add new student
		      addStu(stud_arr, count, curID);
		      break;
		    case 2: // add student from file
		      addStuFromFile(stud_arr, count, curID);
		      break;
		    case 3: // drop a student
		      removeStu(stud_arr, count);
		      break;
		    case 5: // view all student info
		      allStuInfo(stud_arr, count);
		      break;
		    case 4: // view one student info                                                                                                                                  
                      int stud_id;
                      cout << "Enter the student ID: ";
                      cin >> stud_id;

                      int index;
                      index = find(stud_arr, count, stud_id); // will return index otherwise -1                                                                              
		   
                      switch(index)
                        {
                        case -1: // not found                                                                                                                                         
                          cout << "The student ID doesn't exist.\n" << endl;
                          break;
                        default: // index of id                                                                                                                                       
                          showStuInfo(stud_arr[index]);
                          break;
                        }
		    }
		}while(adm_choice == 1 || adm_choice == 2 || adm_choice == 3 || adm_choice == 4 || adm_choice == 5);
	    }
	  else // incorrect password
	    {
	      cout << "The password is wrong\n" << endl;
	    }
	}
      else if(choice == 2) // student
	{
	  int id;
	  cout << "Enter the student ID: ";
	  cin >> id;
	  int index;
	  index = find(stud_arr, count, id); // will return index otherwise -1     
	  if(index == -1) // not found
	    {
	      cout << "The student ID doesn't exist." << endl;
	    }
	  else // entered correct ID
	    {
	      // password is calculated by student id % (prime1(35) * prime2(5))
	      // id of 100000 is 25
	      int pass = id % (PRIME1 * PRIME2); 
	      int pass_attempt; // user's input
	      cout << "Enter the password: ";
	      cin >> pass_attempt;
	      
	      if(pass_attempt == pass) // correct password
		{
		  int stu_choice;
		  cout << "Welcome " << stud_arr[index].getFirstName() << endl;
		  do
		    {
		      stu_choice = showStuMenu();
		      cout << endl;

		      switch(stu_choice)
			{
			case 1:
			  addCourse(stud_arr[index]); // add course
			  break;
			case 2:
			  dropCourse(stud_arr[index]); // drop course
			  break;
			case 3:
			  makePayment(stud_arr[index]); // make payment
			  break;
			case 4: 
			  showStuInfo(stud_arr[index]); // show student info
			  break;
			}
		    }while(stu_choice == 1 || stu_choice == 2 || stu_choice == 3 || stu_choice == 4);
		}
	      else // wrong password
		{
		  cout << "The password is wrong.\n" << endl;
		}
	    }
	}
    
    }while(choice == 1 || choice == 2);

  return 0;
}



// ************************  PHASE 1  ****************************

/*******************************************
arr is student object array
num is number of students
ID is start (100000) to add 

This function adds a student and returns a new object
 *******************************************/

void addStu(Student arr[], int& num, int& ID)
{
  string fN, lN; // first name, last name
  char gen; // gender

  if(num == MAX) // reached max students allowed
    cout << "Error: Cannot add more students" << endl;

  else
    {
      //case 1 of admission
      cout << "Enter the first name: ";
      cin >> fN;
      cout << "Enter the last name: ";
      cin >> lN;
      cout << "Enter the gender: ";
      cin >> gen;
      cout << endl;
      //create a student object. The first student created is given a stu id, 100000 (coming from const START).
      //The second student gets 100001, the third student gets 100002, etc (notice curID in main).
      if(num!=0)
	ID = ID+1; 
      else 
	ID = START;


      Student s1(fN, lN, gen, ID);

      //copy the info from the stu obj into the array at the appropriate slot
      arr[num] = s1;
      num++;
    }
}

/*******************************************                                                                                 
Student s is the student object
                                                                                                                             
This function shows all student info                                                                        
*******************************************/
                                                                                                 
void showStuInfo(Student& s) 
{                                                                                                                                             
  //*********************************************************************
  //DO NOT send the entire array to this function. BIG deduction if you do.
  //SEND only ONE student object as a parameter. If you don't know how, check
  //lab1-struct.cpp.
  //********************************************************************** 
  
  cout << "--------------------" << endl;                                                                                                                                                           
  cout << "first name: " <<  s.getFirstName() << endl;                                                                                                 
  cout << "last name: " << s.getLastName() << endl;                                                                                                  
  cout << "gender: " << s.getGender() << endl;                                                                                               
  cout << "stu id: " << s.getstuID() << endl;                                                                                                      
  cout << "num classes: " << s.getNumClasses() << endl;                                                                                                                                                 
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < s.getNumClasses(); i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i) << " ";                                                                                                                 
                                                                                                                                              
  cout << "\nAmount owed $" << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once                   
  cout << endl;                                                                                                                               
}

/*******************************************                                                                                 
arr is student object array                                                                                                  
num is number of students                                                                                                                                                                                                                                                                                    
This function shows all students in array w/ info                                                                        
*******************************************/
void allStuInfo(Student arr[], int& num)
{
  //Case 5 of Admission and case 4 of student
  //Call showStuInfo()
  //******************************************
  //YOU MUST call showStuInfo() to show each student.
  //*******************************************
  
  cout << "Displaying all students:\n" << endl;
  for(int i=0; i<num; i++)
    {
      showStuInfo(arr[i]);
    }
}


/*******************************************                                                                                 
student s is student object
id is student's ID                                                                                                  
                                                                                                                             
This function adds a student and returns a new object                                                                        
*******************************************/
bool operator==(const Student& s, int id) 
{
  if(s.getstuID() == id)
    return true;
  else
    return false;
}

/*******************************************                                                                                 
arr is student object array                                                                                                  
count is number of students                                                                                                    
                                                                                                                             
This function adds a student and returns a new object                                                                        
*******************************************/
void removeStu(Student arr[], int& count)
{
//Case 3 of Admission

//2 different messages

     //"student with id " << id << " doesn't exist" << endl;
     // f << " " << l << " has been removed." << endl;
  int id;
  cout << "Enter the student id: ";
  cin >> id;
  int key_index = find(arr, count, id); // to know which index key is in

   if(key_index == -1) // not found 
    {
      cout << "student with id " << id << " doesn't exist" << endl;
    }
  else // returned index -> id exists and can remove it
    {
      string fn = arr[key_index].getFirstName(); // first name                                                                                            
      string ln = arr[key_index].getLastName(); // last name   
      if(remove(arr, count, id))
	{
	  cout << fn << " " << ln << " has been removed." << endl;
	  count--;
	}
      
    }
}

/*******************************************                                                                                 
arr is student object array                                                                                                  
num is number of students                                                                                                    
ID is start (100000) to add                                                                                                  
                                                                                                                             
This function adds a student and returns a new object                                                                        
*******************************************/
void addStuFromFile(Student arr[],int& num, int& ID)
{
  //Case 2 of admission
  ifstream fin;
  string fileName;
  cout << "Enter input file name: ";
  cin >> fileName;
  fin.open(fileName.c_str());
  if(!fin)
    {
      cout << "ERROR: " << fileName << " doesn't exist!" << endl;
    }
  else
    {
      while(!fin.eof())
	{
	  string fN, lN; // first name, last name                                                                                                                                              
	  char gen; // gender                                                                                                                                                                  

	  //case 1 of admission                                                                                                                                                                
	  fin >> fN;
	  fin >> lN;
	  fin >> gen;
	  fin.ignore();

	  //create a student object. The first student created is given a stu id, 100000 (coming from const START).                                                                            
	  //The second student gets 100001, the third student gets 100002, etc (notice curID in main).                                                              
	  if(num!=0)
	    ID = ID+1;
	  else
	    ID = START;

	  Student s1(fN, lN, gen, ID);

	  //copy the info from the stu obj into the array at the appropriate slot                                                                                                              
	  arr[num] = s1;
	  num++;
	}
      //allStuInfo(arr, num); // displays students from file
    }
  fin.close();
}


//*******************  PHASE 2 ****************************

void addCourse(Student& s)
{
//case 1 of student
//FYI, I am passing one student to this function not the array. 


//3 different messages to show

  // " has been added successfully" << endl;
  // " was not added because you have " << crn << " already." <<  endl;
  // " was not added because your schedule is full." <<  endl;

  int course;
  cout << "Enter course number you would like to add: ";
  cin >> course;

  int add = s.addCourse(course); // -1 if array is full, 0 if duplicate, 1 if added. 
  if(add == -1)
    cout << course << " was not added because your schedule is full." <<  endl;        
  else if(add == 0)
    cout << course << " was not added because you have " << course << " already." <<  endl;   
  else // 1, $50.14 for each course
    {
      s.addFee(50, 14);
      cout << course << " has been added successfully" << endl;
    }
}


void dropCourse(Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 

//2 different messages
    // " wasn't dropped from " << s.getFirstName() << " because " << cr << " doesn't exist" << endl;
    // " has been dropped successfully." << endl;
  s.getNumClasses();
  int course;
  cout << "Enter course number you would like to drop: ";
  cin >> course;

  bool drop = s.dropCourse(course);

  if(drop) // dropped
    {
      s.getNumClasses();
      s.reduceFee(50, 14);
      cout << course << " has been dropped successfully" << endl;
    }
  else // course not found, not dropped
    cout << course << " wasn't dropped because " << course << " doesn't exist" << endl;
}

void makePayment(Student& s)
{
//case 3 of student
//FYI, I am passing one student to this function not the array.  

  int d, c;
  cout << "You owe $" << s.getBalance()  << endl;
  cout << "Enter your payment: ";
  cin >> d >> c;

  s.reduceFee(d, c);
}

int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}
