/////////////////////////////////////////////////////////////////////
//
// Name: Landon Burns
// Date: 4/21/2022
// Class: CSCI 1370.04
// Semester: Spring 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Program Description: This takes and displays the grade and names. It also displays the curved grade.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

// Include here the libraries that your program needs to compile


using namespace std;

// Insert here your function prototypes
	int getData(ifstream& inner, string name[], int grade[]);
	int getMax(int grade[], int wreck);
void printData(ofstream& outer, string name[], int actualGrade[], int n, int high);
int curveGrade(int lgrade, int high);

// Declare here constant MAX

const int MAX = 40;

int main()
{
	// Declare all the variables that will be used to process the data
    ifstream inner;
    ofstream outer;
    string name[MAX];
    int grade[MAX];
    int wreck;
  int high;
  
	// Open the files ensuring they are opened
   inner.open("input18.txt");
  outer.open("output18.txt");
    if(!inner){

      cout << "Input file not open" << endl;
      
    }
  
   if(!outer)
    {
        cout << "Output file not open" << endl;
    }

  
	// Call the functions to process the data

  wreck = getData(inner, name, grade);
   
  high = getMax(grade, wreck);
  
   printData(outer, name, grade, wreck, high);

  

	// Close the files

return 0;		
}


//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement


// Receives the input file, the array of students� names, and the array of students� grades.
// It reads the input data from the file into the corresponding arrays and returns them along
// with the quantity of students processed to main().Although there should be no more than 40
// students this function must ensure that if the file has more than 40 records it reads only
// the first 40 and displays a warning on the screen indicating that the maximum has been exceeded.


	int getData(ifstream& inner, string name[], int grade[]){
   int count = 0;
   while(!inner.eof())
   {
       inner >> name[count] >> grade[count];
       count++;
       if(count==MAX)
       {
           cout << "Maximum is reached" << endl;
           break;
       }  
   }
  
   return count;
}


// Receives the array of students� grades and the quantity of grades to process. It determines
// and returns to main() the highest grade among the students.


	int getMax(int grade[], int wreck)
{
   int high;
    high = grade[0];
   for(int i = 1; i < wreck; i++)
   {
       if(grade[i] > high)
           high = grade[i];
   }
  
   return high;
}



// Receives the output file, the array of students� names, the array of students� grades, the
// quantity of students to process, and the highest grade among the students.It prints the output
// to the output file as shown in Figure 2. This function must call a function named curveGrade()
// to get the values for the curved grades(curved grade = actual grade / highest grade * 100).



void printData(ofstream& outer, string name[], int grade[], int wreck, int high)
{
   outer << setw(15) << "Student" << setw(15) << "Actual" << setw(15) << "Curved" << setw(15) << "Graph" << endl;
   outer << setw(15) << " Name" << setw(15) << " Grade" << setw(15) << " Grade" << endl;
   outer << setw(18) << "-------------" << setw(15) << "---------"
         << setw(15) << "--------" << setw(20) << "--------------" << endl;

   for(int i = 0; i < (wreck - 1); i++)
   {
       int gradeder = curveGrade(grade[i], high);
       outer << right << setw(15) << name[i] << right << setw(12) << " "
             << right << setw(3) << grade[i] << right << setw(12) << " "
           << right << setw(3) << gradeder << right << setw(10) << " "
           << left << setw(1) << "|";
  gradeder = static_cast<double>(gradeder);
int rounded = round(gradeder / 10);
       for(int coun = 0; coun < rounded; coun++)
       {
           outer << left << setw(1) << "*";
       }
       outer << endl;
   }
}



// Receives the actual and the highest grades and returns the curved grade. Since the arguments that
// it receives are whole numbers, the result of the division must be rounded off to the ones before 
// it is returned by the function.

int curveGrade(int lgrade, int high)
{
   int gradeder;
lgrade = static_cast<double>(lgrade);
  gradeder = (static_cast<double>(lgrade)/high)*100;
   return gradeder;
}