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
        int myStrlen(char const* strIn);
        bool isEqual(char const* strIn);
        int find(char const* strIn);
        void concat(char const* strIn);      
        
    private:
        bool isSub(char const* strIn, int idx);
        char* str;
        int length;                
};
#endif