recordings = open('circlecross.in').read().strip()
crossings = []
for i,c in enumerate(recordings):
    first = recordings.index(c)
    if first < i:
        appearances = []
        # Make a list of all cows that have an entry/exit point between the entry and exit point of the current cow
        for j in range(first + 1, i):
            if recordings[j] in appearances:
                appearances.remove(recordings[j])
            else:
                appearances.append(recordings[j])
        # Add all pairs to the crossings list if not already in it
        for k in appearances:
            if [c, k] not in crossings and [k, c] not in crossings:
                crossings.append([c, k])

print(len(crossings), file=open('circlecross.out', 'w'))