import pylab
from matplotlib.font_manager import FontProperties


x = ['binomial', 'fibonacci', 'binary', 'ternary', 'pairing', 'skew', 'binary\nsearch\ntree', 'min-heap\ntree']

font = FontProperties()
font.set_family('serif')
font.set_size(26)

y = [369.10, 155.14, 130.22, 155.34, 140.55, 120.45, 149.95, 87.52]
fig = pylab.figure(figsize=(18,8), dpi=150)
index = range(len(x))
p = pylab.bar(index, y, width=0.5, align='center')
pylab.setp(p, color='#0044FF')
pylab.xticks(index, x, fontproperties=font)
pylab.yticks(fontproperties=font)
#pylab.title('Dijkstra\'s algorithm run times using different priority queues', fontproperties=font)
pylab.xlabel('Priority Queues', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)

pylab.savefig('pq_runtime.pdf', bbox_inches='tight')
