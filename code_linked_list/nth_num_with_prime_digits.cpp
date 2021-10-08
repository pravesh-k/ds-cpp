#include<iostream>
using namespace std;

class Solution{
    public:
    int theNumber(int n){
        int num = 1, i = 0;
        while(i != n){
            num++;
            if(allDigitPrime(num)){
                i++;
                // cout<<"num: "<<num<<endl;
            }
            // num++;
        }
        return num;
    }
    
    bool allDigitPrime(int num){
        
        bool flag = false;
        while(num){
            int dig = num % 10;
            
            if((dig == 2) || (dig == 3) || (dig == 5) || (dig == 7)){
                flag = true;
                num = num/10;
            }
            else{
                flag = false;
                break;
            }
        }
        return flag;    
    }
};

int main()
 {
	//code
    int n;
	cin>>n;
	Solution ob;
	cout<<ob.theNumber(n)<<endl;
	return 0;
}