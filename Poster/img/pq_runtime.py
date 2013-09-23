import pylab
from matplotlib.font_manager import FontProperties


x = ['binomial', 'fibonacci', 'binary', 'ternary', 'pairing', 'skew', 'binary\nsearch\ntree', 'min-heap\ntree']

font = FontProperties()
#font.set_family('serif')
font.set_size(26)

y = [369.10, 155.14, 130.22, 155.34, 140.55, 120.45, 149.95, 87.52]
fig = pylab.figure(figsize=(18,6), dpi=300)
index = map(lambda t:t+0.5, range(len(x)))
ax = fig.add_subplot(111)
p = ax.bar(index, y, width=0.5, align='center')

ax.spines["right"].set_visible(False)
ax.spines["top"].set_visible(False)
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
pylab.setp(p[:-1], color='#0044FF')
pylab.setp(p[-1], color='#FF5E29')
pylab.xticks(index, x, fontproperties=font)
pylab.yticks(fontproperties=font)
ax.yaxis.set_label_coords(-0.07, 0.5)
ax.tick_params(bottom='off') 

#pylab.title('Dijkstra\'s algorithm run times using different priority queues', fontproperties=font)
#pylab.xlabel('Priority Queues', fontproperties=font)
pylab.ylabel('seconds', {'rotation':'horizontal'}, fontproperties=font)

pylab.savefig('pq_runtime.pdf', bbox_inches='tight')
