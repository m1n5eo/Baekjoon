def even_or_odd(number):
    if number > 0:
        if number%2 == 0:
            return 'Even'
        elif number%2 == 1:
            return 'Odd'
    elif number < 0:
        if -number%2 == 0:
            return 'Even'
        elif -number%2 == 1:
            return 'Odd'
    elif number == 0:
        return 'Even'