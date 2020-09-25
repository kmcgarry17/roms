/*
** svn $Id$
*******************************************************************************
** Copyright (c) 2002-2013 The ROMS/TOMS Group
**
**   Licensed under a MIT/X style license
**
**   See License_ROMS.txt
**
*******************************************************************************
**
**  Options for NWA simulation
*/

 
/* general */
#define CURVGRID
#define MASKING
#define NONLIN_EOS
#define SOLVE3D 
#define SALINITY

#define SPLINES_VDIFF
#define SPLINES_VVISC
#define RI_SPLINES

#undef FLOATS
#undef STATIONS
#undef CCSM_COUPLED
#define CORE_FORCING
#define CCSM_FLUXES
/* #define DOUBLE_PRECISION */
/* #define NO_LBC_ATT */

/* ice */

#ifdef SOLVE3D
# undef  ICE_MODEL
# ifdef     ICE_MODEL
# define  ICE_THERMO
# define  ICE_MK
# undef   ICE_ALB_EC92
# undef   ICE_SMOOTH
# define  ICE_MOMENTUM
# define  ICE_MOM_BULK
# define  ICE_EVP
# define  ICE_ADVECT
# define  ICE_SMOLAR
# define  ICE_UPWIND
# define  ICE_BULK_FLUXES
# define  ANA_AIOBC
# define  ANA_HIOBC
# define  ANA_HSNOBC
# endif
#endif

/* output stuff */
 
#define LONG_NUMS
#define NO_WRITE_GRID
#undef OUT_DOUBLE
#define RST_SINGLE
#define AVERAGES 
#undef AVERAGES2 
#undef NO_HIS

#ifdef SOLVE3D
# undef DIAGNOSTICS_TS
#endif
#undef DIAGNOSTICS_UV

 
/* advection, dissipation, pressure grad, etc. */
 
#ifdef SOLVE3D
# define DJ_GRADPS
#endif
 
#define UV_ADV
#define UV_COR
#undef UV_SADVECTION
 
#define UV_VIS2
#define MIX_S_UV
#define VISC_GRID
#undef SPONGE
#define VISC_3DCOEF

#ifdef SOLVE3D
# define TS_DIF2
# define MIX_GEO_TS           /* mixing on geopotential surfaces for horizontal mixing of tracers */
# define DIFF_GRID            /* scale diffusion coefficients by grid size for horizontal mixing of tracers */
# define TS_U3HADVECTION      /* 3rd-order upstream biased advection */
# define TS_C4VADVECTION      /* 4th-order center vert advection instead */
# undef TS_MPDATA 
#endif

/* vertical mixing */
#ifdef SOLVE3D
# define LMD_MIXING              /* activate Large et al. (1994) interior closure for vertical turbulent mixing of momentum and tracers */
# ifdef LMD_MIXING
#  define LMD_RIMIX              /* add diffusivity due to shear instability for the Large et al. (1994) K-profile parameterization mixing */
#  define LMD_CONVEC             /* add convective mixing due to shear instability for the Large et al. (1994) K-profile parameterization mixing */
#  define LMD_SKPP               /* use surface boundary layer KPP mixing for the Large et al. (1994) K-profile parameterization mixing */
#  define LMD_BKPP
#  define LMD_NONLOCAL           /* use nonlocal transport for the Large et al. (1994) K-profile parameterization mixing */
#  define LMD_SHAPIRO            /* use Shapiro filtering boundary layer depth for the Large et al. (1994) K-profile parameterization mixing */
#  undef LMD_DDMIX
# endif

# undef GLS_MIXING
# undef MY25_MIXING
#endif

 
/* surface forcing */
#ifdef SOLVE3D
# define BULK_FLUXES
# ifdef BULK_FLUXES
#  define LONGWAVE_OUT
#  define DIURNAL_SRFLUX
#  define EMINUSP
#  undef ANA_SRFLUX
#  define ALBEDO_CURVE
#  undef ALBEDO
#  define SOLAR_SOURCE
#  undef ALBEDO_FILE
#  undef LONGWAVE
# endif
#endif

#undef RUNOFF 
/* surface and side corrections */

#ifdef SOLVE3D
# define SCORRECTION
# define SSSC_THRESHOLD
# undef SRELAXATION
# undef QCORRECTION
#endif

/* tides */
#define LTIDES
#ifdef LTIDES
# undef FILTERED
# define SSH_TIDES
# define UV_TIDES
# define ADD_FSOBC
# define ADD_M2OBC
# undef RAMP_TIDES
# define TIDES_ASTRO
# define POT_TIDES

# define UV_LDRAG
# define UV_DRAG_GRID
# define ANA_DRAG
# define LIMIT_BSTRESS
# undef UV_QDRAG
#else
# define UV_QDRAG
# define M2TIDE_DIFF
#endif

/* point sources (rivers, line sources) */


#ifdef SOLVE3D
# undef UV_PSOURCE
# undef ANA_PSOURCE
# undef TS_PSOURCE
#endif

#define RADIATION_2D


/* roms quirks */

#ifdef SOLVE3D
# define ANA_BSFLUX             /* set kinematic bottom salinity flux with an analytical expression */
# define ANA_BTFLUX             /* set kinematic bottom heat flux with an analytical expression */
#else
# define ANA_SMFLUX
#endif

/* biological model options */
#define BIOLOGY
#define BIO_COBALT 
#undef DEBUG_COBALT
/*#define COBALT_CONSERVATION_TEST */
/*#define COBALT_NOSOURCE */
/*#define COBALT_DO_NOTHING  */

#if defined BIO_COBALT
# define OPTIC_MANIZZA
# define COBALT_MINERALS
# undef COBALT_PHOSPHORUS   	/*# define COBALT_PHOSPHORUS*/
# undef BIO_COBALT_RUNOFF
# define COASTDIAT
# define COBALT_IRON		/*# define COBALT_IRON*/

# undef COBALT_CARBON 
# undef DIAGNOSTICS
# undef DIAGNOSTICS_BIO 
/*# define BENTHIC  */
/*# define TIMESERIES */
# undef ANA_BIOLOGY        /* analytical biology initial conditions */
# define ANA_BPFLUX        /* analytical bottom passive tracers fluxes */
# define ANA_SPFLUX        /* analytical surface passive tracers fluxes */
#endif


