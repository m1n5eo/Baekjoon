def number(bus_stops):
    human = 0
    for i in range(len(bus_stops)):
        human = human + bus_stops[i][0] - bus_stops[i][1]
    return human