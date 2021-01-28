for o=1:50
r = 8.31446261815324
%t = input('enter the temperature in celcius :  ')
t = 100
t = t + 273.15
%p = input('enter the pressure in KSCG :  ')
p = o
p = abs((p-1.033)*0.0980665)
s = 10

sname = ["Methane","Hydrogen","H2O","CO","CO2","Argon","Nitrogen","Oxygen","Ammonia","Methanol"]
%for i=1:s
    %prompt = sprintf('enter the mole fraction of %s : ',sname(i));
    %x(i) = input(prompt);
%end

x = [0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1]
tc = [190.6	33.3	647.3	132.9	304.2	150.9	126.1	154.6	406.6	512.6]
pc = [4.604	1.297	22.12	3.499	7.382	4.898	3.394	5.043	11.27	8.096]
w = [0.011	-0.215	0.344	0.066	0.228	-0.004	0.04	0.022	0.252	0.566]

for i=1:s
    tr(i)= t/tc(i)
    m(i) = 0.37464+(1.54226*w(i))-(0.26992*(w(i)^2))
    alpha(i) = (1+(m(i)*(1-sqrt(tr(i)))))^2
    a(i) = 0.4572355289*((r*tc(i))^2)/pc(i)
    b(i) = 0.0777960739*r*tc(i)/pc(i)
    aialpha(i) = a(i) * alpha(i)
end


binaryint_parameters = [0	0.202000007	0.5	2.10E-02	0.100000001	2.30E-02	3.60E-02	0	0	-3.50E-02
0.202000007	0	-0.299800009	2.53E-02	0.120200001	0	-3.60E-02	0	0	0
0.5	-0.299800009	0	-0.389600009	4.45E-02	0.5	-0.315600008	0	-0.253300011	-0.180000007
2.10E-02	2.53E-02	-0.389600009	0	-3.14E-02	0	1.15E-02	0	0	0
0.100000001	0.120200001	4.45E-02	-3.14E-02	0	0	-2.00E-02	9.75E-02	0	4.00E-02
2.30E-02	0	0.5	0	0	0	0	1.04E-02	-0.180000007	0
3.60E-02	-3.60E-02	-0.315600008	1.15E-02	-2.00E-02	0	0	-1.20E-02	0.222000003	-0.214100003
0	0	0	0	9.75E-02	1.04E-02	-1.20E-02	0	0	0
0	0	-0.253300011	0	0	-0.180000007	0.222000003	0	0	0
-3.50E-02	0	-0.180000007	0	4.00E-02	0	-0.214100003	0	0	0
]

for i=1:s
    for j=1:s
        aij(i,j) = sqrt(aialpha(i)*aialpha(j))*(1-binaryint_parameters(i,j))
    end
end

for i=1:s
    for j=1:s
        axij(i,j) = x(i)*x(j)*(aij(i,j))
    end
end

for i=1:s
    bi(i) = x(i) * b(i)
end

at = sum(axij(:));
bt = sum(bi(:));

A = at*p/(r*t)^2;
B = bt*p/(r*t);
a3 = 1
a2 = -(1-B)
a1 = A-(3*B^2)-(2*B)
a0 = -((A*B)-(B^2)-(B^3))
x = [a3 a2 a1 a0]
rr = roots(x)
z =rr(real(rr) >= 0 & imag(rr) == 0)
v(o)=z*r*t/p
end
pre = 1:50
plot(v,pre)
