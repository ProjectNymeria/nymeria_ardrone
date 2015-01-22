/************************************************************
* Permission to use, copy, modify, and/or distribute this
* software for any purpose with or without fee is hereby
* granted.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS
* ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO
* EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
* INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  *
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
* WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
* TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH
* THE USE OR PERFORMANCE OF THIS SOFTWARE.
************************************************************/

#ifndef NYMERIA_CHECK_OBSTACLE_H
#define NYMERIA_CHECK_OBSTACLE_H

#include "ros/ros.h"
#include <ardrone_autonomy/Navdata.h>

void stateDroneCallback(const ardrone_autonomy::Navdata& data);

/**
 * Definition of the class NymeriaCheckObstacle, that
 *declares all functionalities
 * in order to allow for obstacle detection.
 */
class NymeriaCheckObstacle {
public:

NymeriaCheckObstacle();
NymeriaCheckObstacle(ros::NodeHandle * n);

void inputCurFrontDist(int cfd);

double getSecurityDist();
void setSecurityDist(double secDist);
double getSensorMaxRange();
void setSensorMaxRange(double range);

private:

double error;
double sensorMaxRange;

ros::Subscriber sub_navdata;
ros::NodeHandle * nh;

void regulation (double angleEstimated, double userCmd);
double pilotage (const double& distToObstacle, const double& securityDist, const double& userCmd);
double PID (const double lastError, const double estimatedCmd);
double rebouclage(const double& angleEstimated);
double saturationPente(const double lastCmd, const double param_saturation, double& currentCmd);

void saturationCommande(double& cmd);
};

#endif