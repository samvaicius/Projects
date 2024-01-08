
# Imports
import numpy as np
import matplotlib.pyplot as plt
# Registers 3D projection [unused otherwise]
from mpl_toolkits.mplot3d import Axes3D

xs = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
exit = [3.22, 4.98, 7.11, 7.25, 8.01, 8.71, 9.18, 9.4, 9.58, 12.41, 12.82, 13.28, 14.65, 14.92, 15.27]
start = [1, 3.22, 4.98, 7.11, 7.25, 8.01, 8.71, 9.18, 9.4, 10, 12.41, 12.82, 13.28, 14.65, 15]
time_in_queue = [0, 1.22, 1.98, 3.11, 2.25, 2.01, 1.71, 1.18, 0.4, 0, 1.41,  0.82, 0.28, 0.65, 0]
customers_in_system = [1, 2, 3, 3, 3, 4, 5, 4, 3, 1, 2, 3, 2, 2, 1]
customers_in_queue = [0, 1, 2, 2, 2, 3, 4, 3, 2, 0, 1, 2, 1, 1, 0]

def main():

    fig = plt.figure()

    plt.title("customer arrival time vs start time")
    plt.ylabel('start time (min)')
    plt.xlabel('Arrival time (min)')
    plt.plot(xs, start, '-')
    plt.show()

    plt.title("customer arrival time vs exit time")
    plt.ylabel('exit time (min)')
    plt.xlabel('Arrival time (min)')
    plt.plot(xs, exit, '-')
    plt.show()

    plt.title(" customer arrival time vs time in queue ")
    plt.ylabel('time (min)')
    plt.xlabel('Arrival time (min)')
    plt.plot(xs, time_in_queue, '-')
    plt.show()

    plt.title("customer arrival time vs customers in queue")
    plt.ylabel('Nof Customers')
    plt.xlabel('Arrival time (min)')
    plt.plot(xs, customers_in_queue, '-')
    plt.show()

    plt.title("customer arrival time vs customers in the system")
    plt.ylabel('Nof Customers')
    plt.xlabel('Arrival time (min)')
    plt.plot(xs, customers_in_system, '-')
    plt.show()

main()

