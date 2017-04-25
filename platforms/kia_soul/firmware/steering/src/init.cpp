#include <Arduino.h>
#include "serial.h"
#include "can.h"

#include "init.h"
#include "globals.h"


void init_structs( void )
{
    memset( &rx_frame_steering_command,
            0,
            sizeof(rx_frame_steering_command) );

    steering_control_state.enabled = false;
    steering_control_state.emergency_stop = false;
    steering_control_state.operator_override = false;
}


void init_pins( void )
{
    pinMode( PIN_DAC_CHIP_SELECT, OUTPUT );
    pinMode( PIN_TORQUE_POSITION_SENSOR_HIGH, INPUT );
    pinMode( PIN_TORQUE_POSITION_SENSOR_LOW, INPUT );
    pinMode( PIN_TORQUE_POSITION_SPOOF_HIGH, INPUT );
    pinMode( PIN_TORQUE_POSITION_SPOOF_LOW, INPUT );
    pinMode( PIN_SPOOF_ENABLE, OUTPUT );

    digitalWrite( PIN_DAC_CHIP_SELECT, HIGH );

    digitalWrite( PIN_SPOOF_ENABLE, LOW );
}


void init_interfaces( void )
{
    #ifdef DEBUG
    init_serial( );
    #endif

    init_can( can );
}
