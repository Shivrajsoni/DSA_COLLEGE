
#include <iostream>
using namespace std;

 void TOH(int n,char source,char aux,char dest,int &cnt) {
        if(n==1){
        	cout<<"for Disk "<<n<<endl;
        	cnt++;
            cout<<"Move from "<<source<<"to"<<dest<<endl;
		}
        
        else{
        	cout<<"For Disk "<<n<<endl;
        
            TOH(n-1,source,dest,aux,cnt);
            cnt++;
         cout<<"moved from"<<source<<"to"<<dest<<endl;
            
            TOH(n-1,aux,source,dest,cnt);
          
        }
        return ;
    }

int main() {
    int n;
    cout<<"Enter your number";
    cin>>n;
    char f='F',a='A',t='T';
    int cnt=0;
   TOH(n,f,a,t,cnt);
   
   cout<<cnt;
    return 0;
}