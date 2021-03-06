#ifndef C2018_SUBSYSTEMS_SCORE_SUBSYSTEM_WRIST_WRIST_H_
#define C2018_SUBSYSTEMS_SCORE_SUBSYSTEM_WRIST_WRIST_H_

#include <algorithm>
#include <chrono>
#include <cmath>
#include "c2018/subsystems/score_subsystem/queue_types.h"
#include "c2018/subsystems/score_subsystem/wrist/wrist_constants.h"
#include "muan/control/calibration/hall_calibration.h"
#include "muan/control/state_space_controller.h"
#include "muan/control/state_space_observer.h"
#include "muan/control/state_space_plant.h"
#include "muan/control/trapezoidal_motion_profile.h"
#include "muan/queues/queue_manager.h"
#include "muan/units/units.h"
#include "muan/utils/math_utils.h"
#include "muan/utils/monitor.h"
#include "muan/wpilib/queue_types.h"

namespace c2018 {
namespace score_subsystem {
namespace wrist {

// Parameters for the trapezoidal profile
static constexpr double kMaxWristVelocity = 8.0;
static constexpr double kMaxWristAcceleration = 8.0;
static constexpr muan::control::MotionProfileConstraints kWristConstraints = {
    kMaxWristVelocity, kMaxWristAcceleration};

// Angle constants
static constexpr double kWristMinAngle = 0;
static constexpr double kWristStowAngle = 80 * (M_PI / 180);
static constexpr double kWristMaxAngle = 160 * (M_PI / 180);

// Hall Calibration constants
static constexpr double kCalibVoltage = 0;
static constexpr double kHallEffectAngle = 0.23;

// Intake Voltage constants
static constexpr double kSlowOuttakeVoltage = -6;
static constexpr double kFastOuttakeVoltage = -9;
static constexpr double kIntakeVoltage = 12;

// Mannual voltage control constants
static constexpr double kHoldingVoltage = 1.5;
static constexpr double kMaxVoltage = 12;

// Has Cube encoder stuff
static constexpr int kNumHasCubeTicks = 150;

class WristController {
 public:
  // Sets up the state space stuff and motion profile
  WristController();

  // Sets the unprofiled goal after capping
  void SetGoal(double angle, IntakeGoal mode);
  // Updates the model
  void Update(ScoreSubsystemInputProto input, ScoreSubsystemOutputProto* output,
              ScoreSubsystemStatusProto* status, bool outputs_enabled);

  double TimeLeftUntil(double angle, double final_angle);
  void SetWeights(bool has_cube);

  // Getter for hall calibration
  bool is_calibrated() const;

 private:
  // Motion Profile
  muan::control::MotionProfilePosition UpdateProfiledGoal(bool outputs_enabled);
  muan::control::MotionProfilePosition unprofiled_goal_;
  muan::control::MotionProfilePosition profiled_goal_;

  // Hall Calibration
  muan::control::HallCalibration hall_calibration_{kHallEffectAngle};

  // Statespace stuff
  muan::control::StateSpacePlant<1, 3, 1> plant_;
  muan::control::StateSpaceController<1, 3, 1> controller_;
  muan::control::StateSpaceObserver<1, 3, 1> observer_;

  // Keep those V safe
  double CapU(double wrist_voltage);

  IntakeGoal intake_mode_ = IntakeGoal::INTAKE_NONE;
  PinchState pinch_state_ = PinchState::IDLE_WITH_CUBE;

  // Voltage to give to intake
  double intake_voltage_ = 0;

  // Does it _really_ have a cube?
  int has_cube_for_ticks_ = 0;
};

}  // namespace wrist
}  // namespace score_subsystem
}  // namespace c2018

#endif  // C2018_SUBSYSTEMS_SCORE_SUBSYSTEM_WRIST_WRIST_H_
