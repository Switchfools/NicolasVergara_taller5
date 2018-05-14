import numpy as np
import matplotlib.pylab as plt
Sol=np.genfromtxt('campo.txt')
potencial=Sol[:513,:]
Ex=Sol[513:2*513,:]
Ey=Sol[2*513:,:]
plt.imshow(potencial,cmap=plt.cm.inferno,extent=(-2.5, 2.5, -2.5,2.5))
x=np.linspace(-2.5,2.5,513)
y=np.linspace(-2.5,2.5,513)
X,Y = np.meshgrid(x, y)
color = 2 * np.log(np.hypot(Ex, Ey))
plt.streamplot(X,Y,Ex,Ey, color=color,  linewidth=0.5, cmap=plt.cm.inferno,
               density=2, arrowstyle='->', arrowsize=1)
plt.savefig('placas.pdf')
