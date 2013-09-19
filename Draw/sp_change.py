from collections import Counter
import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('sp_change.pdf')

font = FontProperties()
font.set_family('serif')
font.set_size(15)
font2 = FontProperties()
font2.set_family('serif')
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

fig = pylab.figure(figsize=(14,10),dpi=240)

pylab.bar(x,y, align='center')

for xx,yy in zip(x,y):
    pylab.annotate('%.2f' % yy, xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.xticks(x, x, fontproperties=font2)
pylab.yticks(fontproperties=font2)

pylab.title('The percentage of shortest path changes\n for each O-D pair on Chicago Sketch', fontproperties=font2)
pylab.xlabel('Number of times the shortest path for an O-D pair \nchanged 0, 1, 2, 3, $\ldots$, times, out of 26 iterations', fontproperties=font2)
pylab.ylabel('Percentage of total number of O-D pairs', fontproperties=font2)

pylab.autoscale(enable=True, axis='x')
pdf.savefig(fig, bbox_inches='tight')

#------------------------------ 
counts =[]
with open('sp_change_berlin', 'r') as f:
    for line in f:
        o, d, count = map(int, line.split())
        counts.append(count)

x, y = map(list,zip(*Counter(counts).items()))
x = map(lambda t:t-1, x)
y = map(lambda t:100*t/49688.0, y)

x = x[:16]
y = y[:16]

fig = pylab.figure(figsize=(14,10),dpi=240)

pylab.bar(x,y, align='center')

for xx,yy in zip(x,y):
    pylab.annotate('%.2f' % yy, xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.xticks(x, x, fontproperties=font2)
pylab.yticks(fontproperties=font2)

pylab.title('The percentage of shortest path changes\n for each O-D pair on Berlin Center', fontproperties=font2)
pylab.xlabel('Number of times the shortest path for an O-D pair \nchanged 0, 1, 2, 3, $\ldots$, times, out of 23 iterations', fontproperties=font2)
pylab.ylabel('Percentage of total number of O-D pairs', fontproperties=font2)

pylab.autoscale(enable=True, axis='x')
pdf.savefig(fig, bbox_inches='tight')

pdf.close()
