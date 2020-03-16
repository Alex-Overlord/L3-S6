from pulp import *

def distance(x1, y1, x2, y2):
    return


def loueur():
    problem = LpProblem("loueur", LpMaximize)

    # data
    exces = [2, 5, 8, 9]
    deficit = [1, 3, 4, 6, 7, 10]
    x = [0, 4, 4, 6, 7, 7, 1, 1, 2, 0]
    y = [0, 4, 2, 2, 0, 5, 5, 2, 0, 3]
    parc_normal = [10, 6, 8, 11, 9, 7, 15, 7, 9, 12]
    parc_observe = [8, 13, 4, 8, 12, 2, 14, 11, 15, 7]
    exces_ou_deficit = [-2, 7, -4, -3, 3, -5, -1, 4, 6, -5]


    # variables


    # constraints


    # function objective


    # resolution of problem
    problem.solve()


loueur()