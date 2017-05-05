//
//  PointersThisKeyword.cpp
//  DataStructures
//
//  This program is part 2 of PointersHeapReview. It will cover more on pointers dereferencing and 'this' keyword.
//  And it touches on debugging
//  We are going to wrap up two data members into a class, the numerator and the denominator
//  And we will look at operator overloading at the sametime, so that we can add, subtract
//  multiply and divide these fractions at the same time

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
//#include <conio.h>    _getch(); Windows only

using std::cout;
using std::endl;
using std::string;


// Start of fraction class definition (non-template class)
class Fraction {
public:
    Fraction(int numerator, int denominator);       //Fraction class constructor
    ~Fraction() {}                                  //Fraction class destructor - not needed in this example
    Fraction mult(const Fraction& rightOperand);    //mult method declaration, passes Fraction by reference
    Fraction add(const Fraction& rightOperand);     //add method declaration, passes Fraction by reference
    void print();                                   //print method declartion
    
private:
    int numerator;
    int denominator;
};

//////////////////////////////////////////////////////
//Fraction constructor definition
Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//Multiply method definition
Fraction Fraction::mult(const Fraction& rightOperand) {                 //first part is return type, then name of class, then scope
    int newNumerator = this->numerator * rightOperand.numerator;        //the 'this' keyword is pointing to the 'a fraction object' or 'this' dereferences and
                                                                        //then says go its data member and get the numerator data member out of it
    int newDenominator = this->denominator * rightOperand.denominator;
    
    Fraction temp(newNumerator, newDenominator);                        //create a new Fraction object with data members newNumerator and new Denominator
    return temp;
}
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//Add method definition
Fraction Fraction::add(const Fraction& rightOperand) {                      //first part is return type, then name of class, then scope
    int newNumerator = rightOperand.denominator * this->numerator + rightOperand.denominator * this->denominator;          //the 'this' keyword is pointing to the 'a fraction object' or 'this' dereferences and
                                                                            //then says go its data member and get the numerator data member out of it
    
    int newDenominator = this->denominator * rightOperand.denominator;
    
    Fraction temp(newNumerator, newDenominator);                        //create a new Fraction object with data members newNumerator and new Denominator
    return temp;
}
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
//Print method definition                                               //first is return type of void, second is name of class 'Fraction', then name of method, then scope resolution
void Fraction::print(){
    cout << numerator << '/' << denominator << endl;
    return;
}
//////////////////////////////////////////////////////


int main() {
    cout << "You define a class like this:\n"
    << "\n"
    << "class Fraction {\n" << "public:\n"
    << "Fraction(int numerator, int denominator); //this is the Fraction class constructor declaration\n"
    << "\n"
    << "private:\n"
    << "int numerator;\n"
    << "int denominator;\n"
    << "};\n"
    << endl;
    

    cout << "//'::' is the Scope Resolution Operator which is used to define member functions outside of a class\n"
    << "//This is how you could dereference a pointer and get to its data member: *this.dataMember\n"
    << "//The problem is that the dot operator comes first in C++ order preference and we are dealing with pointers and addresses\n"
    << "\n"
    << "//Start of Fraction class constructor definition\n"
    << "Fraction::Fraction(int numerator, int denominator) {\n"

    
    << "this->numerator\n"
    << "}\n"
    << "\n"
    << endl;
    
    //Both Fraction 'a' and Fraction 'b' live on the stack, we are not allocating memory on the heap
    //The are cleaned up at the 'end curly brace' or 'end scope' - both refer to end of program
    //We do not need a destructor
    Fraction a(2,3);
    Fraction b(3,5);
    
    //
    Fraction c = a.mult(b);
    c.print();  //we don't have to use 'this->' because there are no conflicts so the compiler can work it out
   
    
    
    return 0;
}

