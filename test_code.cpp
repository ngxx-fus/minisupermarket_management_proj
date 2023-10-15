#include<bits/stdc++.h>
#define endl '\n'
#include "template_class.h"
using namespace std;

class testT : public templateClass {
    string text;
public:
    testT(){
        text = "This class was created for testing templatClass!";
        refID() = "ID in test Class!";
        refName() = "Name in test Class!";
        refInputPath() = "Input path = C:\\Users\\msnp\\Desktop\\oop-hehehe";
        refOutputPath() = "Output path = C:\\Users\\msnp\\Desktop\\oop-hehehe";
    }
    void print_message(){
        cout << refID() << '\n' << refName() << '\n';
        cout << refInputPath() << '\n' << refOutputPath() << '\n';
        cout << text << endl;
    }

};

int main(){
    testT T;
    T.print_message();
return 0;
}

/**
    ID in test Class!
    Name in test Class!
    Input path = C:\Users\msnp\Desktop\oop-hehehe
    Output path = C:\Users\msnp\Desktop\oop-hehehe
    This class was created for testing templatClass!
 */