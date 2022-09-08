#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// class EquilateralTriangle{
//     int sidelen;
//     int circ;
//     double area;
// public:
//     void setEquiTri(int len){
//         sidelen = len;
//         circ = len*3;
//         area = 0.5 * len * 1.73 * len * 0.5;

//     } 
//     double getter(){
//         return area;
//     }
//     friend class Homework ;

// };





// FRIEND FUNC
// void Print(EquilateralTriangle x){
//     cout << x.sidelen << endl;
// }







// FRIEND CLASS
// class Homework{
// public:
//     void Print(EquilateralTriangle x){
//              cout << x.sidelen << endl;
//      } 
// };





// int main(){
//     EquilateralTriangle s1;
//     s1.setEquiTri(3);
//     cout << s1.getter() <<endl;
//     Homework s2;
//     s2.Print(s1);
    
    
    
    
//     Friend FNC
//     Print(s1);

// }








//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------




//VIRTUAL FUNCTIONS
class Instrument{
    public:
    virtual void MakeSound(){
        cout << "BLABLA" <<endl;
    }
};



// // Pure Virtual FNC and ABSTRACT CLASS
// class Instrument{
//     public:
//     virtual void MakeSound() = 0;
// };

class Guitar : public Instrument{
    public:  
    virtual void MakeSound(){
        cout << "JAMAJAM" <<endl;
    }
};

class Sitar : public Guitar{
    public:  
    void MakeSound(){
        cout << "SAMAMA" <<endl;
    }
};




int main(){
    Instrument * r = new Instrument();
    r->MakeSound();
    Instrument * p = new Guitar();
    Instrument * q = new Sitar();
    q->MakeSound();
    p->MakeSound();





}







