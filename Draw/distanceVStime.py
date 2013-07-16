import matplotlib.pyplot as plt
x, y = [], []
with open("distanceVStime_dijkstra", "r") as f:
    for line in f:
        dist, time = map(float, line.split())
        x.append(dist)
        y.append(time)

plt.plot(x,y, '.')
plt.show()

