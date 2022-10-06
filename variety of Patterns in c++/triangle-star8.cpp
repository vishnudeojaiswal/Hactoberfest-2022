#include<iostream>
using namespace std;
int main()
{
    int i=1;
    int n;
    cin>>n;
    while (i<=n)
    {
        int space=1;
        while(space<=n-i){
            cout<<" ";
            space++;
        }
        int star=1;
        while(star<=i){
            cout<<"*";
            star++; 
        }
        
        int star2=1;
        while (star2<=i-1)
        {
            cout<<"*";
            star2++;
        }
        cout<<endl;
        i++;
}
}