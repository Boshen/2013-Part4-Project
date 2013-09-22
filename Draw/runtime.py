import pylab

from matplotlib.font_manager import FontProperties

#networks = ['Anaheim\n416 nodes\n38 zones\n1406 OD pairs\n914 edges',
#        'Barcelona\n1020 nodes\n110 zones\n7922 OD pairs\n2522 edges', 
#        'Winnipeg\n1052 nodes\n147 zones\n4344 OD pairs\n2836 edges', 
#        'ChicagoSketch\n933 nodes\n387 zones\n93135 pairs\n2950 edges']
#networks = ['1406',  '7922', '4344', '93135']
networks = ['Anaheim',  'Barcelona', 'Winnipeg', 'Chicago Sketch']
algos = ['Bellman-Ford', 'Dijkstra', 'Bidirectional Dijkstra', 'A* search', 'Bidirectional A* search']
shapes = ['ro:', 'bx:', 'k+:', 'm*:', 'gs:']

zones = [14060, 303894, 607344, 2328375]
times = [[1.2, 60, 190, 500],
        [0.3, 13.67, 34.89, 87.52],
        [0.43, 20.93, 49.95, 157.75],
        [0.1, 2.99, 10.42, 18.75],
        [0.28, 8.02, 24.81, 59.82]]

pylab.figure(figsize=(32,20),dpi=300)

for time, shape in zip(times, shapes):
    pylab.plot(zones, time, shape, markersize=30)

font = FontProperties()
font.set_family('serif')
font.set_size(38)
font2 = FontProperties()
font2.set_family('serif')
font2.set_size(45)

k = 0
for (i, j) in zip([620000, 1437860, 1437860, 1437860, 1437860], [140, 65, 100, 18, 40]):
    pylab.annotate(algos[k], xy=(i, j), xytext=(0,0),
            textcoords='offset points', ha='center', va='bottom',
            bbox=dict(boxstyle='round,pad=0.5',fc= 'white', alpha=0.2), fontproperties=font)
    k += 1

pylab.title('Algorithm run times on different networks', fontproperties=font2)
pylab.ylabel('Run Time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
#pylab.xlabel('Number of Origin-Destination Pairs', fontproperties=font)
pylab.xlabel('Networks', fontproperties=font2)
x1, x2, y1, y2 = pylab.axis()
#pylab.legend(algos)
pylab.axis((x1, x2, y1, 160), fontproperties=font)
pylab.xticks(zones, networks, fontproperties=font)
pylab.yticks(fontproperties=font)
pylab.gca().axes.get_yaxis().set_ticks(range(20,180,20))
#pylab.autoscale(enable=True, axis='x', tight=None)
pylab.savefig('runtime.pdf')    
