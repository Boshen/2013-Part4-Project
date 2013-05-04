import networkx as nx
import pygraphviz as pgv
import matplotlib.pyplot as plt

G = nx.DiGraph()

path = "../Data/Instances/"
filename = "Barcelona_net"
path += filename + ".txt"
edgelist = []
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
                edgelist.append( (fr, to, length) )
        if len(ss) != 0 and ss[0] == '~':
            readData = True

tree = []
path = []
with open("barcelonadata", 'r') as f:
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
            tree.append((fr, to))

#G.add_edges_from(edgelist)
G.add_weighted_edges_from(edgelist)
G.add_edges_from(tree)
G.add_edges_from(path)
plt.figure(figsize=(20,20), dpi=240)
#pos=nx.graphviz_layout(G, prog="dot") 
pos=nx.graphviz_layout(G, prog="neato") 
#pos=nx.graphviz_layout(G, prog="fdp") 
#pos=nx.graphviz_layout(G, prog="sfdp") 
#nx.draw(G,pos,with_labels=True, alpha=0.5, node_size=1,widths=0.1,
#        font_color='r',font_size=12,node_color='r',edge_color='k') 
nx.draw_networkx_nodes(G, pos, nodelist=[13, 100],node_size=100,node_color='r')
nx.draw_networkx_edges(G, pos, edgelist=edgelist, edge_color='k', arrows=False, widths=0.1, alpha=0.1)
nx.draw_networkx_edges(G, pos, edgelist=tree, edge_color='b', arrows=False)
nx.draw_networkx_edges(G, pos, edgelist=path, edge_color='r', arrows=False, width=1.5)
xmax=1.1*max(xx for xx,yy in pos.values())
ymax=1.1*max(yy for xx,yy in pos.values())
plt.xlim(-50,xmax)
plt.ylim(-50,ymax)
plt.axis("off")
plt.savefig(filename + ".pdf", bbox_inches="tight")    
