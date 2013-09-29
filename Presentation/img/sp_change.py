from collections import Counter
import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('sp_change.pdf')

font = FontProperties()
#font.set_family('serif')
font.set_size(15)
font2 = FontProperties()
#font2.set_family('serif')
font2.set_size(24)
#------------------------------ 
counts =[]
with open('chicago_sp_change', 'r') as f:
    for line in f:
        o, d, count = map(int, line.split())
        counts.append(count)

x, y = map(list,zip(*Counter(counts).items()))
#x = map(lambda t:t, x)
y = map(lambda t:100*t/93135.0, y)

fig = pylab.figure(figsize=(14,10),dpi=300)
ax = fig.add_subplot(111)

p = ax.bar(x,y, align='center')
pylab.setp(p, color='#3333B3')

ax.spines["right"].set_visible(False)
ax.spines["top"].set_visible(False)
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
ax.tick_params(bottom='off') 

#for xx,yy in zip(x,y):
#    pylab.annotate('%.2f' % yy, xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.xticks(x, x, fontproperties=font2)
pylab.yticks(fontproperties=font2)

#pylab.title('The percentage of shortest path changes\n for each O-D pair on Chicago Sketch', fontproperties=font2)
pylab.xlabel('Number of shortest paths change', fontproperties=font2)
pylab.ylabel('Percentage of total number of O-D pairs', fontproperties=font2)

pylab.autoscale(enable=True, axis='x')
pdf.savefig(fig, bbox_inches='tight')

pdf.close()
