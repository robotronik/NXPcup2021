%TD CCTR

%param model
M=0.05; %Kg
g=9.81; %m/s-2
L=0.01; %h
R=1; %Ohms
K=0.0001; %S.I

%point d'équilibre souhaité
V0=7; %V
i0=V0/R; %A
hp0=0;
h0=(K/(M*g))*i0^2; %m

%Modèle en représentation d'état
A= [ -R/L            0                 0;
    0                0                 1;
    -2*K*i0/(M*h0)   K*i0^2/(M*h0^2)   0  
   ];

B=[ 1/L; 
    0;
    0];

C=[0 1 0];

D=[0];


%Discretisation du système
MM=[A             B;
    zeros(1,3)    0];

Te=0.005; %seconds
MMd= expm(MM*Te);

Ad=MMd(1:3,1:3);
Bd=MMd(1:3,4);
Cd=C;
Dd=D;

%Discretisation de Euler

Ad=A*Te +eye(3);
Bd=B*Te;
Cd=C;
Dd=D;

%%
x=[i0;
   h0;
   0]; %condition initiales de l'état

for k=1:10
    u=V0;
    x=Ad*x+Bd*u;
    %figure(1);
    %plot(k, x(2),'rp');
    hold on;
end

%analyse du système

eig(Ad); %valeurs propres de A (poles du système)

%Xo=inv(eye(3)-Ad)*Bd*V0; %équilibre en utilisant Laplace
%%
Q=C.'*C;
R=1;
K2=mydlqr(Ad,Bd,Q,R);

x=[0.010;
   0;
   0]; %condition initiales de l'état

%Simulation du système boucle fermée
for k=1:10
    u=-K2*x;
    x=Ad*x+Bd*u;
    %figure(2);
    %plot(k, u, 'r*');
    %plot(k, x(2),'rx');
    hold on;
end

gstatic= Cd*inv(eye(3)-Ad+Bd*K2)*Bd;
G=1/gstatic;
r=-0.01;


for k=1:10
    u=-K2*x+G*r;
    x=Ad*x+Bd*u;
    %figure(1);
    %plot(k, u+V0, 'r*');
    %figure(2);
    %plot(k, x(2)+h0,'r*');
    hold on;
end

Q0=Bd*Bd.';
R0=100;

L2=mydlqr(Ad.',Cd.',Q0,R0).';
gstatic= Cd*inv(eye(3)-Ad+Bd*K2)*Bd;
G=1/gstatic;
r=0.01;
xe=10;

x=[i0;
   h0;
   0]; %condition initiales de l'état

for k=1:100
    u=-K2*xe+G*r;
    xe=Ad*xe+Bd*u+L2*(Cd*x-Cd*xe); %Cd*xe = sortie estimé Cd*x = sortie mesurée %Equation d'observeur d'état
    x=Ad*x+Bd*u; % Equation physique
    %figure(1);
    %plot(k, u+V0, 'r*');
    %figure(2);
    %plot(k, x(2),'r*');
   %plot(k, xe(2),'b*');
    %figure(3);
    %plot(k,x(2)-xe(2),'b*'); 
    hold on;
end

%% Analyse et robusesse

%param model
M=0.05; %Kg
g=9.81; %m/s-2
L=0.01; %h
R=1; %Ohms
K=0.0001; %S.I

%point d'équilibre souhaité
V0=7; %V
i0=V0/R; %A
hp0=0;
h0=(K/(M*g))*i0^2; %m

Mr= M-0.2*M; 

for j= 1:1
    %Mr=0.05;
    h0r=(K/(Mr*g))*i0^2; %m
    
    
    Areal= [ -R/L            0                 0;
    0                0                 1;
    -2*K*i0/(Mr*h0r)   K*i0^2/(Mr*h0r^2)   0  
   ];
    
    Adreal=Areal*Te +eye(3);
    x=[i0;
       h0r;
       0]; %condition initiales de l'état
    xe=10;
    for k =1:100
        u=-K2*xe+G*r;
        xe=Ad*xe+Bd*u+L2*(Cd*x-Cd*xe); %Cd*xe = sortie estimé Cd*x = sortie mesurée %Equation d'observeur d'état
        x=Adreal*x+Bd*u; % Equation physique
        %figure(1);
        %plot(k, x(2),'b.');
        hold on;
    end
    Mr= Mr + 0.01 *M;
end    

r=0.02;
Ae= [Ad zeros(3,1);
    Te*C 1];
Be = [Bd;
      0];
Qe = [Q zeros(3,1);
     zeros(1,3) 1e9];    
Re = 1;
Ke = mydlqr(Ae, Be, Qe, Re);

x=[i0;
   h0r;
   0]; %condition initiales de l'état
xe=10;
Z = 0.00;

Mr= M-0.60*M; 
h0r=(K/(Mr*g))*i0^2; %m


Areal= [ -R/L            0                 0;
0                0                 1;
-2*K*i0/(Mr*h0r)   K*i0^2/(Mr*h0r^2)   0  
];

Adreal=Areal*Te +eye(3);
x=[i0;
   h0r;
   0]; %condition initiales de l'état
xe=x/10;

for k =1:1500
    u=-Ke(1:3)*xe- Ke(4)*Z;    
    xe=Ad*xe+Bd*u+L2*(Cd*x-Cd*xe); %Cd*xe = sortie estimé Cd*x = sortie mesurée %Equation d'observeur d'état    
    x=Adreal*x+Bd*u; % Equation physique
    Z= Z + Te * ( Cd * x -r);
    
    figure(1);
    plot(k, x(2),'bh');
    %figure(2);
    plot(k, Z,'r.');
    hold on;
end
