import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.animation
import numpy as np
Sol=np.genfromtxt('onda.txt')
tiempos=Sol[:,0]
index=tiempos==1*0.1
def init_animation():
    global line
    po=tiempos==0
    line, = ax.plot(Sol[po,1],Sol[po,2])
    ax.set_xlim(0, 100)
    ax.set_ylim(-1,1)
def animate(i):
    po=tiempos==i
    line.set_data(Sol[po,1],Sol[po,2])
    return line,
fig = plt.figure()
ax = fig.add_subplot(111)
ani = matplotlib.animation.FuncAnimation(fig, animate,init_func=init_animation, frames=200)
ax.set_xlabel('Posición')
ax.set_ylabel('Amplitud')
ax.set_title("solución ecuación de Onda")
ani.save('./cuerda.gif', writer='imagemagick', fps=24)



