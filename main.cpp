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
    string t;
    t.push_back('0'-48);
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
void multiply2(string *s,string *s2,string *res){
    char_to_int(s);
    char_to_int(s2);
    for(int i=0;i<(*s).length();i++)
        (*res).push_back('0'-48);
    for(int i=0;i<(*s2).length();i++)
        (*res).push_back('0'-48);
    for(int r=(*s).length()-1,j=0;r>=0;r--,j++){
        for(int i=(*s2).length()-1,k=0;i>=0;i--,k++){
            (*res)[(*res).length()-1-(j+k)]+=((*s)[r]*(*s2)[i]);
        }
        refresh(res);
        int_to_char(res);
        char_to_int(res);
    }
    int_to_char(s);
    int_to_char(s2);
    int_to_char(res);
    erase_zero_from_start(res);
}
void division_(string *s,string *s2,string *res){
    *res="0";
    while(compare_(*s,*s2)!=-1){
        minus_(s,s2);
        increase_by_one(res);
    }

}
void division2(string *s,string *s2,string *res){
    string temp;
    //char_to_int(&s)
    for(int i=0;i<(*s).length();i++){
        temp.push_back( (*s)[i++] );
        while(i<(*s).length()&&compare_(temp,*s2)==-1){
            (*res).push_back('0');
            temp.push_back((*s)[i++]);
        }
        int n=0;
        while(compare_(temp,*s2)!=-1){
            minus_(&temp,s2);
            n++;
        }
        if(n){
           (*res).push_back(n+48);
        }else{
            (*res)+=temp;
        }
        if(compare_(temp,"0")==0)
            temp.clear();
        i--;
    }
    erase_zero_from_start(res);
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
    //run();
    string s,s2,res;
    cin>>s;
    cin>>s2;
    division2(&s,&s2,&res);
    cout<<res;
    puts("\nExit enter\n");
    getchar();
    return 0;
}





















