#include<iostream>
#include<math.h>
using namespace std;


int main ()
{
    float t,p;
    cout<<"enter temperature in Deg.Celcius : ";
    cin>>t;
    t=t+273.15;

    cout<<"enter pressure in kscg : ";
    cin>>p;
    p=(p-1.03323)*0.0980665;

    string compound[10] = {"Methane","Hydrogen","H2O","CO","CO2","Argon","Nitrogen","Oxygen","Ammonia","Methanol"};
    float x[10], sum=0;
    for(int i=0;i<10;i++)
    {
        cout<<"Enter the composition of "<<compound[i]<<" : ";
        cin>>x[i];
        sum = sum + x[i];
    }
    if(sum>1 || sum != 1)
    {
       cout<<"Enter correctly u dumbfuck !!!"<<endl;
       cout<<endl;
       main();
    }
    for(int i=0;i<10;i++)
    {
        cout<<"Composition of "<<compound[i]<<" : "<<x[i]<<endl;
    }

    
    return 0;

}