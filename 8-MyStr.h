#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
    public:
        MyString(char const* strIn);
        ~MyString();
        void myDisplay();
        void myStrcpy(char const* strIn);
        int myStrlen();
        bool isEqual(char const* strIn);
        int find(char const strIn);
        void concat(char const* strIn);      
        char* str;
        int length;  
    private:
        bool isSub(char const* strIn, int idx);
        
};
#endif