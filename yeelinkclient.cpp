#include <Process.h>
#include <Console.h>

#include "yeelinkclient.h"


void initYeelinkClient() {
  // Initialize Bridge
  Bridge.begin();

#ifdef CONSOLE_ENABLED
  // Initialize Console
  Console.begin();

  // Wait until a Console Monitor is connected.
  while (!Console);

  Console.println("Network init OK.");
#endif
}

String ftoa(float val, char resolution)
{
  if (val < 0.000001 && val > -0.000001)
  {
    return "0";
  }
  String result;
  bool positive = val > 0.0f ? true : false;
  if (!positive)
  {
    result += "-";
    val = -val;
  }
  int i_part = int(val);
  float f_part = val - i_part;
  result += i_part;

  String temp;
  resolution = (resolution <= 6 ? resolution : 6);
  float min_val = 0.000001;
  for (int i = 0; i < resolution && f_part >= min_val; ++i)
  {
    temp += int(f_part * 10);
    f_part = f_part * 10 - int(f_part * 10);
    min_val *= 10;
  }
  if (temp.length())
  {
    result += ".";
    result += temp;
  }
  return result;
}

void sendSensorDataToYeelink(float dataParam, String sensorId, String deviceId)
{
  // Launch "curl" command and get Arduino ascii art logo from the network
  // curl is command line program for transferring data using different internet protocols
  Process p;        // Create a process and call it "p"
  //command is like ("curl -d '{"value":14.5}' -H U-ApiKey:6259afea8328804a22589aa3c8267512 http://api.yeelink.net/v1.0/device/340732/sensor/377542/datapoints");

  String param = "curl -d '{";
  param += "\"value\":";
  param += ftoa(dataParam, 2);
  param += "}";
  param += "'";
  param += " -H U-ApiKey:";
  param += API_KEY;
  param += " http://api.yeelink.net/v1.0/device/";
  param += deviceId;
  param += "/sensor/";
  param += sensorId;
  param += "/datapoints";

#ifdef CONSOLE_ENABLED
  Console.println("param = " + param);
#endif
  p.runShellCommandAsynchronously(param);

  // Print arduino logo over the Console
  // A process output can be read with the stream methods
#ifdef CONSOLE_ENABLED
  while (p.available() > 0) {
    char c = p.read();
    Console.print(c);
  }
  // Ensure the last bit of data is sent.
  Console.flush();
#endif
}

float getSensorDataFromYeelink(String key, String sensorId, String deviceId)
{
  Process p;        // Create a process and call it "p"
  //command is like ("curl -H U-ApiKey:6259afea8328804a22589aa3c8267512 http://api.yeelink.net/v1.0/device/340732/sensor/377542/datapoints/key");

  String param = "curl ";
  param += " -H U-ApiKey:";
  param += API_KEY;
  param += " http://api.yeelink.net/v1.0/device/";
  param += deviceId;
  param += "/sensor/";
  param += sensorId;
  param += "/datapoints/";
  if (key != NULL) {
    param += key;
  }

#ifdef CONSOLE_ENABLED
  Console.println("param = " + param);
#endif
  p.runShellCommandAsynchronously(param);

  // Print arduino logo over the Console
  // A process output can be read with the stream methods
#ifdef CONSOLE_ENABLED
  while (p.available() > 0) {
    char c = p.read();
    Console.print(c);
  }
  // Ensure the last bit of data is sent.
  Console.flush();
#endif

  return 1;
}

