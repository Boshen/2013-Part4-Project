import networkx as nx
import pygraphviz as pgv
import matplotlib.pyplot as plt

G = nx.DiGraph()

path = "ChicagoSketch_net.txt"
edgelist = []

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

with open(path, 'r') as f:
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

tree = []
path = []
with open("chicago_astar_data", 'r') as f:
    flag = False
    while True:
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
plt.figure(figsize=(20,20),dpi=240)
#pos=nx.graphviz_layout(G, prog="dot") 
#pos=nx.graphviz_layout(G, prog="neato") 
#pos=nx.graphviz_layout(G, prog="fdp") 
#pos=nx.graphviz_layout(G, prog="sfdp") 
#nx.draw_networkx(G,pos,with_labels=True, alpha=0.1, node_size=1,widths=0.1, font_color='r',font_size=8,node_color='r',edge_color='k') 
nx.draw_networkx_nodes(G, pos, nodelist=[origin,destination],node_size=100,node_color='r')
p1 = nx.draw_networkx_edges(G, pos, edgelist=edgelist, edge_color='k', arrows=False, widths=0.1, alpha=0.1)
p2 = nx.draw_networkx_edges(G, pos, edgelist=tree, edge_color='b', arrows=False, width=0.8, alpha=0.6)
p3 = nx.draw_networkx_edges(G, pos, edgelist=path, edge_color='r', arrows=False, width=1.5)
#xmax=max(xx for xx,yy in pos.values())
#ymax=max(yy for xx,yy in pos.values())
#plt.xlim(0,xmax)
#plt.ylim(0,ymax)
plt.legend([p1, p2, p3],["unscanned arcs or\n arcs connecting zones", "scanned arcs", "shortest path"], bbox_to_anchor=(0, 0, 0.9, 0.9), loc=1, prop={"size":20}) 
x, y = pos[origin]
plt.text(x, y-25000, s="Origin", bbox=dict(boxstyle="round", fc="1",alpha=1), fontsize=20)
x, y = pos[destination]
plt.text(x-25000, y+12000, s="Destination", bbox=dict(boxstyle="round", fc="1",alpha=1), fontsize=20)
plt.axis("off")
plt.savefig("chicago.pdf", bbox_inches="tight")    
