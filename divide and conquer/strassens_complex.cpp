#include <iostream>

using namespace std;

//multiplication of complex nos. but multiplication happens only 3 times not 4
int main()
{
    int a,b,c,d;
    cout<<"Enter 1st no.: ";
    cin>>a;
    cin>>b;
    cout<<"Enter 2nd no.: ";
    cin>>c;
    cin>>d;

    int s1 = d-c;
    int s2 = a+b;
    int s3 = 0-c-d;

    int p1 = a*s1;
    int p2 = c*s2;
    int p3 = b*s3;

    cout<<"Multiplication gives: "<<(p2+p3)<<" + ("<<p1+p2<<")i"<<endl;
}
