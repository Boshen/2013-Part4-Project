from collections import Counter
import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('sp_change.pdf')
font = FontProperties()
font.set_family('serif')
#------------------------------ 
counts =[]
with open('chicago_sp_change', 'r') as f:
    for line in f:
        o, d, count = map(int, line.split())
        counts.append(count)

x, y = map(list,zip(*Counter(counts).items()))
x = map(lambda t:t+1, x)
y = map(lambda t:100*t/93135.0, y)

fig = pylab.figure(figsize=(14,10),dpi=240)

pylab.bar(x,y, align='center')

for xx,yy in zip(x,y):
    pylab.annotate('%.2f' % yy, xy=(xx, yy), xytext=(3,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.xticks(x, map(str, x), fontproperties=font)

pylab.title('The percentage of shortest path change for each O-D pair out of 26 iterations for ChicagoSketch', fontproperties=font)
pylab.xlabel('Number of shortest path changes out of 26 iterations', fontproperties=font)
pylab.ylabel('Percentage of total number of O-D pairs', fontproperties=font)

pylab.autoscale(enable=True, axis='x', tight=None)
fontt = {'size':14}
pylab.rc('font', **fontt)
pdf.savefig(fig, bbox_inches='tight')

#------------------------------ 
counts =[]
with open('terrassa_sp_change', 'r') as f:
    for line in f:
        o, d, count = map(int, line.split())
        counts.append(count)

x, y = map(list,zip(*Counter(counts).items()))
x = map(lambda t:t+1, x)

fig = pylab.figure(figsize=(120,10),dpi=240)

pylab.bar(x,y, align='center')

for xx,yy in zip(x,y):
    pylab.annotate(yy, xy=(xx, yy), xytext=(3,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.xticks(x, map(str, x), fontproperties=font)

pylab.title('The number of shortest path change for each O-D pair out of 415 iterations and 2214 OD pairs for Terrassa', fontproperties=font)
pylab.xlabel('Number of shortest path changes out of 415 iterations', fontproperties=font)
pylab.ylabel('Number of total number O-D pairs', fontproperties=font)

pylab.autoscale(enable=True, axis='x', tight=None)
fontt = {'size':8}
pylab.rc('font', **fontt)
pdf.savefig(fig, bbox_inches='tight')

pdf.close()
