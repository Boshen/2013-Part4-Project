import networkx as nx
import pygraphviz as pgv
import matplotlib.pyplot as plt

G = nx.DiGraph()
#G = pgv.AGraph(directed=True)

path = "../Data/Instances/"
filename = "SiouxFalls_net"
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
                G.add_edge(str(fr), str(to))
        if len(ss) != 0 and ss[0] == '~':
            readData = True
    
plt.figure(figsize=(12,12),dpi=120)
pos=nx.graphviz_layout(G,prog="fdp") 
nx.draw(G,pos,with_labels=True, alpha=0.5, node_size=1,widths=0.1,
        font_color='r',font_size=12,node_color='r',edge_color='k') 
xmax=1.1*max(xx for xx,yy in pos.values())
ymax=1.1*max(yy for xx,yy in pos.values())
plt.xlim(-50,xmax)
plt.ylim(-50,ymax)
plt.savefig(filename + ".pdf")    
#pos = nx.spectral_layout(G)
#G.layout(prog='dot')
#G.draw(filename + ".png")
#nx.draw_networkx_nodes(G, pos)
#nx.draw_networkx_edges(G, pos)
#nx.draw_networkx_labels(G, pos)


#plt.show()

#plt.figure(1)
#plt.axis('off')
#plt.show()
#nx.draw_graphviz(G)
#nx.write_dot(G, filename+".dot")
#nx.draw(G,pos,node_color='#A0CBE2',edge_color='#BB0000',width=2,edge_cmap=plt.cm.Blues,with_labels=True)
#plt.show()
#plt.savefig(filename + ".pdf", dpi=200)
