#include <iostream>
using namespace std;

//n-no. of states, e-no. of symbols, f-no. of final states
int Language_recognizer(int n,int q0,int f,int* F,int* T,int e,char* E)
{
    char c; int i,current=q0; 
    cout<<"\n\tEnter input string : ";
    scanf("%c",&c);
    while(c!=' ' && c!='\n'){
        
        //find index of c in E using search 
        //can use efficient search algorithms or E.index(c) in python
        switch(c)
        {
            case 'a': i=0; break;
            case 'b': i=1; break;
            default: cout<<"\n\tWrong Input!"; return -1; 
        }
        current=*((T+current*e) + i); // same as current=T[current][i];
        scanf("%c",&c);
    }
    //if current in F: (python)
    //can use efficient searching algorithms, i'm using linear search
    for(i=0;i<f;++i)
        if(current==F[i])
        {
            cout<<"\n\tstring accepted";
            return 0;
        }
    cout<<"\n\tstring NOT accepted";
    return 1;
}
int main()
{
    int n=4,q0=0,e=2,f=1; //n-no. of states, e-no. of symbols, f-no. of final states
    char E[e]={'a','b'}; //E[0]='a',E[1]='b' Note: E[e]-this declaration is accepted only in latest compilers
    int T[n][e]={{1,3},{0,2},{3,1},{2,0}},F[f]={0};
    Language_recognizer(n,q0,f,F,&T[0][0],e,E);
    return 0;
}