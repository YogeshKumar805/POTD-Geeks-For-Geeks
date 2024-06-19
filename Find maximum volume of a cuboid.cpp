class Solution {
  public:
    double maxVolume(double perimeter, double area) {
      
        double P = perimeter;
        double A = area;
        double sqrtTerm = sqrt(P * P - 24 * A);
        double dimension1 = (P - sqrtTerm) / 12.0;
        double dimension2 = (P / 4.0) - 2 * dimension1;
        
        double volume = pow(dimension1, 2) * dimension2;
        
        return round(volume * 100.0) / 100.0;
    }
};

