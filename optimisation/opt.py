import numpy as np
from sympy import Symbol,solve,diff
import matplotlib.pyplot as plt
#import sys
import subprocess
import shlex

#Gradient Descend Algorithm

W = 590
H = 350

x = np.linspace(-5,5,20)
o = Symbol('o')
y =2/o+o/2

old_min = 0
temp_min = 15
step_size = 0.01
precision = 0.001

def f_derivative(m):
    p = diff(y,o)
    p = p.subs(o,m)
    return p


mins = []
cost = []

while abs(temp_min - old_min) > precision:
    old_min = temp_min
    gradient = f_derivative(old_min)
    move = gradient * step_size
    temp_min = old_min - move
    cost.append((3 - temp_min) ** 2)
    mins.append(temp_min)

print("Local minimum occurs at {}".format(round(temp_min, 2)))
z = y.subs(o,temp_min)
print ("and the local minimum is",z)


#plotting

y = 2/x + x/2
B = np.array([1.98, 2.83069711913966])
O = np.array([0,0])
plt.plot(x, y, 'r', label='$y = 2/x + x/2$')
tri_coords = np.vstack((B, O)).T
plt.scatter(tri_coords[0, :], tri_coords[1, :])
vert_labels = ['B', 'O']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
                 (tri_coords[0, i], tri_coords[1, i]),
                 textcoords="offset points",
                 xytext=(0, 10),
                 ha='center')
    plt.xlabel('$x$')
    plt.ylabel('$y$')
    plt.legend(loc='best')
    plt.grid()
    plt.axis('equal')

#plt.savefig('/Desktop/optimisation/assign5.pdf')
#subprocess.run(shlex.split("termux-open /Desktop/optmisation/assign5.pdf"))
#else
plt.show()
