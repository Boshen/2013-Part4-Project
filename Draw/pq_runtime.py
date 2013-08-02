import pylab
from matplotlib.font_manager import FontProperties

x = ['Fibonacci', 'Binary', 'Ternay', 'Skew', 'Pairing', 'Binomial', 'STL\n Heap', 'STL Binary\nSearch Tree']

y = [155.14, 130.22, 155.34, 120.45, 140.55, 369.10, 87.52, 149.95]

y, x = zip(*sorted(zip(y,x), reverse=True))

font = FontProperties()
font.set_family('serif')

pylab.figure(figsize=(11,6), dpi=300)

index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

pylab.title('Dijkstra\'s algorithim run times using different priority queues on ChicagoSketch', fontproperties=font)
pylab.xlabel('Priority Queues', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)

pylab.savefig('pq_runtime.pdf')
