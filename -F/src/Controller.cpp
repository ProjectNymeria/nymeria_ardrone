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

#include <nymeria_ardrone/Controller.h>

#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/UInt8.h"
#include <ardrone_autonomy/Navdata.h>
#include <nymeria_ardrone/Nymeria.h>

ros::NodeHandle * Controller::getNH(){
        return &nh;
}

Controller::Controller(){
}

int main(int argc, char * *argv)
{
        ros::init(argc, argv, "controller");

        Controller si;

        si.loop(si.getNH());

        return 0;
}

/**
 * Central functionality of the controller: trigger Nymeria
 *in order to actiate
 * obstacle detection and avoidance.
 **/
void Controller::loop(ros::NodeHandle * n){
        int rate = 50;
        int errorCode;
        int lastErrorCode = 0;
        /* Modifiable loop rate */
        ros::Rate loop_rate(rate);

        Nymeria nym (n);

        while( ros::ok())
        {

                /* Trigger Nymeria */
                errorCode = nym.validateStates();

                /* Interpret return value. */
                switch( errorCode )
                {
                case NymeriaConstants::INIT:
                        if( errorCode != lastErrorCode )
                                printf("init\n");
                        break;
                case NymeriaConstants::O_FRONT:
                        if( errorCode != lastErrorCode )
                                printf("obstacle\n");
                        break;
                default:
                        if( errorCode != lastErrorCode )
                                printf("code : %d\n", errorCode);
                        break;
                }

                lastErrorCode = errorCode;

                loop_rate.sleep();
        }

        return;
}