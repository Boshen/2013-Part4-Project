sp = {}

with open('sp_change2', 'r') as f:
    for lines in f:
        line = map(int, lines.split())
        sp[(line[0], line[1])] = line[2:]

for key, value in sp.iteritems():
    if sum(value) == 3:
        print key, value
