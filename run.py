#!/usr/bin/python2.7
import sys
import subprocess


algos_boost = ["Dijkstra", "Astar"]
algos_stl = ["DijkstraSTL", "AstarSTL"]

dataStructs = ["FibonacciHeap", "BinaryHeap", "TernaryHeap",
               "SkewHeap", "PairingHeap", "BinomialHeap"]

networks = ["SiouxFalls_net.txt", "Anaheim_net.txt", "Barcelona_net.txt", "Winnipeg_net.txt", "ChicagoSketch_net.txt"]
matrix = ["SiouxFalls_trips.txt", "Anaheim_trips.txt", "Barcelona_trips.txt", "Winnipeg_trips.txt", "ChicagoSketch_trips.txt"]

prefix = "Data/Instances/"

option = int(sys.argv[1])
if option == 1:
    for a in algos:
        for d in dataStructs:
            with open("input4run", "r") as f:
                args = f.readlines()
            for (i, arg) in enumerate(args):
                if arg.startswith("<ShPathAlgo>"):
                    idx1 = i
                if arg.startswith("<ShPathDataStruct>"):
                    idx2 = i
            args[idx1] = "<ShPathAlgo> : {%s}\n" % a
            args[idx2] = "<ShPathDataStruct> : {%s}\n" % d
    
            with open("input4run", 'w') as f:
                f.write("".join(args))
            subprocess.call(["./ta", "input4run"])
            print 
if option == 2:
    algo = sys.argv[2]
    for j in xrange(len(networks)):
        with open("input4run", "r") as f:
            args = f.readlines()
        for (i, arg) in enumerate(args):
            if arg.startswith("<NETWORK>"):
                idx1 = i
            if arg.startswith("<OD_MATRIX>"):
                idx2 = i
            if arg.startswith("<ShPathAlgo>"):
                idx3 = i
        args[idx1] = "<NETWORK> : {%s}\n" % (prefix +networks[j])
        args[idx2] = "<OD_MATRIX> : {%s}\n" % (prefix + matrix[j])
        args[idx3] = "<ShPathAlgo> : {%s}\n" % algo
        with open("input4run", 'w') as f:
            f.write("".join(args))
        subprocess.call(["./ta", "input4run"])
        print 

elif option == 0:
# use for parsing input.params
    with open("input.params", "r") as f:
        args = f.readlines()
    args = [s.strip() for s in args]
    args = [s for s in args if s != '' ]
    args = [s for s in args if s.find('**') == -1]
    args = [s for s in args if not s.startswith("//")]
    args2 = []
    for arg in args:
        l = arg.find("//")
        if l != -1:
            args2.append(arg[:l])
        else:
            args2.append(arg)
    
    args = args2
    outputFile = open("input4run", 'w')
    outputFile.write("\n".join(args))
    outputFile.close()
