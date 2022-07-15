#ifndef GENDER_H
#define GENDER_H

#include <iostream> 
using namespace std;

class Gender{
    protected:
        string name_;
    public :
        Gender(string a);
        virtual string GetName() const = 0;
        virtual bool IsMale() const = 0;
        ~Gender();
};

class Male : public Gender{
    private:
        static Male *sInstance;
        Male(string a);
    public:  
        static const Male& Type();
        string GetName() const;
        bool IsMale() const;
        friend ostream& operator<<(ostream& os, const Male& ac); 
        static void UnitTest();
};

class Female : public Gender{
    private:
        static Male *sInstance;
        Female(string a);
    public:  
        static const Male& Type();
        string GetName() const;
        bool IsMale() const;
        friend ostream& operator<<(ostream& os, const Female& ac);
        static void UnitTest(); 
};
#endif