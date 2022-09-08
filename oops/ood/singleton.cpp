#include<bits/stdc++.h>
using namespace std;
#define int long long int

// class Singleton
// {
// private:

//     static Singleton* instance; //instance of the class will be stored here.
//     Singleton() { //private constructor to prevent instancing.
//         //do something.
//     }
// public:
//     static Singleton* getInstance(); //static message access.
// };

// Singleton* Singleton::instance = nullptr; //null in begining.

// Singleton* Singleton::getInstance() {
//     if (instance == nullptr)
//         instance = new Singleton();
//     return instance;
// }

class Singleton{
    public :
        // copy constructor deleted 
        Singleton (const Singleton&) = delete;
        static Singleton & Get(){

        }

    private: 
        Singleton(){        } // constructor private
        static Singleton s_instance;
};
Singleton Singleton:: s_instance;
int main(){

}




















int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Singleton* s = Singleton::getInstance();
    Singleton* r = Singleton::getInstance();

    cout << s << endl;
    cout << r << endl; //Address will be same - means same object is returned.

    return 0;
}








