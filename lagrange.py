import numpy as np
import matplotlib.pyplot as plt
PI = 3.14

x_points = np.array([0,PI/2,-PI/2, PI, -PI], dtype=float)
y_points = np.array([0,1,-1,0,0], dtype=float)

def lagranz(x_points, y_points, t):
    result = 0
    for j in range(len(y_points)):
        p1 = 1
        p2 = 1
        for i in range(len(x_points)):
            if i == j:
                continue 
            else: 
                p1 *= (t-x_points[i])
                p2 *= (x_points[j] - x_points[i])
        result += y_points[j]*p1/p2

    return result 

x_new = np.linspace(np.min(x_points)-5, np.max(x_points)+5, 1000)
y_new = [lagranz(x_points, y_points, point) for point in x_new]

plt.plot(x_points, y_points,'o', x_new, y_new)
plt.grid(True)
plt.show()