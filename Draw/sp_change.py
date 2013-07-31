from collections import Counter
import pylab

counts =[]
with open('sp_change', 'r') as f:
    for line in f:
        o, d, count = map(int, line.split())
        counts.append(count)

x, y = map(list,zip(*Counter(counts).items()))
x = map(lambda t:t+1, x)
y = map(lambda t:100*t/93135.0, y)

pylab.figure(figsize=(20,10),dpi=240)

pylab.bar(x,y, align='center')

for xx,yy in zip(x,y):
    pylab.annotate('%.2f' % yy, xy=(xx, yy), xytext=(0,0), textcoords='offset points', ha='center', va='bottom')

pylab.xticks(x, map(str, x))

pylab.title('ChicagoSketch - the percentage of shortest path change for each O-D pair out of 26 iterations')
pylab.xlabel('Number of shortest path changes out of 26 iterations')
pylab.ylabel('Percentage of total number O-D pairs')

pylab.autoscale(enable=True, axis='x', tight=None)
pylab.savefig("sp_change.pdf")   
