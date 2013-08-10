import networkx as nx
import pygraphviz as pgv
import matplotlib.pyplot as plt

G = nx.DiGraph()

edgelist = []

origin = 170 #384
destination = 142 #368
numZones = 386
with open("../Data/Instances/ChicagoSketch_node.txt", 'r') as f:
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

with open("../Data/Instances/ChicagoSketch_net.txt", 'r') as f:
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

forwardtree = []
backwardtree = []
path = []
with open("chicago_astar_bidirect_data2", 'r') as f:
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
                forwardtree.append((fr, to))
        if flag == 2:
            if to > numZones:
                backwardtree.append((fr, to))
        if flag == 3:
            path.append((fr, to))

pos = nx.get_node_attributes(G, "pos")
plt.figure(figsize=(20,20),dpi=240)
#pos=nx.graphviz_layout(G, prog="dot") 
#pos=nx.graphviz_layout(G, prog="neato") 
#pos=nx.graphviz_layout(G, prog="fdp") 
#pos=nx.graphviz_layout(G, prog="sfdp") 
#nx.draw_networkx(G,pos,with_labels=True, alpha=0.1, node_size=1,widths=0.1, font_color='r',font_size=8,node_color='r',edge_color='k') 
nx.draw_networkx_nodes(G, pos, nodelist=[origin,destination],node_size=100,node_color='r')
p1 = nx.draw_networkx_edges(G, pos, edgelist=edgelist, edge_color='k', arrows=False, widths=0.1, alpha=0.1)
p2 = nx.draw_networkx_edges(G, pos, edgelist=forwardtree, edge_color='b', arrows=False, width=0.8, alpha=0.6)
p3 = nx.draw_networkx_edges(G, pos, edgelist=backwardtree, edge_color='g', arrows=False, width=0.8, alpha=0.6)
p4 = nx.draw_networkx_edges(G, pos, edgelist=path, edge_color='r', arrows=False, width=1.5)
#xmax=max(xx for xx,yy in pos.values())
#ymax=max(yy for xx,yy in pos.values())
#plt.xlim(0,xmax)
#plt.ylim(0,ymax)
plt.legend([p1, p2, p3, p4],["unscanned arcs or\n arcs connecting zones", "forward scanned arcs", "backward scanned arcs", "shortest path"], bbox_to_anchor=(0, 0, 0.9, 0.9), loc=1, prop={"size":20}) 
x, y = pos[origin]
#plt.text(x, y-25000, s="Origin", bbox=dict(boxstyle="round", fc="1",alpha=1), fontsize=20)
#plt.text(x-25000, y+12000, s="Destination", bbox=dict(boxstyle="round", fc="1",alpha=1), fontsize=20)
plt.text(x-35000, y+10000, s="Origin", bbox=dict(boxstyle="round", fc="1",alpha=1), fontsize=20)
x, y = pos[destination]
plt.text(x+8000, y-10000, s="Destination", bbox=dict(boxstyle="round", fc="1",alpha=1), fontsize=20)
plt.axis("off")
plt.savefig("chicago_bidirect_astar2.pdf", bbox_inches="tight")    
