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

#include <nymeria_ardrone/NymeriaMutexSecurityDistance.h>
#include <iostream>

/**
 * Defintion of the class NymeriaMutexSecurityDistance,
 *which manages access to the ROS Parameter
 *nymeriaSecurityDistance.
 **/

/**
 * Default constructor in order to create an object of type
 *NymeriaMutexSecurityDistance.
 **/
NymeriaMutexSecurityDistance::NymeriaMutexSecurityDistance(){
};

/**
 * Destructor resetting class attributes.
 */
NymeriaMutexSecurityDistance::~NymeriaMutexSecurityDistance(){
        instanceFlag = false;
        locked = false;
};


/**
 * Flag in order to make sure there is only one instance of
 *the class.
 * true - has been already instantiated once.
 * false - hasn't been instantiated yet.
 */
bool NymeriaMutexSecurityDistance::instanceFlag = false;
/**
 * Attribute that marks whether or not the resource has been
 *acquired yet.
 * true - has been already acquired.
 * false - hasn't been acquired yet.
 */
bool NymeriaMutexSecurityDistance::locked = false;

/**
 * First declaration of instance of type
 *NymeriaMutexSecurityDistance.
 */
NymeriaMutexSecurityDistance * NymeriaMutexSecurityDistance::mutexSecDist = NULL;

/**
 * Function in order to get an instance of
 *NymeriaMutexSecurityDistance.
 * @return useful, i.e. not NULL object of type
 *NymeriaMutexSecurityDistance.
 */
NymeriaMutexSecurityDistance * NymeriaMutexSecurityDistance::getInstance(){
        if( !instanceFlag ){
                mutexSecDist = new NymeriaMutexSecurityDistance();
                instanceFlag = true;
                return mutexSecDist;
        }else  {
                return mutexSecDist;
        }
}

/**
 * Method in order to lock or acquire resource.
 * Resource can not be acquired by any other object while
 *being locked.
 */
void NymeriaMutexSecurityDistance::lock(){
        while( locked )
        {
        }

        locked = true;
}

/**
 * Method in order to unlock or release resource.
 * Resource can be acquired by an other object after being
 *released.
 */
void NymeriaMutexSecurityDistance::unlock(){
        locked = false;
}