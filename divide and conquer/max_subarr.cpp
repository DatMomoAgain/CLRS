#include <iostream>
#include <vector>

using namespace std;

vector<int> max_subarr_mid(vector<int> &arr, int l, int m, int r);
vector<int> max_subarr(vector<int> &arr, int l, int r);

int main()
{
    cout<<"Enter no. of elements: ";
    int n;
    cin>>n;

    vector<int> arr;
    cout<<"Enter elements: ";
    int c;
    for(int i=0; i<n; i++)
    {
        cin>>c;
        arr.push_back(c);
    }

    vector<int> v = max_subarr(arr, 0, arr.size()-1);
    cout<<"Max sum: "<<v[0]<<endl;
    cout<<"Start index: "<<v[1]<<endl;
    cout<<"End index: "<<v[2]<<endl;
}

//returns v[max_sum, left_index, right_index]
vector<int> max_subarr_mid(vector<int> &arr, int l, int m, int r)
{
    vector<int> ans;
    if(l==r)
    {
        ans.push_back(arr[l]);
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }

    int sum=0;
    int max_sumL=INT_MIN;
    int max_sumR=INT_MIN;
    int indexL;
    int indexR;
    for(int i=m; i>=l; i--)
    {
        sum += arr[i];
        if(sum>max_sumL)
        {
            max_sumL = sum;
            indexL=i;
        }
    }
    sum =0;
    for(int i=m+1; i<=r; i++)
    {
        sum+=arr[i];
        if(sum>max_sumR)
        {
            max_sumR = sum;
            indexR=i;
        }
    }

    ans.push_back(max_sumL+max_sumR);
    ans.push_back(indexL);
    ans.push_back(indexR);

    return ans;
}

//returns v[max_sum, left_index, right_index]
vector<int> max_subarr(vector<int> &arr, int l, int r)
{
    vector<int> v;
    vector<int> vR;
    vector<int> vL;
    vector<int> vM;
    if(l==r)
    {
        v.push_back(arr[l]);
        v.push_back(l);
        v.push_back(r);
        return v;
    }
    int m = (l+r)/2;

    vL = max_subarr(arr, l, m);
    vR = max_subarr(arr, m+1, r);
    vM = max_subarr_mid(arr, l, m, r);
    
    if(vL[0]>=vR[0] && vL[0]>= vM[0])
        return vL;
    else if(vR[0]>=vL[0] && vR[0]>=vM[0])
        return vR;
    else
        return vM;
}
