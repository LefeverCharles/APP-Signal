/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Pb4_to_c.c
 *
 * Code generation for function 'Pb4_to_c'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Pb4_to_c.h"
#include "randn.h"
#include "randi.h"
#include "sin.h"

/* Function Definitions */
double Pb4_to_c(void)
{
  static double t[112001];
  int k;
  double kd;
  static double y_sin[112001];
  static double unusedExpr[112001];

  /*  Notes */
  /*  Création des signaux */
  /*  On peut le changer comme on veut */
  /*  en secondes */
  t[0] = 0.0;
  t[112000] = 7.0;
  for (k = 0; k < 55999; k++) {
    kd = ((double)k + 1.0) * 6.25E-5;
    t[k + 1] = kd;
    t[111999 - k] = 7.0 - kd;
  }

  t[56000] = 3.5;
  for (k = 0; k < 112001; k++) {
    y_sin[k] = 1035.5317704762676 * t[k];
  }

  b_sin(y_sin);
  for (k = 0; k < 112001; k++) {
    t[k] *= 1035.5317704762676;
  }

  b_sin(t);
  randi();
  randn(unusedExpr);

  /*  FIGURE 1 */
  /*  Sinus */
  /*  Sinus + bruit */
  /*  FFT Sinus */
  /*  FFT Sinus + bruit filtré */
  /*  FIGURE 2 */
  /*  Carre */
  /*  Carre + bruit */
  /*  FFT Carre */
  /*  FFT Carre + bruit filtré */
  /*  Calcul du score */
  return 0.0;
}

/* End of code generation (Pb4_to_c.c) */
