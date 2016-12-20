#define EPSILON 0.0000001

bool invalidInput = false;

class Solution {
public:
	bool equals(double num1, double num2){
		return ((num1 - num2) < EPSILON && (num1 - num2) > -EPSILON);
	}

	double powerWithPositiveExponent(double base, int absExponent){
		if(absExponent == 0){
			return 1.0;
		}

		if(absExponent == 1){
			return base;
		}

		double res = powerWithPositiveExponent(base, absExponent/2);
		res *= res;

		if(absExponent % 2){
			res *= base;
		}

		return res;
	}

    double Power(double base, int exponent) {
    	invalidInput = false;
    	
    	if(equals(base, 0.0) && exponent < 0){
    		invalidInput = true;
    		return 0.0;
    	}

    	int absExponent = exponent;
    	if(exponent<0){
    		absExponent = -exponent;
    	}

    	double res = powerWithPositiveExponent(base, absExponent);

    	if(exponent<0){
    		res = 1.0/res;
    	}

    	return res;
    }
};