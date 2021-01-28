#include<iostream>
#include<math.h>
using namespace std;


int main ()
{
    float t,p, r=8.31446261815324;
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
    // if(sum>1 || sum != 1)
    // {
    //    cout<<"Enter correctly u dumbfuck !!!"<<endl;
    //    cout<<endl;
    //    main();
    // }

    cout<<endl<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<"Composition of "<<compound[i]<<" : "<<x[i]<<endl;
    }

    float tc[10] = {190.6,33.3,647.3,132.9,304.2,150.9,126.1,154.6,406.6,512.6};
    float pc[10] = {4.604,1.297,22.12,3.499,7.382,4.898,3.394,5.043,11.27,8.096};
    float w[10] = {0.011,-0.215,0.344,0.066,0.228,-0.004,0.04,0.022,0.252,0.566};

    float binaryint_parameters[10][10] = {0 ,0.202000007 ,0.5 ,2.10E-02 ,0.100000001 ,2.30E-02 ,3.60E-02 ,0 ,0 ,-3.50E-02,
0.202000007 ,0 ,-0.299800009 ,2.53E-02 ,0.120200001 ,0 ,-3.60E-02 ,0 ,0 ,0,
0.5 ,-0.299800009 ,0 ,-0.389600009 ,4.45E-02 ,0.5 ,-0.315600008 ,0 ,-0.253300011 ,-0.180000007,
2.10E-02 ,2.53E-02 ,-0.389600009 ,0 ,-3.14E-02 ,0 ,1.15E-02 ,0 ,0 ,0,
0.100000001 ,0.120200001 ,4.45E-02 ,-3.14E-02 ,0 ,0 ,-2.00E-02 ,9.75E-02 ,0 ,4.00E-02,
2.30E-02 ,0 ,0.5 ,0 ,0 ,0 ,0 ,1.04E-02 ,-0.180000007 ,0,
3.60E-02 ,-3.60E-02 ,-0.315600008 ,1.15E-02 ,-2.00E-02 ,0 ,0 ,-1.20E-02 ,0.222000003 ,-0.214100003,
0 ,0 ,0 ,0 ,9.75E-02 ,1.04E-02 ,-1.20E-02 ,0 ,0 ,0,
0 ,0 ,-0.253300011 ,0 ,0 ,-0.180000007 ,0.222000003 ,0 ,0 ,0,
-3.50E-02 ,0 ,-0.180000007 ,0 ,4.00E-02 ,0 ,-0.214100003 ,0 ,0 ,0};


float tr[10],m[10],alpha[10],a[10],b[10],aialpha[10];

for(int i=0;i<10;i++)
{
    tr[i]= t/tc[i];
    m[i] = 0.37464+(1.54226*w[i])-(0.26992*pow(w[i],2));
    alpha[i] = pow((1+(m[i]*(1-sqrt(tr[i])))),2);
    a[i] = 0.4572355289*(pow((r*tc[i]),2))/pc[i];
    b[i] = 0.0777960739*r*tc[i]/pc[i];
    aialpha[i] = a[i] * alpha[i];
}


float aij[10][10],axij[10][10],bi[10],at=0,bt=0;

for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
        aij[i][j] = sqrt(aialpha[i]*aialpha[j])*(1-binaryint_parameters[i][j]);
    
for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
        axij[i][j] = x[i]*x[j]*(aij[i][j]);

for(int i=0;i<10;i++)
    bi[i] = x[i] * b[i];


for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
        at = at + axij[i][j];

for(int i=0;i<10;i++)
    bt = bt + bi[i];
    

cout<<"*****************************************"<<endl;
cout<<at<<endl;
cout<<"*****************************************"<<endl;
cout<<bt<<endl;
cout<<"*****************************************"<<endl;



float v;
    v = (r*t)/p;

    int f=0,ii=0, tolerance=0.00001;
    float vv;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
    while(f==0)
    {
        
        cout<<"the answer for "<<ii<<"th iteration is : "<<v<<endl;
        vv =  bt + ((r*t)/(p + ((at)/((pow(v,2)) + (2* bt*v) + (pow( bt,2))))));
        cout<<"diff :"<<abs(v-vv)<<endl;
        if(abs(v-vv)<=tolerance)
        {
            f=1;
        }
        ii=ii+1;
        v = vv;
    }

cout<<"*****************************************"<<endl;
cout<<"the molar volume is : "<<v<<endl;
cout<<"*****************************************"<<endl;
cout<<"Z = "<<((p*v)/(r*t))<<endl;
cout<<"*****************************************"<<endl;

    return 0;

}