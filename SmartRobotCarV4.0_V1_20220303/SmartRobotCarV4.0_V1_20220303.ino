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
int timeout = 1000;
uint8_t current_wait = 0;
uint8_t targetFound = 0;

void setup()
{
  Application_FunctionSet.ApplicationFunctionSet_Init();
  wdt_enable(WDTO_2S);
}

void loop()
{
  wdt_reset();
  Application_FunctionSet.ApplicationFunctionSet_SensorDataUpdate();
  Application_FunctionSet.ApplicationFunctionSet_ObstacleTracking();
  
//  Application_FunctionSet.MoveTowardsDetectObject();
//  if(!targetFound) {
//  //    targetFound = Application_FunctionSet.DetectObject();
//    while(!targetFound) 
//    {
//      GetAngleOfTarget(); // Every second tries to scan the frontish area of the car to find an object
//    }
//  }
//   else 
//  {
//    Application_FunctionSet.ApplicationFunctionSet_RGB_Green();
//  } 
  
}

int GetAngleOfTarget()
{
  if ((millis() - current_wait) > timeout) // Should run every 1s
  {    
    Application_FunctionSet.ApplicationFunctionSet_RGB_Red();  // Turn LED Red during scan
    target_angle = Application_FunctionSet.ApplicationFunctionSet_Follow4(target_angle);
    current_wait = millis();
  }
  if (target_angle != -1)
    Application_FunctionSet.ApplicationFunctionSet_RGB_Green();  // Default LED to Green when target is detected!

    // at the target angle (where the opponent is) move forward 100 units
    


    // after moving forward
    // 1. stop the car
    // 2. reset target_angle to find the opponent
   Application_FunctionSet.ApplicationFunctionSet::StopCar();
//   target_angle = -1;
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
