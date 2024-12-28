// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<unordered_set>
// // #include<unordered_map>
// using namespace std; 

// bool fun(string s,int n,int i){
//     if(i>=n/2) return true;
//     if(s[i]!=s[n-i-1]) return false;
//     return fun(s,n,i+1);
// }


// int main(){
//     string s="abcacba";
//     cout<<fun(s,7,0);
// }


// // printina all subsequences of an array
// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<unordered_set>
// // #include<unordered_map>
// using namespace std; 

// void fun(vector<int> &v,vector<int> &v1,int n, int i){
//     if(i>=n){
//         cout<<'{';
//         for(auto x:v1){
//             cout<<x<<" ";
//         }
//         cout<<'}';
//         cout<<endl;
//         return;
//     }
//     v1.push_back(v[i]);
//     fun(v,v1,n,i+1);
//     v1.pop_back();
//     fun(v,v1,n,i+1);
// }

// int main(){
//     vector<int> v={3,1,2};
//     vector<int> v1;
//     fun(v,v1,3,0);
//     return 0;
// }



// // Printing all subsequences with a given sum
// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<unordered_set>
// // #include<unordered_map>
// using namespace std; 

// void fun(vector<int> &v,vector<int> &v1, int n,int sum , int i){
//     if(i>=n){
//         int ttl=0;
//         for(auto x:v1){
//             ttl+=x;
//         }
//         if(ttl==sum){
//             for(auto x:v1){
//                 cout<<x<<" ";
//             }
//         cout<<endl;
//         }
//         return ;
//     }
//     fun(v,v1,n,sum,i+1);
//     v1.push_back(v[i]);
//     fun(v,v1,n,sum,i+1);
//     v1.pop_back();
// }

// int main(){
    // vector<int> v={1,2,1};
    // vector<int> v1;
    // int sum=2;
    // fun(v,v1,3,sum,0);
//     return 0;
// }



// // Printing only first subsequence with given sum
// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<unordered_set>
// // #include<unordered_map>
// using namespace std; 

// bool fun(vector<int> &v,vector<int> &v1, int n,int sum , int i, int s){
//     if(i==n){
//         if(s==sum){
//             for(auto x:v1){
//                 cout<<x<<" ";
//             }
//             cout<<endl;
//             return true;
//         }
//         else {return false;}
//     }
//     v1.push_back(v[i]);
//     s+=v[i];
//     if(fun(v,v1,n,sum,i+1,s)){
//         return true;
//     }
//     s-=v[i];
//     v1.pop_back();  
//     if(fun(v,v1,n,sum,i+1,s)){
//         return true;
//     }
//     return false;
// }

// int main(){
    // vector<int> v={1,2,1};
    // vector<int> v1;
    // int sum=2;
    // int a=fun(v,v1,3,sum,0,0);
//     return 0;
// }


// // Return the count of subsequences with given sum
// // #include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<unordered_set>
// #include<unordered_map>
// using namespace std; 

// int fun(vector<int> &v,vector<int> &v1, int n,int sum,int i ,int s){
//     if(i==n){
//         if(s==sum){
//             return 1;
//         }
//         return 0;
//     }
//     s+=v[i];
//     v1.push_back(v[i]);
//     int l=fun(v,v1,n,sum,i+1,s);

//     s-=v[i];
//     v1.pop_back();
//     int r=fun(v,v1,n,sum,i+1,s);
//     return l+r;
// }

// int main(){
//     vector<int> v={1,2,1};
//     vector<int> v1;
//     int sum=2;
//     cout<<fun(v,v1,3,sum,0,0);    
//     return 0;
// }