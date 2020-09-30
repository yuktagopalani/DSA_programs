#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    char s[3001];
    char t[3001];
    
    
    
    cin>>s>>t;
    string ans;
    
    int m=strlen(s) + 1;
    int n=strlen(t) + 1;
    
    int a[m][n];
    
    for(int i=0;i<m;i++)
    a[i][0]=0;
    
    for(int i=0;i<n;i++)
    a[0][i]=0;
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(s[i-1]==t[j-1])
            a[i][j]=a[i-1][j-1]+1;
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int i=m-1;
    int flag=0;
    int j=n-1;
    while(1)
    {
        if(i==0 || j==0)
        break;
        if(a[i][j]==max(a[i][j-1], a[i-1][j]))
        {
            if(max(a[i][j-1], a[i-1][j])==a[i][j-1])
            {
                j--;
                continue;
            }
            else
            {
                
                i--;
                continue;
            }
        }
        
        else
        {
            flag=1;
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    if(flag==0)
    cout<<" ";
    else
    cout<<ans;
    
    
    
    
}