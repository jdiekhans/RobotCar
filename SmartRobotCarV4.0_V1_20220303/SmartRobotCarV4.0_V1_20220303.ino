/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-12-18 14:14:35
 * @LastEditors: Changhua
 * @Description: Smart Robot Car V4.0
 * @FilePath: 
 */

 
#include <avr/wdt.h>
#include "ApplicationFunctionSet_xxx0.h"
uint8_t target_angle = -1;
uint8_t timeout = 1000;
uint8_t current_wait = 0;


void setup()
{
  Application_FunctionSet.ApplicationFunctionSet_Init();
  wdt_enable(WDTO_2S);
}

void loop()
{
  wdt_reset();  
  
  if ((millis() - current_wait) > timeout) // Should run every 1s
  {    
    AppRBG_LED.DeviceDriverSet_RBGLED_xxx(0 /*Duration*/, 2 /*Traversal_Number*/, CRGB::RED);  // Turn LED Red during scan
    target_angle = Application_FunctionSet.ApplicationFunctionSet_Follow4(target_angle);
    current_wait = millis();    
  }
  
  AppRBG_LED.DeviceDriverSet_RBGLED_xxx(0 /*Duration*/, 2 /*Traversal_Number*/, CRGB::GREEN);  // Default LED to Green when doing nothing
}


  /*
   * 
   * 
  //Application_FunctionSet.ApplicationFunctionSet_SensorDataUpdate();
  //Application_FunctionSet.ApplicationFunctionSet_KeyCommand();
  //Application_FunctionSet.ApplicationFunctionSet_RGB();   
  Application_FunctionSet.ApplicationFunctionSet_Obstacle();
  Application_FunctionSet.ApplicationFunctionSet_Tracking();
  Application_FunctionSet.ApplicationFunctionSet_Rocker();
  Application_FunctionSet.ApplicationFunctionSet_Standby();
  Application_FunctionSet.ApplicationFunctionSet_IRrecv();
  Application_FunctionSet.ApplicationFunctionSet_SerialPortDataAnalysis();

  Application_FunctionSet.CMD_ServoControl_xxx0();
  Application_FunctionSet.CMD_MotorControl_xxx0();
  Application_FunctionSet.CMD_CarControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_CarControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_MotorControlSpeed_xxx0();
  Application_FunctionSet.CMD_LightingControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_LightingControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_ClearAllFunctions_xxx0();
  */
