#ifndef C2017_SUBSYSTEMS_SUPERSTRUCTURE_GROUND_GEAR_INTAKE_QUEUE_TYPES_H_
#define C2017_SUBSYSTEMS_SUPERSTRUCTURE_GROUND_GEAR_INTAKE_QUEUE_TYPES_H_

#include "c2017/subsystems/superstructure/ground_gear_intake/ground_gear_intake.pb.h"
#include "muan/proto/stack_proto.h"
#include "muan/queues/message_queue.h"

namespace c2017 {

namespace ground_gear_intake {

using GroundGearIntakeOutputProto =
    muan::proto::StackProto<GroundGearIntakeOutput, 256>;
using GroundGearIntakeInputProto =
    muan::proto::StackProto<GroundGearIntakeInput, 256>;
using GroundGearIntakeStatusProto =
    muan::proto::StackProto<GroundGearIntakeStatus, 256>;
using GroundGearIntakeGoalProto =
    muan::proto::StackProto<GroundGearIntakeGoal, 256>;

using GroundGearIntakeInputQueue =
    muan::queues::MessageQueue<GroundGearIntakeInputProto>;
using GroundGearIntakeStatusQueue =
    muan::queues::MessageQueue<GroundGearIntakeStatusProto>;
using GroundGearIntakeOutputQueue =
    muan::queues::MessageQueue<GroundGearIntakeOutputProto>;

}  // namespace ground_gear_intake
}  // namespace c2017

#endif  // C2017_SUBSYSTEMS_SUPERSTRUCTURE_GROUND_GEAR_INTAKE_QUEUE_TYPES_H_
