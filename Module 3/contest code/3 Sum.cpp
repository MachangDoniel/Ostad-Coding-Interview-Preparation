#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<n-2;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
            int sum=v[i]+v[left]+v[right];
            // cout<<v[i]<<" "<<v[left]<<" "<<v[right]<<endl;
            if(sum==0){
                count++;
                while(v[left]==v[left+1] && left+1<right){
                    count++;
                    left++;
                }
                while(v[right]==v[right-1] && left<right-1){
                    count++;
                    right--;
                }
                left++;
                right--;
            }
            else if(sum<0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout<<count<<endl;

    return 0;
}