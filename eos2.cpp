#include<iostream>
#include<math.h>
using namespace std;

int main ()
{
    float t,p,tc,pc,w;
    cout<<"enter temperature in Deg.Celcius : ";
    cin>>t;
    t=t+273.15;

    cout<<"enter pressure in kscg : ";
    cin>>p;
    p=(p-1.03323)*0.0980665;

    cout<<"enter critical temperature in Kelvin : ";
    cin>>tc;

    cout<<"enter critical pressure : ";
    cin>>pc;

    cout<<"enter W : ";
    cin>>w;

    float a,b,aa,tr,k,r;
    r = 8.314;
    tr = t/tc;
    k = 0.37464 + 1.54226*w - 0.26992*w*w;
    aa = pow((1 + (k*(1 - (pow(tr,0.5))))),2);

    a = (0.457235*r*r*tc*tc*aa) / pc;
    b = (0.077796*r*tc) / pc;

    float v;
    v = (r*t)/p;

    int f=0,ii=0, tolerance=0.01;
    float vv;

    while(f==0)
    {
        
        cout<<"the answer for "<<ii<<"th iteration is : "<<v<<endl;
        vv = b + ((r*t)/(p + ((a*aa)/((pow(v,2)) + (2*b*v) + (pow(b,2))))));
        cout<<"diff :"<<abs(v-vv)<<endl;
        if(abs(v-vv)<=tolerance)
        {
            f=1;
        }
        ii=ii+1;
        v = vv;
    }

    return 0;
    cout<<"the answer is : "<<v<<endl;
    cout<<"Z = "<<((p*v)/(r*t))<<endl;
}