phrase = "abcbcca"
seq = []
encoded = ""

for c in phrase:
    if c not in seq:
        seq.append(c)
        encoded += c
    
    else:
        idx = seq.index(c)
        c2 = seq[idx-1]
        
        # equivaut à:
        #if idx == 0:
        #    c2 = seq[-1]
        #else:
        #    c2 = seq[idx-1]

        encoded += c2
        seq.remove(c)
        seq.append(c)

print(encoded)