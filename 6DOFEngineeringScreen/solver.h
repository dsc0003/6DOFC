#ifndef SOLVER_H
#define SOLVER_H
#define Num 100


class Solver{


public:

    Solver();
    virtual ~Solver();


    // parameters for GEOM 2D, NLLS 2D and 3D solvers
    float x1, y1, z1;  // center of first circle (set z to default if using 2D version)
    float x2, y2, z2;  // center of second circle (set z to default if using 2D version)
    float x3, y3, z3;  // center of third circle
    float r1, r2, r3;  // radius of first, second and third circle respectively (set r3 to default if using the 2D version)
    float xg, yg, zg;  // seed value (set zg to default if using the 2D version)
    float px, py, pz;  // intersection point closest to the seed value
    int maxI;
    float eps;
    int valid;

public:
    int find_intersection_points_nlls3d(float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2,
                                 float x3, float y3, float z3, float r3, float xg, float yg, float zg,
                                 float& px, float& py, float& pz);







};

// function prototypes here




#endif // SOLVER_H
