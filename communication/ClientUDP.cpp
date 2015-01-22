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

#include "udp_wrapper.hpp"
#include <stdlib.h>

int main()
{
        char message[10];
        int nb_char;

        // UDP port (7777) is synchronized with server's one
        UDPClient client("127.0.0.1", 7777);

        // first client request
        while( client.send("go", 2) <= 0 )
                ;

        while( 1 )
        {
                nb_char = client.recv(message, 10);
                if( message[0] > 120 ){
                        message[0] = 128;
                }
                printf("received : %d-\n", message[0]);
        }
}