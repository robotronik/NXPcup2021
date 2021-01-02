% TD CCTR

% Paramètres du problème

M = 0.05; % kg
g = 9.81; % m/s^2
L_ind = 0.01; % H
R = 1; % Omh
K_K = 0.0001; % SI

% Point d'équilibre souhaité

V0 = 7; % V
i0 = V0 / R; % A
h0 = K_K * i0 * i0 / (M * g); % m
hp0 = 0;

% Modèle en représentation d'états

A = [0,                      1,  0; 
     ((K_K * i0^2) / (M * h0^2)), 0,  (-2*K_K*i0) / (M * h0);
     0,                      0,  -R/L_ind];
 
 
B = [0;
     0;
     1/L_ind];
 
 C = [1, 0, 0];
 
 D = 0;
 
 
% Discretisation du système avec la méthode EXACTE

MM = [A, B;
      zeros(1,3), 0];

Te = 0.005; % seconds

MMd = expm(MM * Te);

Ad = MMd(1:3, 1:3) % récupère les lignes 1 à 3 et les colonnes 1 à 3;
Bd = MMd(1:3, 4) 
Cd = C;
Dd = D;

% Discretisation du système avec la méthode d'EULER

Add = A*Te + eye(3);
Bdd = B*Te;
Cdd = C;
Ddd = D;


%% Simulation de mon système discrétisé 

% Cellule qu'on peut exécuter indépendemment du reste

x = [h0;
     hp0;
     i0]; % conditions initiales de l'état
 
for k=1:1
    u = V0;
    x = Ad*x + Bd*u;
    figure(1)
    plot(k, x(1), 'ro')
    
    
    hold on
end
 
%% Analyse du système

%eig(Ad)  % valeurs propres de A (poles du systeme)
%eig(Add)

% X0 = inv(-A)*B*V0
 


%% Simulation de notre système

Q = C.'*C  % C' = transposé de C
R = 0.01

K = mydlqr(Ad, Bd, Q, R)

Q0 = B*B.';
R0 = 1e-6;
L = mydlqr(Ad.', C.', Q0, R0) 
x = [0.010; 0; 0];
xe = [1; 1; 1];

I = eye(3);
Gstatic = C * inv(I - Ad + Bd*K) * Bd;
G = inv(Gstatic);
r = 1e-3;
 
 
for k=1:100
    u = -K*xe + G*r;
    y = C*x;
    ye = C*xe;
    xe = Ad*xe + Bd*u + (L*(y - ye))';
    
    x = Ad*x + Bd*u;
    figure(1)
    plot(k, x(1), 'ro')
    plot(k, xe(1), 'bx');
    hold on
end

%% Analyse robustesse: Masse variable

% Q = C.'*C  % C' = transposé de C
% R = 0.01
% 
% K = mydlqr(Ad, Bd, Q, R)
% 
% Q0 = B*B.';
% R0 = 1e-6;
% L = mydlqr(Ad.', C.', Q0, R0) 
% xe = [1; 1; 1];
% 
% I = eye(3);
% Gstatic = C * inv(I - Ad + Bd*K) * Bd;
% G = inv(Gstatic);
% r = 1e-3;
% 
% 
% K_K = 0.0001; % SI
% V0 = 7; % V
% R_R = 1; % Omh
% i0 = V0 / R_R;

% for M=0.04:0.002:0.07
%     h0 = K_K * i0 * i0 / (M * g); % m
%     x = [h0;
%         hp0;
%         i0]; 
%     M
%     h0
%     xe = [1; 1; 1];
% 
%     for k=1:1000
%         u = -K*xe + G*r;
%         y = C*x;
%         ye = C*xe;
%         xe = Ad*xe + Bd*u + (L*(y - ye))';
% 
%         x = f_Ad_real(M)*x + Bd*u;
%         figure(1)
%         plot(k, x(1), 'ro')
%         plot(k, xe(1), 'bx');
%         hold on
%     end
% 
% end

%% Correcteur intégrale


Q = C.'*C  % C' = transposé de C
Re = 1

Qe = [Q zeros(3,1);
      zeros(1,3) 1];
  
Ae = [Ad zeros(3,1);
      Te.*C 1];
Be = [Bd; 
      0];
z = 0;

Ke = mydlqr(Ae, Be, Qe, Re);
r = 1e-2;

for M=0.02:0.005:0.8
    h0 = K_K * i0 * i0 / (M * g); % m
    x = [h0; 0; 0]; 
    xe = [h0; 0; 0];
    for k=1:100
        u = -Ke(1:3)*xe - Ke(4).*z;
        y = C*x;
        ye = C*xe;
        xe = Ad*xe + Bd*u + (L*(y - ye))';
        z = z + Te * (y - r);

        x = f_Ad_real(M)*x + Bd*u;
        figure(1)
        plot(k, x(1), 'ro')
        plot(k, xe(1), 'bx');
        hold on
    end
end 


function [Ad_real] = f_Ad_real(M)

g = 9.81; % m/s^2
L_ind = 0.01; % H
R = 1; % Omh
K_K = 0.0001; % SI

% Point d'équilibre souhaité

V0 = 7; % V
i0 = V0 / R; % A
h0 = K_K * i0 * i0 / (M * g); % m
hp0 = 0;

% Modèle en représentation d'états

A = [0,                      1,  0; 
     ((K_K * i0^2) / (M * h0^2)), 0,  (-2*K_K*i0) / (M * h0);
     0,                      0,  -R/L_ind];

B = [0;
     0;
     1/L_ind];
 
% Discretisation du système avec la méthode EXACTE

MM = [A, B;
      zeros(1,3), 0];

Te = 0.005; % seconds

MMd = expm(MM * Te);

Ad_real = MMd(1:3, 1:3); % récupère les lignes 1 à 3 et les colonnes 1 à 3;

end 