#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"kalmanStepRedux.h"
#include"kalmanStepRedux_initialize.h"
#include"kalmanStepRedux_terminate.h"

using namespace std;



int main()
{
// True angluar rate; not needed for filter, but useful for testing
double w_true[3] = { };

//Input variables
double B_hat_in[3]={0,0,0};
double q_hat_in[4]={0,.7071,0,0.7071};
double B_in[3] = { };
double P_holder[36] = { }; 
double *P_in = P_holder;
double B_meas_in[3] = {9, 6, 18};
double w_meas[3] = {.1,.2,.3};
double q_meas_in[4] = { };
double rr_meas_in[3] = { };

//Output variables
double B_hat_out[3] = { };
double q_hat_out[4] = { };
double P_out[36] = { };
double sig3_out[6] = { };
double w_hat[3] = { };

//Euler angles; needed for function (for now) and useful for testing, but not needed on flight version
double theta = 0;
double *theta_hat_out = &theta;
double psi = 0;
double *psi_hat_out = &psi;
double phi = 0;
double *phi_hat_out = &phi;
double track = 1.0;
double *trackerAvail = &track;

//Initialization of string variables to use standard in; not needed if you have a better method (please have a better method)
string time; string gyrox; string gyroy; string gyroz; string magx; string magy; string magz; string thetaTrue; string phiTrue; string psiTrue;
string wtrue1; string wtrue2; string wtrue3; string igrf1; string igrf2; string igrf3; string rrmeas1; string rrmeas2; string rrmeas3; string qmeas1; string qmeas2; string qmeas3; string qmeas4;
string track_in;

string::size_type sz;

while(1)
{
	//Get input from the standard output of the python serial parser
	// Order: true euler angles, true angular rate, reference magnetic field, body magnetic field, gyro readings, star tracker reference measurement, star tracker quaternion measurement, star tracker availability, time

  cin >> thetaTrue >> psiTrue >> phiTrue >> wtrue1 >> wtrue2 >> wtrue3 >> igrf1 >> igrf2 >> igrf3 >> magx >> magy >> magz >> gyrox >> gyroy >> gyroz >> rrmeas1 >> rrmeas2 >> rrmeas3 >> qmeas1 >> qmeas2 >> qmeas3 >> qmeas4 >> track_in >> time;

	// Copy input data into the matricies to be fed to the filter
	w_true[0] = stod(wtrue1); w_true[1] = stod(wtrue2); w_true[2] = stod(wtrue3);
	B_in[0] = stod(igrf1); B_in[1] = stod(igrf2); B_in[2] = stod(igrf3);
	B_meas_in[0] = stod(magx); B_meas_in[1] = stod(magy); B_meas_in[2] = stod(magz);
	w_meas[0] = stod(gyrox); w_meas[1] = stod(gyroy); w_meas[2] = stod(gyroz);
	rr_meas_in[0] = stod(rrmeas1); rr_meas_in[1] = stod(rrmeas2); rr_meas_in[2] = stod(rrmeas3);
	q_meas_in[0] = stod(qmeas1); q_meas_in[1] = stod(qmeas2); q_meas_in[2] = stod(qmeas3); q_meas_in[3] = stod(qmeas4);
	
	// am I even doing this right
	*trackerAvail = stod(track_in);

	//cout << "Initialzing K_step" << endl;
	kalmanStepRedux_initialize();
	//cout << "Running K_step" << endl;
	kalmanStepRedux(B_in,B_meas_in,rr_meas_in,q_meas_in,track,w_meas,q_hat_in,P_in, B_hat_in,q_hat_out, w_hat,&theta, &psi, &phi, sig3_out,B_hat_out,P_out);

	//Output the processed values
	// cout << time << endl;
	// cout << theta << endl;
	// cout << phi << endl;
	// cout << psi << endl;
	// cout << thetaTrue << endl;
	// cout << phiTrue << endl;
	// cout << psiTrue << endl;
	// cout << flush;
	
	//Printing to std out; this would be replaced by a more real method of inter-program communication
	cout << time << ',' << theta << ',' << thetaTrue << ',' << phi << ',' << phiTrue << ',' << psi << ',' << psiTrue << ',' << endl;
	cout << flush;

	//Reset the variables to prep for the next iteration
	B_hat_in[0] = B_hat_out[0];
	B_hat_in[1] = B_hat_out[1];
	B_hat_in[2] = B_hat_out[2];
	q_hat_in[0] = q_hat_out[0];
	q_hat_in[1] = q_hat_out[1];
	q_hat_in[2] = q_hat_out[2];
	q_hat_in[3] = q_hat_out[3];
	for(int i = 0; i <= 35; i++)
		{
		P_holder[i] = P_out[i];
		}
	//I think I have to run this but I'm not sure and too afraid to not
	kalmanStepRedux_terminate();

}
}
