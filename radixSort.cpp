#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int> &v, int digit);
int digit_func(int num, int digit);
void radix(vector<int> &v);
int max_digit(vector<int> v);

int main()
{
    srand(time(0));
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        v.push_back(rand() % 9000000);
    }

    radix(v);

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<','<<' ';
    }

}

void radix(vector<int> &v)
{
    int maxdigit = max_digit(v);
    for(int i=1; i<=maxdigit; i++)
    {
        v = countSort(v, i);
    }
}

vector<int> countSort(vector<int> &v, int digit)
{
    //range is 0 to 9
    vector<int> count(10);
    for(int i=0; i<10; i++){
        count[i] = 0;
    }

    for(int i =0; i<v.size(); i++)
    {
        count[digit_func(v[i], digit)]++;
    }

    for(int i=0; i<10; i++)
    {
        if(i==0)
            continue;
        
        count[i] = count[i-1]+count[i];
    }

    vector<int> ans(v.size());
    for(int i=v.size()-1; i>=0; i--)
    {
        ans[count[digit_func(v[i], digit)]-1] = v[i];
        count[digit_func(v[i], digit)]--;
    }

    return ans;
}

int digit_func(int num, int digit)
{
    int temp = num;
    if(pow(10,digit-1)>num)
    {
        return 0;
    }
    for(int i=digit; i>=1; i--)
    {
        if(i==1)
            return temp%10;
        
        temp = temp/10;
    }

    return 0;
}

int max_digit(vector<int> v)
{
    int max=v[0];
    for(int i=0; i<v.size(); i++)
    {
        if(max<v[i])
        {
            max=v[i];
        }
    }

    int temp=max;
    int ans=0;
    while(temp!=0)
    {
        temp /= 10;
        ans++;
    }

    return ans;
}
