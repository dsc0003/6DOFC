//#include <QtCore/QCoreApplication>
#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>

using namespace std;


//void get_parameters(float* x0, float* y0, float* x1, float* y1, float* r0, float* r1, float* seedx, float* seedy);
int find_intersection_points(int x0, int y0, int x1, int y1, int r0, int r1, int seedx, int seedy, int* px, int* py);

//ifstream inFile;
//ofstream outFile;

//int main(int argc, char *argv[])
//{
//    //QCoreApplication a(argc, argv);

//    // function [x,y,valid] = SolverGeom2D( x0, y0, x1, y1, r0, r1, seedx, seedy )
//    // Uses intersection of circles technique to determine 2D position.
//    // Since there are almost always two valid solutions, the solution closest
//    // to the seed will be returned.
//    //
//    // Inputs:
//    // (x0,y0) coordinates of anchor 0
//    // (x1,y1) coordinates of anchor 1
//    // r0 and r1: distance (range) from anchor0 and anchor1 to mobile, respectively
//    //
//    // Outputs:
//    // (x,y) the location of the mobile (intersection of the two circles closest to the seed)
//    // valid = 1 unless the circles don't intersect (ranges too short, or one
//    // circle is totally inside the other
//    //
//    // Note: consult this website to explain the math:
//    // http://local.wasp.uwa.edu.au/~pbourke/geometry/2circle/
//    //
//    // 2010 Brandon Dewberry, Time Domain
//    // BeerRight: Feel free to use without restriction but if this comes in handy and we ever meet you owe me a beer.
//    // Also if you find a bug or make it better please let me know (brandon.dewberry@timedomain.com)
//    //

//    int valid;  // 1 when the result is valid, 0 otherwise
//    float x0, y0;  // center of the first circle
//    float x1, y1;  // center of the second circle
//    float r0, r1;  // radius of first and second circle respectively
//    float seedx, seedy;  // seed value, return the intersectio point closest to the seed point
//    float px, py;  // intersection point



//    inFile.open("testbenchGEOM2D.txt");
//    outFile.open("resultsGEOM2D.txt", ios::app);

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


//    get_parameters(&x0, &y0, &x1, &y1, &r0, &r1, &seedx, &seedy);

//    while(inFile)
//    {
//        valid = find_intersection_points(x0, y0, x1, y1, r0, r1, seedx, seedy, &px, &py);

//        cout << "valid = " << valid << endl << "px = " << px << endl << "py = " << py << endl << endl;
//        outFile << "valid = " << valid << endl << "px = " << px << endl << "py = " << py << endl << endl;

//        get_parameters(&x0, &y0, &x1, &y1, &r0, &r1, &seedx, &seedy);

//    }



//    inFile.close();
//    outFile.close();

//    //return a.exec();

//}


//void get_parameters(float* x0, float* y0, float* x1, float* y1, float* r0, float* r1, float* seedx, float* seedy)
//{

////    cout << "Please enter the cordinates of the first circle: x0 y0 " << endl;
////    cin >> *x0 >> *y0;

////    cout << "Please enter the radius of the first circle: r0 " << endl;
////    cin >> *r0;

////    cout << "Please enter the cordinates of the second circle: x1 y1 " << endl;
////    cin >> *x1 >> *y1;

////    cout << "Please enter the radius of the second circle: r1 " << endl;
////    cin >> *r1;

////    cout << "Please enter the cordinates of the seed point: seedx seedy " << endl;
////    cin >> *seedx >> *seedy;


////    inFile >> *x0 >> *y0;
////    inFile >> *r0;
////    inFile >> *x1 >> *y1;
////    inFile >> *r1;
////    inFile >> *seedx >> *seedy;


//}




int find_intersection_points(int x0, int y0, int x1, int y1, int r0, int r1, int seedx, int seedy, int *px, int *py)
{


    //         1. Determine the distance, "dist", between the two centers by taking the square root of the difference
    //            of the x coordinates squared plus the difference of the y coordinates squared. For example,
    //            if circle 1 is centered at (x1, y1) = (4, 6) and circle 2 is centered at (x2, y2) = (1, 2),
    //            the distance between the centers is sqrt[(x1 - x2)^2 + (y1 - y2)^2] = sqrt[(4 - 1)^2 + (6 - 2)^2] = sqrt(9 + 16) = 5.

    //         2. Add the radii of the two circles and if that sum (r0 + r1) is less than dist, the circles are too far
    //            apart to intersect. Take the absolute value of the difference of the circles radii, |r0 - r1|, and
    //            if that is greater than dist, the one circle is completely contained in the other and they do not intersect.
    //            If dist is 0 and the two radii are equal, the circles are the same and intersect at infinitely many points.
    //            If none of these is the case, proceed to Step 3 because the circles intersect at one or two points.

    //         3. Determine the distance "a" of the midpoint of the two intersections from the center of the first circle
    //            with the formula: a = (r0^2 - r1^2 + dist^2) / (2dist), where r0 is the radius of the first circle, and r1 is
    //            the radius of the second circle. For example, with r0 = 3 and r1 = 4, then a = (3^2 - 4^2 + 5^2) / (2 * 5) = (9 - 16 + 25) / 10 = 1.8.

    //         4. Find the midpoint of the two intersections "P" with the formula: P = c0 + a * (c1 - c0) / d, where c0 is the
    //            center of the first circle and c1 is the center of the second circle. For example, with circle 1 centered at (4, 6)
    //            and circle 2 centered at (1, 2), then P = (4, 6) + 1.8 * (1 - 4, 2 - 6) / 5 = (4, 6) - 1.8 * (3, 4) / 5 = (2.92, 4.56).

    //         5. Solve for the distance of the two intersections from the point P by taking the square root of the difference of
    //            the r0 squared and a squared: h = sqrt(r0^2 - a^2). For the running example, h = sqrt(3^2 - 1.8^2) = sqrt(5.76) = 2.4.

    //         6. Find the first intersection point at (xa, ya) with the formulas (xa = Px + h (c1y - c0y) / dist) and
    //            (ya = Py - h (c1x - c0x) / dist) where c1x is the x coordinate of the second circle's center, and c0x is
    //            the x coordinate of the first circle's center. For the running example, this yields x1 = 2.92 + 2.4 * (2 - 6) / 5 = 1
    //            and y1 = 4.56 - 2.4 * (1 - 4) / 5 = 6.

    //         7. Find the second intersection point (xb, yb) with the formulas (xb = Px - h (c1y - c0y) / dist) and (yb = Py + h (c1x - c0x) / dist).
    //            For the running example, x2 = 2.92 - 2.4 (2 - 6) / 5 = 4.84 and y2 = 4.56 + 2.4 * (1 - 4) / 5 = 3.12.



    float xdiff, ydiff;  // (x1-x0), (y1-y0)
    float xdiff2, ydiff2;  // (x1-x0)^2, (y1-y0)^2
    float dist;  // distance between the centers of the circles
    int valid;  // return value
    float a; // distance from the center of the first circle to the line joining the points of intersection at point p0
    float x2, y2; // midpoint of the two intersection points, point p0
    float h; // distance from point p0 to each intersection point
    float xa, ya;  // first intersection point
    float xb, yb;  // second intersection point
    float dist_seed_to_Pa_squared;  // distance from seed point to the first intesection point
    float dist_seed_to_Pb_squared;  // distance from seed point to the second inersection point





    /* step 1 */

    // distance between center coordinates
    xdiff = x1 - x0;
    ydiff = y1 - y0;

    cout << "xdiff = " << xdiff << endl << "ydiff = " << ydiff << endl;
   // outFile << "xdiff = " << xdiff << endl << "ydiff = " << ydiff << endl;

    // square the differences
    xdiff2 = xdiff * xdiff;
    ydiff2 = ydiff * ydiff;

    // distance between centers
    dist = sqrt( xdiff2 + ydiff2 );

    cout << "dist = " << dist << endl;
    //outFile << "dist = " << dist << endl;


    /* step 2 */

    // If the radii are too short for the circles to intercept then
    // find the point half way between the circle/baseline intersections
    if ((r0 + r1) < dist) // circles do not intersect
    {
        cout << "the circles do not intersect because the radii are too short" << endl;
        //outFile << "the circles do not intersect because the radii are too short" << endl;
        valid = 0;
        return valid;
    }

    // If r1 circle encompasses the r2 circle, one circle is completely inside the other
    else if ((abs(r1-r0)) > dist)
    {
        cout << "the circles do not intersect because one circle is completely inside the other" << endl;
        //outFile << "the circles do not intersect because one circle is completely inside the other" << endl;
        valid = 0;
        return valid;
    }

    // If dist = 0 and the radii are the same, the circles completely overlap each other
    else if((r0 == r1) && (dist == 0))
    {
        cout << "the circles do not intersect because they overlap completely" << endl;
        //outFile << "the circles do not intersect because they overlap completely" << endl;
        valid = 0;
        return valid;
    }
    else
    {


        /* step 3 */

        // distance from x0 to line joining points of intersection
        // distance "a" of the midpoint of the two intersections from the center of the first circle
        a = ((dist*dist) + (r0*r0) - (r1*r1) )/( 2*dist );
        cout << "a = " << a << endl;
        //outFile << "a = " << a << endl;




        /* step 4 */

        // Find the midpoint of the two intersections "P"
        // point on center line perpendicular to target point
        // P = c0 + a * (c1 - c0) / dist
        // where c0 is the center of the first circle and c1 is the center of the second circle.
        x2 = x0 + xdiff*a/dist;
        y2 = y0 + ydiff*a/dist;

        cout << "x2 = " << x2 << endl << "y2 = " << y2 << endl;
        //outFile << "x2 = " << x2 << endl << "y2 = " << y2 << endl;




        /* step 5 */
        // Solve for the distance of the two intersections from the point P by taking the
        // square root of the difference of the r0 squared and a squared: h = sqrt(r0^2 - a^2)
        // a^2 + b^2 = c^2 - sides of a triangle
        // height of perpendicular line

        // if r0 == a the circles intersect at only one point, return that intersection point but set valid to zero
        if (r0 <= a) // guard against neg sqrt
        {
            *px = x2;
            *py = y2;
            h = 0;
            cout << "the circles intersect at only one point" << endl;
            //outFile << "the circles intersect at only one point" << endl;
            valid = 0;
            return valid;
        }
        else
        {
            h = sqrt((r0*r0) - (a*a));
        }

        cout << "h = " << h << endl;
        //outFile << "h = " << h << endl;


        /* step 6 */
        // Find the first intersection point at (x1, y1) with the formulas (x1 = Px + h (c1y - c0y) / d)
        // and (y1 = Py - h (c1x - c0x) / d) where c1x is the x coordinate of the second circle's center,
        // and c0x is the x coordinate of the first circle's center.
        // Find solution
        xa = x2 + h*ydiff/dist;
        ya = y2 - h*xdiff/dist;

        cout << "xa = " << xa << endl << "ya = " << ya << endl;
        //outFile << "xa = " << xa << endl << "ya = " << ya << endl;


        /* step 7 */
        // Find the second intersection point (x2, y2) with the formulas (x2 = Px - h (c1y - c0y) / d) and (y2 = Py + h (c1x - c0x) / d).
        // Find alternate solution
        xb = x2 - h*(y1-y0)/dist;
        yb = y2 + h*(x1-x0)/dist;

        cout << "xb = " << xb << endl << "yb = " << yb << endl;
        //outFile << "xb = " << xb << endl << "yb = " << yb << endl;

        // Pick the choice closest to the seed
        dist_seed_to_Pa_squared = ((xa-seedx)*(xa-seedx)) + ((ya-seedy)*(ya-seedy));
        dist_seed_to_Pb_squared = ((xb-seedx)*(xb-seedx)) + ((yb-seedy)*(yb-seedy));

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



