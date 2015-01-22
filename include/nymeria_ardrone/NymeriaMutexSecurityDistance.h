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

#ifndef NYMERIA_SECURITY_DISTANCE_H
#define NYMERIA_SECURITY_DISTANCE_H
#include <nymeria_ardrone/NymeriaMutex.h>

/**
 * Defintion of the class NymeriaMutexSecurityDistance,
 *which manages access to the ROS Parameter
 *nymeriaSecurityDistance.
 **/

class NymeriaMutexSecurityDistance : public NymeriaMutex {
public:
static NymeriaMutexSecurityDistance * getInstance();
static void lock();
static void unlock();
~NymeriaMutexSecurityDistance();
private:
NymeriaMutexSecurityDistance();
static bool locked;
static bool instanceFlag;
static NymeriaMutexSecurityDistance * mutexSecDist;
};
#endif