import networkx as nx
import pygraphviz as pgv
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages

G = nx.DiGraph()

origin = 384
destination = 368
numZones = 386

pdf = PdfPages('chicago_astar_animation.pdf')
#pdf = PdfPages('chicago_dijkstra_animation.pdf')

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
                if fr > numZones and to > numZones:
                    edgelist.append( (fr, to) )
                #G.add_edge(fr, to)
        if len(ss) != 0 and ss[0] == '~':
            readData = True
    
for i in xrange(5):
    tree, path = [], []
    #with open("chicago_astar_data", 'r') as f:
    with open("chicago_dijkstra_data", 'r') as f:
        flag = False
        j = 0
        while True:
            j += 1
            if j > i*100:
                break
            line = f.readline()
            if not line:
                break
            if line == "path\n":
                flag = True
                continue
            fr, to = map(int, line.split()) 
            if flag:
                path.append((fr, to))
            else:
                if to > numZones:
                    tree.append((fr, to))
    
    pos = nx.get_node_attributes(G, "pos")
    fig = plt.figure(figsize=(20,20),dpi=240)
    nx.draw_networkx_nodes(G, pos, nodelist=[origin,destination],node_size=100,node_color='r')
    nx.draw_networkx_nodes(G, pos, nodelist=[origin,destination],node_size=100,node_color='r')
    p1 = nx.draw_networkx_edges(G, pos, edgelist=edgelist, edge_color='k', arrows=False, widths=1, alpha=0.1)
    p2 = nx.draw_networkx_edges(G, pos, edgelist=tree, edge_color='b', arrows=False, width=2)
    p3 = nx.draw_networkx_edges(G, pos, edgelist=path, edge_color='#FF5E29', arrows=False, width=5)
    plt.legend([p1, p2, p3],["unsearched areas", "forward search", "shortest path"], bbox_to_anchor=(0, 0, 0.99, 0.9), loc=1, prop={"size":35}, frameon=False) 
    x, y = pos[origin]
    plt.text(x-26000, y-30000, s="Origin", fontsize=35)
    x, y = pos[destination]
    plt.text(x-54000, y+12000, s="Destination", fontsize=35)
    plt.axis("off")
    pdf.savefig(fig, bbox_inches='tight')

pdf.close()
