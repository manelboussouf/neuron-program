#ifndef NEURON_H
#define NEURON_H
#include <vector>

class Neuron
{
	private:
		double mb_potential;
		std::vector<double> time_spikes;
		int nb_spikes;
		double tau;
		
	public:
		Neuron(double mb_p = 10.0, int nb_s = 0.0, double to = 20.0 );
		double get_mb_potential();
		int get_nb_spikes(int n);
		double get_tau();
		std::vector <double> get_time_spikes();
		void update_neuron(double& time, double h, double v_r, double t_rp, double v_threshold, double Iext, double c);
		
};

#endif
