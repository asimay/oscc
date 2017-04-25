#ifndef _KIA_SOUL_STEERING_GLOBALS_H_
#define _KIA_SOUL_STEERING_GLOBALS_H_


#include <Arduino.h>
#include "DAC_MCP49xx.h"
#include "mcp_can.h"
#include "can.h"
#include "PID.h"

#include "steering_module.h"


/*******************************************************************************
*   WARNING
*
*   The ranges selected to do steering control are carefully tested to
*   ensure that a torque is not requested that the vehicles steering motor
*   cannot handle. By changing any of this code you risk attempting to actuate
*   a torque outside of the vehicles valid range. Actuating a torque outside of
*   the vehicles valid range will, at best, cause the vehicle to go into an
*   unrecoverable fault state. Clearing this fault state requires one of Kia's
*   native diagnostics tools, and someone who knows how to clear DTC codes with
*   said tool.
*
*   It is NOT recommended to modify any of the existing control ranges, or
*   gains, without expert knowledge.
*******************************************************************************/

#define PARAM_STEERING_ANGLE_RATE_MAX_IN_DEGREES_PER_USEC ( 1000.0 )
#define PARAM_OVERRIDE_WHEEL_THRESHOLD_IN_DEGREES_PER_USEC ( 3000 )
#define PARAM_PID_PROPORTIONAL_GAIN ( 0.3 )
#define PARAM_PID_INTEGRAL_GAIN ( 1.3 )
#define PARAM_PID_DERIVATIVE_GAIN ( 0.03 )
#define PARAM_PID_WINDUP_GUARD ( 1500 )
#define PARAM_RX_TIMEOUT_IN_MSEC ( 250 )

#define PIN_DAC_CHIP_SELECT ( 9 )
#define PIN_CAN_CHIP_SELECT ( 10 )
#define PIN_TORQUE_POSITION_SENSOR_HIGH ( A0 )
#define PIN_TORQUE_POSITION_SENSOR_LOW ( A1 )
#define PIN_TORQUE_POSITION_SPOOF_HIGH ( A2 )
#define PIN_TORQUE_POSITION_SPOOF_LOW ( A3 )
#define PIN_SPOOF_ENABLE ( 6 )


#ifdef GLOBAL_DEFINED
    DAC_MCP49xx dac( DAC_MCP49xx::MCP4922, PIN_DAC_CHIP_SELECT );
    MCP_CAN can( PIN_CAN_CHIP_SELECT );

    #define EXTERN
#else
    extern DAC_MCP49xx dac;
    extern MCP_CAN can;

    #define EXTERN extern
#endif


EXTERN can_frame_s rx_frame_steering_command;
EXTERN can_frame_s tx_frame_steering_report;
EXTERN kia_soul_steering_state_s steering_state;
EXTERN kia_soul_steering_control_state_s steering_control_state;
EXTERN PID pid;
EXTERN uint8_t torque_sum;


#endif
