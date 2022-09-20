#include <stdio.h>

#include <stdlib.h>


void * aggregate(void * base, size_t size, int n, void * initial_value, void * ( * opr)(const void * ,
  const void * ));

void * addInt(const void * a,
  const void * b) {

  int * p = malloc(sizeof(int));
  * p = * (int * ) a + * (int * ) b;
  return p;
}

void * addDouble(const void * a,
  const void * b) {

  double * p = malloc(sizeof(double));
  * p = * (double * ) a + * (double * ) b;
  return p;

}

void * mulInt(const void * a,
  const void * b) {

  int * p = malloc(sizeof(int));
  * p = * (int * ) a * * (int * ) b;
  return p;

}

void * mulDouble(const void * a,
  const void * b) {

  double * p = malloc(sizeof(double));
  * p = * (double * ) a * * (double * ) b;
  return p;

}

void * meanInt(const void * a,
  const void * b) {

  int * p = malloc(sizeof(int));
  * p = * (int * ) a + * (int * ) b;
  return p;

}

void * meanDouble(const void * a,
  const void * b) {

  double * p = malloc(sizeof(double));
  * p = * (double * ) a + * (double * ) b;
  return p;

}

void * aggregate(void * base, size_t size, int n, void * initial_value, void * ( * opr)(const void * ,
  const void * )) {

  void * output;

  if (size == sizeof(int)) { // base is a pointer to an integer
    int * p1, * p2, * p3;
    p1 = (int * ) initial_value;
    for (int i = 0; i < n; i++) {
      p2 = ((int * ) base) + i;
      p1 = opr(p1, p2);
      if (i) //free pointer of the previous answer 
        free(p3);
      p3 = p1;
    }
    if (opr == meanInt)
      *
      p1 /= n;
    output = p1;

  } else { // base is a pointer to a double

    double * p1, * p2, * p3;
    p1 = (double * ) initial_value;
    for (int i = 0; i < n; i++) {
      p2 = ((double * ) base) + i;
      p1 = opr(p1, p2);
      if (i) //free pointer of the previous answer 
        free(p3);
      p3 = p1;
    }
    if (opr == meanDouble)
      *
      p1 /= n;
    output = p1;
  }

  return output;
}

int main() {

  int * ints = malloc(sizeof(int) * 5);
  double * doubles = malloc(sizeof(double) * 5);

  for (int i = 0; i < 5; i++) {
    ints[i] = i + 1;
    doubles[i] = (i + 1) / 2.0;
  }

  int intZero = 0;
  double doubleZero = 0.0;
  int intOne = 1;
  double doubleOne = 1.0;

  // Addition

  int * result1a;

  result1a = aggregate(ints, sizeof(int), 5, & intZero, addInt);

  printf("%d\n", * result1a);

  double * result2a;

  result2a = aggregate(doubles, sizeof(double), 5, & doubleZero, addDouble);

  printf("%f\n", * result2a);

  // Multiplication

  int * result1m;

  result1m = aggregate(ints, sizeof(int), 5, & intOne, mulInt);

  printf("%d\n", * result1m);

  double * result2m;

  result2m = aggregate(doubles, sizeof(double), 5, & doubleOne, mulDouble);

  printf("%f\n", * result2m);

  // Mean

  int * result1mean;

  result1mean = aggregate(ints, sizeof(int), 5, & intZero, meanInt);

  printf("%d\n", * result1mean);

  double * result2mean;

  result2mean = aggregate(doubles, sizeof(double), 5, & doubleZero, meanDouble);

  printf("%f\n", * result2mean);

  free(result1mean);
  free(result2mean);
  free(result1m);
  free(result2m);
  free(result1a);
  free(result2a);
  free(doubles);
  free(ints);

  return EXIT_SUCCESS;
}
