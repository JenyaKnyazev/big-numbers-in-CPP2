#include <iostream>
#include <stdio.h>
using namespace std;
void add_to_start(string *s,string s2){
    (*s).insert(0,s2);
}
void char_to_int(string *s){
    for(int i=0;i<(*s).length();i++)
        if( (*s)[i]>='0'&&(*s)[i]<='9')
            (*s)[i]=(*s)[i]-'0';
}
void int_to_char(string *s){
    for(int i=0;i<(*s).length();i++)
        if( (*s)[i]<10&&(*s)[i]>=0 )
            (*s)[i]=(*s)[i]+'0';
}
void refresh(string *s){
    string :: reverse_iterator itr;
    char_to_int(s);
    itr=(*s).rbegin();
    int n=0;
    for(;itr!=(*s).rend();itr++){
        *itr+=n;
        n=*itr/10;
        *itr=*itr%10;
    }
    string t="0";
    t[0]=n;
    if(n)
        add_to_start(s,t);
    int_to_char(s);
}
void erase_zero_from_start(string *s){
    string t;
    int i=0;
    while((*s)[i]=='0'&&i<(*s).length()-1)
        i++;
    for(;i<(*s).length();i++)
        t+=(*s)[i];
        *s=t;
}
void refresh2(string *s){
    char_to_int(s);
    for(int i=0;i<(*s).length()-1;i++){
        (*s)[i]=(*s)[i]-1;
        (*s)[i+1]=(*s)[i+1]+10;
    }
    refresh(s);
    int_to_char(s);
    erase_zero_from_start(s);
}
void plus_(string *s,string *s2){
    while((*s).length()<(*s2).length())
        add_to_start(s,"0");
    char_to_int(s);
    char_to_int(s2);
    for(int i=(*s).length()-1,r=(*s2).length()-1;i>=0&&r>=0;i--,r--)
        (*s)[i]+=(*s2)[r];
    refresh(s);
    int_to_char(s);
    int_to_char(s2);
}
void minus_(string *s,string *s2){
    for(int i=(*s).length()-1,r=(*s2).length()-1;i>=0&&r>=0;i--,r--)
        (*s)[i]=(*s)[i]-(*s2)[r];
    refresh2(s);
}
void decrease_by_one(string *s){
    if((*s).length()>0)
        (*s)[(*s).length()-1]=(*s)[(*s).length()-1]-1;
    refresh2(s);
}
void increase_by_one(string *s){
    char_to_int(s);
    if((*s).length()>0)
        (*s)[(*s).length()-1]=(*s)[(*s).length()-1]+1;
    else
        (*s).push_back('1');
    refresh(s);
}
int compare_(string s,string s2){
    if(s.length()>s2.length())
        return 1;
    if(s.length()<s2.length())
        return -1;
    for(int i=0;i<s.length();i++){
        if(s[i]>s2[i])
            return 1;
        if(s[i]<s2[i])
            return -1;
    }
    return 0;
}
void multiply(string *s,string *s2,string *res){
    while(compare_(*s2,"0")!=0){
        plus_(res,s);
        decrease_by_one(s2);
    }
}
void division_(string *s,string *s2,string *res){
    *res="0";
    while(compare_(*s,*s2)!=-1){
        minus_(s,s2);
        increase_by_one(res);
    }

}
void run(){
    string s,s2,res;
    char ch;
    printf("Arithmetic operations on big numbers C++\n");
    while(1){
        cout<<"Enter arithmetic operator + - * /\nExit enter @\n";
        cin>>ch;
        if(ch=='@')
            break;
        cout<<"Enter first number\n";
        cin>>s;
        cout<<"Enter second number\n";
        cin>>s2;
        switch(ch){
            case '+':
                plus_(&res,&s);
                plus_(&res,&s2);
                break;
            case '-':
                plus_(&res,&s);
                minus_(&res,&s2);
                break;
            case '*':
                multiply(&s,&s2,&res);
                break;
            case '/':
                division_(&s,&s2,&res);
                break;
        }
        cout<<"\nResult = "<<res<<endl;
        s.clear();
        s2.clear();
        res.clear();
    }
}
int main() {
    run();
    puts("\nExit enter\n");
    getchar();
    return 0;
}





















