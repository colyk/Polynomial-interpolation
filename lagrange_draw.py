import numpy as np
import matplotlib.pyplot as plt

def lagrange(x_points, y_points, point):
    result = 0
    for j in range(len(y_points)):
        p1 = 1
        p2 = 1
        for i in range(len(x_points)):
            if i == j:
                continue 
            p1 *= (point - x_points[i])
            p2 *= (x_points[j] - x_points[i])
        result += y_points[j] * p1/p2

    return result 


def main():
    x_points = np.array([-4, -2, 0, 2, 4], dtype=float)
    y_points = np.array([16, 4, 0, 4, 16], dtype=float)
    
    x_new = np.linspace(np.min(x_points)-5, np.max(x_points)+5, 1000)
    y_new = [lagrange(x_points, y_points, point) for point in x_new]
    
    plt.plot(x_points, y_points, 'o', x_new, y_new)
    plt.grid(True)
    plt.show()

    
if __name__ == '__main__':
   main()