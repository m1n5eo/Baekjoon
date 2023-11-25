def DNA_strand(dna):
    ans = ""
    for i in range(len(dna)):
        if dna[i] == 'G':
            ans = ans + 'C'
        elif dna[i] == 'C':
            ans = ans + 'G'
        elif dna[i] == 'A':
            ans = ans + 'T'
        else:
            ans = ans + 'A'
    return ans