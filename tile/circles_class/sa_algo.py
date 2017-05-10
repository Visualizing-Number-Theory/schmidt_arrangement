"""Algo developed from written portion"""

import argparse
import numpy as np
from sympy import isprime

class sa_algo:

    def __init__(self, radius, x_coor, y_coor, prime, delta=-1):
        #initial variables
        self.r = radius
        self.x = x_coor
        self.y = y_coor
        self.p = prime
        self.delta = delta

        #e_d, e_bp, e_dp
        self.e_d = None
        self.e_bp = None
        self.e_dp = None

        #d_p
        self.d_p = None

        #d, b_p
        self.d = None
        self.b_p = None

        #b, a, a_p, c, c_p
        self.b = None
        self.a = None
        self.a_p = None
        self.c = None
        self.c_p = None

        #matrix
        self.matrix = None


    def check_conditions(self):
        right_side = self.x ** self.x + self.y + self.y ** self.y
        if right_side % self.r != 0:
            raise Exception('The condition (1) does not hold')

        if isprime(self.p) == True:
            if self.r % self.p != 0:
                raise Exception('p does not divide r')
        else:
            raise Exception('p is not prime')

    def find_ed(self):
        var = 1 + self.y
        if var % self.p != 0:
            self.e_d = 0
        else:
            e_r = self.r / self.p
            e_x = self.x / self.p
            self.e_d = min([e_r, e_x])

    def find_ebp_edp(self):
        if self.y % self.p != 0:
            self.e_bp = 0
            self.e_dp = 0
        else:
            e_r = self.r / self.p
            e_x = self.x / self.p
            self.e_bp = min([e_r, e_x])
            self.e_dp = self.e_bp
            
    def find_dp(self):
        iterations = self.r /self.p
        p_to_edp = self.p ** self.e_dp
        while iterations > 1:
            p_to_edp *= p_to_edp
            iterations -= 1

        self.d_p = p_to_edp

    def solve_congruence_1(self):
        left1 = self.y
        right1 = -self.d_p * self.x  

        left2 = self.x
        right2 = self.d_p * (1 + self.y)

        mod = self.p ** (self.r / self.p)  

        arr = [i for i in range(0, mod)] 

        for d in arr:
            eqn1 = (d * left1 - right1)
            eqn2 = (d * left2 - right2) 
            if eqn1 % mod == 0 and eqn2 % mod == 0:
                self.d = d
                break

    def solve_congruence_2(self):
        left1 = self.d * self.y + self.d_p * self.x
        right1 = -self.r * self.y

        left2 = self.d * self.x - self.d_p * (1 + self.y)
        right2 = -self.r * self.x
        
        mod = self.p ** (self.r / self.p + self.e_dp)

        arr = [i for i in range(0, mod)]

        for bp in arr:
            eqn1 = (bp * left1 - right1)
            eqn2 = (bp * left2 - right2)
            if eqn1 % mod == 0 and eqn2 % mod == 0:
                self.b_p = bp
                break

    def create_points(self):
        self.b = (self.r + self.b_p * self.d) / self.d_p
        self.a = (self.b * self.x - self.b_p * (1 + self.y)) / self.r
        self.a_p = (self.b * self.y + self.b_p * self.x) / self.r
        self.c = (self.d * self.x - self.d_p * (1 + self.y)) / self.r
        self.c_p = (self.d_p * self.x + self.d * self.y) / self.r

    def create_matrix(self):
        a_11 = np.complex(self.a, self.a_p)
        a_12 = np.complex(self.c, self.c_p)
        a_21 = np.complex(self.b, self.b_p)
        a_22 = np.complex(self.d, self.d_p)

        self.matrix = np.array([[a_11, a_12], [a_21, a_22]])

    def check_circle_equivalence(self):
        if self.delta == -1:
            check = (self.b * self.d_p - self.b_p * self.d, 
                     self.b * self.c_p - self.a_p * self.d, 
                     self.a_p * self.d_p - self.b_p * self.c_p)

            if check != (self.r, self.x, self.y):
                raise Exception('Matrix not valid - error occurred')
        else:
            check = (self.b_p * self.d - self.b * self.d_p,
                     self.a_p * self.d - self.b * self.c_p,
                     self.b * self.c - self.a * self.d)

            if check != (self.r, self.x, self.y):
                raise Exception('Matrix not valid - error occurred')


if __name__ == '__main__':

    #NOTE: Does not handle for cases where congruences cannot be solved yet

    #NOTE: TO RUN IN COMMAND LINE EXAMPLE ->   --r 3 --x 1 --y 1 --p 3 (picture example in directory also)
    #      Otherwise just comment/uncomment below where specified

    #------Comment starting here------#
    parser = argparse.ArgumentParser(description='Create Matrix from point (r,x,y) and prime p')

    parser.add_argument('--r', type=int, required=True, help='The radius of the circle')
    parser.add_argument('--x', type=int, required=True, help='The x coordinate')
    parser.add_argument('--y', type=int, required=True, help='The y coordinate')
    parser.add_argument('--p', type=int, required=True, help='The prime')
    parser.add_argument('--delta', type=int, required=False, default=-1, help='Delta of Schmidt arrangement')

    args = parser.parse_args()

    n = sa_algo(args.r, args.x, args.y, args.p, args.delta)
    #------to here------#

    #Uncomment the line below -- manually point in the coordinates
    #n = sa_algo(3,1,1,3)
    n.check_conditions()
    n.find_ed()
    n.find_ebp_edp()
    n.find_dp()
    n.solve_congruence_1()
    n.solve_congruence_2()
    n.create_points()
    n.create_matrix()
    n.check_circle_equivalence()
    print n.matrix

