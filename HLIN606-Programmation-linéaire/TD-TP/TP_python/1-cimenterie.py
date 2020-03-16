from pulp import *


def cement_plant():
    problem = LpProblem("cement_plant", LpMaximize)

    # datas
    x = LpVariable(name="x", lowBound=0)
    y = LpVariable(name="y", lowBound=0)

    # constraints
    problem += (40 * x + 20 * y) <= 420
    problem += (20 * x + 30 * y) <= 510

    # function objective
    problem += (50 * x + 70 * y)

    # resolution of problem
    problem.solve()

    print(x.varValue)
    print(y.varValue)


cement_plant()