/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file : piecewise_linear_generator.h
 * @brief: The definition of PiecewiseLinearGenerator class
 **/

#ifndef MODULES_PLANNING_MATH_SMOOTHING_SPLINE_PIECEWISE_LINEAR_GENERATOR_H_
#define MODULES_PLANNING_MATH_SMOOTHING_SPLINE_PIECEWISE_LINEAR_GENERATOR_H_

#include <memory>
#include <vector>

#include "Eigen/Core"

#include "modules/common/math/qp_solver/qp_solver.h"
#include "modules/planning/math/smoothing_spline/piecewise_linear_constraint.h"
#include "modules/planning/math/smoothing_spline/piecewise_linear_kernel.h"

namespace apollo {
namespace planning {

class PiecewiseLinearGenerator {
 public:
  // x = f(t)
  PiecewiseLinearGenerator(const uint32_t num_of_segments,
                           const double unit_segment);
  virtual ~PiecewiseLinearGenerator() = default;

  PiecewiseLinearConstraint* mutable_constraint();

  PiecewiseLinearKernel* mutable_kernel();

  // solve
  bool Solve();

 private:
  const uint32_t num_of_segments_;
  const double unit_segment_;
  const double total_t_;

  PiecewiseLinearConstraint constraint_;
  PiecewiseLinearKernel kernel_;

  std::unique_ptr<apollo::common::math::QpSolver> qp_solver_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_MATH_SMOOTHING_SPLINE_PIECEWISE_LINEAR_GENERATOR_H_
