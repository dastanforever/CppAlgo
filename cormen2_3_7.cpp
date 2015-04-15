#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsearch(vector<int> vec2,int start,int end, int key)
{
    if (start - end <= 1)
    {
        if (vec2[start] == key)
            return start;
        else if(vec2[end] == key)
            return end;
        return -1;
    }
    else
    {
        if (vec2[(start+end)/2] > key)
        {
            return bsearch(vec2,start,(start+end)/2,key);
        }
        else
            return bsearch(vec2,(start+end)/2,end,key);
    }
}

int main(void)
{
    int num,i,ele,key;
    vector < int > vec;
    cin>>num>>key;
    for(i = 0 ; i < num; ++i)
    {
        cin>>ele;
        vec.push_back(ele);
    }
    sort(vec.begin(),vec.end());
    vector< int > vec2;
    for(i = 0; i < vec.size();++i)
    {
        if(vec[i] < key)
        {
            vec2.push_back(vec[i]);
        }
        else
            break;
    }
    int flag = 0;
    for (i = 0; i < vec2.size(); ++i)
    {
        if(bsearch(vec2,0,vec2.size()-1,key - vec2[i]) != -1)
        {
            cout<<"Found!!!!!";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout<<"Not Found!!!";
    }
    return 0;
}
