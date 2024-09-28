#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a number from a given base to decimal
long long baseToDecimal(char *value, int base) {
  long long decimalValue = 0;
  int length = strlen(value);
  for (int i = 0; i < length; i++) {
    char digit = value[i];
    decimalValue *= base;
    if (digit >= '0' && digit <= '9') {
      decimalValue += digit - '0';
    } else if (digit >= 'A' && digit <= 'F') {
      decimalValue += digit - 'A' + 10;
    }
  }
  return decimalValue;
}

// Lagrange Interpolation function to find the constant term c
double lagrangeInterpolation(int n, long long x[], long long y[], int degree) {
  double result = 0.0;

  for (int i = 0; i <= degree; i++) {
    double term = y[i];
    for (int j = 0; j <= degree; j++) {
      if (i != j) {
        term *= (0.0 - x[j]) /
                (x[i] - x[j]); // Interpolating for x = 0 (constant term)
      }
    }
    result += term;
  }

  return result;
}

int main() {
  // Test cases JSON data (parsed manually for simplicity)
  char *testCase1[] = {
      "{\"n\": 4, \"k\": 3, \"1\": {\"base\": \"10\", \"value\": \"4\"}, "
      "\"2\": {\"base\": \"2\", \"value\": \"111\"}, \"3\": {\"base\": \"10\", "
      "\"value\": \"12\"}, \"6\": {\"base\": \"4\", \"value\": \"213\"}}",
      "{\"n\": 9, \"k\": 6, \"1\": {\"base\": \"10\", \"value\": "
      "\"28735619723837\"}, \"2\": {\"base\": \"16\", \"value\": "
      "\"1A228867F0CA\"}, \"3\": {\"base\": \"12\", \"value\": "
      "\"32811A4AA0B7B\"}, \"4\": {\"base\": \"11\", \"value\": "
      "\"917978721331A\"}, \"5\": {\"base\": \"16\", \"value\": "
      "\"1A22886782E1\"}, \"6\": {\"base\": \"10\", \"value\": "
      "\"28735619654702\"}, \"7\": {\"base\": \"14\", \"value\": "
      "\"71AB5070CC4B\"}, \"8\": {\"base\": \"9\", \"value\": "
      "\"122662581541670\"}, \"9\": {\"base\": \"8\", \"value\": "
      "\"642121030037605\"}}"};

  // Assuming the data is parsed into the following arrays
  // Test case 1
  int n1 = 4;
  int degree1 = 3; // k = 3, so degree = k-1 = 2
  long long x1[] = {1, 2, 3, 6};
  long long y1[] = {baseToDecimal("4", 10), baseToDecimal("111", 2),
                    baseToDecimal("12", 10), baseToDecimal("213", 4)};

  // Test case 2
  int n2 = 9;
  int degree2 = 6; // k = 6, so degree = k-1 = 5
  long long x2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  long long y2[] = {
      baseToDecimal("28735619723837", 10), baseToDecimal("1A228867F0CA", 16),
      baseToDecimal("32811A4AA0B7B", 12),  baseToDecimal("917978721331A", 11),
      baseToDecimal("1A22886782E1", 16),   baseToDecimal("28735619654702", 10),
      baseToDecimal("71AB5070CC4B", 14),   baseToDecimal("122662581541670", 9),
      baseToDecimal("642121030037605", 8)};

  // Calculate the constant term for each test case
  double c1 = lagrangeInterpolation(n1, x1, y1, degree1);
  double c2 = lagrangeInterpolation(n2, x2, y2, degree2);

  // Print the constant term for both test cases
  printf("Constant term for Test Case 1: %.0lf\n", c1);
  printf("Constant term for Test Case 2: %.0lf\n", c2);

  return 0;
}
