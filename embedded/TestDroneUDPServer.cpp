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

#include "UDPWrapper.h"

#include <stdio.h>   /* Standard input/output definitions */
#include <errno.h>   /* Error number definitions */
#include <stdlib.h>


#define BUFFER_SIZE 8
#define NB_VAL 10
#define TIMEOUT 1000000

int main()
{
        int cpt_loop = 0;
        int timeoutCnt = 0;
        int pgExit = 0;

        int bsent, chread;
        char readBuffer[BUFFER_SIZE];
        char sendBuffer[4];

        printf("tcsetattr succeed\nIMPALA version\n");

        // Open UDP server //
        UDPServer server("192.168.1.1", 7777);

        printf("Wait for client to be ready\n");

        // wait for client to connect
        while( server.recv(readBuffer, BUFFER_SIZE) == -1 )
                ;

        printf("connected\n");

        while( cpt_loop < 500 && pgExit == 0 )
        {

                printf("test %d\n", cpt_loop);
                sprintf(sendBuffer, "%d", cpt_loop);
                bsent = server.send(sendBuffer, 4);
                cpt_loop++;

                try {
                        server.recv(readBuffer, BUFFER_SIZE);
                }catch( const std::exception & ex ){
                        printf(ex.what());
                        break;
                }

        } //end while

        printf("Program exit...\n");

} //end main