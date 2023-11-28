def validate_pin(pin):
    if not(len(pin) == 4 or len(pin) == 6):
        return False
    for i in range(len(pin)):
        if not('0' <= pin[i] and pin[i] <= '9'):
            return False
    return True