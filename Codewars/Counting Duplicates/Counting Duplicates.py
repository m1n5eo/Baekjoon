def duplicate_count(text):
    text = text.lower()
    cnt = 0
    for i in range(len(text)):
        if text[i] == " ":
            continue
        for j in range(i+1, len(text)):
            if text[i] == text[j]:
                cnt = cnt + 1
                text = text.replace(text[j], " ")
                break
    return cnt