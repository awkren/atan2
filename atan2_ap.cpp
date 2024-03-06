#include <cmath>

float atan2_ap(float y, float x) {
  const float PI = 3.1415926535897932384626433832795;
  float coeff_1 = PI / 4.0;
  float coeff_2 = 3.0 * coeff_1;
  float abs_y = std::fabs(y) + 1e-10; // prevents division by 0
  float angle;
  if (x >= 0.0) {
    float r = (x - abs_y) / (x + abs_y);
    angle = coeff_1 - coeff_1 * r;
  } else {
    float r = (x + abs_y) / (abs_y - x);
    angle = coeff_2 - coeff_1 * r;
  }
  return (y < 0.0) ? -angle : angle;
}
