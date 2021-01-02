import sys
import time
import math 
import numpy as np
'''
Simule des données en provenance de la camera par le port
serie
'''
x = np.arange(0.0, 128, 1)
i= 0
while True:
    
    y= 128+(((i*10)%100))*np.cos(2*np.pi*x/20)
    print('camera ' + ' '.join((str(int(ys)) for ys in y)))
    # simule plusieurs donnees pour un cycle de camera
    for j in range(15):
        ii=i*15+j
        print('y ' + str(ii % 255))
        if ii % 5 == 0 :
            print('zs ' + str(ii % 255))
        print('z ' + str((120+i) % 255))
        print('grr ' + str(float.hex(math.cos(ii*2*np.pi/30))))
        print('trez ' + str( float.hex(math.sin(ii*2*np.pi/30))))
        print('a ' + str( 170-(ii % 10)))
        print('b ' + str((255 -ii) % 255))
    i += 1
    #time.sleep(0.1)
