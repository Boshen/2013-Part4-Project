import pylab

x = ['Fibonacci', 'Binary', 'Ternay', 'Skew', 'Pairing', 'Binomial', 'STL\n Heap', 'STL Binary\nSearch Tree']

y = [155.14, 130.22, 155.34, 120.45, 140.55, 369.10, 87.52, 149.95]

y, x = zip(*sorted(zip(y,x), reverse=True))


pylab.figure(figsize=(11,6), dpi=300)

index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small')

pylab.title('Dijkstra\'s Algorithim run times using different priority queues on ChicagoSketch')
pylab.xlabel('Priority Queues')
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'})

pylab.savefig('pq_runtime.pdf')
