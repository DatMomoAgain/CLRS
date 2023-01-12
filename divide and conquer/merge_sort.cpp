#include <iostream>
#include <vector>

using namespace std;

void disp(int* arr, int n);
void merge_sort(int* arr, int p, int r, int n);

int main()
{
    int n;
    cout<<"No. of elements: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1,n);
    disp(arr,n);
}

void disp(int* arr,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int* arr, int p, int q, int r, int n)
{
    int le[q-p+1];
    int ri[r-q];

    for(int i=0; i<q-p+1; i++)
    {
        le[i] = arr[p+i];
    }
    for(int i=0; i<r-q; i++)
    {
        ri[i] = arr[q+i+1];
    }

    int i1=0;
    int j1=0;
    for(int i=p; i<r+1; i++)
    {
        if(le[i1]<ri[j1])
        {
            arr[i]=le[i1];
            i1++;
            if(i1==q-p+1)
            {
                for(int j=i+1; j<r+1; j++)
                {
                    arr[j]=ri[j1];
                    j1++;
                }
                break;
            }
        }
        else
        {
            arr[i]=ri[j1];
            j1++;
            if(j1==r-q)
            {
                for(int j=i+1; j<r+1; j++)
                {
                    arr[j]=le[i1];
                    i1++;
                }
                break;
            }
        }
    }
}

void merge_sort(int* arr, int p, int r, int n)
{
    if(p<r)
    {
        int q = (p+r)/2;
        merge_sort(arr, p, q, n);
        merge_sort(arr, q+1, r, n);
        merge(arr,p,q,r,n);
    }
}
