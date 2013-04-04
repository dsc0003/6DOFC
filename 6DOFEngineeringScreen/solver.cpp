//#include <QtCore/QCoreApplication>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include "solver.h"

using namespace std;

#define pi 3.14159265359

Solver::Solver()
{
    maxI = 15;
    eps = 0.001;
}


Solver::~Solver()
{

}






int Solver::find_intersection_points_nlls3d(float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2,
                             float x3, float y3, float z3, float r3, float xg, float yg, float zg,
                             float& px, float& py, float& pz)
{
    float f1, f2, f3; // functions f1, f2 and f3 where f = (xg-x)^2 + (yg-y)^2 + (zg-z)^2 - r^2
    float df1dx, df1dy, df1dz;  // derivative of f1 wrt x, y and z
    float df2dx, df2dy, df2dz;  // derivative of f2 wrt x, y and z
    float df3dx, df3dy, df3dz;  // derivative of f3 wrt x, y and z
    float J[3][3]; // Jacobian matrix, matrix of the derivatives of f1 and f2 wrt to x and y
    float JInv[3][3];  // inverse of the Jacobian matrix
    float JAdj[3][3];  // adjoint matrix or the jacobian
    float JCof[3][3];  // cofactor matrix
    float det;  // determinant of te Jacobian matrix
    float det1;  // det1 = 1/det
    float xnew, ynew, znew;  // new values of x and y
    int valid;
    float a, b, c, d, e, f, g, h, i;  // letters hold the values of the 3x3 jacobian matrix elements  a b c
                                      //                                                              d e f
                                      //                                                              g h i





    for(int n = 1; n <= maxI; n++)
    {

        // form the functions f1, f2 and f3
        f1 = ((xg-x1)*(xg-x1)) + ((yg-y1)*(yg-y1)) + ((zg-z1)*(zg-z1)) - (r1*r1);
        f2 = ((xg-x2)*(xg-x2)) + ((yg-y2)*(yg-y2)) + ((zg-z2)*(zg-z2)) - (r2*r2);
        f3 = ((xg-x3)*(xg-x3)) + ((yg-y3)*(yg-y3)) + ((zg-z3)*(zg-z3)) - (r3*r3);

        cout << "\n\nvalue of f1 = " << f1 << " , f2 = " << f2 << " , f3 = "  << f3 << endl;


        // find the partial derivatives
        df1dx = 2*xg - 2*x1;        df1dy = 2*yg - 2*y1;        df1dz = 2*zg - 2*z1;
        df2dx = 2*xg - 2*x2;        df2dy = 2*yg - 2*y2;        df2dz = 2*zg - 2*z2;
        df3dx = 2*xg - 2*x3;        df3dy = 2*yg - 2*y3;        df3dz = 2*zg - 2*z3;


        // form the Jacobian matrix
        a = J[0][0] = df1dx;
        b = J[0][1] = df1dy;
        c = J[0][2] = df1dz;

        d = J[1][0] = df2dx;
        e = J[1][1] = df2dy;
        f = J[1][2] = df2dz;

        g = J[2][0] = df3dx;
        h = J[2][1] = df3dy;
        i = J[2][2] = df3dz;

        cout << "jacobian matrix: \n" << endl;
        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0; k <= 2; k++)
            {
                cout << J[j][k] << " ";
            }

            cout << endl;
        }


        // find the determinant of the Jacobian matrix and 1/det
        det = (a*((e*i)-(h*f))) - (b*((d*i)-(g*f))) + (c*((d*h)-(g*e)));

        cout << "determinant of jacobian: " << det << endl;

        if (det != 0)
        {
            det1 = 1/det;
        }
        else
        {
            cout << "determinant = 0, program will now exit" << endl;
            valid = 0;
            return valid;
        }


        float A, B, C, D, E, F, G, H, I;  // elements of the cofactor matrix formed by taking the determinant of the submatrix
                                          // formed by eliminating the row and column of the concerned element

        // compute the cofactor matrix
        // for element i,j eliminate row i and column j and find the determinant of
        // the remaining submatrix, this is the minor of that element M(i,j)
        // the cofactor for an element A(i,j) = (-1)^(i+j) * M(i,j)

        JCof[0][0] = A = (e*i)-(h*f);
        JCof[0][1] = B = -1*((d*i)-(g*f));
        JCof[0][2] = C = (d*h)-(g*e);

        JCof[1][0] = D = -1*((b*i)-(h*c));
        JCof[1][1] = E = (a*i)-(g*c);
        JCof[1][2] = F = -1*((a*h)-(g*b));

        JCof[2][0] = G = (b*f)-(e*c);
        JCof[2][1] = H = -1*((a*f)-(d*c));
        JCof[2][2] = I = (a*e)-(d*b);

        cout << "cofactor matrix: \n" << endl;
        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0; k <= 2; k++)
            {
                cout << JCof[j][k] << " ";
            }

            cout << endl;
        }




        // compute the adjoint matrix
        // the adjoint matrix is formed by transposing the cofactor matrix

        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0; k <= 2; k++)
            {
                JAdj[j][k] = JCof[k][j];
            }

            cout << endl;
        }


        cout << "adjoint matrix: \n" << endl;
        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0; k <= 2; k++)
            {
                cout << JAdj[j][k] << " ";
            }

            cout << endl;
        }


        // compute the inverse of the Jacobian matrix -> JInv = 1/det * JAdj
        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0; k <= 2; k++)
            {
                JInv[j][k] = det1 * JAdj[j][k];
            }
        }

        cout << "inverse matrix: \n" << endl;
        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0; k <= 2; k++)
            {
                cout << JInv[j][k] << " ";
            }

            cout << endl;
        }
        float h0 = (JInv[0][0] * f1) + (JInv[0][1] * f2) + (JInv[0][2] * f3);
        float h1 = (JInv[1][0] * f1) + (JInv[1][1] * f2) + (JInv[1][2] * f3);
        float h2 = (JInv[2][0] * f1) + (JInv[2][1] * f2) + (JInv[2][2] * f3);

        xnew = xg - h0;
        ynew = yg - h1;
        znew = zg - h2;

        cout << "Iteration " << n << ": h0 = " << h0 << " h1 = " << h1 << " h2 = " << h2
             << "\nxnew: " << xnew << " ynew: "  << ynew << " znew: " << znew << endl;


        if(((abs(h0) + abs(h1) + abs(h2)) < eps))
        {
            px = xnew;
            py = ynew;
            pz = znew;
            valid = 1;
            return valid;
        }

        xg = xnew;
        yg = ynew;
        zg = znew;

    }

    cout << "Maximum number of iterations reached" << endl;
    valid = 0;
    return valid;

}






