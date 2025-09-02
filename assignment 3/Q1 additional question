// Q1. Given an array A, find the nearest smaller element for every A[i] 
// such that the element has an index smaller than i.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmaller(vector<int>& arr) {
    stack<int> st;            // stores potential smaller elements
    vector<int> ans(arr.size());

    for(int i=0;i<arr.size();i++){
        while(!st.empty() && st.top()>=arr[i]) st.pop(); // remove bigger elements
        if(st.empty()) ans[i]=-1;  // no smaller element
        else ans[i]=st.top();      // nearest smaller = top of stack
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr={4,5,2,10,8};
    vector<int> res=nearestSmaller(arr);
    for(int x:res) cout<<x<<" ";
}
