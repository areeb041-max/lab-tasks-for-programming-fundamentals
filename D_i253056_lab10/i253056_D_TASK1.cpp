#include<iostream>
using namespace std;
int main()
{
	float temperature[7];
	float avg_temp,max_temp,min_temp,sum=0;
	int min_day,max_day;
	for(int i=0;i<7;i++)
	{
		cin>>temperature[i];
		sum=sum+temperature[i];
	}
	avg_temp=sum/7;
	min_temp=temperature[0];
	max_temp=temperature[0];
	for(int i=0;i<7;i++)
	{
		if(max_temp<temperature[i])
		{
		max_temp=temperature[i];
		max_day=i+1;
		}
	}
        for(int i=0;i<7;i++)
        {
                if(min_temp>temperature[i]&&min_temp!=max_temp)
                {
                min_temp=temperature[i];
                min_day=i+1;
                }
        }
	for(int i=0;i<7;i++)
	{
	cout<<temperature[i]<<"\t";
	}
	cout<<endl<<"AVERAGE TEMPERATURE= "<<avg_temp<<endl;
	cout<<"MAXIMUM TEMPERATURE= "<<max_temp<<" ( day "<<max_day<<" )"<<endl;
	cout<<"MINIMUM TEMPERATURE= "<<min_temp<<" ( day "<<min_day<<" )"<<endl;

}