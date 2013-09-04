import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('random_time.pdf')
font = FontProperties()
font.set_family('serif')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = [0, 0.3, 0.4, 0.5, 0.6, 0.7]
y = [126.92, 105.73, 86.8, 73.12, 82.46, 86.6]
iters = [415, 409, 408, 396, 507, 620]
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,y)):
    pylab.annotate('%d iters' % iters[i], xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.title('A* search with skipping calculations randomly on Terrassa', fontproperties=font)
pylab.xlabel('Probability of skipping a calculation', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = [0, 0.3, 0.4, 0.5, 0.6, 0.7]
y = [19.53, 18.71, 17.48, 18.18, 17.42, 16.53]
iters = [26, 25, 26, 30, 31, 34]
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,y)):
    pylab.annotate('%d iters' % iters[i], xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.ylim([0, 25])
pylab.title('A* search with skipping calculations randomly on ChicagoSketch', fontproperties=font)
pylab.xlabel('Probability of skipping a calculation', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = ['none', 15, 25, 50, 100, 200]
y = [126.92, 68.48, 61.60, 56.52, 50.82, 59.21]
iters = [415, 351, 355, 379, 411, 563]
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,y)):
    pylab.annotate('%s iters' % str(iters[i]), xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.title('A* search with skipping calculations when no change occur on Terrassa', fontproperties=font)
pylab.xlabel('Skipping the next $n$ calculations', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = ['none', 5, 10, 15, 20]
y = [19.53, 16.14, 16.03, 16.46, 17.94]
iters = [26, 26, 35, 42, 53]
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,y)):
    pylab.annotate('%s iters' % str(iters[i]), xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.ylim([0, 25])
pylab.title('A* search with skipping calculations when change occur on ChicagoSketch', fontproperties=font)
pylab.xlabel('Skipping the next $n$ calculations', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

pdf.close()
