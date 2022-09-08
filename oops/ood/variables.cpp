/*
Const variable
create a program to use the const keyword with different data types in the C++.  
#include <iostream>  
#include <conio.h>  
using namespace std;  
int main ()  
{  
// declare variables  
const int x = 20;  
const int y = 25;  
int z;  
// add the value of x and y  
z = x + y;  
cout << " The sum of the x and y is: " << z << endl;  
return 0;  
}
*/

/*
const pointer
#include <iostream>  
using namespace std;  
int main ()  
{  
// declaration of the integer variables  
int x = 10, y = 20;  
  
// use const keyword to make constant pointer  
int* const ptr = &x; //  const integer ptr variable point address to the variable x  
  
// ptr = &y; // now ptr cannot changed their address  
*ptr = 15; // ptr can only change the value  
cout << " The value of x: " << x << endl;  
cout << " The value of ptr: " << *ptr << endl;  
return 0;  
} */