#ifndef RECEIVER_ENUMS_H
#define RECEIVER_ENUMS_H

enum class ReceiverStartType
{
  NONE = 0,
  COLD = 1,
  WARM = 2,
  HOT = 3
};

enum class ReceiverStatus
{
  ACTIVE,
  INACTIVE,
  STARTING,
  NOT_DETECTED
};

#endif
