// Lightweight contextual header of standard requirements (i.e. morphs per include, no guard here!)

namespace Cg
{
  #ifdef DOUBLE_PRECISION
    typedef double Scalar;
  #else
    typedef float Scalar;
  #endif
}