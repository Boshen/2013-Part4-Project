import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('pq_runtime.pdf')

x = ['binomial', 'fibonacci', 'binary', 'ternary', 'pairing', 'skew', 'binary\nsearch\ntree', 'binary\nmin-heap\ntree']

font = FontProperties()
#font.set_family('serif')
font.set_size(26)

y = [369.10, 155.14, 130.22, 155.34, 140.55, 120.45, 149.95, 87.52]
fig = pylab.figure(figsize=(18,7), dpi=300)
index = map(lambda t:t+0.5, range(len(x)))
ax = fig.add_subplot(111)
p = ax.bar(index, y, width=0.5, align='center')

ax.spines["right"].set_visible(False)
ax.spines["top"].set_visible(False)
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
pylab.setp(p[:-1], color='#3333B3')
pylab.setp(p[-1], color='#FF5E29')
pylab.xticks(index, x, fontproperties=font)
pylab.yticks(fontproperties=font)
ax.yaxis.set_label_coords(-0.07, 0.5)
ax.tick_params(bottom='off') 
pylab.ylabel('seconds', fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

y = map(lambda t: t/93000, y)
fig = pylab.figure(figsize=(18,7), dpi=300)
ax = fig.add_subplot(111)
p = ax.bar(index, y, width=0.5, align='center')

ax.spines["right"].set_visible(False)
ax.spines["top"].set_visible(False)
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
pylab.setp(p[:-1], color='#3333B3')
pylab.setp(p[-1], color='#FF5E29')
pylab.xticks(index, x, fontproperties=font)
pylab.yticks(fontproperties=font)
ax.yaxis.set_label_coords(-0.07, 0.5)
ax.tick_params(bottom='off') 
pylab.ylabel('seconds', fontproperties=font)
pylab.ylim(0, 400)
pdf.savefig(fig, bbox_inches='tight')

pdf.close()
