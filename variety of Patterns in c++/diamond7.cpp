#include<iostream>
using namespace std;
int main()
{
    int n;
    int i=1;
    cin>>n;
    int n1=((n+1)/2);
    int n2=n/2;
    
    while(i<=n1){
        int j=1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
    while(i<=n){
        int j=i;
        while(j<=n){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
    
    }
