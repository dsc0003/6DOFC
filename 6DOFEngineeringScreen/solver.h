#ifndef SOLVER_H
#define SOLVER_H
#define N 100


class Solver{


public:


    // parameters for GEOM 2D, NLLS 2D and 3D solvers
    float x1, y1, z1;  // center of first circle (set z to default if using 2D version)
    float x2, y2, z2;  // center of second circle (set z to default if using 2D version)
    float x3, y3, z3;  // center of third circle
    float r1, r2, r3;  // radius of first, second and third circle respectively (set r3 to default if using the 2D version)
    float xg, yg, zg;  // seed value (set zg to default if using the 2D version)
    float px, py, pz;  // intersection point closest to the seed value
    int maxI;
    float e;
    int valid;


    // parameters for the EKF 2D solver
    // anchor/antenna positions
    double a1;
    double b1;
    double a2;
    double b2;

    // simulation parameters
    //const int N;  // maximum number of points we are going to use
    int T[N];  // array of times that we recieve the ranges
    double Xtruth[N];   // true trajectory in x direction
    double Ytruth[N];   // true trajectory in y direction
    double Rtruth1[N];  // true ranges from antenna 1
    double Rtruth2[N];  // true ranges from antenna 2
    double Rnoise1[N];  // noise added to the true ranges
    double Rnoise2[N];  // noise added to the true ranges

    // filter parameters
    double Rmeasured1[N];  // measured ranges from antenna 1
    double Rmeasured2[N];  // measured ranges from antenna 2
    double KalmanGain[N];  // kalman gain value calculated at each iteration
    double StateVector[4]; // initial state vector
    double CovarianceMatrix[4][4];  // initial covariance matrix
    double refLoc[2];  // anchor tag - tell you which antenna the reading came from
    int dT; // time interval between two consecutive range measurements
    double sigma_r;  // standard deviation of the range
    double sigma_a;  // standard deviation of the acceleration
    int status;  // status bit to let us know if we got valid readings or if something went wrong




    // all class methods here


    // NLLS2D methods
    void get_parameters_nlls2d(float* x1, float* y1, float* r1, float* x2, float* y2, float* r2, float* xg, float* yg);
    int find_intersection_points_nlls2d(float x1, float y1, float r1, float x2, float y2, float r2, float xg, float yg,
                                 float& px, float& py, int maxI, float e);




    // NLLS3D methods
    void get_parameters_nlls3d(float* x1, float* y1, float* z1, float* r1, float* x2, float* y2, float* z2, float* r2,
                        float* x3, float* y3, float* z3, float* r3, float* xg, float* yg, float* zg);


    int find_intersection_points_nlls3d(float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2,
                                 float x3, float y3, float z3, float r3, float xg, float yg, float zg,
                                 float& px, float& py, float& pz, int maxI, float ex);




    // GEOM2D methods
    void get_parameters_geom2d(float* x0, float* y0, float* x1, float* y1, float* r0, float* r1, float* seedx, float* seedy);
    int find_intersection_points_geom2d(float x0, float y0, float x1, float y1, float r0, float r1, float seedx, float seedy, float* px, float* py);




    // EKF2D methods
    int get_parameters_ekf2d(int antenna, int iteration, double& time, double& sigmaAcceleration, double anchorPos[], double& measuredRange, double& sigmaRange);
    void get_initialConditions_ekf2d(double initialStateVector[], double initialCovarianceMatrix[][4]);
    void simulate_data_ekf2d();
    void EKF2Dsolver();





    // EKF3D methods  - comment to avoid compiler warnings
    int get_parameters_ekf3d(); //int antenna, int iteration, double& time, double& sigmaAcceleration, double anchorPos[], double& measuredRange, double& sigmaRange);
    void get_initialConditions_ekf3d(); //double initialStateVector[], double initialCovarianceMatrix[][4]);
    void simulate_data_ekf3d();
    void EKF3Dsolver();





};

// function prototypes here




#endif // SOLVER_H
