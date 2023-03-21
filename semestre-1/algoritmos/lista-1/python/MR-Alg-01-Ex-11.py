from math import *

t1 = radians(float(input("Latitude 1: ")))
g1 = radians(float(input("Longitude 1: ")))
t2 = radians(float(input("Latitude 2: ")))
g2 = radians(float(input("Longitude 2: ")))

distancia = 6371.01 * acos(sin(t1) * sin(t2) + cos(t1) * cos(t2) * cos(g1 - g2))

print(f"Distância dos dois pontos: {distancia} km")