/** @file pooling.hpp
 ** @brief Max pooling filters
 ** @author Andrea Vedaldi
 ** @author Karel Lenc
 **/

/*
Copyright (C) 2014 Andrea Vedaldi and Karel Lenc.
All rights reserved.

This file is part of the VLFeat library and is made available under
the terms of the BSD license (see the COPYING file).
*/

#ifndef VL_NNPOOLING_H
#define VL_NNPOOLING_H

#include <cstddef>

enum PoolMethod {
  NN_POOL_MAX = 0, NN_POOL_AVG, NN_POOL_METHODS_NUM
} ;

template<typename T>
void pooling_cpu(T* pooled,
                 T const* data,
                 PoolMethod method,
                 size_t width,
                 size_t height,
                 size_t depth,
                 size_t windowWidth,
                 size_t windowHeight,
                 size_t strideX,
                 size_t strideY,
                 size_t padLeft,
                 size_t padRight,
                 size_t padTop,
                 size_t padBottom) ;

template<typename T>
void poolingBackward_cpu(T* dzdx,
                         T const* data,
                         T const* dzdy,
                         PoolMethod method,
                         size_t width,
                         size_t height,
                         size_t depth,
                         size_t windowWidth,
                         size_t windowHeight,
                         size_t strideX,
                         size_t strideY,
                         size_t padLeft,
                         size_t padRight,
                         size_t padTop,
                         size_t padBottom) ;

template<typename T>
void pooling_cpu_fast(T* pooled,
                      T const* data,
                      int const* indices,
                      PoolMethod method,
                      size_t dataSize,
                      size_t depth,
                      size_t windowSize,
                      size_t pooledSize) ;

template<typename T>
void pooling_backward_cpu_fast(T* dzdx,
                               T const* data,
                               T const* dzdy,
                               int const* indices,
                               PoolMethod method,
                               size_t dataSize,
                               size_t depth,
                               size_t windowSize,
                               size_t pooledSize) ;

void max_pooling_indices_cpu(int* indices,
                             int const* inindices,
                             size_t width,
                             size_t height,
                             size_t windowWidth,
                             size_t windowHeight,
                             size_t strideX,
                             size_t strideY,
                             size_t padLeft,
                             size_t padRight,
                             size_t padTop,
                             size_t padBottom) ;

void avg_pooling_indices_cpu(int* indices,
                             int const* inindices,
                             size_t width,
                             size_t height,
                             size_t windowWidth,
                             size_t windowHeight,
                             size_t strideX,
                             size_t strideY,
                             size_t padLeft,
                             size_t padRight,
                             size_t padTop,
                             size_t padBottom) ;

#ifdef ENABLE_GPU
template<typename T>
void pooling_gpu(T* pooled,
                 T const* data,
                 PoolMethod method,
                 size_t width,
                 size_t height,
                 size_t depth,
                 size_t windowWidth,
                 size_t windowHeight,
                 size_t strideX,
                 size_t strideY,
                 size_t padLeft,
                 size_t padRight,
                 size_t padTop,
                 size_t padBottom) ;

template<typename T>
void poolingBackward_gpu(T* dzdx,
                         T const* data,
                         T const* dzdy,
                         PoolMethod method,
                         size_t width,
                         size_t height,
                         size_t depth,
                         size_t windowWidth,
                         size_t windowHeight,
                         size_t strideX,
                         size_t strideY,
                         size_t padLeft,
                         size_t padRight,
                         size_t padTop,
                         size_t padBottom) ;

template<typename T>
void pooling_gpu_fast(T* pooled,
                      T const* data,
                      int const* indices,
                      PoolMethod method,
                      size_t dataSize,
                      size_t depth,
                      size_t windowSize,
                      size_t pooledSize) ;

template<typename T>
void pooling_backward_gpu_fast(T* dzdx,
                               T const* data,
                               T const* dzdy,
                               int const* indices,
                               PoolMethod method,
                               size_t dataSize,
                               size_t depth,
                               size_t windowSize,
                               size_t pooledSize) ;

#endif

#endif /* defined(VL_NNPOOLING_H) */
