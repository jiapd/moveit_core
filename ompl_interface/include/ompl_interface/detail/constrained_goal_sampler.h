/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2011, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Ioan Sucan */

#ifndef MOVEIT_OMPL_INTERFACE_DETAIL_CONSTRAINED_GOAL_SAMPLER_
#define MOVEIT_OMPL_INTERFACE_DETAIL_CONSTRAINED_GOAL_SAMPLER_

#include <ompl/base/GoalLazySamples.h>
#include <kinematic_constraints/kinematic_constraint.h>
#include <kinematic_constraints/constraint_samplers.h>

namespace ompl_interface
{

class ModelBasedPlanningContext;

/** @class ConstrainedGoalSampler
 *  An interface to the OMPL goal lazy sampler*/
class ConstrainedGoalSampler : public ompl::base::GoalLazySamples
{
public:
  
  ConstrainedGoalSampler(const ModelBasedPlanningContext *pc, const kinematic_constraints::KinematicConstraintSetPtr &ks,
                         const kinematic_constraints::ConstraintSamplerPtr &cs = kinematic_constraints::ConstraintSamplerPtr());
  
private:
  
  bool sampleUsingConstraintSampler(const ompl::base::GoalLazySamples *gls, ompl::base::State *newGoal);
  bool sampleUsingGAIK(const ompl::base::GoalLazySamples *gls, ompl::base::State *newGoal);
  
  const ModelBasedPlanningContext                 *planning_context_;
  kinematic_constraints::KinematicConstraintSetPtr kinematic_constraint_set_;
  kinematic_constraints::ConstraintSamplerPtr      constraint_sampler_;
  planning_models::KinematicState                  state_;
};
}

#endif
