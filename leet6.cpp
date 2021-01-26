#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//best runtime
class Solution {
public:
    string convert(string s, int numRows) {
        int max = s.size();
        string str;
        int num=0;
        int z;
        if(numRows==1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            num=i;
            int z=0;
            while(num<max){
                str.push_back(s.at(num));
                if(z%2==0){
                    if(i!=numRows-1){
                        num = num+ 2*(numRows-1-i);
                    }
                    else{
                        num = num+ 2*(numRows-1);
                        
                    }
                }
                else if(z%2==1){    
                    if(i!=0 && i!=numRows-1){
                            num = num + 2*i;
                    }else{
                        num = num + 2*(numRows-1);
                    }
                }
                z++;
            }
            
        }
        return str;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int n = s.length();
        int diff = 2*numRows-2;
        string str= "";
        int left = diff, right = 0;
        for(int i=0;i<numRows;i++){
            int j = i;
            while(j<n){
                if(left!=0){
                    str+=s[j];
                    j+=left;    
                }
                
                if(j<n && right!=0){
                    str+=s[j];
                    j+=right;
                }
                
            }
            left-=2;
                right+=2;
        }
        return str;
    }
};
int main()
{
    string s = "PAYPALISHIRING";
    Solution q;
    cout << q.convert(s, 3) << endl;
    return 0;
}
