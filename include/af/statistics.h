/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#pragma once
#include <af/defines.h>

#ifdef __cplusplus
namespace af
{
class array;

/**
   C++ Interface for mean

   \param[in] in is the input array
   \param[in] dim the dimension along which the mean is extracted
   \return    the mean of the input array along dimension \p dim

   \ingroup stat_func_mean

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.
*/
AFAPI array mean(const array& in, const dim_t dim=-1);

/**
   C++ Interface for mean of weighted inputs

   \param[in] in is the input array
   \param[in] weights is used to scale input \p in before getting mean
   \param[in] dim the dimension along which the mean is extracted
   \return    the mean of the weighted input array along dimension \p dim

   \ingroup stat_func_mean

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.
*/
AFAPI array mean(const array& in, const array& weights, const dim_t dim=-1);

/**
   C++ Interface for variance

   \param[in] in is the input array
   \param[in] isbiased is boolean denoting Population variance (false) or Sample
              Variance (true)
   \param[in] dim the dimension along which the variance is extracted
   \return the variance of the input array along dimension \p dim

   \ingroup stat_func_var

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.

   \deprecated Use \ref af::var that takes \ref af_var_bias instead
*/
AF_DEPRECATED("Use \ref af::var(const array&, const af_var_bias, const dim_t)")
AFAPI array var(const array& in, const bool isbiased=false, const dim_t dim=-1);

#if AF_API_VERSION >= 38
/**
   C++ Interface for variance

   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes o
              value of type \ref af_var_bias.
   \param[in] dim the dimension along which the variance is extracted
   \return the variance of the input array along dimension \p dim

   \ingroup stat_func_var

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.
*/
AFAPI array var(const array &in, const af_var_bias bias, const dim_t dim = -1);
#endif

/**
   C++ Interface for variance of weighted inputs

   \param[in] in is the input array
   \param[in] weights is used to scale input \p in before getting variance
   \param[in] dim the dimension along which the variance is extracted
   \return    the variance of the weighted input array along dimension \p dim

   \ingroup stat_func_var

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.
*/
AFAPI array var(const array& in, const array &weights, const dim_t dim=-1);

#if AF_API_VERSION >= 37
/**
   C++ Interface for mean and variance

   \param[out] mean     The mean of the input array along \p dim dimension
   \param[out] var      The variance of the input array along the \p dim dimension
   \param[in]  in       The input array
   \param[in]  weights  The weights to scale the input array before calculating
                        the mean and varience. If empty, the input is not scaled
   \param[in] bias      The type of bias used for variance calculation
   \param[in] dim       The dimension along which the variance and mean are
                        calculated. Default is -1 meaning the first non-zero dim
  */
AFAPI void meanvar(array& mean, array& var, const array& in, const array& weights,
                   const af_var_bias bias = AF_VARIANCE_POPULATION, const dim_t dim=-1);
#endif

/**
   C++ Interface for standard deviation

   \param[in] in is the input array
   \param[in] dim the dimension along which the standard deviation is extracted
   \return    the standard deviation of the input array along dimension \p dim

   \ingroup stat_func_stdev

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.

   \deprecated Use \ref af::stdev that takes \ref af_var_bias instead
*/
AF_DEPRECATED("Use af::stdev(const array&, const af_var_bias, const dim_t)")
AFAPI array stdev(const array& in, const dim_t dim=-1);

#if AF_API_VERSION >= 38
/**
   C++ Interface for standard deviation

   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias.
   \param[in] dim the dimension along which the standard deviation is extracted
   \return    the standard deviation of the input array along dimension \p dim

   \ingroup stat_func_stdev

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.
*/
AFAPI array stdev(const array &in, const af_var_bias bias,
                  const dim_t dim = -1);
#endif

/**
   C++ Interface for covariance

   \param[in] X is the first input array
   \param[in] Y is the second input array
   \param[in] isbiased is boolean specifying if biased estimate should be
              taken (default: false)
   \return    the covariance of the input arrays

   \ingroup stat_func_cov

   \deprecated Use af::cov(const array&, const array& const af_var_bias)
*/
AF_DEPRECATED("Use af::cov(const af::array&, const array&, conv af_var_bias)")
AFAPI array cov(const array& X, const array& Y, const bool isbiased=false);

#if AF_API_VERSION >= 38
/**
   C++ Interface for covariance

   \param[in] X is the first input array
   \param[in] Y is the second input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias.
   \return the covariance of the input arrays

   \ingroup stat_func_cov
*/
AFAPI array cov(const array &X, const array &Y, const af_var_bias bias);
#endif

/**
   C++ Interface for median

   \param[in] in is the input array
   \param[in] dim the dimension along which the median is extracted
   \return    the median of the input array along dimension \p dim

   \ingroup stat_func_median

   \note \p dim is -1 by default. -1 denotes the first non-singleton dimension.
*/
AFAPI array median(const array& in, const dim_t dim=-1);

/**
   C++ Interface for mean of all elements

   \param[in] in is the input array
   \return    mean of the entire input array

   \ingroup stat_func_mean
*/
template<typename T>
AFAPI T mean(const array& in);

/**
   C++ Interface for mean of all elements in weighted input

   \param[in] in is the input array
   \param[in] weights  is used to scale input \p in before getting mean
   \return    mean of the entire weighted input array

   \ingroup stat_func_mean
*/
template<typename T>
AFAPI T mean(const array& in, const array& weights);

/**
   C++ Interface for variance of all elements

   \param[in] in is the input array
   \param[in] isbiased is boolean denoting Population variance (false) or Sample
              Variance (true)
   \return variance of the entire input array

   \ingroup stat_func_var

   \deprecated Use \ref af::var that takes \ref af_var_bias instead
*/
template <typename T>
AF_DEPRECATED("Use af::var(const af::array&, const af_var_bias)")
AFAPI T var(const array &in, const bool isbiased = false);

#if AF_API_VERSION >= 38
/**
   C++ Interface for variance of all elements

   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias.
   \return variance of the \p in array

   \ingroup stat_func_var
*/
template <typename T> AFAPI T var(const array &in, const af_var_bias bias);
#endif

/**
   C++ Interface for variance of all elements in weighted input

   \param[in] in is the input array
   \param[in] weights  is used to scale input \p in before getting variance
   \return    variance of the entire input array

   \ingroup stat_func_var
*/
template<typename T>
AFAPI T var(const array& in, const array& weights);

/**
   C++ Interface for standard deviation of all elements

   \param[in] in is the input array
   \return    standard deviation of the entire input array

   \ingroup stat_func_stdev

   \deprecated Use \ref af::stdev that takes \ref af_var_bias instead
*/
template <typename T>
AF_DEPRECATED("Use af::stdev(const array&, const af_var_bias)")
AFAPI T stdev(const array &in);

#if AF_API_VERSION >= 38
/**
   C++ Interface for standard deviation of all elements

   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias.
   \return    standard deviation of the entire input array

   \ingroup stat_func_stdev
*/
template <typename T> AFAPI T stdev(const array &in, const af_var_bias bias);
#endif

/**
   C++ Interface for median of all elements

   \param[in] in is the input array
   \return    median of the entire input array

   \ingroup stat_func_median
*/
template<typename T>
AFAPI T median(const array& in);

/**
   C++ Interface for correlation coefficient

   \param[in] X is the first input array
   \param[in] Y is the second input array
   \return    correlation coefficient of the input arrays

   \note There are many ways correlation coefficient is calculated. This algorithm returns Pearson product-moment correlation coefficient.

   \ingroup stat_func_corrcoef
*/
template<typename T>
AFAPI T corrcoef(const array& X, const array& Y);

#if AF_API_VERSION >= 36
/**
   C++ Interface for finding top k elements along a given dimension

   \param[out] values  The values of the top k elements along the \p dim dimension
   \param[out] indices The indices of the top k elements along the \p dim dimension
   \param[in]  in      Input \ref af::array with at least \p k elements along
                       \p dim
   \param[in]  k       The number of elements to be retriefed along the \p dim dimension
   \param[in]  dim     The dimension along which top k elements are extracted.
                       (Must be 0)
   \param[in]  order   If Descending the highest values are returned. Otherwise
                       the lowest values are returned

   \note{This function is optimized for small values of k.}
   \note{The order of the returned keys may not be in the same order as the
   appear in the input array, for a stable topk, set the AF_TOPK_STABLE flag
   in the order param. These are equivalent to AF_TOPK_STABLE_MAX and AF_TOPK_STABLE_MIN}
   \ingroup stat_func_topk
*/
AFAPI void topk(array &values, array &indices, const array& in, const int k,
                const int dim = -1, const topkFunction order = AF_TOPK_MAX);
#endif
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
   C Interface for mean

   \param[out] out will contain the mean of the input array along dimension \p dim
   \param[in] in is the input array
   \param[in] dim the dimension along which the mean is extracted
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_mean
*/
AFAPI af_err af_mean(af_array *out, const af_array in, const dim_t dim);

/**
   C Interface for mean of weighted input array

   \param[out] out will contain the mean of the input array along dimension \p dim
   \param[in] in is the input array
   \param[in] weights is used to scale input \p in before getting mean
   \param[in] dim the dimension along which the mean is extracted
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_mean
*/
AFAPI af_err af_mean_weighted(af_array *out, const af_array in, const af_array weights, const dim_t dim);

/**
   C Interface for variance

   \param[out] out will contain the variance of the input array along dimension \p dim
   \param[in] in is the input array
   \param[in] isbiased is boolean denoting Population variance (false) or Sample Variance (true)
   \param[in] dim the dimension along which the variance is extracted
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_var

   \deprecated Use \ref af_var_v2 instead
*/
AF_DEPRECATED("Use af_var_v2")
AFAPI af_err af_var(af_array *out, const af_array in, const bool isbiased, const dim_t dim);

#if AF_API_VERSION >= 38
/**
   C Interface for variance

   \param[out] out will contain the variance of the input array along dimension
               \p dim
   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias
   \param[in] dim the dimension along which the variance is extracted
   \return \ref AF_SUCCESS if the operation is successful, otherwise an
           appropriate error code is returned.

   \ingroup stat_func_var

*/
AFAPI af_err af_var_v2(af_array *out, const af_array in, const af_var_bias bias,
                       const dim_t dim);
#endif

/**
   C Interface for variance of weighted input array

   \param[out] out will contain the variance of the input array along dimension \p dim
   \param[in] in is the input array
   \param[in] weights is used to scale input \p in before getting variance
   \param[in] dim the dimension along which the variance is extracted
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_var

*/
AFAPI af_err af_var_weighted(af_array *out, const af_array in, const af_array weights, const dim_t dim);

#if AF_API_VERSION >= 37
/**
   C Interface for mean and variance

   \param[out] mean     The mean of the input array along \p dim dimension
   \param[out] var      The variance of the input array along the \p dim dimension
   \param[in]  in       The input array
   \param[in]  weights  The weights to scale the input array before calculating
                        the mean and varience. If empty, the input is not scaled
   \param[in]  bias     The type of bias used for variance calculation
   \param[in]  dim      The dimension along which the variance and mean are
                        calculated. Default is -1 meaning the first non-zero dim
  */
AFAPI af_err af_meanvar(af_array *mean, af_array *var, const af_array in,
                        const af_array weights, const af_var_bias bias, const dim_t dim);
#endif

/**
   C Interface for standard deviation

   \param[out] out will contain the standard deviation of the input array along dimension \p dim
   \param[in] in is the input array
   \param[in] dim the dimension along which the standard deviation is extracted
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_stdev

   \deprecated Use \ref af_stdev_v2 instead
*/
AF_DEPRECATED("Use af_stdev_v2")
AFAPI af_err af_stdev(af_array *out, const af_array in, const dim_t dim);

#if AF_API_VERSION >= 38
/**
   C Interface for standard deviation

   \param[out] out will contain the standard deviation of the input array along
               dimension \p dim
   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias
   \param[in] dim the dimension along which the standard deviation is extracted
   \return \ref AF_SUCCESS if the operation is successful, otherwise an
           appropriate error code is returned.

   \ingroup stat_func_stdev

*/
AFAPI af_err af_stdev_v2(af_array *out, const af_array in,
                         const af_var_bias bias, const dim_t dim);
#endif

/**
   C Interface for covariance

   \param[out] out will the covariance of the input arrays
   \param[in] X is the first input array
   \param[in] Y is the second input array
   \param[in] isbiased is boolean specifying if biased estimate should be taken (default: false)
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_cov

   \deprecated Use \ref af_cov_v2 instead
*/
AF_DEPRECATED("Use af_cov_v2")
AFAPI af_err af_cov(af_array* out, const af_array X, const af_array Y, const bool isbiased);

#if AF_API_VERSION >= 38
/**
   C Interface for covariance

   \param[out] out will the covariance of the input arrays
   \param[in] X is the first input array
   \param[in] Y is the second input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias
   \return \ref AF_SUCCESS if the operation is successful, otherwise an
           appropriate error code is returned.

   \ingroup stat_func_cov
*/
AFAPI af_err af_cov_v2(af_array *out, const af_array X, const af_array Y,
                       const af_var_bias bias);
#endif

/**
   C Interface for median

   \param[out] out will contain the median of the input array along dimension \p dim
   \param[in] in is the input array
   \param[in] dim the dimension along which the median is extracted
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_median
*/
AFAPI af_err af_median(af_array* out, const af_array in, const dim_t dim);

/**
   C Interface for mean of all elements

   \param[out] real will contain the real part of mean of the entire input array
   \param[out] imag will contain the imaginary part of mean of the entire input array
   \param[in] in is the input array
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_mean
*/
AFAPI af_err af_mean_all(double *real, double *imag, const af_array in);

/**
   C Interface for mean of all elements in weighted input

   \param[out] real will contain the real part of mean of the entire weighted input array
   \param[out] imag will contain the imaginary part of mean of the entire weighted input array
   \param[in] in is the input array
   \param[in] weights  is used to scale input \p in before getting mean
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_mean
*/
AFAPI af_err af_mean_all_weighted(double *real, double *imag, const af_array in, const af_array weights);


/**
   C Interface for variance of all elements

   \param[out] realVal will contain the real part of variance of the entire input array
   \param[out] imagVal will contain the imaginary part of variance of the entire input array
   \param[in] in is the input array
   \param[in] isbiased is boolean denoting Population variance (false) or Sample Variance (true)
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_var

   \deprecated Use \ref af_var_all_v2 instead
*/
AF_DEPRECATED("Use af_var_all_v2")
AFAPI af_err af_var_all(double *realVal, double *imagVal, const af_array in, const bool isbiased);

#if AF_API_VERSION >= 38
/**
   C Interface for variance of all elements

   \param[out] realVal will contain the real part of variance of the entire
               input array
   \param[out] imagVal will contain the imaginary part of variance
               of the entire input array
   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias
   \return \ref AF_SUCCESS if the operation is successful, otherwise an
           appropriate error code is returned.

   \ingroup stat_func_var
*/
AFAPI af_err af_var_all_v2(double *realVal, double *imagVal, const af_array in,
                           const af_var_bias bias);
#endif

/**
   C Interface for variance of all elements in weighted input

   \param[out] realVal will contain the real part of variance of the entire weighted input array
   \param[out] imagVal will contain the imaginary part of variance of the entire weighted input array
   \param[in] in is the input array
   \param[in] weights  is used to scale input \p in before getting variance
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_var
*/
AFAPI af_err af_var_all_weighted(double *realVal, double *imagVal, const af_array in, const af_array weights);

/**
   C Interface for standard deviation of all elements

   \param[out] real will contain the real part of standard deviation of the entire input array
   \param[out] imag will contain the imaginary part of standard deviation of the entire input array
   \param[in] in is the input array
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_stdev

   \deprecated Use \ref af_stdev_all_v2 instead
*/
AF_DEPRECATED("Use af_stdev_all_v2")
AFAPI af_err af_stdev_all(double *real, double *imag, const af_array in);

#if AF_API_VERSION >= 38
/**
   C Interface for standard deviation of all elements

   \param[out] real will contain the real part of standard deviation of the
               entire input array
   \param[out] imag will contain the imaginary part of standard deviation
               of the entire input array
   \param[in] in is the input array
   \param[in] bias The type of bias used for variance calculation. Takes of
              value of type \ref af_var_bias
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_stdev
*/
AFAPI af_err af_stdev_all_v2(double *real, double *imag, const af_array in,
                             const af_var_bias bias);
#endif

/**
   C Interface for median

   \param[out] realVal will contain the real part of median of the entire input array
   \param[out] imagVal will contain the imaginary part of median of the entire input array
   \param[in] in is the input array
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \ingroup stat_func_median
*/
AFAPI af_err af_median_all(double *realVal, double *imagVal, const af_array in);

/**
   C Interface for correlation coefficient

   \param[out] realVal will contain the real part of correlation coefficient of the inputs
   \param[out] imagVal will contain the imaginary part of correlation coefficient of the inputs
   \param[in] X is the first input array
   \param[in] Y is the second input array
   \return     \ref AF_SUCCESS if the operation is successful,
   otherwise an appropriate error code is returned.

   \note There are many ways correlation coefficient is calculated. This algorithm returns Pearson product-moment correlation coefficient.

   \ingroup stat_func_corrcoef
*/
AFAPI af_err af_corrcoef(double *realVal, double *imagVal, const af_array X, const af_array Y);

#if AF_API_VERSION >= 36
/**
   C Interface for finding top k elements along a given dimension

   \param[out] values  The values of the top k elements along the \p dim dimension
   \param[out] indices The indices of the top k elements along the \p dim dimension
   \param[in]  in      Input \ref af::array with at least \p k elements along
                       \p dim
   \param[in]  k       The number of elements to be retriefed along the \p dim dimension
   \param[in]  dim     The dimension along which top k elements are extracted.
                       (Must be 0)
   \param[in]  order   If Descending the highest values are returned. Otherwise
                       the lowest values are returned

   \note{This function is optimized for small values of k.}
   \note{The order of the returned keys may not be in the same order as the
   appear in the input array, for a stable topk, set the AF_TOPK_STABLE flag
   in the order param. These are equivalent to AF_TOPK_STABLE_MAX and AF_TOPK_STABLE_MIN}
   \ingroup stat_func_topk
*/
AFAPI af_err af_topk(af_array *values, af_array *indices, const af_array in,
                     const int k, const int dim, const af_topk_function order);
#endif

#ifdef __cplusplus
}
#endif
