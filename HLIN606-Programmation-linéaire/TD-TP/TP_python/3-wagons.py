from pulp import *


def wagon(boxes, nb_wagons):
    nb_boxes = len(boxes)
    problem = LpProblem("Wagons", LpMinimize)
    w = {}
    for i in range(nb_wagons):
        for j in range(nb_boxes):
            w[i, j] = LpVariable(name='w_%s_%s' % (j, i), cat='Binary')

    k = LpVariable(name="k", lowBound=0, upBound=1000, cat="Integer")

    for j in range(nb_boxes):
        problem += lpSum(w[i, j] for i in range(nb_wagons)) == 1

    for i in range(nb_wagons):
        problem += lpSum(w[i, j] * boxes[j] for j in range(nb_boxes)) <= k

    problem += k

    problem.solve()

    sol = [0] * nb_boxes

    for j in range(nb_boxes):
        for i in range(nb_wagons):
            if w[i, j].varValue == 1:
                sol[j] = i

    return k.varValue, sol


boxes = [34, 6, 8, 17, 16, 5, 13, 21, 25, 21, 14, 13, 33, 9, 25, 25]
print(wagon(boxes, 3))
# j'ajoute des boxes et un wagon
boxes += [35, 23, 12, 10]
print(wagon(boxes, 4))