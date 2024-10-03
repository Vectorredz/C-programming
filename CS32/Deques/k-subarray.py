list = [5,3,4]
k = 1
currMax = 0
resMax = []

for i in range(len(list) - k + 1):
    currMax = max(list[i:i+k])
    resMax.append(currMax)

print(resMax)