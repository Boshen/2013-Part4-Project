import pylab
from matplotlib.font_manager import FontProperties
import matplotlib.gridspec as gridspec

font = FontProperties()
#font.set_family('serif')
font.set_size(26)

times =  [500, 87.52, 157.75, 18.75, 59.82]

algos = ['Bellman-Ford\n(existing)', 'Dijkstra', 'Bidirectional\nDijkstra', 'A* search', 'Bidirectional\nA* search', '']

index = map(lambda t:t+0.5, range(len(times)))

fig = pylab.figure(figsize=(18,6),dpi=300)

gs = gridspec.GridSpec(2, 1, height_ratios=[1,2])

ax =  pylab.subplot(gs[0])
ax2 = pylab.subplot(gs[1], sharex=ax)

p1 = ax.bar(index, times, width=0.3, align='center')
p2 = ax2.bar(index, times, width=0.3, align='center')

pylab.setp(p1, color='#0044FF')
pylab.setp(p2, color='#0044FF')
pylab.setp(p2[3], color='#FF5E29')

ax.set_ylabel('seconds', {'rotation':'horizontal'},ha='left', va = 'top', fontproperties=font)#fontsize = 9)

ax.set_ylim(400, 500)
ax2.set_ylim(0, 200)

pylab.xticks(index, algos, fontproperties=font)

ax.spines["right"].set_visible(False)
ax.spines["top"].set_visible(False)
ax.spines['bottom'].set_visible(False)
ax.xaxis.set_ticks_position('top')
ax.yaxis.set_ticks_position('left')
ax2.spines["right"].set_visible(False)
ax2.spines["top"].set_visible(False)
ax2.xaxis.set_ticks_position('bottom')
ax2.yaxis.set_ticks_position('left')

ax.yaxis.set_tick_params(labelsize=24)
ax2.yaxis.set_tick_params(labelsize=24)

ax.yaxis.set_label_coords(-0.165, -.5)

ax.yaxis.set_ticks(range(400,550,50))
ax2.yaxis.set_ticks(range(0,250,50))

ax.tick_params(labeltop='off', bottom='off',top='off')
ax2.tick_params(bottom='off',top='off') 

d = .015 # how big to make the diagonal lines in axes coordinates
# arguments to pass plot, just so we don't keep repeating them
kwargs = dict(transform=ax.transAxes, color='k', clip_on=False)
ax.plot((-d,+d),(-d,+d), **kwargs)      # top-left diagonal
#ax.plot((1-d,1+d),(-d,+d), **kwargs)    # top-right diagonal

kwargs.update(transform=ax2.transAxes)  # switch to the bottom axes
ax2.plot((-d,+d),(1-d,1+d), **kwargs)   # bottom-left diagonal
#x2.plot((1-d,1+d),(1-d,1+d), **kwargs) # bottom-right diagonal


#pylab.xlabel('Algorithms', fontproperties=font)
#pylab.gca().axes.get_yaxis().set_ticks(range(0,550,50))

#pylab.subplots_adjust(wspace=0.15)


pylab.savefig('runtime.pdf', bbox_inches='tight')
