// printer example with try catch and throw exceptions

#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
class Printer{
    char * name;
    int availablePaper;
public:
    Printer(char * name , int availablePaper){
        name = new char[100];
        this->name = name;
        this->availablePaper = availablePaper;
        
    }
    void Print(string textdoc){
        int reqPaper = textdoc.size()/10; //if 40 char then we will need 4 paper toprint the doc
        // if(reqPaper > availablePaper)throw "Error , not enough paper";
        // throw is gonna break the excetion of the fnc
         if(reqPaper > availablePaper)throw "ERROR";

        cout << " Printing ... " << textdoc <<endl;
        availablePaper -= reqPaper;
    }
};


int main(){
    char name[6] = "HPJET";
    Printer printer(name , 10);
    // to handle the exception use try /catch blocks
    //Pls ttry to exec the foll code
    try{
        printer.Print("hi I am Ishan Minhas, I study Computer Sci");
        printer.Print("hi I am Ishan Minhas, I study Computer Sci");
        printer.Print("hi I am Ishan Minhas, I study Computer Sci");
        printer.Print("hi I am Ishan Minhas, I study Computer Sci");
        printer.Print("hi I am Ishan Minhas, I study Computer Sci");
        printer.Print("hi I am Ishan Minhas, I study Computer Sci");
        printer.Print("hi I am Ishan Minhas, I study Computer Sci");
    }
    // but if you get execp you are gonna catch and you are gonna handle it in the below block of code
    catch(const char * txtexception){
        // we use const char * bcz we threw sttring exception 
        cout << "Exception : " << txtexception <<endl;
    }
    // can wrtie multiple catch bloack for 1 try blocks
    catch(int excode){
        cout <<" Exception : " <<excode <<endl;
    }
    //Default Exception handler
    catch(...){
        // this will handle all types of exceptions
        //but since we have excep blocks for specific datatypes before this block it will not work
        // and user defined exception blocks will always come before default block
        cout << "Exception handled "<<endl;
    }

    string s;
    getline(cin , s);
    cout << s.length();
    return 0;
}