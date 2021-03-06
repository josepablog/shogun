/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Jakub Jirku
 * Copyright (C) 2007-2011 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include <shogun/lib/config.h>

#ifndef LOGKERNEL_H_
#define LOGKERNEL_H_

#include <shogun/lib/common.h>
#include <shogun/kernel/Kernel.h>
#include <shogun/distance/Distance.h>

namespace shogun
{

class CDistance;

/** @brief Log kernel
 *
 * Formally described as
 *
 * \f[
 * 		K(x,x') = - log (\| x-x' \|^{degree} + 1)
 * \f]
 *
 */

class CLogKernel: public CKernel
{
public:
	/** default constructor */
	CLogKernel();

	/** constructor
	 * @param cache size of cache
	 * @param degree kernel parameter degree
	 * @param dist distance to be used
	 */
	CLogKernel(int32_t cache, float64_t degree, CDistance* dist);

	/** constructor
	 * @param l features left-side
	 * @param r features right-side
	 * @param degree kernel parameter degree
	 * @param dist distance to be used
	 */
	CLogKernel(CFeatures *l, CFeatures *r, float64_t degree, CDistance* dist);

	/** initialize kernel with features
	 * @param l features left-side
	 * @param r features right-side
	 * @return true if successful
	 */
	virtual bool init(CFeatures* l, CFeatures* r);

	/**
	 * @return kernel type
	 */
	virtual EKernelType get_kernel_type() { return K_POWER; }

	/**
	 * @return type of features
	 */
	virtual EFeatureType get_feature_type() { return m_distance->get_feature_type(); }

	/**
	 * @return class of features
	 */
	virtual EFeatureClass get_feature_class() { return m_distance->get_feature_class(); }

	/**
	 * @return name of kernel
	 */
	virtual const char* get_name() const { return "LogKernel"; }

	virtual ~CLogKernel();

protected:
	/**
	 * compute kernel for specific feature vectors
	 * corresponding to [idx_a] of left-side and [idx_b] of right-side
	 * @param idx_a left-side index
	 * @param idx_b right-side index
	 * @return kernel value
	 */
	virtual float64_t compute(int32_t idx_a, int32_t idx_b);

private:
	void init();

protected:
	/// distance to be used
	CDistance* m_distance;

	/// degree parameter of kernel
	float64_t m_degree;
};
}

#endif /* LOGKERNEL_H_ */
