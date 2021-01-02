import serial
import sys
import time

import numpy as np
import matplotlib.pyplot as plt

def inthex(hexstr):
    return  int(hexstr,16)


def twos_complement(hexstr,bits):
    value = int(hexstr,16)
    if value & (1 << (bits-1)):
        value -= 1 << bits
    return value


def int8s(v):
    return twos_complement(v, 8)


def int16s(v):
    return twos_complement(v, 16)


def int32s(v):
    return twos_complement(v, 32)


class Line:
    def __init__(self, name, xr=(0,128), yr=(0,255), depth=4, period=1):
        self.name = name
        self.xr = xr
        self.yr = yr
        self.depth = depth
        self.figure = plt.figure(name)
        
        self.plt = self.figure.add_subplot(111)
        self.x = np.arange(xr[0], xr[1], 1)
        self.y = np.array(depth*[xr[1]*[0]])
        self.t = 0
 
        self.period = period
        self.p = 0
        self.plot()
        plt.draw()
        plt.show(block=False)
        
    def plot(self):
        self.plt.set_xlim(self.xr[0], self.xr[1])
        self.plt.set_ylim(self.yr[0], self. yr[1])
        self.line = self.depth*[None]
        a= 255/self.depth
        for d in range(self.depth):
            c = str((d*a)/255)
            self.line[d], = self.plt.step(self.x, self.y[d], color= c)
        plt.draw()
        plt.show(block=False)
        
    def set(self, data):
        self.y = np.roll(self.y, 1, axis=0)
        self.y[0] = np.array(data)
        for d in range(self.depth):
            self.line[d].set_ydata(self.y[d])
        
    def draw(self):
        if self.p == 0:
            #plt.draw()
            #plt.show(block= False)
            self.plt.draw_artist(self.plt.patch)
            for d in range(self.depth):
                self.plt.draw_artist(self.line[d])
        self.p = (self.p+1) % self.period
        self.figure.canvas.draw()
        self.figure.canvas.flush_events()
                
    def update(self, s):
        ok = False
        r = s
        if s is not None:
            if s.startswith(self.name+' '):
                dta = s.split()
                yd = list(int(float(y)) for y in dta[1:])
                self.set(yd)
                self.draw()
                r = None
        return r


class Oscillo:
    def __init__(self, names, xr=(0,128), yr=(0,255), colors= {}, labels={}, step={}, formats={}, period= 10, figname= None):
        '''
        @param names : la liste des clés de l'entrée
        @param xr, yr : les échelles des axes x et y
        @param colors : les couleurs de chaque courbe: noir par défaut
        @param label   : lable de chaque courbe; le nom par defaut
        @param step  : la duree relative de chaque echantillon; 1 par défaut
        @param formats : le format de conversion depuis l'ascii; int par défaut float.fromhex, int8s, int16s, int32s, inthex
        @period        : la période de mise à jour de l'affichage, 10 par défaut
        @figname          : le nom de la figure dans laquelle on dessine

        ATTENTION : le systeme matplot a un rafraichissement d'environ 20 images par secondes. Pour des signaux plus rapides, il faut faire un rafraichissement uniquement lorsque suffisament de donnees sont presentes sinon le flux de texte est ralenti et bufferise. Ceci produit un decalage entre les courbes et la realite.
        Le parametre period permet de regler le nombre de donnees par rafraichissement. Le rafraichissement est effectué lorsque la premiere clé apparait 'period' fois. S'il y a plusieurs courbes, les autres courbes doivent avoir pris leur valeur avant la premiere, sinon les valeurs sont decalees horizontalement d'une unite. De la meme façon, si plusieurs figures sont dans la meme fenetre, l'affichage est synchronise entre toutes les courbes, qui ont la meme periode, le rafraichissement est fait sur la premiere courbe de la premiere figure.
        Si un signal de rythme different doit etre affiche sur la meme figure, le parametre step indique que ce signal est de duree superieure, et il est etire horizontalement de la valeur de step


        '''
        
        self.names = names
        self.xr = xr
        self.yr = yr
        self.n = len(names)
        self.figname = str(names)
        if figname is not None:
            self.figname = figname
        self.labels = labels
        self.colors = colors
            
        self.figure = plt.figure(str(self.figname))
        self.nfig = 1
        self.o = [self]
        self.plt = self.figure.add_subplot(111)
        self.figure.show()
        self.x = np.arange(xr[0], xr[1], 1)
        self.y = np.array(self.n*[xr[1]*[0.0]])
        self.period = period
        self.p = 0
        self.draw_enable = True
        self.figure_enable = True
        self.step = step
        self.s = self.n*[1]
        self.formats = {}
        for n in names: self.formats[n] = int
        self.formats.update(formats)
        self.plot()
        
    def plot(self):
        self.plt.set_xlim(self.xr[0], self.xr[1])
        self.plt.set_ylim(self.yr[0], self.yr[1])
  
        self.line = self.n*[None]
        for n in range(self.n):
            name= self.names[n]
            self.line[n], = self.plt.step(self.x, self.y[n])
            
            color= 'black'
            if name in self.colors :
                color= self.colors[name]
            self.line[n].set_color(color)
            
            label= name
            if name in self.labels :
                label= self.labels[name]
            self.line[n].set_label(label)
            
            self.s[n]= 1
            if name in self.step:
                self.s[n]= self.step[name]
                
        self.plt.legend(loc='upper left')
        plt.draw()
        plt.show(block=False)
      
    def set(self, name, data):
        n=  self.names.index(name)
        self.y[n]= np.roll(self.y[n], -self.s[n])
        for s in range(self.s[n]):
            self.y[n][-1-s]= data
        self.line[n].set_ydata(self.y[n])
        # declenche le dessin lorsque la courbe0 a ete mise a jour period fois
        if n == 0 :
            self.p = (self.p+1) % self.period
            self.draw_enable= self.p == 0
            self.figure_enable= self.p == 0

        
    def draw(self):
        if self.draw_enable :
            self.plt.draw_artist(self.plt.patch)
            for n in range(self.n):
                self.plt.draw_artist(self.line[n])
            self.draw_enable = False

         
    def update(self, s, FigDraw= True):
        r= s
        ok= False
        if s != None :
            for nm in self.names:
                if s.startswith(nm+ ' '):
                    dta= s.split()
                    yd= self.formats[nm](dta[1])
                    self.set(nm, yd)
                    r= None
                    ok= True
        # Dessine les autres courbes
        if len(self.o) > 1:
            for o in self.o[1:]:
                r= o.update(r, FigDraw= False)
        if ok : 
            self.draw()
            # Ne dessine la figure qu'une seule fois pour tous les oscillos
            if FigDraw :
                if self.figure_enable :
                    self.figure.canvas.draw()
                    self.figure.canvas.flush_events()
                    self.figure_enable= False
            
        return r
    
    def stack(self, oscillo):
        '''
        Regroupe plusieurs oscillos dans une seule fenetre
        Attention : par defaut ils sont synchrones et partagent la meme periode
        Si des variables ont des periodes différentes, il faut les synchroniser lorsqu'elle sont générées dans le processeur embarqué 
        '''
        self.o.append(oscillo)
        plt.close(self.figure)
        plt.close(oscillo.figure)
        plt.show(block=False)
        oscillo.period= self.period
        self.nfig+= 1
        self.figname += str(oscillo.figname)
        self.figure, self.axs= plt.subplots(nrows= self.nfig, ncols=1, num=self.figname, sharex=True)
        for i in range(len(self.o)):
            #self.o[i].plt.remove()
            self.o[i].plt= self.axs[i]
            self.o[i].plot()
        plt.show(block=False)
