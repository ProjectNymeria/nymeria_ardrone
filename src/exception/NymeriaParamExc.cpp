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

#include <nymeria_ardrone/NymeriaParamExc.h>

/**
 * Definition of the class NymeriaParamExc, that defines the
 *exception
 * thrown when the ROS parameter requested does not exist or
 *was misspelled.
 */

/**
 * Constructor in order to create an object of type
 *NymeriaParamExc.
 * @param msg - message to be shown, when exception is
 *thrown.
 */
NymeriaParamExc::NymeriaParamExc(string msg) : NymeriaExceptions(msg){
}

/**
 * Method in order to throw exception.
 */
NymeriaParamExc::~NymeriaParamExc(void) throw(){
}

/* overriding what() for particular error message. */
const char * NymeriaParamExc::what() const throw()
{
        string s = "ROS parameter not existent or misspelled.";

        return s.c_str();
}