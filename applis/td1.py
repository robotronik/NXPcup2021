# TD CCTR

import numpy as np
from scipy.linalg import expm

# Paramètres du problème

M = 0.05 # kg
g = 9.81 # m/s^2
L = 0.01 # H
R = 1.0 # Omh
K = 0.0001 # SI

# Point d'équilibre souhaité


V0 = 7.0 # 7
i0 = V0 / R # A
h0 = K * i0 * i0 / (M * g) # m
hp0 = 0.0

A = np.array([
    [0.0, 1.0,  0.0],
    [(K * i0 * i0) / (M * h0 * h0), 0.0,  (-2*K*i0) / (M * h0)],
     [0.0, 0.0,  -R/L]])


B = np.array([
    [0.0],
    [0.0],
    [1/L]])

C = np.array([1, 0, 0])

D = 0

Z = np.zeros((1, 4))

tmp = np.concatenate((A, B), axis=1)

MM = np.concatenate((tmp, Z), axis=0)

Te = 0.005 # seconds
MMd = expm(MM * Te)

print(MMd)

