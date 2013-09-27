
import pylab
from matplotlib.font_manager import FontProperties
import matplotlib.gridspec as gridspec

font = FontProperties()
#font.set_family('serif')
font.set_size(26)

fig = pylab.figure(figsize=(18,7),dpi=300)
ax = fig.add_subplot(111)
y = [19.53, 17.14, 16.04]
index = [1, 1.5, 2]
p1 = ax.bar(index, y, width=0.1, align='center')
pylab.setp(p1, color='#3333B3')
pylab.setp(p1[-1], color='#FF5E29')

pylab.xticks(index, ['A* search', 'avoid next 5 iterations', 'avoid randomly with \n 50% probability'], fontproperties=font)
pylab.yticks(fontproperties=font)

ax.yaxis.set_label_coords(-0.05, 0.5)

ax.spines["right"].set_visible(False)
ax.spines["top"].set_visible(False)
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
ax.tick_params(bottom='off') 

#pylab.title('Run times of A* search and with 50% random skipping\n on Philadelphia and Chicago Regional network', fontproperties=font)
pylab.ylabel('seconds', fontproperties=font)

pylab.savefig('random_runtime.pdf', bbox_inches='tight')
