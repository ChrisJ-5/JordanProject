# File Name: dataParse.py

temperatures = []

file_path = 'feed_data.csv'
with open(file_path, 'r') as f:
  flines = f.readlines()

  for l in flines:
    l = l.strip()
    parts = l.split(",")

    try:
      temp = float(parts[1])
      temperatures.append(temp)
    except ValueError:
      pass


total = 0
min_temp = temperatures[0]
max_temp = temperatures[0]

for temp in temperatures:
  total += temp
  if temp < min_temp:
    min_temp = temp
  if temp > max_temp:
    max_temp = temp

average = total / len(temperatures)

print("Average:", average)
print("Min Temp:", min_temp)
print("Max Temp:" , max_temp)
