import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('pq_runtime.pdf')

x = ['Binomial', 'Fibonacci', 'Binary', 'Ternary', 'Pairing', 'Skew', '<set>', '\t <priority_queue>'.expandtabs()]

y = [165.8, 73.66, 56.94, 62.21, 69.83, 52.57, 49.95, 34.89]

#y, x = zip(*sorted(zip(y,x), reverse=True))

font = FontProperties()
font.set_family('serif')
font.set_size(18)
font2 = FontProperties()
font2.set_family('serif')
font2.set_size(13)

fig = pylab.figure(figsize=(11,6), dpi=300)
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, fontproperties=font2)
pylab.yticks(fontproperties=font)
pylab.title('Dijkstra\'s algorithm run times using\n different priority queues on Winnipeg', fontproperties=font)
pylab.xlabel('Priority Queues', fontproperties=font2)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

y = [369.10, 155.14, 130.22, 155.34, 140.55, 120.45, 149.95, 87.52]
fig = pylab.figure(figsize=(11,6), dpi=300)
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, fontproperties=font2)
pylab.yticks(fontproperties=font)
pylab.title('Dijkstra\'s algorithm run times using\n different priority queues on Chicago Sketch', fontproperties=font)
pylab.xlabel('Priority Queues', fontproperties=font2)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)

pdf.savefig(fig, bbox_inches='tight')

pdf.close()
