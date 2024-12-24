#include <bits/stdc++.h>
using namespace std;
string longestNiceSubstring(string s) {
    int n=s.size();
    string res="";
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            string sub=s.substr(i,j-i+1);
            unordered_set<char> st(sub.begin(),sub.end());
            bool flag=true;
            for (char c:st){
                if (c>='a'&&c<='z'){
                    if (!st.count(c-'a'+'A')){
                        flag=false;
                        break;
                    }
                }
                else{
                    if (!st.count(c-'A'+'a')){
                        flag=false;
                        break;
                    }
                }
            }
            if (flag&&sub.size()>res.size()) res=sub;
        }
    }
    return res;
}