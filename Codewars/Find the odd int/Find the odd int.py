def find_it(seq):
    for i in range(len(seq)):
        cnt = 0
        for j in range(len(seq)):
            if seq[i] == seq[j]:
                cnt = cnt + 1
        if cnt%2 == 1:
            return seq[i]