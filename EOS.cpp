#include<iostream>
using namespace std;


float solution()
{
    

}



float preosparameters (float p, float t, float pc, float tc, float w)
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
    preos(t, p, a, b, aa, iniv);

}

float preos (float t, float p, float a, float b, float aa, float v)
{
    float vv, r = 8.314;
    vv = b + ((r*t)/(p + ((a*aa)/(v^2 + 2*b*v + b^2))))
    return vv

}


int main ()
{
    float t,p,tc,pc,w;
    cout<<"enter temperature in Deg.Celcius : "
    cin>>t;
    t=t+273.15;
    cout<<"enter pressure in kscg : "
    cin>>p;
    p=(p+1.0333)*98066.5;
    cout<<"enter critical temperature in Kelvin : "
    cin>>tc;
    cout<<"enter critical pressure : "
    cin>>pc;
    cout<<"enter W : "
    cin>>w;

   preosparameters(p,t,pc,tc,w);


    return 0;
}