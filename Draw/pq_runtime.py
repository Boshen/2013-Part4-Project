import pylab
from matplotlib.font_manager import FontProperties

x = ['Binomial', 'Fibonacci', 'Binary', 'Ternary', 'Pairing', 'Skew', 'STL Binary\nSearch Tree', 'STL\n Heap']

#y = [369.10, 155.14, 130.22, 155.34, 140.55, 120.45, 149.95, 87.52]
y = [165.8, 73.66, 56.94, 62.21, 69.83, 52.57, 49.95, 34.89]

#y, x = zip(*sorted(zip(y,x), reverse=True))

font = FontProperties()
font.set_family('serif')

pylab.figure(figsize=(11,6), dpi=300)

index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

#pylab.title('Dijkstra\'s algorithim run times using different priority queues on ChicagoSketch', fontproperties=font)
pylab.title('Dijkstra\'s algorithim run times using different priority queues on Winnipeg', fontproperties=font)
pylab.xlabel('Priority Queues', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)

pylab.savefig('pq_runtime2.pdf')
