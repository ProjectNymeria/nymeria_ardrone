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

#ifndef NYMERIA_EXCEPTIONS_H
#define NYMERIA_EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

/**
 * Declaration of the class NymeriaExceptions, that declares
 *the base class
 * for all exceptions particular to Nymeria.
 */

class NymeriaExceptions : public exception {
public:
NymeriaExceptions(string msg);
virtual ~NymeriaExceptions(void) throw();
virtual const char * what() const throw();
private:
string errMsg;
};

#endif