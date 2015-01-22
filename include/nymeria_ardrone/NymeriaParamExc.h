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

#ifndef NYMERIA_PARAM_EXC_H
#define NYMERIA_PARAM_EXC_H

#include <nymeria_ardrone/NymeriaExceptions.h>

/**
 * Declaration of the class NymeriaParamExc, that declares
 *the exception
 * thrown when the ROS parameter requested does not exist or
 *was misspelled.
 */

class NymeriaParamExc :
        public NymeriaExceptions {
public:
NymeriaParamExc(string msg = "");
virtual ~NymeriaParamExc(void) throw();
virtual const char * what() const throw();
private:

};

#endif