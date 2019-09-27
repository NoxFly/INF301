phrase = "abcbcca"
seq = []
encoded = ""

print("phrase de départ:",phrase)

for c in phrase:
    if c not in seq:
        seq.append(c)
        encoded += c
    
    else:
        idx = seq.index(c)
        c2 = seq[idx-1]

        encoded += c2
        seq.remove(c)
        seq.append(c)

print("phrase encodée:",encoded)

decoded = ""
seq = []

for c in encoded:
    if c not in seq:
        seq.append(c)
        decoded += c
    
    else:
        idx = seq.index(c)
        c2 = seq[(idx+1)%len(seq)]

        decoded += c2
        seq.remove(c2)
        seq.append(c2)

print("phrase décodée",decoded)
