//
// Created by floodd on 27/02/2024.
//
#include "Solutions.h"
/**
 *
 *  Draw the Call Stack for the sample code function:
    demoPassByValue(int x, double z);
    at the point just before the function returns

 */
void question1()
{
    string main[] {"main           ","", "a = 10","result = 7","x = 3","y = 4","d = 3.14"};
    string demoPassByValue[] {"demoPassByValue","", "x = 777", "z = 8.11"};

    frame(demoPassByValue, 4);
    frame(main, 7);
}
/**
 *  Write a function density( ) that accepts the width, height, depth, and mass (weight) of a
    solid rectangular block allowing the use of decimal values (i.e. floating point numbers),
    and calculates the density. Test your function by calling it and displaying the result.
 */

double density(double w, double h, double d, double m)
{
    return m / (w*h*d);
}

void question2()
{
    double w, h, d, m;
    cout << "Width: " ;
    cin >> w;
    cout << "Height: " ;
    cin >> h;
    cout << "Depth: " ;
    cin >> d;
    cout << "Mass: " ;
    cin >> m;
    double densityValue = density(w,h,d,m);
    cout << "The density of this object is " << densityValue << endl;
}
/**
    Write a function charToDecimal() that accepts a character as an argument and returns
    the ASCII value of that character (in base 10). Call your function, passing in the character
    ‘a’ and output the returned value.
 */

int charToDecimal(char c)
{
    return (int)c;
}
void question3()
{
    char c = 'a';
    cout << "The decimal value of " << c << " is " << charToDecimal(c) << endl;
}
/*
    Draw the Call Stack for the demoPassByReference() function in the sample code, at the
    point just before it returns.

 */
void question4()
{
    string main[] {"main           ","", "a = 10","result = 7","x = 2000","y = 4","d = 8.11"};
    string demoPassByReference[] {"demoPassByReference","", "x = (main)x", "z = (main)d"};

    frame(demoPassByReference, 4);
    frame(main, 7);
}
/*

     Write a function increment( ) that accepts one integer argument and increments the
    value of the variable in the caller by one. You will need to use a reference parameter of
    type int& in this case. Draw the call stack at the point where the function is about to
    return. What happens if you don’t use a reference parameter?

 */
void increment(int &z)
{
    z++;
}
void question5()
{
    int x;
    cout << "Enter initial value" << endl;
    cin >> x;
    increment(x);
    cout << "Final value of x: " << x << endl;

    cout << "Call stack assuming 4 passed in for x"<<endl;
    string main[] {"main    ","", "x=5"};
    string inc[] {"increment","", "z=(main)x"};

    frame(inc, 3);
    frame(main, 3);


}
/**
    Write a function called swap( ) that will swap the contents of two integer variables in the
    calling function. From the calling function, output the values of the two variables before
    and after the call. Do we need call-by-value or call-by-reference in this case? – explain.
 */
 void swap(int &x, int &y)
{
     int temp = x;
     x = y;
     y=temp;
}
void question6()
{
    int x, y;
    cout << "Enter initial value for x" << endl;
    cin >> x;
    cout << "Enter initial value for y" << endl;
    cin >> y;
    cout << "Initial values: x=" << x << " and y="<<y<<endl;
    swap(x, y);
    cout << "Final values: x=" << x << " and y="<<y<<endl;
}
/**
    Write a function sumRandom(start, end) that will generate 100 random integers in the
    range start -> end, (e.g. 20->200) and return the sum of the numbers.
    https://en.cppreference.com/w/cpp/numeric/random/rand

 */

int sumRandom(int start, int end) {
    srand(time_t(NULL));
    int total=0;
    for (int i = 0; i < 100; i++)
    {
        total += (rand()%(end-start))+start;
    }
    return total;
}
void question7()
{
    int start, end;
    cout << "Start of range: ";
    cin >> start;
    cout << "End of range:";
    cin >> end;
    cout << "The total of 100 numbers in this range is " << sumRandom(start, end) << endl;
}
/**
    Draw a Call Stack for the recursive call factorial(4), at the point of execution where the
    terminating condition becomes true. (See the sample code.) Note that the variable n is
    created many times, but only the variable at the top of the stack is active and in scope at
    a given time. (i.e. the ‘current invocation’ of the function).
 */
void question8()
{
    string main[]  {"main          ","","n = 4"};
    string fact4[] {"factorial(n=4)","","n = 4"};
    string fact3[] {"factorial(n=3)","","n = 3"};
    string fact2[] {"factorial(n=2)","","n = 2"};
    string fact1[] {"factorial(n=1)","","n = 1"};

    frame(fact1, 3);
    frame(fact2, 3);
    frame(fact3, 3);
    frame(fact4, 3);
    frame(main, 3);

}
/**
    Write a recursive function divide( int ) that will take an int argument and will
    repeatedly divide the argument by 2 (integer division), by calling divide() recursively,
    until the argument becomes less than 1. In the divide() function, output the value of the
    argument each time the function is called.

    Assume that the function divide() is called with an argument of 4. Draw a call stack with
    stack frames showing the parameter variable for all method invocations at the point
    when the terminating condition becomes true.
 */
 void divide(int x)
{
     cout << x << endl;
     if(x > 0)
         divide(x/2);
}
void question9()
{
    int x = 4;
    divide(4);

    string main[]  {"main          ","","x = 4"};
    string div4[] {"divide(x=4)","","x = 4"};
    string div2[] {"divide(x=2)","","x = 2"};
    string div1[] {"divide(x=1)","","x = 1"};
    string div0[] {"divide(x=0)","","x = 0"};

    frame(div0, 3);
    frame(div1, 3);
    frame(div2, 3);
    frame(div4, 3);
    frame(main, 3);
}
/**
    Write a recursive function fibonacci( int n ); that returns the Nth Fibonacci number for the
    argument N. The Fibonacci sequence is 0,1,1,2,3,5,8,13,…, where each value in the
    sequence is the sum of the previous two values. The first Fibonacci number, F(1) , is 0, the
    second Fibonaccci number F(2) is 1, the third Fibonacci number F(3) is 1. The Nth Fibonacci
    number, F(N), is defined as the sum of the (N-1)th Fibonacci number and the (N-2)th Fibonacci
    number. So, F(N) = F(N-1) + F(N-2). Using your function, print out the first 10 Fibonacci
    numbers.
 */

int fib(int N)
{
    if(N < 3)
        return N-1;
    return fib(N-1) + fib (N-2);
}

void question10()
{
    int N;
    cout << "Please enter N to represent the Nth Fibonacci number"<<endl;
    cin >> N;
    cout << "The " << N << "th fibonacci number is " << fib(N)<<endl;
}
/**
    Helper functions for drawing the call stacks
*/
string::size_type getMaxLength(string lines[], int size)
{
    string::size_type max = lines[0].length();
    for(int i = 0; i < size;i++)
    {
        if(max < lines[i].length())
        {
            max = lines[i].length();
        }

    }
    return max;
}

void frame(string lines[], int size)
{


    string::size_type max = getMaxLength(lines, size);
    string top(max+4, '*');
    cout << top <<endl;
    for(int i = 0; i < size;i++)
    {
        string padd(max - lines[i].length(), ' ');
        cout << "* " << lines[i] << padd <<" *"<<endl;
    }
    cout << top <<endl;
}



