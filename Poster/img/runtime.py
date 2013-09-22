import pylab
from matplotlib.font_manager import FontProperties

font = FontProperties()
#font.set_family('serif')
font.set_size(18)

times =  [500, 87.52, 157.75, 18.75, 59.82, 0.001]

algos = ['Bellman-Ford\n(existing)', 'Dijkstra', 'Bidirectional\nDijkstra', 'A* search', 'Bidirectional\nA* search', '']

index = range(1, len(times)+1)

#pylab.figure(figsize=(20,20),dpi=150)

fig,(ax,ax2) = pylab.subplots(2, 1, sharex=True, figsize=(16,16),dpi=150)

p1 = ax.bar(index, times, width=0.5, align='center')
p2 = ax2.bar(index, times, width=0.5, align='center')

pylab.setp(p1, color='#0044FF')
pylab.setp(p2, color='#0044FF')

ax.set_ylabel('Run Time\n(seconds)', {'rotation':'horizontal'},ha='left', va = 'top', fontproperties=font)#fontsize = 9)

ax.set_ylim(400, 500)
ax2.set_ylim(0, 200)

pylab.xticks(index, algos, fontproperties=font)

ax.yaxis.set_tick_params(labelsize=18)
ax2.yaxis.set_tick_params(labelsize=18)

ax.yaxis.set_label_coords(-0.13, -0.06)

ax.yaxis.set_ticks(range(300,550,50))
ax2.yaxis.set_ticks(range(0,250,50))

ax.spines['bottom'].set_visible(False)
ax2.spines['top'].set_visible(False)
ax.xaxis.tick_top()
ax.tick_params(labeltop='off') # don't put tick labels at the top
ax2.xaxis.tick_bottom()

d = .015 # how big to make the diagonal lines in axes coordinates
# arguments to pass plot, just so we don't keep repeating them
kwargs = dict(transform=ax.transAxes, color='k', clip_on=False)
ax.plot((-d,+d),(-d,+d), **kwargs)      # top-left diagonal
ax.plot((1-d,1+d),(-d,+d), **kwargs)    # top-right diagonal

kwargs.update(transform=ax2.transAxes)  # switch to the bottom axes
ax2.plot((-d,+d),(1-d,1+d), **kwargs)   # bottom-left diagonal
ax2.plot((1-d,1+d),(1-d,1+d), **kwargs) # bottom-right diagonal


#pylab.xlabel('Algorithms', fontproperties=font)
#pylab.gca().axes.get_yaxis().set_ticks(range(0,550,50))

#pylab.subplots_adjust(wspace=0.15)


pylab.savefig('runtime.pdf', bbox_inches='tight')
