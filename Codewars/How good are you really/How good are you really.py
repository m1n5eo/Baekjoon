def better_than_average(class_points, your_points):
    sum = 0
    for i in range(len(class_points)):
        sum = sum + class_points[i]
    if sum/len(class_points) < your_points:
        return True
    else:
        return False