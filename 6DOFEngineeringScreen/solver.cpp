//#include <QtCore/QCoreApplication>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include "solver.h"

using namespace std;


#define pi 3.14159265359

// NLLS2d methods
void Solver::get_parameters_nlls2d(float* x1, float* y1, float* r1, float* x2, float* y2, float* r2, float* xg, float* yg)
{
//    in_nlls2d >> *x1 >> *y1 >> *r1;
//    in_nlls2d >> *x2 >> *y2 >> *r2;
//    in_nlls2d >> *xg >> *yg;
}


int Solver::find_intersection_points_nlls2d(float x1, float y1, float r1, float x2, float y2, float r2, float xg, float yg,
                             float& px, float& py, int maxI, float e)
{
    float f1, f2; // functions f1 and f2
    float df1dx, df1dy;  // derivative of f1 wrt x and y
    float df2dx, df2dy;  // derivative of f2 wrt x and y
    float J[2][2]; // Jacobian matrix, matrix of the derivatives of f1 and f2 wrt to x and y
    float JInv[2][2];  // inverse of the Jacobian matrix
    float JAdj[2][2];  // adjoint matrix or the jacobian
    float JCof[2][2];  // cofactor matrix
    float JMin[2][2];    // minor matrix
    float det;  // determinant of te Jacobian matrix
    float det1;  // det1 = 1/det
    float xnew, ynew;  // new values of x and y
    int valid;




    for(int n = 0; n <= maxI; n++)
    {

        // form the functions f1 and f2
        f1 = ((xg-x1)*(xg-x1)) + ((yg-y1)*(yg-y1)) - (r1*r1);
        f2 = ((xg-x2)*(xg-x2)) + ((yg-y2)*(yg-y2)) - (r2*r2);

        cout << "\n\nvalue of f1 = " << f1 << " and f2 = " << f2 << endl;


        // find the partial derivatives
        df1dx = 2*xg - 2*x1;
        df1dy = 2*yg - 2*y1;
        df2dx = 2*xg - 2*x2;
        df2dy = 2*yg - 2*y2;


        // form the Jacobian matrix
        J[0][0] = df1dx;
        J[0][1] = df1dy;
        J[1][0] = df2dx;
        J[1][1] = df2dy;

        cout << "jacobian matrix: \n" << J[0][0] << " "  << J[0][1] << "\n" << J[1][0] << " " << J[1][1] << endl;


        // find the determinant of the Jacobian matrix and 1/det
        det = (J[0][0] * J[1][1]) - (J[0][1] * J[1][0]);

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


        // compute the cofactor matrix
        // for element i,j eliminate row i and column j and find the determinant of
        // the remaining submatrix, this is the minor of that element M(i,j)
        // the cofactor for an element A(i,j) = (-1)^(i+j) * M(i,j)

        JMin[0][0] = J[1][1];
        JMin[0][1] = J[1][0];
        JMin[1][0] = J[0][1];
        JMin[1][1] = J[0][0];

        cout << "jacobian minor matrix: \n" << JMin[0][0] << " "  << JMin[0][1] << "\n" << JMin[1][0] << " " << JMin[1][1] << endl;


        JCof[0][0] = JMin[0][0];
        JCof[0][1] = -1 * JMin[0][1];
        JCof[1][0] = -1 * JMin[1][0];
        JCof[1][1] = JMin[1][1];

        cout << "jacobian cofactor matrix: \n" << JCof[0][0] << " "  << JCof[0][1] << "\n" << JCof[1][0] << " " << JCof[1][1] << endl;


        // compute the adjoint matrix
        // the adjoint matrix is formed by transposing the cofactor matrix
        JAdj[0][0] = JCof[0][0];
        JAdj[0][1] = JCof[1][0];
        JAdj[1][0] = JCof[0][1];
        JAdj[1][1] = JCof[1][1];


        cout << "jacobian adjoint matrix: \n" << JAdj[0][0] << " "  << JAdj[0][1] << "\n" << JAdj[1][0] << " " << JAdj[1][1] << endl;


        // compute the inverse of the Jacobian matrix -> JInv = 1/det * JAdj
        for(int i = 0; i <= 1; i++)
        {
            for(int j = 0; j <= 1; j++)
            {
                JInv[i][j] = det1 * JAdj[i][j];
            }
        }

        cout << "jacobian inverse matrix: \n" << JInv[0][0] << " "  << JInv[0][1] << "\n" << JInv[1][0] << " " << JInv[1][1] << endl;

        float h1 = (JInv[0][0] * f1) + (JInv[0][1] * f2);
        float h2 = (JInv[1][0] * f1) + (JInv[1][1] * f2);

        xnew = xg - h1;
        ynew = yg - h2;

        cout << "Iteration " << n << ": h1 = " << h1 << " h2 = " << h2
             << ": new x value: " << xnew << " new y value: "  << ynew << endl;


        if(((abs(h1) + abs(h2)) < e))
        {
            px = xnew;
            py = ynew;
            valid = 1;
            return valid;
        }

        xg = xnew;
        yg = ynew;

    }

    cout << "Maximum number of iterations reached" << endl;
    valid = 0;
}

























// NLLS3D methods
void Solver::get_parameters_nlls3d(float* x1, float* y1, float* z1, float* r1, float* x2, float* y2, float* z2, float* r2,
                    float* x3, float* y3, float* z3, float* r3, float* xg, float* yg, float* zg)
{
//    in_nlls3d >> *x1 >> *y1 >> *z1 >> *r1;
//    in_nlls3d >> *x2 >> *y2 >> *z2 >> *r2;
//    in_nlls3d >> *x3 >> *y3 >> *z3 >> *r3;
//    in_nlls3d >> *xg >> *yg >> *zg;
}


int Solver::find_intersection_points_nlls3d(float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2,
                             float x3, float y3, float z3, float r3, float xg, float yg, float zg,
                             float& px, float& py, float& pz, int maxI, float ex)
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


        if(((abs(h0) + abs(h1) + abs(h2)) < ex))
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






















// GEOM2D methods
void Solver::get_parameters_geom2d(float* x1, float* y1, float* x2, float* y2, float* r1, float* r2, float* xg, float* yg)
{
//    in_geom2d >> *x1 >> *y1;
//    in_geom2d >> *r1;
//    in_geom2d >> *x2 >> *y2;
//    in_geom2d >> *r2;
//    in_geom2d >> *xg >> *yg;
}

int Solver::find_intersection_points_geom2d(float x1, float y1, float x2, float y2, float r1, float r2, float xg, float yg, float* px, float* py)
{
    float xdiff, ydiff;  // (x2-x1), (y2-y1)
    float xdiff2, ydiff2;  // (x2-x1)^2, (y2-y1)^2
    float dist;  // distance between the centers of the circles
    int valid;  // return value
    float a; // distance from the center of the first circle to the line joining the points of intersection at point p0
    float xm, ym; // midpoint of the two intersection points, point p0
    float h; // distance from point p0 to each intersection point
    float xa, ya;  // first intersection point
    float xb, yb;  // second intersection point
    float dist_seed_to_Pa_squared;  // distance from seed point to the first intesection point
    float dist_seed_to_Pb_squared;  // distance from seed point to the second inersection point





    /* step 1 */

    // distance between center coordinates
    xdiff = x2 - x1;
    ydiff = y2 - y1;

    cout << "xdiff = " << xdiff << endl << "ydiff = " << ydiff << endl;
//    out_geom2d << "xdiff = " << xdiff << endl << "ydiff = " << ydiff << endl;

    // square the differences
    xdiff2 = xdiff * xdiff;
    ydiff2 = ydiff * ydiff;

    // distance between centers
    dist = sqrt( xdiff2 + ydiff2 );

    cout << "dist = " << dist << endl;
    //out_geom2d << "dist = " << dist << endl;


    /* step 2 */

    // If the radii are too short for the circles to intercept then
    // find the point half way between the circle/baseline intersections
    if ((r1 + r2) < dist) // circles do not intersect
    {
        cout << "the circles do not intersect because the radii are too short" << endl;
        //out_geom2d << "the circles do not intersect because the radii are too short" << endl;
        valid = 0;
        return valid;
    }

    // If r2 circle encompasses the r2 circle, one circle is completely inside the other
    else if ((abs(r2-r1)) > dist)
    {
        cout << "the circles do not intersect because one circle is completely inside the other" << endl;
        //out_geom2d << "the circles do not intersect because one circle is completely inside the other" << endl;
        valid = 0;
        return valid;
    }

    // If dist = 0 and the radii are the same, the circles completely overlap each other
    else if((r1 == r2) && (dist == 0))
    {
        cout << "the circles do not intersect because they overlap completely" << endl;
        //out_geom2d << "the circles do not intersect because they overlap completely" << endl;
        valid = 0;
        return valid;
    }
    else
    {


        /* step 3 */

        // distance from x1 to line joining points of intersection
        // distance "a" of the midpoint of the two intersections from the center of the first circle
        a = ((dist*dist) + (r1*r1) - (r2*r2) )/( 2*dist );
        cout << "a = " << a << endl;
        //out_geom2d << "a = " << a << endl;




        /* step 4 */

        // Find the midpoint of the two intersections "P"
        // point on center line perpendicular to target point
        // P = c0 + a * (c1 - c0) / dist
        // where c0 is the center of the first circle and c1 is the center of the second circle.
        xm = x1 + xdiff*a/dist;
        ym = y1 + ydiff*a/dist;

        cout << "xm = " << xm << endl << "ym = " << ym << endl;
        //out_geom2d << "xm = " << xm << endl << "ym = " << ym << endl;




        /* step 5 */
        // Solve for the distance of the two intersections from the point P by taking the
        // square root of the difference of the r1 squared and a squared: h = sqrt(r1^2 - a^2)
        // a^2 + b^2 = c^2 - sides of a triangle
        // height of perpendicular line

        // if r1 == a the circles intersect at only one point, return that intersection point but set valid to zero
        if (r1 <= a) // guard against neg sqrt
        {
            *px = xm;
            *py = ym;
            h = 0;
            cout << "the circles intersect at only one point" << endl;
            //out_geom2d << "the circles intersect at only one point" << endl;
            valid = 0;
            return valid;
        }
        else
        {
            h = sqrt((r1*r1) - (a*a));
        }

        cout << "h = " << h << endl;
        //out_geom2d << "h = " << h << endl;


        /* step 6 */
        // Find the first intersection point at (xa, ya) with the formulas (xa = Px + h (c1y - c0y) / d)
        // and (ya = Py - h (c1x - c0x) / d) where c1x is the x coordinate of the second circle's center,
        // and c0x is the x coordinate of the first circle's center.
        // Find solution
        xa = xm + h*ydiff/dist;
        ya = ym - h*xdiff/dist;

        cout << "xa = " << xa << endl << "ya = " << ya << endl;
        //out_geom2d << "xa = " << xa << endl << "ya = " << ya << endl;


        /* step 7 */
        // Find the second intersection point (xb, yb) with the formulas (xb = Px - h (c1y - c0y) / d) and (yb = Py + h (c1x - c0x) / d).
        // Find alternate solution
        xb = xm - h*(y2-y1)/dist;
        yb = ym + h*(x2-x1)/dist;

        cout << "xb = " << xb << endl << "yb = " << yb << endl;
        //out_geom2d << "xb = " << xb << endl << "yb = " << yb << endl;

        // Pick the choice closest to the seed
        dist_seed_to_Pa_squared = ((xa-xg)*(xa-xg)) + ((ya-yg)*(ya-yg));
        dist_seed_to_Pb_squared = ((xb-xg)*(xb-xg)) + ((yb-yg)*(yb-yg));

        if (dist_seed_to_Pa_squared < dist_seed_to_Pb_squared)
        {
            *px = xa;
            *py = ya;
        }
        else
        {
            *px = xb;
            *py = yb;
        }

        valid = 1;
        return valid;
    }
}


















// EKF2D methods
int Solver::get_parameters_ekf2d(int antenna, int iteration, double& time, double& sigmaAcceleration, double anchorPos[], double& measuredRange, double& sigmaRange)
{
    //cout << "\n\n getting parameters now...\n\n";

    // check if there is valid data first by checking status bit
    if (status == 1)
    {
        time = dT;
        sigmaAcceleration = sigma_a;
        sigmaRange = sigma_r;

        if (antenna == 0)
        {
            measuredRange = Rmeasured1[iteration];
            anchorPos[0] = a1;
            anchorPos[1] = b1;
        }
        else
        {
            measuredRange = Rmeasured2[iteration];
            anchorPos[0] = a2;
            anchorPos[1] = b2;
        }

        return status;
    }
    else
    {
        return 0;
    }
}

void Solver::get_initialConditions_ekf2d(double initialStateVector[], double initialCovarianceMatrix[][4])
{
    cout << "\n\n getting initial conditions...\n\n";

    // get initial state vector and initial covariance matrix
    for(int i = 0; i < 4; i++)
    {
        initialStateVector[i] = StateVector[i];

        for(int j = 0; j < 4; j++)
        {
             initialCovarianceMatrix[i][j] = CovarianceMatrix[i][j];
        }
    }

    //cout << "\n\n getting initial conditions...\n\n";

}

void Solver::simulate_data_ekf2d()
{
//    srand(100);
    //double r = rand()/RAND_MAX;

    float avgVel = 0.5*pi/180;

    for(int i = 0; i < N; i++)
    {


//        in_ekf2d >> Rmeasured1[i] >> Rmeasured2[i];











        T[i] = i+1;
        Xtruth[i] = 5 + 3*sin(avgVel*T[i]);
        Ytruth[i] = 5*cos(avgVel*T[i]);
//        Rtruth1[i] = sqrt(((Xtruth[i]-a1) * (Xtruth[i]-a1)) + ((Ytruth[i]-b1)*(Ytruth[i]-b1)));
//        Rtruth2[i] = sqrt(((Xtruth[i]-a2) * (Xtruth[i]-a2)) + ((Ytruth[i]-b2)*(Ytruth[i]-b2)));
//        Rnoise1[i] = sigma_r*((rand() % 100)/50 - sigma_r);
//        Rmeasured1[i] = Rtruth1[i] + Rnoise1[i];
//        Rnoise2[i] = sigma_r*((rand() % 100)/50 - sigma_r);
//        Rmeasured2[i] = Rtruth2[i] + Rnoise2[i];

    }








//    out_ekf2d << "True Trajectory" << endl;

    for(int i = 0; i < N; i++)
    {
        //out_ekf2d << "x[" << i << "],y[" << i << "] = " << Xtruth[i] << ", " << Ytruth[i] << endl;
    }


//    outFile << "\n\nTrue Ranges: Antenna 1" << endl;

//    for(int i = 0; i < N; i++)
//    {
//        outFile << "Rtruth1[" << i << "] = " << Rtruth1[i] << endl;
//    }


//    outFile << "\n\nTrue Ranges: Antenna 2" << endl;

//    for(int i = 0; i < N; i++)
//    {
//        outFile << "Rtruth2[" << i << "] = " << Rtruth2[i] << endl;
//    }


//    outFile << "\n\nNoise: Antenna 1" << endl;
//    for(int i = 0; i < N; i++)
//    {
//        outFile << "Rnoise1[" << i << "] = " << Rnoise1[i] << endl;
//    }


//    outFile << "\n\nNoise: Antenna 2" << endl;
//    for(int i = 0; i < N; i++)
//    {
//        outFile << "Rnoise2[" << i << "] = " << Rnoise2[i] << endl;
//    }


//    outFile << "\n\nMeasured Ranges: Antenna 1" << endl;

//    for(int i = 0; i < N; i++)
//    {
//        outFile << "Rmeas1[" << i << "] = " << Rmeasured1[i] << endl;
//    }


//    outFile << "\n\nMeasured Ranges: Antenna 2" << endl;

//    for(int i = 0; i < N; i++)
//    {
//        outFile << "Rmeas2[" << i << "] = " << Rmeasured2[i] << endl;
//    }






    // initial state vector
    StateVector[0] = Xtruth[0];               // x
    StateVector[1] = Xtruth[1] - Xtruth[0];   // xdot
    StateVector[2] = Ytruth[0];               // y
    StateVector[3] = Ytruth[1] - Ytruth[0];   // ydot


    cout << "\n\nInitial State Vector" << endl;
    //out_ekf2d << "\n\nInitial State Vector" << endl;
    for(int i = 0; i < 4; i++)
    {
        cout << StateVector[i] << endl;
        //out_ekf2d << StateVector[i] << endl;
    }


    // initial covariance matrix
    for(int i = 0; i < 4; i++)
    {
            for(int j = 0; j < 4; j++)
            {
                    if(i == j)
                    {
                            if((i == 1) || (i == 3))
                            {
                                    CovarianceMatrix[i][j] = 1;
                            }
                            else
                            {
                                    CovarianceMatrix[i][j] = 5;
                            }
                    }
                    else
                    {
                            CovarianceMatrix[i][j] = 0;
                    }
            }
    }

    cout << "\n\nInitial Covariance Matrix" << endl;
    //out_ekf2d << "\n\nInitial Covariance Matrix" << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << CovarianceMatrix[i][j] << " ";
            //out_ekf2d << CovarianceMatrix[i][j] << " ";
        }

        cout << endl;
        //out_ekf2d << endl << endl;
    }
}




void Solver::EKF2Dsolver()
{

    double timeBetweenUpdates; // time between update k and k-1

    double previousStateVector[4];  // input state vector
    double predictedStateVector[4];  // pedicted state vector
    double currentStateVector[4];   // output state vector

    double previousCovarianceMatrix[4][4];   // input covariance matrix
    double predictedCovarianceMatrix[4][4];   // predicted covariance matrix
    double currentCovarianceMatrix[4][4];   // output covariance matrix

    double measuredRange;   // measured range to anchor node at update k
    double predictedRange;
    double anchorPos[2];   // contains x, y (and z coordinate in 3D) coordinates of the anchor/antenna
    // double zCoordinate;  // known z coordinate (height) of the mobile node

    double sigmaRange;   // standard deviation of the measured range
    double sigmaAcceleration;  // standard deviation of the acceleration

    double noiseMatrix[4][4];
    double stateTransitionMatrix[4][4];
    double stateTransitionMatrixTransposed[4][4];
    double measurementMatrix[4];
    double kalmanGain[4];

    int antenna;


    //in_ekf2d.open("testbenchEKF2D.txt");

    //out_ekf2d.open("resultsEKF2D.txt");


//    if (!in_ekf2d.is_open())
//    {
//        cout << "ekf2d: Input file failed to open, the program will now exit" << endl;
//        exit(1);
//    }

//    if (!out_ekf2d.is_open())
//    {
//        cout << "ekf2d: Output file failed to open, the program will now exit" << endl;
//        exit(1);
//    }


    simulate_data_ekf2d();

    get_initialConditions_ekf2d(previousStateVector, previousCovarianceMatrix);


    for(int iteration = 1; iteration < N; iteration++)
    {
        antenna = (iteration + 1) % 2;

        int valid = get_parameters_ekf2d(antenna, iteration, timeBetweenUpdates, sigmaAcceleration, anchorPos, measuredRange, sigmaRange);


        if(valid == 1)
        {
             cout << "Measured Range = " << measuredRange << endl;
             cout << "Iteration = " << iteration << endl
             << "Valid = " << valid << endl
             << "Anchor Position (x,y) = (" << anchorPos[0] << "," << anchorPos[1] << ")" << endl;


            // output the values you just read in
           // cout //<< "Time between updates = " << timeBetweenUpdates << endl
                 //<< "Standard deviation of the Acceleration = " << sigmaAcceleration << endl
                 //<< "Standard deviation of the Range = " << sigmaRange << endl
                // cout << "Measured Range = " << measuredRange << endl;
               // outFile << "Antenna = " << antenna << endl
//                 cout << "Iteration = " << iteration << endl
//                 << "Valid = " << valid << endl
//                 << "Anchor Position (x,y) = (" << anchorPos[0] << "," << anchorPos[1] << ")" << endl;


//            for(int i = 0; i < 4; i ++)
//            {
//                cout << previousStateVector[i] << " ";
//            }
//            cout << endl;


//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << previousCovarianceMatrix[i][j] << " ";
//                }

//                cout << endl;
//            }






            // prepare the noise marix with the standard deviation of the acceleration
            // this propagates the modelled variance
            double m = (timeBetweenUpdates * timeBetweenUpdates) * (sigmaAcceleration * sigmaAcceleration);

            // cout << "m = " << m << endl;

            noiseMatrix[0][0] = (timeBetweenUpdates*timeBetweenUpdates*m)/3;
            noiseMatrix[0][1] = (timeBetweenUpdates*m)/2;
            noiseMatrix[0][2] = 0;
            noiseMatrix[0][3] = 0;

            noiseMatrix[1][0] = (timeBetweenUpdates*m)/2;
            noiseMatrix[1][1] = 1*m;
            noiseMatrix[1][2] = 0;
            noiseMatrix[1][3] = 0;

            noiseMatrix[2][0] = 0;
            noiseMatrix[2][1] = 0;
            noiseMatrix[2][2] = (timeBetweenUpdates*timeBetweenUpdates*m)/3;
            noiseMatrix[2][3] = (timeBetweenUpdates*m)/2;

            noiseMatrix[3][0] = 0;
            noiseMatrix[3][1] = 0;
            noiseMatrix[3][2] = (timeBetweenUpdates*m)/2;
            noiseMatrix[3][3] = 1*m;




            // display the noise matrix
            cout << "Noise Matrix" << endl;
            for(int i = 0; i < 4; i ++)
            {
                for(int j = 0; j < 4; j++)
                {
                    cout << noiseMatrix[i][j] << " ";
                }

                cout << endl;
            }


            // from the state transition matrix
            // it is a typical linear state space model for the state
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(i == j)
                    {
                        stateTransitionMatrix[i][j] = 1;
                        stateTransitionMatrixTransposed[i][j] = 1;
                    }
                    else
                    {
                        stateTransitionMatrix[i][j] = 0;
                        stateTransitionMatrixTransposed[j][i] = 0;
                    }
                }
            }

                stateTransitionMatrix[0][1] = stateTransitionMatrix[2][3] = timeBetweenUpdates;
                stateTransitionMatrixTransposed[1][0] = stateTransitionMatrixTransposed[3][2] = timeBetweenUpdates;


//            // display the state transition matrix
//            cout << "State Transition Matrix" << endl;
//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << stateTransitionMatrix[i][j] << " ";
//                }

//                cout << endl;
//            }


//            // display the transposed state transition matrix
//            cout << "Transposed State Transition Matrix" << endl;
//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << stateTransitionMatrixTransposed[i][j] << " ";
//                }

//                cout << endl;
//            }


            // form the predicted state vector
            for(int i = 0; i < 4; i++)
            {
                double temp = 0;

                for(int j = 0; j < 4; j++)
                {
                     temp = temp + (stateTransitionMatrix[i][j] * previousStateVector[j]);
                }
                predictedStateVector[i] = temp;
            }

            // display predicted state vector
            cout << "predicted state vector" << endl;
            for(int i = 0; i < 4; i++)
            {
                cout << predictedStateVector[i] << " " << endl;
            }
            cout << endl;



            // form the predicted state covariance matrix
            int rows = 4;
            int cols = 4;

            double tempMatrix1[4][4];
            double tempMatrix2[4][4];


            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    tempMatrix1[i][j] = 0;

                    for(int k = 0; k < rows; k ++)
                    {
                        tempMatrix1[i][j] = tempMatrix1[i][j] + (stateTransitionMatrix[i][k] * previousCovarianceMatrix[k][j]);
                    }
                }
            }


//            // display the F*P(k-1) matrix
//            cout << "F*P(k-1) Matrix" << endl;
//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << tempMatrix1[i][j] << " ";
//                }

//                cout << endl;
//            }


            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    tempMatrix2[i][j] = 0;

                    for(int k = 0; k < rows; k ++)
                    {
                        tempMatrix2[i][j] = tempMatrix2[i][j] + (tempMatrix1[i][k] * stateTransitionMatrixTransposed[k][j]);
                    }
                }
            }


//            // display the F*P(k-1)*F(T) matrix
//            cout << "\nF*P(k-1)*F(T) Matrix" << endl;
//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << tempMatrix2[i][j] << " ";
//                }

//                cout << endl;
//            }


            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    predictedCovarianceMatrix[i][j] = tempMatrix2[i][j] + noiseMatrix[i][j];
                }
            }


            // display the predicted covariance matrix
            cout << "predicted covariance Matrix" << endl;
            for(int i = 0; i < 4; i ++)
            {
                for(int j = 0; j < 4; j++)
                {
                    cout << predictedCovarianceMatrix[i][j] << " ";
                }

                cout << endl;
            }



            // prepare predicted range measurement
            double xValue;
            double yValue;
            //double zValue;

            xValue = predictedStateVector[0] - anchorPos[0];
            yValue = predictedStateVector[2] - anchorPos[1];
            //zValue = zCoordinate - anchorPos[2];

            predictedRange = sqrt((xValue * xValue) + (yValue * yValue)); // + (zValue * zValue));

            //cout << "predicted range = " << predictedRange << endl;


            // prepare measurement marix
            measurementMatrix[0] = xValue/predictedRange;
            measurementMatrix[1] = 0;
            measurementMatrix[2] = yValue/predictedRange;
            measurementMatrix[3] = 0;


            // display the measurement matrix
            cout << "measurement matrix" << endl;
            for(int i = 0; i < 4; i++)
            {
                cout << measurementMatrix[i] << " " << endl;
            }
            cout << endl;


            // prepare the Kalman Gain
            double numerator[4];

            for(int i = 0; i < 4; i++)
            {
                double temp = 0;

                for(int j = 0; j < 4; j++)
                {
                     temp = temp + (predictedCovarianceMatrix[i][j] * measurementMatrix[j]);
                }
                numerator[i] = temp;
            }


//            cout << "numerator matrix" << endl;
//            for(int i = 0; i < 4; i++)
//            {
//                cout << numerator[i] << " " << endl;
//            }
//            cout << endl;



            double den = 0;
            for (int i = 0; i < 4; i++)
            {
                den = den + (measurementMatrix[i] *  numerator[i]);
            }

                //cout << "denominator = " << den << endl;


            double denominator = den + sigmaRange*sigmaRange;

                //cout << "denominator + sigmaRange^2 = " << denominator << endl;



            for (int i = 0; i < 4; i++)
            {
                kalmanGain[i] = numerator[i]/denominator;
            }


            // display the kalman gain
            cout << "kalman gain vector" << endl;
            for(int i = 0; i < 4; i++)
            {
                cout << kalmanGain[i] << " " << endl;
            }
            cout << endl;



            // calculate the updated state vector
            double innovation = measuredRange - predictedRange;
            cout << "innovation = " << innovation << endl;

            for (int i = 0; i < 4; i++)
            {
                currentStateVector[i] = predictedStateVector[i] + (kalmanGain[i] * innovation);
            }


            // display the current/updated state vector
            cout << "\n\nupdated state vector" << endl;
            //outFile << "\n\nUpdated state vector - iteration: " << iteration << endl;
            for(int i = 0; i < 4; i++)
            {
                cout << setw(10) << left << currentStateVector[i] << endl;
                //outFile << setw(10) << left << currentStateVector[i] << endl;
            }

            //out_ekf2d << setw(10) << left << currentStateVector[0] << ", " << currentStateVector[2] << endl;










            // calculate the updated covariance matrix

            // create an identity matrix
            double identityMatrix[4][4];
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(i == j)
                    {
                        identityMatrix[i][j] = 1;
                    }
                    else
                    {
                        identityMatrix[i][j] = 0;
                    }
                }
            }

//            // display the identity matrix
//            cout << "identity Matrix" << endl;
//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << identityMatrix[i][j] << " ";
//                }

//                cout << endl;
//            }




        // create the matrix KH
            double KH[4][4];
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    KH[i][j] = kalmanGain[i] * measurementMatrix[j];
                }
            }


//            // display the KH matrix
//            cout << "KH Matrix" << endl;
//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << KH[i][j] << " ";
//                }

//                cout << endl;
//            }



            // form the matrix I - KH
            double temp[4][4];
            for(int i = 0; i < 4; i ++)
            {
                for(int j = 0; j < 4; j++)
                {
                    temp[i][j] = identityMatrix[i][j] - KH[i][j];
                }

            }


//            // display the I-KH matrix
//            cout << "I-KH Matrix" << endl;
//            for(int i = 0; i < 4; i ++)
//            {
//                for(int j = 0; j < 4; j++)
//                {
//                    cout << temp[i][j] << " ";
//                }

//                cout << endl;
//            }



            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    currentCovarianceMatrix[i][j] = 0;

                    for(int k = 0; k < rows; k ++)
                    {
                        currentCovarianceMatrix[i][j] = currentCovarianceMatrix[i][j] + (temp[i][k] * predictedCovarianceMatrix[k][j]);
                    }
                }
            }



            // display the updated covariance matrix
            cout << "\n\n updated covariance Matrix" << endl;
            //outFile << "\n\nUpdated covariance matrix - iteration: " << iteration << endl;
            for(int i = 0; i < 4; i ++)
            {
                for(int j = 0; j < 4; j++)
                {
                    cout << setw(10) << left << currentCovarianceMatrix[i][j] << " ";
                    //outFile << setw(10) << left << currentCovarianceMatrix[i][j] << " ";
                }

                cout << endl;
                //outFile << endl;
            }








            for(int i = 0; i < 4; i ++)
            {
                previousStateVector[i] = currentStateVector[i];
            }


            for(int i = 0; i < 4; i ++)
            {
                for(int j = 0; j < 4; j++)
                {
                    previousCovarianceMatrix[i][j] = currentCovarianceMatrix[i][j];
                }
            }
        }

        //outFile << "end of if: " << iteration << endl;
    }

    //outFile << "end of for" << endl;
}




// EKF3D methods
int Solver::get_parameters_ekf3d() //int antenna, int iteration, double& time, double& sigmaAcceleration, double anchorPos[], double& measuredRange, double& sigmaRange)
{
    return 1;
}

void Solver::get_initialConditions_ekf3d() //double initialStateVector[], double initialCovarianceMatrix[][4])
{

}

void Solver::simulate_data_ekf3d()
{

}

void Solver::EKF3Dsolver()
{

}























