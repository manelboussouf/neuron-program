#include "Neuron.hpp"
#include "Neuron.cpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

int main ()
{
	Neuron neuron;
	const double v_threshold_= 20.0;
	const double v_reset_ = 10.0;
	const int c_ = 1; 
	const double t_rp_= 2.0; 
	const double step_time_=0.1; 
	double iext_;
	double t_start_;
	double t_stop_;
	
	
	cout << "Specify an external current:" << endl;
	cin >> iext_;
	do{
	cout << "Specify a time positive interval:" << endl;
	cout << "starting time:" << endl;
	cin >> t_start_;
	cout << "Ending time:" << endl;
	cin >> t_stop_;
	} while ( (t_start_ < 0.0) or (t_stop_ <= 0.0));
	double time_(t_start_);

	ofstream neuron_values;
	neuron_values.open("neurones.odt");
	if(neuron_values.fail())
	{throw runtime_error("The file hasn't been opened correctly");}
	
	do {
		neuron.update_neuron(time_, step_time_, v_reset_, t_rp_, v_threshold_, iext_,c_);
	} while (time_ <= t_stop_);
	//cout << "ouf" << endl;
	
	vector<double> tab(neuron.get_time_spikes());
	for (size_t i(0); i < tab.size(); ++i) {
		neuron_values << tab[i] << " " ;
		
	}	
	neuron_values.close();
	return 0;
}

