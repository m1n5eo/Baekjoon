def solution(text, ending):
    if text.find(ending) == -1:
        return False
    else:
        if text.find(ending)+len(ending)+1 == len(text):
            return False
        else:
            return True