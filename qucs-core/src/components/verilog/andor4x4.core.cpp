/*
 * andor4x4.core.cpp - device implementations for andor4x4 module
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 */

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include "andor4x4.analogfunction.h"
#include "component.h"
#include "device.h"
#include "andor4x4.core.h"

#ifndef CIR_andor4x4
#define CIR_andor4x4 -1
#endif

// external nodes
#define A11 0
#define A12 1
#define A13 2
#define A14 3
#define A21 4
#define A22 5
#define A23 6
#define A24 7
#define A31 8
#define A32 9
#define A33 10
#define A34 11
#define A41 12
#define A42 13
#define A43 14
#define A44 15
#define Y 16
// internal nodes
#define n1 17
#define n2 18

// useful macro definitions
#define NP(node) real (getV (node))
#define BP(pnode,nnode) (NP(pnode) - NP(nnode))
#define _load_static_residual2(pnode,nnode,current)\
	_rhs[pnode] -= current;\
	_rhs[nnode] += current;
#define _load_static_augmented_residual2(pnode,nnode,current)\
	_rhs[pnode] -= current;\
	_rhs[nnode] += current;
#define _load_static_residual1(node,current)\
	_rhs[node] -= current;
#define _load_static_augmented_residual1(node,current)\
	_rhs[node] -= current;
#define _load_static_jacobian4(pnode,nnode,vpnode,vnnode,conductance)\
	_jstat[pnode][vpnode] += conductance;\
	_jstat[nnode][vnnode] += conductance;\
	_jstat[pnode][vnnode] -= conductance;\
	_jstat[nnode][vpnode] -= conductance;\
	if (doHB) {\
	_ghs[pnode] += conductance * BP(vpnode,vnnode);\
	_ghs[nnode] -= conductance * BP(vpnode,vnnode);\
        } else {\
	_rhs[pnode] += conductance * BP(vpnode,vnnode);\
	_rhs[nnode] -= conductance * BP(vpnode,vnnode);\
	}
#define _load_static_jacobian2p(node,vpnode,vnnode,conductance)\
	_jstat[node][vpnode] += conductance;\
	_jstat[node][vnnode] -= conductance;\
	if (doHB) {\
        _ghs[node] += conductance * BP(vpnode,vnnode);\
        } else {\
        _rhs[node] += conductance * BP(vpnode,vnnode);\
	}
#define _load_static_jacobian2s(pnode,nnode,node,conductance)\
	_jstat[pnode][node] += conductance;\
	_jstat[nnode][node] -= conductance;\
	if (doHB) {\
	_ghs[pnode] += conductance * NP(node);\
	_ghs[nnode] -= conductance * NP(node);\
        } else {\
	_rhs[pnode] += conductance * NP(node);\
	_rhs[nnode] -= conductance * NP(node);\
	}
#define _load_static_jacobian1(node,vnode,conductance)\
	_jstat[node][vnode] += conductance;\
	if (doHB) {\
	_ghs[node] += conductance * NP(vnode);\
        } else {\
	_rhs[node] += conductance * NP(vnode);\
	}
#define _load_dynamic_residual2(pnode,nnode,charge)\
	if (doTR) _charges[pnode][nnode] += charge;\
	if (doHB) {\
	_qhs[pnode] -= charge;\
	_qhs[nnode] += charge;\
	}
#define _load_dynamic_residual1(node,charge)\
	if (doTR) _charges[node][node] += charge;\
	if (doHB) {\
	_qhs[node] -= charge;\
	}
#define _load_dynamic_jacobian4(pnode,nnode,vpnode,vnnode,capacitance)\
	if (doAC) {\
	_jdyna[pnode][vpnode] += capacitance;\
	_jdyna[nnode][vnnode] += capacitance;\
	_jdyna[pnode][vnnode] -= capacitance;\
	_jdyna[nnode][vpnode] -= capacitance;\
	}\
        if (doTR) {\
        _caps[pnode][nnode][vpnode][vnnode] += capacitance;\
  	}\
	if (doHB) {\
	_chs[pnode] += capacitance * BP(vpnode,vnnode);\
	_chs[nnode] -= capacitance * BP(vpnode,vnnode);\
	}
#define _load_dynamic_jacobian2s(pnode,nnode,vnode,capacitance)\
	if (doAC) {\
	_jdyna[pnode][vnode] += capacitance;\
	_jdyna[nnode][vnode] -= capacitance;\
	}\
	if (doTR) {\
	_caps[pnode][nnode][vnode][vnode] += capacitance;\
	}\
	if (doHB) {\
	_chs[pnode] += capacitance * NP(vnode);\
	_chs[nnode] -= capacitance * NP(vnode);\
	}
#define _load_dynamic_jacobian2p(node,vpnode,vnnode,capacitance)\
	if (doAC) {\
	_jdyna[node][vpnode] += capacitance;\
        _jdyna[node][vnnode] -= capacitance;\
        }\
	if (doTR) {\
        _caps[node][node][vpnode][vnnode] += capacitance;\
	}\
	if (doHB) {\
	_chs[node] += capacitance * BP(vpnode,vnnode);\
	}
#define _load_dynamic_jacobian1(node,vnode,capacitance)\
	if (doAC) {\
	_jdyna[node][vnode] += capacitance;\
	}\
	if (doTR) {\
	_caps[node][node][vnode][vnode] += capacitance;\
	}\
	if (doHB) {\
	_chs[node] += capacitance * NP(vnode);\
	}

#define _save_whitenoise1(n1,pwr,type)\
	_white_pwr[n1][n1] += pwr;
#define _save_whitenoise2(n1,n2,pwr,type)\
	_white_pwr[n1][n2] += pwr;
#define _save_flickernoise1(n1,pwr,exp,type)\
	_flicker_pwr[n1][n1] += pwr;\
	_flicker_exp[n1][n1] += exp;
#define _save_flickernoise2(n1,n2,pwr,exp,type)\
	_flicker_pwr[n1][n2] += pwr;\
	_flicker_exp[n1][n2] += exp;
#define _load_whitenoise2(n1,n2,pwr)\
	cy (n1,n2) -= pwr/kB/T0; cy (n2,n1) -= pwr/kB/T0;\
	cy (n1,n1) += pwr/kB/T0; cy (n2,n2) += pwr/kB/T0;
#define _load_whitenoise1(n1,pwr)\
	cy (n1,n1) += pwr/kB/T0;
#define _load_flickernoise2(n1,n2,pwr,exp)\
	cy (n1,n2) -= pwr*pow(_freq,-exp)/kB/T0;\
	cy (n2,n1) -= pwr*pow(_freq,-exp)/kB/T0;\
	cy (n1,n1) += pwr*pow(_freq,-exp)/kB/T0;\
	cy (n2,n2) += pwr*pow(_freq,-exp)/kB/T0;
#define _load_flickernoise1(n1,pwr,exp)\
	cy (n1,n1) += pwr*pow(_freq,-exp)/kB/T0;

// derivative helper macros
#define m00_hypot(v00,x,y)      v00 = xhypot(x,y);
#define m10_hypot(v10,v00,x,y)  v10 = (x)/(v00);
#define m11_hypot(v11,v00,x,y)  v11 = (y)/(v00);
#define m00_max(v00,x,y)        v00 = ((x)>(y))?(x):(y);
#define m10_max(v10,v00,x,y)    v10 = ((x)>(y))?1.0:0.0;
#define m11_max(v11,v00,x,y)    v11 = ((x)>(y))?0.0:1.0;
#define m00_min(v00,x,y)        v00 = ((x)<(y))?(x):(y);
#define m10_min(v10,v00,x,y)    v10 = ((x)<(y))?1.0:0.0;
#define m11_min(v11,v00,x,y)    v11 = ((x)<(y))?0.0:1.0;
#define m00_pow(v00,x,y)        v00 = pow(x,y);
#define m10_pow(v10,v00,x,y)    v10 = (x==0.0)?0.0:(v00)*(y)/(x);
#define m11_pow(v11,v00,x,y)    v11 = (x==0.0)?0.0:(log(x)*(v00));

#define m00_div(v00,v10,x,y)    double v10=1/(y); double v00=(x)*v10;
#define m10_div(v10,v00,vv,x,y)
#define m11_div(v11,v00,vv,x,y) double v11 = -v00*vv;

#define m00_mult(v00,v10,v11,x,y) double v10=(x); double v11=(y); double v00=v10*v11;
#define m00_add(v00,x,y)        double v00=(x)+(y);

#define m00_cos(v00,x)          v00 = cos(x);
#define m10_cos(v10,v00,x)      v10 = (-sin(x));
#define m00_sin(v00,x)          v00 = sin(x);
#define m10_sin(v10,v00,x)      v10 = (cos(x));
#define m00_tan(v00,x)          v00 = tan(x);
#define m10_tan(v10,v00,x)      v10 = (1.0/cos(x)/cos(x));
#define m00_cosh(v00,x)         v00 = cosh(x);
#define m10_cosh(v10,v00,x)     v10 = (sinh(x));
#define m00_sinh(v00,x)         v00 = sinh(x);
#define m10_sinh(v10,v00,x)     v10 = (cosh(x));
#define m00_tanh(v00,x)         v00 = tanh(x);
#define m10_tanh(v10,v00,x)     v10 = (1.0/cosh(x)/cosh(x));
#define m00_acos(v00,x)         v00 = acos(x);
#define m10_acos(v10,v00,x)     v10 = (-1.0/sqrt(1-x*x));
#define m00_asin(v00,x)         v00 = asin(x);
#define m10_asin(v10,v00,x)     v10 = (+1.0/sqrt(1-x*x));
#define m00_atan(v00,x)         v00 = atan(x);
#define m10_atan(v10,v00,x)     v10 = (+1.0/(1+x*x));
#define m00_atanh(v00,x)        v00 = atanh(x);
#define m10_atanh(v10,v00,x)    v10 = (+1.0/(1-x*x));
#define m00_logE(v00,x)         v00 = log(x);
#define m10_logE(v10,v00,x)     v10 = (1.0/x);
#define m00_log10(v00,x)        v00 = log10(x);
#define m10_log10(v10,v00,x)    v10 = (1.0/x/M_LN10);
#define m00_sqrt(v00,x)         v00 = sqrt(x);
#define m10_sqrt(v10,v00,x)     v10 = (0.5/v00);
#define m00_fabs(v00,x)         v00 = fabs(x);
#define m10_fabs(v10,v00,x)     v10 = (((x)>=0)?(+1.0):(-1.0));

#define m00_exp(v00,x)          v00 = exp(x);
#define m10_exp(v10,v00,x)      v10 = v00;

#define m00_abs(v00)            ((v00)<(0)?(-(v00)):(v00))
#define m00_floor(v00,x)        v00 = floor(x);
#define m00_limexp(v00,x)       v00 = ((x)<80.0?exp(x):exp(80.0)*(x-79.0));
#define m10_limexp(v10,v00,x)   v10 = ((x)<80.0?(v00):exp(80.0));

#define m20_logE(v00)           (-1.0/v00/v00)
#define m20_exp(v00)            exp(v00)
#define m20_limexp(v00)         ((v00)<80.0?exp(v00):0.0)
#define m20_sqrt(v00)           (-0.25/(v00)/sqrt(v00))
#define m20_fabs(v00)           0.0
#define m20_pow(x,y)            ((y)*((y)-1.0)*pow(x,y)/(x)/(x))
#define m00_vt(x)               (kBoverQ*(x))
#define m10_vt(x)               (kBoverQ)

// simulator specific definitions
#define _modelname              "andor4x4"
#define _instancename           getName()
#define _circuit_temp	        (getPropertyDouble("Temp")+273.15)
#define _param_given(p)		(isPropertyGiven(p)?1:0)


// $vt and $vt() functions 
#define _vt_nom                 (kBoverQ*_circuit_temp)

using namespace device;

/* Device constructor. */
andor4x4::andor4x4() : circuit (19)
{
  type = CIR_andor4x4;
}

/* Initialization of model. */
void andor4x4::initModel (void)
{
  // create internal nodes
  setInternalNode (n1, "n1");
  setInternalNode (n2, "n2");

  // get device model parameters
  loadVariables ();
  // evaluate global model equations
  initializeModel ();
  // evaluate initial step equations
  initialStep ();
  // evaluate global instance equations
  initializeInstance ();
}

/* Initialization of DC analysis. */
void andor4x4::initDC (void)
{
  allocMatrixMNA ();
  initModel ();
  pol = 1;
  restartDC ();
  doAC = 1;
  doTR = 0;
  doHB = 0;
}

/* Run when DC is restarted (fallback algorithms). */
void andor4x4::restartDC (void)
{
}

/* Initialize Verilog-AMS code. */
void andor4x4::initVerilog (void)
{
  // initialization of noise variables

  int i1, i2, i3, i4;

  // zero charges
  for (i1 = 0; i1 < 19; i1++) {
  for (i2 = 0; i2 < 19; i2++) {
    _charges[i1][i2] = 0.0;
  } }

  // zero capacitances
  for (i1 = 0; i1 < 19; i1++) {
  for (i2 = 0; i2 < 19; i2++) {
  for (i3 = 0; i3 < 19; i3++) {
  for (i4 = 0; i4 < 19; i4++) {
    _caps[i1][i2][i3][i4] = 0.0;
  } } } }

  // zero right hand side, static and dynamic jacobian
  for (i1 = 0; i1 < 19; i1++) {
    _rhs[i1] = 0.0;
    _qhs[i1] = 0.0;
    _chs[i1] = 0.0;
    _ghs[i1] = 0.0;
    for (i2 = 0; i2 < 19; i2++) {
      _jstat[i1][i2] = 0.0;
      _jdyna[i1][i2] = 0.0;
    }
  }
}

/* Load device model input parameters. */
void andor4x4::loadVariables (void)
{
  TR = getPropertyDouble ("TR");
  Delay = getPropertyDouble ("Delay");
}

/* #define's for translated code */
#undef  _DDT
#define _DDT(q) q
#define _DYNAMIC
#define _DERIVATE
#define _DDX
#define _DERIVATEFORDDX

/* Evaluate Verilog-AMS equations in model initialization. */
void andor4x4::initializeModel (void)
{
#if defined(_DYNAMIC)
#endif
{
Rd=1e3;
#if defined(_DYNAMIC)
Cd=((Delay*1.43)/Rd);
#endif
}
}

/* Evaluate Verilog-AMS equations in instance initialization. */
void andor4x4::initializeInstance (void)
{
}

/* Evaluate Verilog-AMS equations in initial step. */
void andor4x4::initialStep (void)
{
}

/* Evaluate Verilog-AMS equations in final step. */
void andor4x4::finalStep (void)
{
}

/* Evaluate Verilog-AMS equations in analog block. */
void andor4x4::calcVerilog (void)
{

/* ----------------- evaluate verilog analog equations -------------------- */
double Iand;
#if defined(_DERIVATE)
double Iand_VA11_GND;
double Iand_VA12_GND;
double Iand_VA13_GND;
double Iand_VA14_GND;
double Iand_VA21_GND;
double Iand_VA22_GND;
double Iand_VA23_GND;
double Iand_VA24_GND;
double Iand_VA31_GND;
double Iand_VA32_GND;
double Iand_VA33_GND;
double Iand_VA34_GND;
double Iand_VA41_GND;
double Iand_VA42_GND;
double Iand_VA43_GND;
double Iand_VA44_GND;
#endif
double m4;
#if defined(_DERIVATE)
double m4_VA41_GND;
double m4_VA42_GND;
double m4_VA43_GND;
double m4_VA44_GND;
#endif
double m3;
#if defined(_DERIVATE)
double m3_VA31_GND;
double m3_VA32_GND;
double m3_VA33_GND;
double m3_VA34_GND;
#endif
double m2;
#if defined(_DERIVATE)
double m2_VA21_GND;
double m2_VA22_GND;
double m2_VA23_GND;
double m2_VA24_GND;
#endif
double m1;
#if defined(_DERIVATE)
double m1_VA11_GND;
double m1_VA12_GND;
double m1_VA13_GND;
double m1_VA14_GND;
#endif
#if defined(_DERIVATE)
m1_VA11_GND=(NP(A12))*NP(A13)*NP(A14);
m1_VA12_GND=(NP(A11))*NP(A13)*NP(A14);
m1_VA13_GND=((NP(A11)*NP(A12)))*NP(A14);
m1_VA14_GND=(((NP(A11)*NP(A12))*NP(A13)));
#endif
m1=(((NP(A11)*NP(A12))*NP(A13))*NP(A14));
#if defined(_DERIVATE)
m2_VA21_GND=(NP(A22))*NP(A23)*NP(A24);
m2_VA22_GND=(NP(A21))*NP(A23)*NP(A24);
m2_VA23_GND=((NP(A21)*NP(A22)))*NP(A24);
m2_VA24_GND=(((NP(A21)*NP(A22))*NP(A23)));
#endif
m2=(((NP(A21)*NP(A22))*NP(A23))*NP(A24));
#if defined(_DERIVATE)
m3_VA31_GND=(NP(A32))*NP(A33)*NP(A34);
m3_VA32_GND=(NP(A31))*NP(A33)*NP(A34);
m3_VA33_GND=((NP(A31)*NP(A32)))*NP(A34);
m3_VA34_GND=(((NP(A31)*NP(A32))*NP(A33)));
#endif
m3=(((NP(A31)*NP(A32))*NP(A33))*NP(A34));
#if defined(_DERIVATE)
m4_VA41_GND=(NP(A42))*NP(A43)*NP(A44);
m4_VA42_GND=(NP(A41))*NP(A43)*NP(A44);
m4_VA43_GND=((NP(A41)*NP(A42)))*NP(A44);
m4_VA44_GND=(((NP(A41)*NP(A42))*NP(A43)));
#endif
m4=(((NP(A41)*NP(A42))*NP(A43))*NP(A44));
#if defined(_DERIVATE)
Iand_VA11_GND=m1_VA11_GND;
Iand_VA12_GND=m1_VA12_GND;
Iand_VA13_GND=m1_VA13_GND;
Iand_VA14_GND=m1_VA14_GND;
Iand_VA21_GND=m2_VA21_GND;
Iand_VA22_GND=m2_VA22_GND;
Iand_VA23_GND=m2_VA23_GND;
Iand_VA24_GND=m2_VA24_GND;
Iand_VA31_GND=m3_VA31_GND;
Iand_VA32_GND=m3_VA32_GND;
Iand_VA33_GND=m3_VA33_GND;
Iand_VA34_GND=m3_VA34_GND;
Iand_VA41_GND=m4_VA41_GND;
Iand_VA42_GND=m4_VA42_GND;
Iand_VA43_GND=m4_VA43_GND;
Iand_VA44_GND=m4_VA44_GND;
#endif
Iand=(((m1+m2)+m3)+m4);
if
((Iand>0.5))
{
#if defined(_DERIVATE)
Iand_VA11_GND=0.0;
Iand_VA12_GND=0.0;
Iand_VA13_GND=0.0;
Iand_VA14_GND=0.0;
Iand_VA21_GND=0.0;
Iand_VA22_GND=0.0;
Iand_VA23_GND=0.0;
Iand_VA24_GND=0.0;
Iand_VA31_GND=0.0;
Iand_VA32_GND=0.0;
Iand_VA33_GND=0.0;
Iand_VA34_GND=0.0;
Iand_VA41_GND=0.0;
Iand_VA42_GND=0.0;
Iand_VA43_GND=0.0;
Iand_VA44_GND=0.0;
#endif
Iand=1;
}
else
{
#if defined(_DERIVATE)
Iand_VA11_GND=0.0;
Iand_VA12_GND=0.0;
Iand_VA13_GND=0.0;
Iand_VA14_GND=0.0;
Iand_VA21_GND=0.0;
Iand_VA22_GND=0.0;
Iand_VA23_GND=0.0;
Iand_VA24_GND=0.0;
Iand_VA31_GND=0.0;
Iand_VA32_GND=0.0;
Iand_VA33_GND=0.0;
Iand_VA34_GND=0.0;
Iand_VA41_GND=0.0;
Iand_VA42_GND=0.0;
Iand_VA43_GND=0.0;
Iand_VA44_GND=0.0;
#endif
Iand=0;
}
{
double m00_tanh(d00_tanh0,(TR*(Iand-0.5)))
#if defined(_DERIVATE)
double m10_tanh(d10_tanh0,d00_tanh0,(TR*(Iand-0.5)))
#endif
_load_static_residual1(n1,((-0.5)*(1+d00_tanh0)));
#if defined(_DERIVATE)
_load_static_jacobian1(n1,A44,((-0.5)*(TR*Iand_VA44_GND)*d10_tanh0));
_load_static_jacobian1(n1,A43,((-0.5)*(TR*Iand_VA43_GND)*d10_tanh0));
_load_static_jacobian1(n1,A42,((-0.5)*(TR*Iand_VA42_GND)*d10_tanh0));
_load_static_jacobian1(n1,A41,((-0.5)*(TR*Iand_VA41_GND)*d10_tanh0));
_load_static_jacobian1(n1,A34,((-0.5)*(TR*Iand_VA34_GND)*d10_tanh0));
_load_static_jacobian1(n1,A33,((-0.5)*(TR*Iand_VA33_GND)*d10_tanh0));
_load_static_jacobian1(n1,A32,((-0.5)*(TR*Iand_VA32_GND)*d10_tanh0));
_load_static_jacobian1(n1,A31,((-0.5)*(TR*Iand_VA31_GND)*d10_tanh0));
_load_static_jacobian1(n1,A24,((-0.5)*(TR*Iand_VA24_GND)*d10_tanh0));
_load_static_jacobian1(n1,A23,((-0.5)*(TR*Iand_VA23_GND)*d10_tanh0));
_load_static_jacobian1(n1,A22,((-0.5)*(TR*Iand_VA22_GND)*d10_tanh0));
_load_static_jacobian1(n1,A21,((-0.5)*(TR*Iand_VA21_GND)*d10_tanh0));
_load_static_jacobian1(n1,A14,((-0.5)*(TR*Iand_VA14_GND)*d10_tanh0));
_load_static_jacobian1(n1,A13,((-0.5)*(TR*Iand_VA13_GND)*d10_tanh0));
_load_static_jacobian1(n1,A12,((-0.5)*(TR*Iand_VA12_GND)*d10_tanh0));
_load_static_jacobian1(n1,A11,((-0.5)*(TR*Iand_VA11_GND)*d10_tanh0));
#endif
}
_load_static_residual1(n1,NP(n1));
#if defined(_DERIVATE)
_load_static_jacobian1(n1,n1,1.0);
#endif
_load_static_residual2(n1,n2,(BP(n1,n2)/Rd));
#if defined(_DERIVATE)
_load_static_jacobian4(n1,n2,n1,n2,(1/Rd));
#endif
#if defined(_DYNAMIC)
_load_dynamic_residual1(n2,_DDT((Cd*NP(n2))));
#if defined(_DERIVATE)
_load_dynamic_jacobian1(n2,n2,(Cd));
#endif
#endif
_load_static_residual1(Y,(-NP(n2)));
#if defined(_DERIVATE)
_load_static_jacobian1(Y,n2,(-1.0));
#endif
_load_static_residual1(Y,NP(Y));
#if defined(_DERIVATE)
_load_static_jacobian1(Y,Y,1.0);
#endif

/* ------------------ end of verilog analog equations --------------------- */

/* ------------------ evaluate verilog noise equations -------------------- */

/* ------------------- end of verilog noise equations --------------------- */
}

/* Perform DC iteration. */
void andor4x4::calcDC (void)
{
  // evaluate Verilog code
  initVerilog ();		
  calcVerilog ();		

  // fill right hand side and static jacobian
  for (int i1 = 0; i1 < 19; i1++) {
    setI (i1, _rhs[i1]);
    for (int i2 = 0; i2 < 19; i2++) {
      setY (i1, i2, _jstat[i1][i2]);
    }
  }
}

/* Save operating points. */
void andor4x4::saveOperatingPoints (void)
{
  // save global instance operating points
}

/* Load operating points. */
void andor4x4::loadOperatingPoints (void)
{
}

/* Calculate operating points. */
void andor4x4::calcOperatingPoints (void)
{
}

/* Initialization of AC analysis. */
void andor4x4::initAC (void)
{
  allocMatrixMNA ();
}

/* Perform AC calculations. */
void andor4x4::calcAC (nr_double_t frequency)
{
  setMatrixY (calcMatrixY (frequency));
}

/* Compute Y-matrix for AC analysis. */
matrix andor4x4::calcMatrixY (nr_double_t frequency)
{
  _freq = frequency;
  saveOperatingPoints ();
  matrix y (19);

  for (int i1 = 0; i1 < 19; i1++) {
    for (int i2 = 0; i2 < 19; i2++) {
      y (i1,i2) = rect (_jstat[i1][i2], _jdyna[i1][i2] * 2 * M_PI * _freq);
    }
  }

  return y;
}

/* Initialization of S-parameter analysis. */
void andor4x4::initSP (void)
{
  allocMatrixS ();
}

/* Perform S-parameter calculations. */
void andor4x4::calcSP (nr_double_t frequency)
{
  setMatrixS (ytos (calcMatrixY (frequency)));   
}

/* Initialization of transient analysis. */
void andor4x4::initTR (void)
{
  setStates (2 * 19 * 19);
  initDC ();
}

/* Perform transient analysis iteration step. */
void andor4x4::calcTR (nr_double_t)
{
  doHB = 0;
  doAC = 1;
  doTR = 1;
  calcDC ();

  int i1, i2, i3, i4, state;

  // 2-node charge integrations
  for (i1 = 0; i1 < 19; i1++) {
  for (i2 = 0; i2 < 19; i2++) {
    state = 2 * (i2 + 19 * i1);
    if (i1 != i2)
    if (_charges[i1][i2] != 0.0)
      transientCapacitanceQ (state, i1, i2, _charges[i1][i2]);
  } }

  // 1-node charge integrations
  for (i1 = 0; i1 < 19; i1++) {
    state = 2 * (i1 + 19 * i1);
    if (_charges[i1][i1] != 0.0)
      transientCapacitanceQ (state, i1, _charges[i1][i1]);
  }

  // charge: 2-node, voltage: 2-node
  for (i1 = 0; i1 < 19; i1++) {
  for (i2 = 0; i2 < 19; i2++) {
  if (i1 != i2)
  for (i3 = 0; i3 < 19; i3++) {
  for (i4 = 0; i4 < 19; i4++) {
    if (i3 != i4)
    if (_caps[i1][i2][i3][i4] != 0.0)
      transientCapacitanceC (i1, i2, i3, i4, _caps[i1][i2][i3][i4], BP(i3,i4));
  } } } }

  // charge: 2-node, voltage: 1-node
  for (i1 = 0; i1 < 19; i1++) {
  for (i2 = 0; i2 < 19; i2++) {
  if (i1 != i2)
  for (i3 = 0; i3 < 19; i3++) {
    if (_caps[i1][i2][i3][i3] != 0.0)
      transientCapacitanceC2Q (i1, i2, i3, _caps[i1][i2][i3][i3], NP(i3));
  } } }

  // charge: 1-node, voltage: 2-node
  for (i1 = 0; i1 < 19; i1++) {
  for (i3 = 0; i3 < 19; i3++) {
  for (i4 = 0; i4 < 19; i4++) {
    if (i3 != i4)
    if (_caps[i1][i1][i3][i4] != 0.0)
      transientCapacitanceC2V (i1, i3, i4, _caps[i1][i1][i3][i4], BP(i3,i4));
  } } }
     
  // charge: 1-node, voltage: 1-node
  for (i1 = 0; i1 < 19; i1++) {
  for (i3 = 0; i3 < 19; i3++) {
    if (_caps[i1][i1][i3][i3] != 0.0)
      transientCapacitanceC (i1, i3, _caps[i1][i1][i3][i3], NP(i3));
  } }
}

/* Compute Cy-matrix for AC noise analysis. */
matrix andor4x4::calcMatrixCy (nr_double_t frequency) 
{
  _freq = frequency;
  matrix cy (19);


  return cy;
}

/* Perform AC noise computations. */
void andor4x4::calcNoiseAC (nr_double_t frequency) 
{
  setMatrixN (calcMatrixCy (frequency));
}

/* Perform S-parameter noise computations. */
void andor4x4::calcNoiseSP (nr_double_t frequency) 
{
  setMatrixN (cytocs (calcMatrixCy (frequency) * z0, getMatrixS ()));
}

/* Initialization of HB analysis. */
void andor4x4::initHB (int)
{
  initDC ();
  allocMatrixHB ();
}

/* Perform HB analysis. */
void andor4x4::calcHB (int)
{
  doHB = 1;
  doAC = 1;
  doTR = 0;

  // jacobian dI/dV and currents get filled
  calcDC ();
  saveOperatingPoints ();

  // fill in HB matrices
  for (int i1 = 0; i1 < 19; i1++) {
    setQ  (i1, _qhs[i1]); // charges
    setCV (i1, _chs[i1]); // jacobian dQ/dV * V
    setGV (i1, _ghs[i1]); // jacobian dI/dV * V
    for (int i2 = 0; i2 < 19; i2++) {
      setQV (i1, i2, _jdyna[i1][i2]); // jacobian dQ/dV
    }
  }
}

#include "andor4x4.defs.h"
