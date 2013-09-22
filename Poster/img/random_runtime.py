
import pylab
from matplotlib.font_manager import FontProperties
import matplotlib.gridspec as gridspec

font = FontProperties()
#font.set_family('serif')
font.set_size(26)

fig = pylab.figure(figsize=(18,8),dpi=150)
y = [19.53, 17.14, 16.04]
index = range(1, 4)
p1 = pylab.bar(index, y, width=0.2, align='center')
pylab.setp(p1, color='#0044FF')

pylab.xticks(index, ['A* search', 'avoid next 5', 'avoid randomly with \n 50% probability'], fontproperties=font)
pylab.yticks(fontproperties=font)

#pylab.title('Run times of A* search and with 50% random skipping\n on Philadelphia and Chicago Regional network', fontproperties=font)
pylab.ylabel('Run time\n(seconds)', {'rotation':'horizontal'}, fontproperties=font)

pylab.savefig('random_runtime.pdf', bbox_inches='tight')
