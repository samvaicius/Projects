import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button




# Define initial parameters
t = np.linspace(0, 1, 1000)
init_sigma = 10
init_r = 28
init_b = 8/3
dt = 0.01
num_iterations = 10000
xs = np.empty(num_iterations + 1)  # Create empty np.array for x
ys = np.empty(num_iterations + 1)  # Create empty np.array for y
zs = np.empty(num_iterations + 1)  # Create empty np.array for z


# The parametrized function to be plotted
def f(x, y, z, sigma, r, b):
    x_prime = sigma * (y - x)  # x' = sigma * (y-x); calculates x'
    y_prime = r * x - y - x * z  # y' = r*x - y -x*z; calculates y'
    z_prime = x * y - b * z  # z' = x*y - b*z; calculates z'
    return x_prime, y_prime, z_prime
    #return amplitude * np.sin(2 * np.pi * frequency * t)

def generatedata(sigma, r, b):
    xs[0] = 11.8  # Average size of a png in KB
    ys[0] = 4.4  # Average size of a jpg in KB
    zs[0] = 2.4  # Average size of a gif in KB

    for i in range(num_iterations):  # Iterates number of desired iterations over 'time'
        x_prime, y_prime, z_prime = f(xs[i], ys[i], zs[i], sigma, r, b)  # Call Lorenz
        xs[i + 1] = xs[i] + (x_prime * dt)  # Estimate next x-value using x_prime [partial derivative]
        ys[i + 1] = ys[i] + (y_prime * dt)  # Estimate next y-value using y_prime [partial derivative]
        zs[i + 1] = zs[i] + (z_prime * dt)  # Estimate next z-value using z_prime [partial derivative]

    ax.plot(xs, ys, zs, lw=0.5)
    return None

# Plot Lorenz
fig = plt.figure()  # Set fig equal to a figure
ax = plt.axes(projection='3d')


ax.plot3D(xs,ys,zs, lw=0.5)  # Plot x, y, and z with line width 0.5
ax.set_xlabel("x-axis")  # Sets x label
ax.set_ylabel("y-axis")  # Sets y label
ax.set_zlabel("z-axis")  # Sets z label
ax.set_title("Lorenz:")  # Set title based on r

# adjust the main plot to make room for the sliders
plt.subplots_adjust(left=0.25, bottom=0.25)

# Make a horizontal slider to control the sigma
axsigma = plt.axes([0.25, 0.1, 0.65, 0.03])
sigma_slider = Slider(
    ax=axsigma,
    label='Sigma val',
    valmin=0.1,
    valmax=20,
    valinit=init_sigma,
)

# Make a horizontal slider to control the b value
axb = plt.axes([0.25, 0.01, 0.65, 0.03])
b_slider = Slider(
    ax=axb,
    label='b val',
    valmin=0.1,
    valmax=4,
    valinit=init_b,
)

# Make a vertically oriented slider to control the r value
axr = plt.axes([0.1, 0.25, 0.0225, 0.63])
r_slider = Slider(
    ax=axr,
    label="R val",
    valmin=0,
    valmax=30,
    valinit=init_r,
    orientation="vertical"
)

# The function to be called anytime a slider's value changes
def update(val):
    generatedata(sigma_slider.val,r_slider.val,b_slider.val)
    fig.canvas.draw_idle()

# register the update function with each slider
sigma_slider.on_changed(update)
r_slider.on_changed(update)
b_slider.on_changed(update)

# Create a `matplotlib.widgets.Button` to reset the sliders to initial values.
resetax = plt.axes([0.8, 0.9, 0.1, 0.04])
button = Button(resetax, 'Reset', hovercolor='0.975')

def reset(event):
    sigma_slider.reset()
    r_slider.reset()
    b_slider.reset()
button.on_clicked(reset)

plt.show()