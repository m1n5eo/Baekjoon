def narcissistic( value ):
    value_ = 0
    for i in range(len(str(value))):
        value_ = value_ + int(str(value)[i])**len(str(value))
    if value_ == value:
        return True
    else:
        return False