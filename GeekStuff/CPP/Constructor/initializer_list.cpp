/*
Reference:
https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
This program shows the different ways of initializing the class members using member initializing lists
of a class
*/

#include<iostream>

using namespace std;

/*
A constant variable is one whose value cannot be updated or altered anywhere in your program.
A constant variable must be initialized at its declaration.
*/
class Something
{
private:
    const int m_value;

public:
/*
    // This is not the correct way of initializing a const variable
    Something()
    {
        // error: const vars can not be assigned to, it must be initialized in the constructor
        // inilialization list itself. Becasue all the members of a class are created as soon as
        // the constructor is called.
        m_value = 1; 
    }
*/
    // This is the correct way of initializing a const variable
    Something(int value): m_value(value) {}
};

// Initialization of reference data members
// This is also same as const member above.

#include<iostream>
using namespace std;

class Test {
	int &t;
public:
	Test(int &t):t(t) {} //Initializer list must be used
	int getT() { return t; }
};


/* OUTPUT:
	20
	30
*/

// Initializing array members with member initializer lists

class Something1
{
private:
    const int m_array[5];

public:
    Something1(): m_array { 1, 2, 3, 4, 5 } // use uniform initialization to initialize our member array
    {
    }

};


/*
Initializing the class member which is an object of another class.
In the below example, when the object for Test2 is creates, its member test1(object of Test1)
is also created first. In order to create the test1 object there should be a default constructor.
Since we have a parameterised constructor in Test1, when we create Test2 object we should be
intializing the test1 member using constructor initializer list.
If we don't want to use Initializer, The alternate approach is to have a default constructor.
*/
class Test1
{
    int a;
public:
/*
    Test1()
    {
        cout << "Test1 default constructor called. value of a: " << a << endl;
    }
*/
    Test1(int value): a(value)
    {
        cout << "Test1 constructor called. value of a: " << a << endl;
    }
    int getVal() { return a; };
    int setVal(int val) { a = val; };
};

class Test2
{
    // Object of class Test1.
    Test1 test1;
public:
    
    Test2(int value): test1(value)
    {
        test1.setVal(value);
        // Please note here how we are accessing the member 'a' using get() function.
        cout << "Test2 constructor called. value of a: " << test1.getVal() << endl;
    }
    
    // This will throw below error. becasue there is not default constructor
    // ERR: no default constructor exists for class "Test1".
    // To get rid of this error, we need to have a default constructor for calss Test1.
    /*
    Test2(int value)
    {
        test1.setVal(value);
        // Please note here how we are accessing the member 'a' using get() function.
        cout << "Test2 constructor called. value of a: " << test1.getVal() << endl;
    }
    */
};


int main() {
	int x = 20;
	Test t1(x);
	cout<<t1.getT()<<endl;
	x = 30;
	cout<<t1.getT()<<endl;

    Test2 obj1(10);
	return 0;
}

/*
Summary:
Member initializer lists allow us to initialize our members rather than assign values to them.
This is the only way to initialize members that require values upon initialization,
such as const or reference members, and it can be more performant than assigning values
in the body of the constructor. Member initializer lists work both with fundamental types
and members that are classes themselves.
*/
