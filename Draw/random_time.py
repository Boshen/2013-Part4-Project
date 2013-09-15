


import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('random_time.pdf')
font = FontProperties()
font.set_family('serif')
fontsize = {'size':16}

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
y = [[99.58],[93.9 , 96.38, 96.39, 96.05, 93.52, 97.23, 96.68, 96.68, 95.84, 94.22], [110.62, 111.84, 112.26, 112.39, 112.05, 111.29, 110.95, 112.11, 110.49, 98.79 ], [109.72, 111.18, 111.27, 112.53, 112.02, 113.31, 111.66, 110.82, 111.53, 110.84], [98.18, 97.24, 97.63, 96.95, 94.58, 97.43, 97.1 , 96.88, 94.92, 94.6], [113.74, 115.69, 112.65, 110.64, 113.81, 112, 112.47, 111.83, 113.6 , 109.96]]
x = [0, 0.3, 0.4, 0.5, 0.6, 0.7]
iters = [23, 23, 23, 23, 24, 28]
index = range(1, len(x)+1)
pylab.boxplot(y, 0, '')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,x)):
    pylab.annotate('%d iters' % iters[i], xy=(xx, 95), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.ylim([94, 114])
pylab.title('A* search with random skipping on Berlin Center', fontproperties=font)
pylab.xlabel('Probability of skipping a calculation', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pylab.rc('font', **fontsize)
pdf.savefig(fig, bbox_inches='tight')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
y= [[19.33],
[18.67, 18.18, 18.35, 18.31, 18.19, 17.87, 17.59, 16.91, 17.99, 17.68],
[15.13, 15.91, 15.97, 15.99, 16.06, 15.99, 15.98, 16.04, 15.95, 16.14],
[16.06, 16.1 , 16.04, 16.03, 15.97, 16.03, 16.11, 15.97, 16.11, 15.64],
[14.11, 14.11, 14.11, 14.13, 14.14, 14.04, 14.11, 14.08, 14.05, 13.69],
[14.45, 14.41, 14.41, 14.41, 14.43, 14.44, 14.4 , 14.39, 14.31, 14.3]]
x = [0, 0.3, 0.4, 0.5, 0.6, 0.7]
iters = [26, 25, 25, 31, 34, 34]
index = range(1,len(x)+1)
pylab.boxplot(y, 0, '')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,x)):
    pylab.annotate('%d iters' % iters[i], xy=(xx, 14.5), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.ylim([10, 25])
pylab.title('A* search with random skipping on ChicagoSketch', fontproperties=font)
pylab.xlabel('Probability of skipping a calculation', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pylab.rc('font', **fontsize)
pdf.savefig(fig, bbox_inches='tight')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = ['none', 5, 10, 15, 20]
y = [99.58, 85.75, 118.65, 158.42, 196.4]
iters = [23, 21, 30, 40, 50]
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,y)):
    pylab.annotate('%s iters' % str(iters[i]), xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.title('A* search with skipping calculations on Berlin Center', fontproperties=font)
pylab.xlabel('Skipping the next $n$ calculations', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pylab.rc('font', **fontsize)
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

#pylab.ylim([0, 25])
pylab.title('A* search with skipping calculations on ChicagoSketch', fontproperties=font)
pylab.xlabel('Skipping the next $n$ calculations', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pylab.rc('font', **fontsize)
pdf.savefig(fig, bbox_inches='tight')

pdf.close()
