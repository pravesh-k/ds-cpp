// Program to find nth number with all digits as prime numbers

#include<iostream>
using namespace std;

class Solution{
    public:

    // function to find the nth number with all digits prime
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
    
    // boolean function to determine whether a number has all digits prime or not
    bool allDigitPrime(int num){
        
        bool flag = false;
        while(num){
            int dig = num % 10;
            
            if((dig == 2) || (dig == 3) || (dig == 5) || (dig == 7)){       // single digits prime only can be 2,3,5,7
                flag = true;
                num = num/10;
            }
            else{
                flag = false;       // if any digit is not prime, break the loop and return false
                break;
            }
        }
        return flag;    
    }
};

// driver code
int main()
 {
	//code
    int n;
	cin>>n;
	Solution ob;
	cout<<ob.theNumber(n)<<endl;
	return 0;
}