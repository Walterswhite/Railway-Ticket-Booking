#include <iostream>
#include "Gender.h"

using namespace std;

Gender::Gender(string s) : name_(s) {};

Male *Male::sInstance = NULL;

Male::Male(string s = "Male") : Gender(s) {}

const Male& Male::Type(){
    if(!sInstance){
        sInstance = new Male();
    }
    return *sInstance;
}
 
string Male::GetName() const{
    return (*this).name_ ;
}

bool Male::IsMale() const{
    if((*this).name_ == "Male"){
            return true ;
    }
    else{
        return false;
    }
}

ostream& operator<<(ostream& os, const Male& ac){
    os<<"Gender : Male"<<endl;
    return os;
}

void Male::UnitTest(){
    Male m;
    if(m.GetName()!="Male"){
        cout << "Male Class : Error in GetName Function" << endl;
    }
    if(m.IsMale()!= true){
        cout << "Male Class : Error in IsMale Function" << endl;
    }
}