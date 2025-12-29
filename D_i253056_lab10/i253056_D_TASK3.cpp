#include<iostream>
using namespace std;
int main()
{

int arr[10], count = 0, n;
cout<<"ENTER ELEMENTS OF ARRAY"<<endl;
for( int i = 0 ; i < 10 ; i++ )
{
cin>>arr[i];
}
cout<<endl;
cout<<" Enter the number you want to find: ";
cin>>n;

for( int i = 0 ; i < 10 ; i++ )
{
 if( arr[i] == n)
{
 count +=1;
}

}

cout<<" The number "<<n<<" appears "<<count<<" times.";
return 0;
} 
