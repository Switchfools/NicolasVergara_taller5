import matplotlib.pyplot as plt
import numpy as np
Sol=np.genfromtxt('caos.txt')
plt.plot(Sol[:,0],Sol[:,1],label='q2 vs p2',color='teal',alpha=0.8)
plt.legend()
plt.xlabel('q2')
plt.ylabel('p2')
plt.title('Caos(no muy caotico para epsilon=0.001)')
plt.savefig('caos.pdf')

