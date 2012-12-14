
// https://www.ualberta.ca/dept/chemeng/courses/che374/notes/U03_nonlin/374_nonlinear_b_4up.pdf

#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>

using namespace std;


void get_parameters(float* x1, float* y1, float* r1, float* x2, float* y2, float* r2, float* xg, float* yg);
int find_intersection_points(float x1, float y1, float r1, float x2, float y2, float r2, float xg, float yg, float& px, float& py, int maxI, float e);

ifstream inFile;
ofstream outFile;

//int main(int argc, char *argv[])
//{


//    int valid;  // 1 when the result is valid, 0 otherwise
//    float x1, y1;  // center of the first circle
//    float x2, y2;  // center of the second circle
//    float r1, r2;  // radius of first and second circle respectively
//    float xg, yg;  // seed value, return the intersectio point closest to the seed point
//    float px, py;  // intersection point
//    int maxI;
//    float e;



//    inFile.open("testbenchNLLS2D.txt");
//    outFile.open("resultsNLLS2D.txt", ios::app);

//    if (!inFile.is_open())
//    {
//        cout << "Input file failed to open, the program will now exit" << endl;
//        exit(1);
//    }

//    if (!outFile.is_open())
//    {
//        cout << "Output file failed to open, the program will now exit" << endl;
//        exit(1);
//    }


//    //get_parameters(&x1, &y1, &r1, &x2, &y2, &r2, &xg, &yg);

////    //cout << "x1 = " << x1 << " y1 = " << y1 << " r1 = " << r1
////         << " x2 = " << x2 << " y2 = " << y2 << " r2 = " << r2
////         << " xg = " << xg << " yg = " << yg << endl;


//    //r1 = r2 = sqrt(5);

//    maxI = 15;
//    e = 0.01;

//    while(inFile)
//    {
//        valid = find_intersection_points(x1, y1, r1, x2, y2, r2, xg, yg, px, py, maxI, e);

//        if (valid == 1)
//        {
//            cout << "valid = " << valid << endl << "px = " << px << endl << "py = " << py << "\n\n\n\n" << endl << endl;
//            outFile << "valid = " << valid << endl << "px = " << px << endl << "py = " << py << "\n\n\n\n" << endl << endl;

//            get_parameters(&x1, &y1, &r1, &x2, &y2, &r2, &xg, &yg);
//            cout << "x1 = " << x1 << " y1 = " << y1 << " r1 = " << r1
//                 << " x2 = " << x2 << " y2 = " << y2 << " r2 = " << r2
//                 << " xg = " << xg << " yg = " << yg << endl;

//        }
//        else
//        {
//            cout << "Error: valid = 0, the program will now exit" << endl;
//            exit(1);
//        }
//    }



//    inFile.close();
//    outFile.close();


//}

void get_parameters(float* x1, float* y1, float* r1, float* x2, float* y2, float* r2, float* xg, float* yg)
{
    inFile >> *x1 >> *y1 >> *r1;
    inFile >> *x2 >> *y2 >> *r2;
    inFile >> *xg >> *yg;
}




int find_intersection_points(float x1, float y1, float r1, float x2, float y2, float r2, float xg, float yg, float& px, float& py, int maxI, float e)
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




    for(int n = 1; n <= maxI; n++)
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
    return valid;
}

