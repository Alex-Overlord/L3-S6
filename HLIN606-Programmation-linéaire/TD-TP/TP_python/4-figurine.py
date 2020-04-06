from pulp import *


def figurine():
    problem = LpProblem("figurine", LpMaximize)

    # data
    molding = [2, 4, 5, 7]
    baking = [1, 1, 2, 2]
    paint = [1, 2, 3, 3]
    profit = [7, 9, 18, 17]

    # variables
    x = {}

    for i in range(4):
        x[i] = LpVariable(name='x_%s' % i, lowBound=0, cat="Integer")

    # constraints
    problem += lpSum(x[i] * molding[i] for i in range(4)) <= 42
    problem += lpSum(x[i] * baking[i] for i in range(4)) <= 17
    problem += lpSum(x[i] * paint[i] for i in range(4)) <= 24

    # function objective
    problem += lpSum(x[i] * profit[i] for i in range(4))

    # resolution of problem
    problem.solve()

    print(value(problem.objective))
    for i in range(4):
        print(x[i].name, x[i].value())


figurine()