//link:https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int replace(int l,int r,int element,vector<int> &v)
    {
        while(r-l>1){
            int m=(l+r)/2;
            if(v[m]>=element){
                r=m;
            }
            else{
                l=m;
            }
        }
        return r;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> v;
       v.push_back(a[0]);
       for(int i=1;i<n;i++)
       {
           if(v[0]>a[i]) v[0]=a[i];
           
           else if(v[v.size()-1]<a[i]){
               v.push_back(a[i]);
           }
           else{
              v[replace(0,v.size(),a[i],v)]=a[i]; 
           }
       }
       return v.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
