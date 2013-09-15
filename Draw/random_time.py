


import pylab
from matplotlib.font_manager import FontProperties
from matplotlib.backends.backend_pdf import PdfPages

pdf = PdfPages('random_time.pdf')
font = FontProperties()
font.set_family('serif')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = ['none', 0.3, 0.4, 0.5, 0.6, 0.7]
#y = [126.92, 105.73, 86.8, 73.12, 82.46, 86.6]
y = [[100.62], [104.43, 101.37, 100.70, 100.56, 100.20, 100.57, 100.40, 102.31, 100.46, 103.28], [97.03, 102.01, 97.45, 108.43, 97.04, 108.51, 96.84, 108.73, 96.70, 108.79], [105.90, 100.09, 111.60, 100.37, 111.15, 100.29, 112.31, 100.32, 104.62, 100.18], [110.51, 114.98, 101.03, 100.79, 102.39, 100.32, 101.85, 100.81, 102.59, 101.20], [109.95, 109.57, 113.18, 111.75, 110.15, 110.65, 109.42, 109.70, 110.29, 110.54]]
iters = [23,23,22,23,24,28]
#iters = [415, 409, 408, 396, 507, 620]
index = range(1, len(x)+1)
pylab.boxplot(y, 0, '')
#pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,x)):
    pylab.annotate('%d iters' % iters[i], xy=(xx, 95), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.ylim([94, 114])
pylab.title('A* search with skipping calculations randomly on Berlin Center', fontproperties=font)
pylab.xlabel('Probability of skipping a calculation', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = [0, 0.3, 0.4, 0.5, 0.6, 0.7]
#y = [19.53, 18.71, 17.48, 18.18, 17.42, 16.53]
y = [[19.53],[17.46, 17.50, 17.37, 17.78, 19.03, 18.98, 19.01, 19.19, 18.96, 18.98], [19.26, 18.89, 18.91, 19.00, 19.09, 18.91, 17.53, 17.10, 17.26, 17.48], [18.34, 17.23, 18.05, 18.07, 18.39, 18.44, 21.94, 26.55, 27.00, 26.55], [18.03, 18.10, 17.94, 20.96, 19.39, 18.27, 18.16, 18.16, 21.57, 18.93], [16.05, 16.02, 15.94, 16.18, 15.83, 15.69, 15.60, 15.64, 15.56, 15.60]]
iters = [26, 25, 25, 31, 34, 34]
index = range(1,len(x)+1)
pylab.boxplot(y, 0, '')
#pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,x)):
    pylab.annotate('%d iters' % iters[i], xy=(xx, 14.5), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

#pylab.ylim([0, 25])
pylab.title('A* search with skipping calculations randomly on ChicagoSketch', fontproperties=font)
pylab.xlabel('Probability of skipping a calculation', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)
pdf.savefig(fig, bbox_inches='tight')

#--------------------------------------------- 
fig = pylab.figure(figsize=(9,5), dpi=200)
x = ['none', 5, 10, 15, 20]
y = [100.62, 96.57, 115.13, 139.6, 164.76]
iters = [23, 22, 30, 40, 50]
index = range(len(x))
pylab.bar(index, y, width=0.5, align='center')
pylab.xticks(index, x, size='small', fontproperties=font)

for i, (xx,yy) in enumerate(zip(index,y)):
    pylab.annotate('%s iters' % str(iters[i]), xy=(xx, yy), xytext=(0,2), textcoords='offset points', ha='center', va='bottom', fontproperties=font)

pylab.title('A* search with skipping calculations when no change occur on Berlin Center', fontproperties=font)
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
