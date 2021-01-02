% Modèle de la voiture 

% Paramètres du modèle


m = 1.2; % kg
lt = 0.187; % m
lf = 0.108; % m
lr = 0.079; % m

le = 0.15; % m

cf = 57; % N.rad-1
cr = 81; % N.rad-1

Ix = 2; % kg.m2

vx = 1.2; % m.s-1


Te = 0.02; % s

% Modèle 
K1 = -(cf + cr) / (m * vx);
K2 = ((cr * lr - cf * lf) / (m * vx)) - vx;
K3 = cf / m;
K4 = (lr*cr - lf*cf) / (Ix * vx);
K5 = -( lr * lr * cr + lf *lf *cf) / (Ix * vx);
K6 = (lf * cf) / Ix;

A = [ 0 1  0 0;
      0 K1 0 K2;
      0 0  0 1;
      0 K4 0 K5];

B = [ 0;
      K3;
      0;
      K6 ];
  
C = [1, 0, 0, 0;
     0, 0, 1, 0];

D = 0;

% Point d'équilibre; 

y0 = 0;
vy0 = 0;
psi0 = 0;
psi_point0 = 0;

x = [y0; vy0; psi0; psi_point0];

% Discretisation du système avec la méthode d'EULER

Ad = A*Te + eye(4);
Bd = B*Te;
Cd = C;
Dd = D;

%Q = [1e3 0    0    0;
%     0 1e-6 0    0;
%     0 0    1e-4 0;
%     0 0    0    1];
Q = C.'*C;  % C' = transposé de C

Mc = [B A*B A*A*B A*A*A*B]
rank(Mc)
test = [1 0 0;
        0 2 4;
        0 1 2];
rank(test)

Mo = [C;
      C*A;
      C*A*A;
      C*A*A*A]
rank(Mo)


Ae= [Ad zeros(4,2);
    Te*C eye(2)];
Be = [Bd;
      0;
      0]; 
Qe = [Q zeros(4,2);
     zeros(2,4) 1e3*eye(2)];    
Re = 1e3;
Ke = mydlqr(Ae, Be, Qe, Re);

z = [0;0];
r = [0;0];

Q0 = eye(4); 
%Q0 = Bd*Bd.'
R0 = eye(2);
L = mydlqr(Ad', C', Q0, R0)' ;

xe = [0.10; 0; 0; 0];

 for k=1:20
    

    u = -Ke(1:4)*xe - Ke(5:6)*z;
    y = C*x;
    
     %if k == 80
      %   y = [0.005; 0.001];
     %end
     
    
    ye = C*xe;
    xe = Ad*xe + Bd*u + L*(y - ye);
    z = z + Te * (y - r);

    x = Ad*x + Bd*u;
    figure(1)
    plot(k, x(1), 'ro')
    plot(k, xe(1), 'bx');
    plot(k, u, 'g^');
    hold on

end




