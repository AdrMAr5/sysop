import csv
import sys
from pulp import *

# Funkcja do wczytywania wektorów z pliku CSV
def wczytaj_wektory(nazwa_pliku):
    wektory = []
    with open(nazwa_pliku, newline='') as csvfile:
        csvreader = csv.reader(csvfile, delimiter=',')
        for row in csvreader:
            wektory.append([float(x) for x in row])
    return wektory


args = map(int, sys.argv[1:4])
P, M, S = args
print(P, M, S)
PP = 100
MM = 50

# Wczytanie wektorów z pliku
materiały = wczytaj_wektory('materiały.csv')
maszyny = wczytaj_wektory('maszyny.csv')
czas = wczytaj_wektory('czas.csv')

# Definiowanie zmiennych decyzyjnych
produkcja = LpVariable.dicts("Produkcja", range(P), 0)

# Definiowanie funkcji celu
prob = LpProblem("Optymalizacja produkcji", LpMaximize)
prob += lpSum([produkcja[i]*float(czas[i][0]) for i in range(P)])

# Definiowanie ograniczeń
for j in range(M):
    prob += lpSum([materiały[i][j] * produkcja[i] for i in range(P)]) <= MM

for j in range(S):
    prob += lpSum([maszyny[i][j] * produkcja[i] for i in range(P)]) <= S

for i in range(P):
    prob += produkcja[i] >= 1
    prob += produkcja[i] <= PP
    
prob.solve()

for i in range(P):
    print("Produkcja produktu {}: {}".format(i+1, produkcja[i].varValue))
