from pulp import *


def viennoiserie():
    problem = LpProblem("viennoiserie", LpMaximize)

    # data
    x = LpVariable(name="nb_croissant", lowBound=10, cat="Integer")
    y = LpVariable(name="nb_Kouign-Amamn", lowBound=0, cat="Integer")

    # constraints
    problem += (500*x + 250*y) <= 10000
    problem += (200*x + 200*y) <= 10000

    # function objective

    problem += (1.23*x + 2.5*y)

    # resolution of problem
    problem.solve()

    print(x.varValue)
    print(y.varValue)
    print(value(problem.objective))


viennoiserie()