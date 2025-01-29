class Solution {
  public:
    double power(double b, int e) {
         double result = 1.0;
    bool isNegativeExponent = false;

    // Handle negative exponents
    if (e < 0) {
        isNegativeExponent = true;
        e = -e; // Make the exponent positive
    }

    // Exponentiation by squaring
    while (e > 0) {
        if (e % 2 == 1) { // If e is odd
            result *= b;
        }
        b *= b; // Square the base
        e /= 2; // Halve the exponent
    }

    // If the exponent was negative, take the reciprocal
    if (isNegativeExponent) {
        result = 1.0 / result;
    }

    return result;
    }
};

