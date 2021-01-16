#include<iostream>
using namespace std;

float preos (float v)
{
    
}

float solution()
{

}


float preosparameters (float p, float t,float tc,float pc,float w)
{
    float a,b,aa,tr,k,r;
    r = 8.314;
    tr = t/tc;
    k = 0.37464 + 1.54226*w - 0.26992*w*w;
    aa = (1 + (k*(1 - tr^0.5)))^2;

    a = (0.457235*r*r*tc*tc*aa) / pc;
    b = (0.077796*r*tc) / pc;

    float iniv;
    iniv = (p*v)/t;

}


int main ()
{
    cout<<"omale"<<"    otha";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\n";
    }
    return 0;
}