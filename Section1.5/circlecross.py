TOTAL = 52
    
recordings = open('circlecross.in').read().strip()
crossings = []
for i in range(TOTAL):
    if i == recordings.index(recordings[i]):
        # First appearance of letter
        continue
    else:
        appearances = []
        # Make a list of all cows that have an entry/exit point between the entry and exit point of the current cow
        for j in range(recordings.index(recordings[i]) + 1, i):
            if recordings[j] in appearances:
                appearances.remove(recordings[j])
            else:
                appearances.append(recordings[j])
        # Add all pairs to the crossings list if not already in it
        for k in appearances:
            if [recordings[i], k] not in crossings and [k, recordings[i]] not in crossings:
                crossings.append([recordings[i], k])

print(len(crossings), file=open('circlecross.out', 'w'))