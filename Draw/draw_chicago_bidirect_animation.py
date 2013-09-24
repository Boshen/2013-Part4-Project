import networkx as nx
import pygraphviz as pgv
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages

G = nx.DiGraph()


pdf = PdfPages('chicago_astar_bidirect_animation.pdf')
#pdf = PdfPages('chicago_bidirect_animation.pdf')

origin = 384
destination = 368
numZones = 386

with open("ChicagoSketch_node.txt", 'r') as f:
    f.readline()
    while True:
        line = f.readline()
        if not line:
            break
        ss = line.split()
        if ss != []:
            node = int(ss[0])-1
            X = int(ss[1])
            Y = int(ss[2])
            G.add_node(node, pos=(X, Y))

edgelist = []
with open("ChicagoSketch_net.txt", 'r') as f:
    readData = False
    while True:
        line = f.readline()
        if not line:
            break
        ss = line.split()
        if readData :
            if ss != []:
                fr = int(ss[0])-1
                to = int(ss[1])-1
                length = float(ss[4])
                #edgelist.append( (fr, to, length) )
                if fr > numZones and to > numZones: # dont draw zone nodes
                    edgelist.append( (fr, to) )
                #G.add_edge(fr, to)
        if len(ss) != 0 and ss[0] == '~':
            readData = True
    
_forwardtree = []
_backwardtree = []
_path = []
with open("chicago_astar_bidirect_data", 'r') as f:
#with open("chicago_bidirect_data", 'r') as f:
    while True:
        line = f.readline()
        if not line:
            break
        if line == "forwardtree\n":
            flag = 1
            continue
        if line == "backwardtree\n":
            flag = 2
            continue
        if line == "path\n":
            flag = 3
            continue

        fr, to = map(int, line.split()) 
        if flag == 1:
            if to > numZones:
                _forwardtree.append((fr, to))
        if flag == 2:
            if to > numZones:
                _backwardtree.append((fr, to))
        if flag == 3:
            _path.append((fr, to))

pos = nx.get_node_attributes(G, "pos")

x_range = [0, 50, 50, 125, 125, len(_forwardtree), len(_forwardtree)]
y_range = [0,   0, 50, 50, 125,               125, len(_backwardtree)]
path = []
for i in xrange(7):
    forwardtree = _forwardtree[0:x_range[i]]
    backwardtree = _backwardtree[0:y_range[i]]
    if i == 6:
        path = _path
    
    fig = plt.figure(figsize=(20,20),dpi=240)
    #nx.draw_networkx(G,pos,with_labels=True, alpha=0.1, node_size=1,widths=0.1, font_color='r',font_size=8,node_color='r',edge_color='k') 
    nx.draw_networkx_nodes(G, pos, nodelist=[origin,destination],node_size=100,node_color='r')

    p1 = nx.draw_networkx_edges(G, pos, edgelist=edgelist, edge_color='k', arrows=False, widths=1, alpha=0.1)
    p2 = nx.draw_networkx_edges(G, pos, edgelist=forwardtree, edge_color='b', arrows=False, width=2, alpha=0.6)
    p3 = nx.draw_networkx_edges(G, pos, edgelist=backwardtree, edge_color='g', arrows=False, width=0.8, alpha=0.6)
    p4 = nx.draw_networkx_edges(G, pos, edgelist=path, edge_color='#FF5E29', arrows=False, width=1.5)
    plt.legend([p1, p2, p3, p4],["unsearched areas", "forward search", "backward search", "shortest path"], bbox_to_anchor=(0, 0, 0.99, 0.9), loc=1, prop={"size":35}, frameon=False) 

    x, y = pos[origin]
    plt.text(x-26000, y-30000, s="Origin", fontsize=35)
    x, y = pos[destination]
    plt.text(x-54000, y+12000, s="Destination", fontsize=35)
    plt.axis("off")
    pdf.savefig(fig, bbox_inches='tight')

pdf.close()
