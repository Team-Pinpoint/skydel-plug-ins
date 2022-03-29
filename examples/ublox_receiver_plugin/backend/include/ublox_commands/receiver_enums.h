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
  NOT_CONNECTED,
  NO_FIX,
  FIX_1D,
  FIX_2D,
  FIX_3D,
  GPS_AND_DEAD_RECKONING,
  TIME_ONLY
};

enum class Constellation
{
  GPS = 0,
  SBAS = 1,
  GALILEO = 2,
  BEIDOU = 3,
  IMES = 4,
  QZSS = 5,
  GLONASS = 6
};

#endif
