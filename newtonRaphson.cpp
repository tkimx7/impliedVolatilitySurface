#include<bits/stdc++.h>

using namespace std;

class impliedVol {

	int len; 
	int lim;
	double c;
	double x;
	double tol;
	
	vector<double> p;
	
	public:
	
		void setP() { // Set polynomial coefficients, degree n to 1
			
			cout << "Set vector length: " << endl;
			cin >> len;
			
			for (int i = 1; i <= len; i++) {
				
				cout << "Set " << i << "th element: " << endl;
				cin >> c;
				
				p.push_back(c);
			}
		}		
		void setInputs() { // Set inputs
			
			cout << "Set x for f(x): " << endl;
			cin >> x;
			
			cout << "Set tol for abs(x1-x0) < tol: " << endl;
			cin >> tol;

			cout << "Set lim for iteration limit: " << endl;
			cin >> lim;
		}
		
		double f(double x) { // Horner's Rule to evaluate polynomial
			
			double y = p[0];
			
			for (int i = 1; i <= p.size(); i++) {
				
				y = y * x + p[i];
			}
			return y;
		}
		
		double fd(double x, double h = 0.005) { // Numerical differentiation
				
			double yd;
					
			yd = (f(x + h) - f(x - h))/(2 * h);
			
			return yd;
		}
		
		double newtonRaphson() {
			
			double x0 = x;
			double x1;
			
			int i = 1;

			while (i < lim) {

				x1 = x0 - f(x0)/fd(x0);
				
				cout << x1 << endl;
				
				if (abs(x1 - x0) <= tol) { 
				
					return(x1);
				}
				x0 = x1;
			}
			return(9999);
		}
};

int main() {
	
	impliedVol* iv = new impliedVol();
	
	iv->setP();
	iv->setInputs();
	iv->newtonRaphson();
	
	delete iv;
}
