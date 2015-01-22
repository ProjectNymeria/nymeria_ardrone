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

#include <nymeria_ardrone/NymeriaExceptions.h>

/**
 * Definition of the class NymeriaExceptions, that defines
 *the base class
 * for all exceptions particular to Nymeria.
 */

/**
 * \file NymeriaExceptions.cpp
 * \class NymeriaExceptions NymeriaExceptions.h
 * \author Team-Nymeria
 * \version 0.2
 * \date 18th of January 2015
 */

/**
 * Constructor in order to create an object of type
 *NymeriaException.
 **/
NymeriaExceptions::NymeriaExceptions(string msg){
        this->errMsg = msg;
}

NymeriaExceptions::~NymeriaExceptions(void) throw(){
}

/**
 * Overriding what() function from standard Exception.
 **/
const char * NymeriaExceptions::what() const throw(){
        /* display error message */
        return this->errMsg.c_str();
}