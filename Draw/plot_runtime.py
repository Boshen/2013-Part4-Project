import pylab

networks = ["Anaheim\n416 nodes\n38 zones\n1406 OD pairs\n914 edges",
        "Barcelona\n1020 nodes\n110 zones\n7922 OD pairs\n2522 edges", 
        "Winnipeg\n1052 nodes\n147 zones\n4344 OD pairs\n2836 edges", 
        "ChicagoSketch\n933 nodes\n387 zones\n93135 pairs\n2950 edges"]
algos = ["Bellman-Ford", "Dijkstra", "Bidirectional Dijkstra", "A* search", "Bidirectional A* search"]

zones = [38, 110, 147, 387]
times = [[1.2, 60, 190, 500],
        [0.3, 13.67, 34.89, 87.52],
        [0.43, 20.93, 49.95, 157.75],
        [0.1, 2.99, 10.42, 18.75],
        [0.28, 8.02, 24.81, 59.82]]

pylab.figure(figsize=(30,20),dpi=300)

for time in times:
    pylab.plot(zones, time, 'o-', linewidth=2)

k = 0
for (i, j) in zip([150, 220, 210, 220, 220], [140, 55, 75, 15, 35]):
    pylab.annotate(algos[k], xy=(i, j), xytext=(0,0),
            textcoords='offset points', ha='center', va='bottom',
            bbox=dict(boxstyle='round,pad=0.5',fc= 'white', alpha=0.2))
    k += 1

pylab.title("Algorithm run times vs Different graph sizes")
pylab.ylabel("Run time (seconds)")
x1, x2, y1, y2 = pylab.axis()
#pylab.legend(algos)
pylab.axis((x1, x2, y1, 160))
pylab.xticks(zones, networks)
pylab.autoscale(enable=True, axis='x', tight=None)
font = {'size':22}
pylab.rc('font', **font)
pylab.savefig("runtime.pdf")    

