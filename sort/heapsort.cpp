#include <iostream>
#include <vector>
using namespace std;

//to find out left,right children and parent of a node
class Fam{
    public:
    int i, left, right, parent;
    Fam(int curr){
        i = curr;
        left = 2*i+1;
        right = 2*i +2;
        if(i%2==0){
            parent = i/2-1;
        }
        else{
            parent = i/2;
        }
    }    
};

//display array
void disp(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

//puts a node to its position in tree such that it is greater than both its children
void max_heapify(vector<int> &v, int i, int heap_size){
    Fam fam(i);
    int max = i;

    if(fam.left<=heap_size-1)
    {
        if(v[fam.left]>v[max])
        {
            max = fam.left;
        }
    }
    if(fam.right<=heap_size-1)
    {
        if(v[fam.right]>v[max])
        {
            max = fam.right;
        }
    }

    if(max!=i){
        //swap v[i] and v[max]
        int t = v[max];
        v[max] = v[i];
        v[i] = t;

        max_heapify(v, max, heap_size);
    }
}

//converts random array into max-heap tree
void build_max_heap(vector<int> &v){
    for(int i=v.size()/2; i>=0; i--)
    {
        max_heapify(v, i, v.size());
    }
}

//sorts
void heapsort(vector<int> &v){
    int heap_size = v.size();
    build_max_heap(v);
    for(int i=v.size()-1; i>=1; i--)
    {
        int t = v[0];
        v[0] = v[i];
        v[i] = t;

        heap_size--;
        max_heapify(v, 0, heap_size);
    }
}

int main()
{
    vector<int> v = {5,13,2,25,7,17,20,8,4};

    heapsort(v);
    disp(v);
}
