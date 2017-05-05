//
//  PointersHeapReview.cpp
//  DataStructures
//
//  Created by Hurtado, Ken on 3/31/17.
//  Copyright © 2017 Hurtado, Ken. All rights reserved.
//
//  This is a review of video 2420 may112015
//  I stopped st 1:22:26

#include <stdio.h>
#include <iostream>
#include <iomanip>
//#include <conio.h>    _getch(); Windows only

using namespace std; 

int main() {
    
    cout << "Hello, World!" << endl;
    
    //all of these examples below can be read from right to left
    
    //ptr uses 64-bits of memory or 64-bits of addressable space, on a 64-bit machine
    int * ptr;      //the '*' means declare pointer
    cout << "The command 'int * ptr' equals: ptr is at address " << ptr << " after being declared but not initializied." << endl;
    ptr = NULL;     //initialize pointer to NULL so it doesn't have garbage address
    cout << "The command 'ptr = NULL' equals: ptr is at address " << ptr <<  " after being initialized to NULL." << endl;
    
    int value = 42;     //initialize value variable to 42
    //assign address to pointer
    //the & sign is the 'address of' operator.
    //Where ever value is in memory, tell me that address. And ptr has a copy of it.
    ptr = &value;
    
    cout << "The command 'ptr = &value' equals: take the 'address of' the variable 'value' and assign it to ptr, so that ptr address is now " << ptr << "." << endl;
    
    //*ptr means dereference
    cout << "The command '*ptr' equals: go to the spot that ptr is pointing to, dereference it, and display the data in it which is " << *ptr << "." << endl;
    
    //*ptr dereferences ptr and says go to the spot that ptr is pointing to and stick 12 in that spot
    *ptr = 12;
    cout << "The command '*ptr = 12' equals: go to the spot that ptr is pointing to and stick 'values' value of " << value << " in that spot." << endl;
    
    //this can be read from right to left
    int ** fun;
    cout << "The command 'int ** fun' equals: 'fun' is a pointer to a pointer to 'int." << endl;
    
    //fun can hold the address of our pointer ptr
    fun = &ptr;
    cout << "The command 'fun = &ptr' equals: fun can hold the address of ptr which is " << &ptr << "." << endl;
    
    //ptr holds a value which is an address, that value is stored in RAM at the memory address location
    cout << "ptr holds a value that is an address of " << &ptr << ", which is an address in RAM" << endl;
    
    //double dereferencing the address of an address to get the value
    cout << "The command **fun equals: a double dereference of 'fun' so we can go to the address of an address which holds the value of " << **fun << endl;
    
    //now we start ararys
    /*On our computer we have two memory spaces and one is called the stack which is about 1 MB or so. 
     When we declare variables or call functions they are all placed in the stack. If I declare int value
     it is placed on the stack. When you run a program you are given a stack of memory which runs right
     to left. And we get to fill it up.
     */
    int * arr = new int[100];  //declare pointer to an array of type int named 'arr' and allocate a chunk of memory of size 100
    cout << "\nOn our computer we have two memory spaces and one is called the stack which is about 1 MB or so." <<
    " When we declare variables or call functions they are all placed on the stack. If I declare int value it is placed on the stack."
    << "When you run a program you are given a stack of memory which runs right to left. And we get to fill it up. " <<
    "This implies we can't have a lot of data. So if we need more memory we need to go somewhere else, like the heap. " <<
    "How big is heap? Usually about as big as our addressable space can be. Which is either the logical addressable space or the physical amount of RAM " <<
    "plus any spillover to hard drive if necessary. So gigabytes in size. So how do we access the heap, or stick a variable on the heap? " <<
    "We use the 'new' keyword. The 'new' keyword querries Windows and says 'please give me a spot in heap'. Windows will say, 'I need more " <<
    "information, I can't just give you a spot you have to tell me how much'. So the compiler says, 'OK, please give me 100 ints or int[100]'. " <<
    "Windows says that it doesn't know what 100 ints is, but the compiler does. 4 bytes is an int. So 4x100, the compiler says I need 400 bytes. " <<
    "Windows says that it can do that. And then Windows goes into heap, alocates 400 bytes, and then Windows reutrns the address to the very first element. " <<
    "If it's going to return an address, how do we manage that thing? What data type do we use to store addresses? Pointers!!" << endl;
    
    //
    cout << "The command 'int * arr' equals: array is a pointer to some int." << endl;
    cout << "The command ' new int[100]' equals: that pointer to int is holding something, which is the address to the first of 100 elements that will be treated as if they were ints." << endl;
    
    cout << "\nIn other words, it's just a pointer to some chunck of data in memory." << endl;
    
    //currently our array just holds garbage because it hsan't been initialize
    *arr = 111;
    cout << "\nThe command '*arr = 666' equals: dereference arr and assign the value of 666 to it." << endl;
    cout << "the array's 0th index is: " << *arr << endl;
    
    //this moves our pointer over one spot, or because it's an int, it adds four bytes. If it were a double it would add eight
    //this is how you traverse through an array
    arr = arr + 1;
    //now that we are looking at one spot to the right, we can assign a value to it
    *arr = 222;
    cout << "The array's 1 index is: " << *arr << endl;
    
    //_getch(); keeps command window open until any key pressed, get character. Windows only
    return 0;
}

