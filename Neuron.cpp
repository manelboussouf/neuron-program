#include "Neuron.hpp"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

Neuron::Neuron (double mb_p, int nb_s, double to)
	: mb_potential(mb_p), nb_spikes(nb_s), tau(to) { }
	
double Neuron::get_mb_potential(){return mb_potential;}
int Neuron::get_nb_spikes(int n){ 
	n = time_spikes.size();
	nb_spikes =n; 
	return nb_spikes;}
double Neuron::get_tau(){return tau;}
vector <double> Neuron::get_time_spikes(){return time_spikes;}
void Neuron::update_neuron(double& time, double h, double v_r, double t_rp, double v_threshold, double Iext, double c)
{
	if (mb_potential < v_threshold)
	{
		mb_potential = exp(-h/tau)*mb_potential + Iext*(tau/c)*(1-exp(-h/tau));
		time = time + h;
		
			
	}
	else {
		time_spikes.push_back(time);
		cout << time_spikes.back() << endl;
		do
		{mb_potential = v_r;
			time += h;
		}while(time < time_spikes.back() + t_rp);
			
		
	 }
	
		cout << time << endl;
			cout << mb_potential << endl;	
		}
	
		
	

